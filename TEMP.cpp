if(nj != chain.getNrOfJoints() || ns != chain.getNrOfSegments())
    return (error = E_NOT_UP_TO_DATE);

//Check sizes when in debug mode
if(q.rows()!=nj || q_dot.rows()!=nj || q_dotdot.rows()!=nj || torques.rows()!=nj || f_ext.size()!=ns)
    return (error = E_SIZE_MISMATCH);
unsigned int j=0;

//Sweep from root to leaf
for(unsigned int i=0;i<ns;i++){
    double q_,qdot_,qdotdot_;
    if(chain.getSegment(i).getJoint().getType()!=Joint::None){
        q_=q(j);
        qdot_=q_dot(j);
        qdotdot_=q_dotdot(j);
        j++;
    }else
        q_=qdot_=qdotdot_=0.0;

    //Calculate segment properties: X,S,vj,cj
    X[i]=chain.getSegment(i).pose(q_);//Remark this is the inverse of the
                                        //frame for transformations from
                                        //the parent to the current coord frame
    //Transform velocity and unit velocity to segment frame
    Twist vj=X[i].M.Inverse(chain.getSegment(i).twist(q_,qdot_));
    S[i]=X[i].M.Inverse(chain.getSegment(i).twist(q_,1.0));
    //We can take cj=0, see remark section 3.5, page 55 since the unit velocity vector S of our joints is always time constant
    //calculate velocity and acceleration of the segment (in segment coordinates)
    if(i==0){
        v[i]=vj;
        a[i]=X[i].Inverse(ag)+S[i]*qdotdot_+v[i]*vj;
    }else{
        v[i]=X[i].Inverse(v[i-1])+vj;
        a[i]=X[i].Inverse(a[i-1])+S[i]*qdotdot_+v[i]*vj;
    }
    //Calculate the force for the joint
    //Collect RigidBodyInertia and external forces
    RigidBodyInertia Ii=chain.getSegment(i).getInertia();
    f[i]=Ii*a[i]+v[i]*(Ii*v[i])-f_ext[i];
//std::cout << "a[i]=" << a[i] << "\n f[i]=" << f[i] << "\n S[i]" << S[i] << std::endl;
}
//Sweep from leaf to root
j=nj-1;
for(int i=ns-1;i>=0;i--){
    if(chain.getSegment(i).getJoint().getType()!=Joint::None){
        torques(j)=dot(S[i],f[i]);
        torques(j)+=chain.getSegment(i).getJoint().getInertia()*q_dotdot(j);  // add torque from joint inertia
        --j;
    }
    if(i!=0)
        f[i-1]=f[i-1]+X[i]*f[i];
}
return (error = E_NOERROR);
