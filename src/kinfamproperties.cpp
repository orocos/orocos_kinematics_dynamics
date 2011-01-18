/******************************************************************************
*                   This file is part of the KDL project                      *
*                                                                             *
*                     (C) 2010 Ruben Smits                                    *
*                         2010 Steven Bellens                                 *
*                     ruben.smits@mech.kuleuven.be                            *
*                     steven.bellens@mech.kuleuven.be                         *
*                    Department of Mechanical Engineering,                    *
*                   Katholieke Universiteit Leuven, Belgium.                  *
*                                                                             *
*       You may redistribute this software and/or modify it under either the  *
*       terms of the GNU Lesser General Public License version 2.1 (LGPLv2.1  *
*       <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>) or (at your *
*       discretion) of the Modified BSD License:                              *
*       Redistribution and use in source and binary forms, with or without    *
*       modification, are permitted provided that the following conditions    *
*       are met:                                                              *
*       1. Redistributions of source code must retain the above copyright     *
*       notice, this list of conditions and the following disclaimer.         *
*       2. Redistributions in binary form must reproduce the above copyright  *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*       3. The name of the author may not be used to endorse or promote       *
*       products derived from this software without specific prior written    *
*       permission.                                                           *
*       THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  *
*       IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
*       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    *
*       ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,*
*       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    *
*       (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS       *
*       OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) *
*       HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   *
*       STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING *
*       IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE    *
*       POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                             *
*******************************************************************************/

#include "kinfamproperties.hpp"
#include "motionproperties.hpp"
#include <boost/lexical_cast.hpp>
#include <string>

namespace RTT
{
    void decomposeProperty(const Joint& joint, PropertyBag& targetbag)
    {
        targetbag.setType("KDL.Joint");
        targetbag.add( new Property<std::string>("Type", "Type of Joint",joint.getTypeName()));
    }

    bool composeProperty(const PropertyBag& bag, Joint& joint)
    {
        if ( bag.getType() == "KDL.Joint" ){ // check the type
            Property<std::string> type_name = bag.getPropertyType<std::string>("Type");
            if ( !type_name.ready() )
                return false;
            if (type_name.value()=="RotX"){
                joint=Joint(Joint::RotX);
                return true;
            }else if(type_name.value()=="RotY"){
                joint=Joint(Joint::RotY);
                return true;
            }else if(type_name.value()=="RotZ"){
                joint=Joint(Joint::RotZ);
                return true;
            }else if(type_name.value()=="TransX"){
                joint=Joint(Joint::TransX);
                return true;
            }else if(type_name.value()=="TransY"){
                joint=Joint(Joint::TransY);
                return true;
            }else if(type_name.value()=="TransZ"){
                joint=Joint(Joint::TransZ);
                return true;
            }else if(type_name.value()=="None"){
                joint=Joint(Joint::None);
                return true;
            }
            else
                return false;
        }
        return false;
    }

    void decomposeProperty(const Segment& segment, PropertyBag& targetbag)
    {
        PropertyBag frame_bag;
        PropertyBag joint_bag;
        targetbag.setType("KDL.Segment");
        decomposeProperty(segment.getJoint(), joint_bag);
        targetbag.add(new Property<PropertyBag>("joint","The joint at the base of this segment",joint_bag));
        decomposeProperty(segment.getFrameToTip(), frame_bag);
        targetbag.add(new Property<PropertyBag>("frame","The offset frame from the joint at the base to the end of the link",frame_bag));
    }

    bool composeProperty(const PropertyBag& bag, Segment& segment)
    {
        if ( bag.getType() == "KDL.Segment" ){ // check the type
            Property<PropertyBag> joint_bag = bag.getPropertyType<PropertyBag>("joint");
            Property<PropertyBag> frame_bag = bag.getPropertyType<PropertyBag>("frame");
            if(!(frame_bag.ready()&&joint_bag.ready()))
                return false;
            Property<Joint> joint_prop(joint_bag.getName(),joint_bag.getDescription());
            joint_prop.getTypeInfo()->composeType(joint_bag.getDataSource(),
                                                 joint_prop.getDataSource());
            Property<Frame> frame_prop(frame_bag.getName(),frame_bag.getDescription());
            frame_prop.getTypeInfo()->composeType(frame_bag.getDataSource(),
                                                 frame_prop.getDataSource());
            segment=Segment(joint_prop.value(),frame_prop.value());
            return true;
        }
        else
            return false;
    }

