import unittest
from PyKDL import *
from math import *

class FrameVelTestFunctions(unittest.TestCase):

    def testVectorVel(self):
        v=VectorVel(Vector(3,-4,5),Vector(6,3,-5))
        vt = Vector(-4,-6,-8);
        self.assertTrue(Equal( 2*v-v,v))
        self.assertTrue(Equal( v*2-v,v))
        self.assertTrue(Equal( v+v+v-2*v,v))
        v2=VectorVel(v)
        self.assertTrue(Equal( v,v2))
        v2+=v
        self.assertTrue(Equal( 2*v,v2))
        v2-=v
        self.assertTrue(Equal( v,v2))
        v2.ReverseSign()
        self.assertTrue(Equal( v,-v2))
        self.assertTrue(Equal( v*vt,-vt*v))
        v2 = VectorVel(Vector(-5,-6,-3),Vector(3,4,5))
        self.assertTrue(Equal( v*v2,-v2*v))

       
    def testRotationVel(self):
        v=VectorVel(Vector(9,4,-2),Vector(-5,6,-2))
        vt=Vector(2,3,4)
        a= radians(-15)
        b= radians(20)
        c= radians(-80)
        R = RotationVel(Rotation.RPY(a,b,c),Vector(2,4,1))
        R2=RotationVel(R)
        self.assertTrue(Equal(R,R2))
        self.assertTrue(Equal((R*v).Norm(),(v.Norm())))
        self.assertTrue(Equal(R.Inverse(R*v),v))
        self.assertTrue(Equal(R*R.Inverse(v),v))
        self.assertTrue(Equal(R*Rotation.Identity(),R))
        self.assertTrue(Equal(Rotation.Identity()*R,R))
        self.assertTrue(Equal(R*(R*(R*v)),(R*R*R)*v))
        self.assertTrue(Equal(R*(R*(R*vt)),(R*R*R)*vt))
        self.assertTrue(Equal(R*R.Inverse(),RotationVel.Identity()))
        self.assertTrue(Equal(R.Inverse()*R,RotationVel.Identity()))
        self.assertTrue(Equal(R.Inverse()*v,R.Inverse(v)))
        #v2=v*v-2*v
        #print dot(v2,v2)
        #self.assertTrue(Equal((v2).Norm(),sqrt(dot(v2,v2))))

    def testFrameVel(self):
        v=VectorVel(Vector(3,4,5),Vector(-2,-4,-1))
        vt=Vector(-1,0,-10)
        F = FrameVel(Frame(Rotation.EulerZYX(radians(10),radians(20),radians(-10)),Vector(4,-2,1)),
                     Twist(Vector(2,-2,-2),Vector(-5,-3,-2)))
        F2=FrameVel(F)
        self.assertTrue(Equal( F,F2))
        self.assertTrue(Equal( F.Inverse(F*v),v))
        self.assertTrue(Equal( F.Inverse(F*vt), vt))
        self.assertTrue(Equal( F*F.Inverse(v),v))
        self.assertTrue(Equal( F*F.Inverse(vt),vt))
        self.assertTrue(Equal( F*Frame.Identity(),F))
        self.assertTrue(Equal( Frame.Identity()*F,F))
        self.assertTrue(Equal( F*(F*(F*v)),(F*F*F)*v))
        self.assertTrue(Equal( F*(F*(F*vt)),(F*F*F)*vt))
        self.assertTrue(Equal( F*F.Inverse(),FrameVel.Identity()))
        self.assertTrue(Equal( F.Inverse()*F,Frame.Identity()))
        self.assertTrue(Equal( F.Inverse()*vt,F.Inverse(vt)))


    def testPickle(self):
        rot = Rotation.RotX(1.3)
        import pickle
        data = {}
        data['vv'] = VectorVel(Vector(1,2,3), Vector(4,5,6))
        data['rv'] = RotationVel(rot, Vector(4.1,5.1,6.1))
        data['fv'] = FrameVel(data['rv'], data['vv'])
        data['tv'] = TwistVel(data['vv'], data['vv'])
        
        f = open('/tmp/pickle_test_kdl_framevel', 'w')
        pickle.dump(data, f)
        f.close()
        
        f = open('/tmp/pickle_test_kdl_framevel', 'r')
        data1 = pickle.load(f)
        f.close()
       
        self.assertEqual(data['vv'].p, data1['vv'].p)
        self.assertEqual(data['vv'].v, data1['vv'].v)
        self.assertEqual(data['rv'].R, data1['rv'].R)
        self.assertEqual(data['rv'].w, data1['rv'].w)
        self.assertEqual(data['fv'].M.R, data1['fv'].M.R)
        self.assertEqual(data['fv'].M.w, data1['fv'].M.w)
        self.assertEqual(data['fv'].p.p, data1['fv'].p.p)
        self.assertEqual(data['fv'].p.v, data1['fv'].p.v)
        self.assertEqual(data['tv'].vel.p, data1['tv'].vel.p)
        self.assertEqual(data['tv'].vel.v, data1['tv'].vel.v)
        self.assertEqual(data['tv'].rot.p, data1['tv'].rot.p)
        self.assertEqual(data['tv'].rot.v, data1['tv'].rot.v)

