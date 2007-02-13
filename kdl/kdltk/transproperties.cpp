// Copyright (C) 2007 Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//  
#include <kdl/kdltk/transproperties.hpp>

namespace RTT
{
    using namespace KDL;
    using namespace std;

    bool decomposeTrans(const Transmission* trans, PropertyBag& targetbag)
    {
        if(trans->getTypeName()=="UnitTransmission")
            targetbag.add( new Property<UnitTransmission>("transmission","transmission of the serialchain",*((UnitTransmission*)(trans))));
        else if (trans->getTypeName()=="LinearTransmission")
            targetbag.add( new Property<LinearTransmission>("transmission","transmission of the serialchain",*((LinearTransmission*)(trans))));
        else if (trans->getTypeName()=="Kuka361Transmission")
            targetbag.add( new Property<Kuka361Transmission>("transmission","transmission of the serialchain",*((Kuka361Transmission*)(trans))));
        else
            return false;
        return true;
    }
            
    Transmission* composeTrans(const Property<PropertyBag>& trans_bag)
    {
        {
            Property<UnitTransmission> trans(trans_bag.getName(), trans_bag.getDescription());
            if(trans.getTypeInfo()->composeType(trans_bag.getDataSource(),trans.getDataSource() )){
                return trans.value().clone();
            }
        }
        {
            Property<LinearTransmission> trans(trans_bag.getName(), trans_bag.getDescription());
            if(trans.getTypeInfo()->composeType(trans_bag.getDataSource(),trans.getDataSource() )){
                return trans.value().clone();
            }
        }
        {
            Property<Kuka361Transmission> trans(trans_bag.getName(), trans_bag.getDescription());
            if(trans.getTypeInfo()->composeType(trans_bag.getDataSource(),trans.getDataSource() )){
                return trans.value().clone();
            }
        }
        return NULL;
    }
    

    void decomposeProperty(const UnitTransmission &trans, PropertyBag& targetbag)
    {
        targetbag.setType("UnitTransmission");
        targetbag.add( new Property<int>("nrofjoints", "nr of joints", trans.nrofjoints));
    }
    bool composeProperty(const PropertyBag& bag, UnitTransmission &trans)
    {
        if ( bag.getType() == std::string("UnitTransmission") ){ // check the type
            Property<int> nrofjoints = bag.getProperty<int>("nrofjoints");
            if ( !nrofjoints.ready() )
                return false;
            trans.nrofjoints=nrofjoints.value();
            return true;
        }
        return false;
        // unknown type !
    }
    
    
    void decomposeProperty(const LinearTransmission &trans, PropertyBag& targetbag)
    {
        targetbag.setType("LinearTransmission");
        targetbag.add( new Property<int>("nrofjoints", "nr of joints", trans.nrofjoints));
        targetbag.add( new Property<vector<double> >("scale", "scale of the joints", trans.scale));
        targetbag.add( new Property<vector<double> >("offset", "offset value of the joints", trans.offset));
    }
    bool composeProperty(const PropertyBag& bag, LinearTransmission &trans)
    {
        if ( bag.getType() == std::string("LinearTransmission") ){ // check the type
            Property<int> nrofjoints = bag.getProperty<int>("nrofjoints");
            if ( !nrofjoints.ready() )
                return false;
            Property<PropertyBag> scale_bag = bag.getProperty<PropertyBag>("scale");
            if(!scale_bag.ready())
                return false;
            Property<vector<double> > scale = Property<vector<double> >(scale_bag.getName(),scale_bag.getDescription());
            scale.getTypeInfo()->composeType(scale_bag.getDataSource(),
                                             scale.getDataSource() );
            Property<PropertyBag> offset_bag = bag.getProperty<PropertyBag>("offset");
            if(!offset_bag.ready())
                return false;
            Property<vector<double> > offset = Property<vector<double> >(offset_bag.getName(),offset_bag.getDescription());
            offset.getTypeInfo()->composeType(offset_bag.getDataSource(),
                                              offset.getDataSource() );
            trans.nrofjoints= nrofjoints.value();
            trans.scale=scale.value();
            trans.offset=offset.value();
            return true;
        }
        return false;
        // unknown type !
    }
    
    void decomposeProperty(const Kuka361Transmission &trans, PropertyBag& targetbag)
    {
        targetbag.setType("Kuka361Transmission");
    }
    bool composeProperty(const PropertyBag& bag, Kuka361Transmission &trans)
    {
        if ( bag.getType() == std::string("Kuka361Transmission") ){ // check the type
            return true;
        }
        return false;
        // unknown type !
    }
}