    void decomposeProperty(const Chain& chain, PropertyBag& targetbag)
    {
        targetbag.setType("KDL.Chain");
        PropertyBag segment_bag;
        for(unsigned int i=0;i<chain.getNrOfSegments();i++){
            decomposeProperty(chain.getSegment(i),segment_bag);
            targetbag.add(new Property<PropertyBag>("Segment","Segment of the chain",segment_bag));
        }
    }

    bool composeProperty(const PropertyBag& bag, Chain& chain)
    {
        Chain chain_new;
        if( bag.getType() =="KDL.Chain"){
            for(unsigned int i=0;i<bag.size();i++){
                RTT::base::PropertyBase* segment_bag = bag.getItem(i);
                if(!segment_bag->ready())
                    return false;
                Property<Segment> segment_prop(segment_bag->getName(),
                                               segment_bag->getDescription());
                segment_prop.getTypeInfo()->composeType(segment_bag->getDataSource(),
                                                        segment_prop.getDataSource());
                chain_new.addSegment(segment_prop.value());
            }
            chain = chain_new;
            return true;
        }else
            return false;
    }

    void decomposeProperty(const JntArray& jntarray, PropertyBag& targetbag)
    {
        targetbag.setType("KDL.JntArray");
        for(int i = 0; i < jntarray.data.rows(); i++)
        {
          string rindx = boost::lexical_cast<string>( i );
          targetbag.add(new Property<double>("Element" + rindx,"JntArray element",jntarray.data(i)));
        }
    }

    bool composeProperty(const PropertyBag& bag, JntArray& jntarray)
    {
        JntArray jntarray_new(bag.size());
        if( bag.getType() =="KDL.JntArray"){
            for(unsigned int i = 0; i < bag.size(); i++){
                RTT::base::PropertyBase* jntarray_bag = bag.getItem(i);
                if(!jntarray_bag->ready())
                    return false;
                Property<double> jntarray_prop(jntarray_bag->getName(), jntarray_bag->getDescription());
                jntarray_prop.getTypeInfo()->composeType(jntarray_bag->getDataSource(), jntarray_prop.getDataSource());
                jntarray_new.data(i) = jntarray_prop.value();
            }
            jntarray = jntarray_new;
            return true;
        } else
            return false;
    }

    void decomposeProperty(const Jacobian& jacobian, PropertyBag& targetbag)
    {
      targetbag.setType("KDL.Jacobian");
      for(int i = 0; i < jacobian.data.rows(); i++){
        for(int j = 0; j < jacobian.data.cols(); j++){
          string rindx = boost::lexical_cast<string>( i );
          string cindx = boost::lexical_cast<string>( j );
          targetbag.add(new Property<double>("Element (" + rindx + "," + cindx + ")","Jacobian element",jacobian.data(i,j)));
        }
      }
    }

    bool composeProperty(const PropertyBag& bag, Jacobian& jacobian)
    {
      Jacobian jacobian_new((bag.size() / 6));
      
      if( bag.getType() =="KDL.Jacobian"){
        for(unsigned int i = 0; i < 6; i++){
          for(unsigned int j = 0; j < bag.size() / 6; j++){
            RTT::base::PropertyBase* data_bag = bag.getItem((bag.size() / 6) * i + j);
            if(!data_bag->ready())
                return false;
            Property<double> data_prop(data_bag->getName(), data_bag->getDescription());
            data_prop.getTypeInfo()->composeType(data_bag->getDataSource(), data_prop.getDataSource());
            jacobian_new.data(i,j) = data_prop.value();
          }
        }
        jacobian = jacobian_new;
        return true;
      }
      else
        return false;
      }
}