#void TestTwistVel() {
#    KDL_CTX;
#	// Twist
#	TwistVel t(VectorVel(
#				Vector(6,3,5),
#				Vector(1,4,2)
#			 ),VectorVel(
#			 		Vector(4,-2,7),
#			 		Vector(-1,-2,-3)
#			 )
#		);
#	TwistVel t2;
#	RotationVel  R(Rotation::RPY(10*deg2rad,20*deg2rad,-15*deg2rad),Vector(-1,5,3));
#	FrameVel F = FrameVel(
#		Frame(
#			Rotation::EulerZYX(-17*deg2rad,13*deg2rad,-16*deg2rad),
#			Vector(4,-2,1)
#		),
#		Twist(
#			Vector(2,-2,-2),
#			Vector(-5,-3,-2)
#		)
#	);
#
#	KDL_DIFF(2.0*t-t,t);
#	KDL_DIFF(t*2.0-t,t);
#	KDL_DIFF(t+t+t-2.0*t,t);
#	t2=t;
#	KDL_DIFF(t,t2);
#	t2+=t;
#	KDL_DIFF(2.0*t,t2);
#	t2-=t;
#	KDL_DIFF(t,t2);
#	t.ReverseSign();
#	KDL_DIFF(t,-t2);
#	KDL_DIFF(R.Inverse(R*t),t);
#	KDL_DIFF(R*t,R*R.Inverse(R*t));
#	KDL_DIFF(F.Inverse(F*t),t);
#	KDL_DIFF(F*t,F*F.Inverse(F*t));
#	KDL_DIFF(doubleVel(3.14,2)*t,t*doubleVel(3.14,2));
#	KDL_DIFF(t/doubleVel(3.14,2),t*(1.0/doubleVel(3.14,2)));
#	KDL_DIFF(t/3.14,t*(1.0/3.14));
#	KDL_DIFF(-t,-1.0*t);
#	VectorVel p1(Vector(5,1,2),Vector(4,2,1)) ;
#	VectorVel p2(Vector(2,0,5),Vector(-2,7,-1)) ;
#	KDL_DIFF(t.RefPoint(p1+p2),t.RefPoint(p1).RefPoint(p2));
#	KDL_DIFF(t,t.RefPoint(-p1).RefPoint(p1));
#}
#
#void TestTwistAcc() {
#    KDL_CTX;
#	// Twist
#	TwistAcc     t( VectorAcc(Vector(6,3,5),Vector(1,4,2),Vector(5,2,1)),
#		              VectorAcc(Vector(4,-2,7),Vector(-1,-2,-3),Vector(5,2,9) )
#					);
#	TwistAcc    t2; 
#	RotationAcc  R(Rotation::RPY(10*deg2rad,20*deg2rad,-15*deg2rad),
#		             Vector(-1,5,3),
#					 Vector(2,1,3)
#					 ) ;
#	FrameAcc F = FrameAcc(
#			Frame(Rotation::EulerZYX(-17*deg2rad,13*deg2rad,-16*deg2rad),Vector(4,-2,1)),
#			Twist(Vector(2,-2,-2),Vector(-5,-3,-2)),
#			Twist(Vector(5,4,-5),Vector(12,13,17))
#		    );	
#
#	KDL_DIFF(2.0*t-t,t);
#	KDL_DIFF(t*2.0-t,t);
#	KDL_DIFF(t+t+t-2.0*t,t);
#	t2=t; 
#	KDL_DIFF(t,t2);
#	t2+=t;
#	KDL_DIFF(2.0*t,t2);
#	t2-=t;
#	KDL_DIFF(t,t2);
#	t.ReverseSign();
#	KDL_DIFF(t,-t2);
#	KDL_DIFF(R.Inverse(R*t),t);
#	KDL_DIFF(R*t,R*R.Inverse(R*t));
#	KDL_DIFF(F.Inverse(F*t),t);
#	KDL_DIFF(F*t,F*F.Inverse(F*t));
#	KDL_DIFF(doubleAcc(3.14,2,3)*t,t*doubleAcc(3.14,2,3));
#	KDL_DIFF(t/doubleAcc(3.14,2,7),t*(1.0/doubleAcc(3.14,2,7)));
#	KDL_DIFF(t/3.14,t*(1.0/3.14));
#	KDL_DIFF(-t,-1.0*t);
#	VectorAcc p1(Vector(5,1,2),Vector(4,2,1),Vector(2,1,3));
#	VectorAcc p2(Vector(2,0,5),Vector(-2,7,-1),Vector(-3,2,-1));
#	KDL_DIFF(t.RefPoint(p1+p2),t.RefPoint(p1).RefPoint(p2));
#	KDL_DIFF(t,t.RefPoint(-p1).RefPoint(p1));
#}
#

def suite():
    suite=unittest.TestSuite()
    suite.addTest(FrameVelTestFunctions('testVectorVel'))
    suite.addTest(FrameVelTestFunctions('testRotationVel'))
    suite.addTest(FrameVelTestFunctions('testFrameVel'))
    suite.addTest(FrameVelTestFunctions('testPickle'))
    return suite

#suite = suite()
#unittest.TextTestRunner(verbosity=5).run(suite)



