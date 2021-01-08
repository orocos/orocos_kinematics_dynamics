<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>articulatedbodyinertia.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>articulatedbodyinertia_8cpp</filename>
    <includes id="articulatedbodyinertia_8hpp" name="articulatedbodyinertia.hpp" local="yes" imported="no">articulatedbodyinertia.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa7100a66f621fadcd96168a97d27784d</anchor>
      <arglist>(double a, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3bc91024ee0a8b23fa94b74fa7c952f0</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af14129ba902ec31f692ae97e29c033ef</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a148a5015338fa55d58b91dc7b9bb9983</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2dfa94ee82b9d4f12d9c4ee2b79a43b6</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a57e5b07873e812f8d7f94d5ca1acd229</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab60953771d5ef2a0ef08cf7e8266473f</anchor>
      <arglist>(const Frame &amp;T, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a786c8142a2aad06781373faeccbfd353</anchor>
      <arglist>(const Rotation &amp;R, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>articulatedbodyinertia.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>articulatedbodyinertia_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="rotationalinertia_8hpp" name="rotationalinertia.hpp" local="yes" imported="no">rotationalinertia.hpp</includes>
    <includes id="rigidbodyinertia_8hpp" name="rigidbodyinertia.hpp" local="yes" imported="no">rigidbodyinertia.hpp</includes>
    <class kind="class">KDL::ArticulatedBodyInertia</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa7100a66f621fadcd96168a97d27784d</anchor>
      <arglist>(double a, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3bc91024ee0a8b23fa94b74fa7c952f0</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a698a887bd036f999ead109cb2f29c5e5</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a148a5015338fa55d58b91dc7b9bb9983</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8b9e70a1774fb129e540065eb6b263e3</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a57e5b07873e812f8d7f94d5ca1acd229</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab60953771d5ef2a0ef08cf7e8266473f</anchor>
      <arglist>(const Frame &amp;T, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a786c8142a2aad06781373faeccbfd353</anchor>
      <arglist>(const Rotation &amp;R, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>chain.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chain_8cpp</filename>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chain.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chain_8hpp</filename>
    <includes id="segment_8hpp" name="segment.hpp" local="yes" imported="no">segment.hpp</includes>
    <class kind="class">KDL::Chain</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chaindynparam.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chaindynparam_8cpp</filename>
    <includes id="chaindynparam_8hpp" name="chaindynparam.hpp" local="yes" imported="no">chaindynparam.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chaindynparam.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chaindynparam_8hpp</filename>
    <includes id="chainidsolver__recursive__newton__euler_8hpp" name="chainidsolver_recursive_newton_euler.hpp" local="yes" imported="no">chainidsolver_recursive_newton_euler.hpp</includes>
    <includes id="articulatedbodyinertia_8hpp" name="articulatedbodyinertia.hpp" local="yes" imported="no">articulatedbodyinertia.hpp</includes>
    <includes id="jntspaceinertiamatrix_8hpp" name="jntspaceinertiamatrix.hpp" local="yes" imported="no">jntspaceinertiamatrix.hpp</includes>
    <class kind="class">KDL::ChainDynParam</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfdsolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfdsolver_8hpp</filename>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <class kind="class">KDL::ChainFdSolver</class>
    <namespace>KDL</namespace>
    <member kind="typedef">
      <type>std::vector&lt; Wrench &gt;</type>
      <name>Wrenches</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afeffe2d8d9e5e5cfbad0fc90b720c264</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>chainfdsolver_recursive_newton_euler.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfdsolver__recursive__newton__euler_8cpp</filename>
    <includes id="chainfdsolver__recursive__newton__euler_8hpp" name="chainfdsolver_recursive_newton_euler.hpp" local="yes" imported="no">chainfdsolver_recursive_newton_euler.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="kinfam__io_8hpp" name="kinfam_io.hpp" local="yes" imported="no">kinfam_io.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfdsolver_recursive_newton_euler.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfdsolver__recursive__newton__euler_8hpp</filename>
    <includes id="chainfdsolver_8hpp" name="chainfdsolver.hpp" local="yes" imported="no">chainfdsolver.hpp</includes>
    <includes id="chainidsolver__recursive__newton__euler_8hpp" name="chainidsolver_recursive_newton_euler.hpp" local="yes" imported="no">chainidsolver_recursive_newton_euler.hpp</includes>
    <includes id="chaindynparam_8hpp" name="chaindynparam.hpp" local="yes" imported="no">chaindynparam.hpp</includes>
    <class kind="class">KDL::ChainFdSolver_RNE</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfksolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfksolver_8hpp</filename>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <includes id="framevel_8hpp" name="framevel.hpp" local="yes" imported="no">framevel.hpp</includes>
    <includes id="frameacc_8hpp" name="frameacc.hpp" local="yes" imported="no">frameacc.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="jntarrayvel_8hpp" name="jntarrayvel.hpp" local="yes" imported="no">jntarrayvel.hpp</includes>
    <includes id="jntarrayacc_8hpp" name="jntarrayacc.hpp" local="yes" imported="no">jntarrayacc.hpp</includes>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <class kind="class">KDL::ChainFkSolverPos</class>
    <class kind="class">KDL::ChainFkSolverVel</class>
    <class kind="class">KDL::ChainFkSolverAcc</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfksolverpos_recursive.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfksolverpos__recursive_8cpp</filename>
    <includes id="chainfksolverpos__recursive_8hpp" name="chainfksolverpos_recursive.hpp" local="yes" imported="no">chainfksolverpos_recursive.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfksolverpos_recursive.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfksolverpos__recursive_8hpp</filename>
    <includes id="chainfksolver_8hpp" name="chainfksolver.hpp" local="yes" imported="no">chainfksolver.hpp</includes>
    <class kind="class">KDL::ChainFkSolverPos_recursive</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfksolvervel_recursive.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfksolvervel__recursive_8cpp</filename>
    <includes id="chainfksolvervel__recursive_8hpp" name="chainfksolvervel_recursive.hpp" local="yes" imported="no">chainfksolvervel_recursive.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainfksolvervel_recursive.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainfksolvervel__recursive_8hpp</filename>
    <includes id="chainfksolver_8hpp" name="chainfksolver.hpp" local="yes" imported="no">chainfksolver.hpp</includes>
    <class kind="class">KDL::ChainFkSolverVel_recursive</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainhdsolver_vereshchagin.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainhdsolver__vereshchagin_8cpp</filename>
    <includes id="chainhdsolver__vereshchagin_8hpp" name="chainhdsolver_vereshchagin.hpp" local="yes" imported="no">chainhdsolver_vereshchagin.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainhdsolver_vereshchagin.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainhdsolver__vereshchagin_8hpp</filename>
    <includes id="chainidsolver_8hpp" name="chainidsolver.hpp" local="yes" imported="no">chainidsolver.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="articulatedbodyinertia_8hpp" name="articulatedbodyinertia.hpp" local="yes" imported="no">articulatedbodyinertia.hpp</includes>
    <class kind="class">KDL::ChainHdSolver_Vereshchagin</class>
    <class kind="struct">KDL::ChainHdSolver_Vereshchagin::segment_info</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainidsolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainidsolver_8hpp</filename>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <class kind="class">KDL::ChainIdSolver</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainidsolver_recursive_newton_euler.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainidsolver__recursive__newton__euler_8cpp</filename>
    <includes id="chainidsolver__recursive__newton__euler_8hpp" name="chainidsolver_recursive_newton_euler.hpp" local="yes" imported="no">chainidsolver_recursive_newton_euler.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainidsolver_recursive_newton_euler.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainidsolver__recursive__newton__euler_8hpp</filename>
    <includes id="chainidsolver_8hpp" name="chainidsolver.hpp" local="yes" imported="no">chainidsolver.hpp</includes>
    <class kind="class">KDL::ChainIdSolver_RNE</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainidsolver_vereshchagin.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainidsolver__vereshchagin_8cpp</filename>
    <includes id="chainidsolver__vereshchagin_8hpp" name="chainidsolver_vereshchagin.hpp" local="yes" imported="no">chainidsolver_vereshchagin.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainidsolver_vereshchagin.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainidsolver__vereshchagin_8hpp</filename>
    <includes id="chainhdsolver__vereshchagin_8hpp" name="chainhdsolver_vereshchagin.hpp" local="yes" imported="no">chainhdsolver_vereshchagin.hpp</includes>
    <class kind="class">KDL::ChainIdSolver_Vereshchagin</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolver_8hpp</filename>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="framevel_8hpp" name="framevel.hpp" local="yes" imported="no">framevel.hpp</includes>
    <includes id="frameacc_8hpp" name="frameacc.hpp" local="yes" imported="no">frameacc.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="jntarrayvel_8hpp" name="jntarrayvel.hpp" local="yes" imported="no">jntarrayvel.hpp</includes>
    <includes id="jntarrayacc_8hpp" name="jntarrayacc.hpp" local="yes" imported="no">jntarrayacc.hpp</includes>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <class kind="class">KDL::ChainIkSolverPos</class>
    <class kind="class">KDL::ChainIkSolverVel</class>
    <class kind="class">KDL::ChainIkSolverAcc</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolverpos_lma.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolverpos__lma_8cpp</filename>
    <includes id="chainiksolverpos__lma_8hpp" name="chainiksolverpos_lma.hpp" local="yes" imported="no">chainiksolverpos_lma.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>void</type>
      <name>Twist_to_Eigen</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad99081b5fff0a9d43dfc07a3f64ee714</anchor>
      <arglist>(const KDL::Twist &amp;t, Eigen::MatrixBase&lt; Derived &gt; &amp;e)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>chainiksolverpos_lma.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolverpos__lma_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <class kind="class">KDL::ChainIkSolverPos_LMA</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolverpos_nr.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolverpos__nr_8cpp</filename>
    <includes id="chainiksolverpos__nr_8hpp" name="chainiksolverpos_nr.hpp" local="yes" imported="no">chainiksolverpos_nr.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolverpos_nr.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolverpos__nr_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chainfksolver_8hpp" name="chainfksolver.hpp" local="yes" imported="no">chainfksolver.hpp</includes>
    <class kind="class">KDL::ChainIkSolverPos_NR</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolverpos_nr_jl.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolverpos__nr__jl_8cpp</filename>
    <includes id="chainiksolverpos__nr__jl_8hpp" name="chainiksolverpos_nr_jl.hpp" local="yes" imported="no">chainiksolverpos_nr_jl.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolverpos_nr_jl.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolverpos__nr__jl_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chainfksolver_8hpp" name="chainfksolver.hpp" local="yes" imported="no">chainfksolver.hpp</includes>
    <class kind="class">KDL::ChainIkSolverPos_NR_JL</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_pinv.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__pinv_8cpp</filename>
    <includes id="chainiksolvervel__pinv_8hpp" name="chainiksolvervel_pinv.hpp" local="yes" imported="no">chainiksolvervel_pinv.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_pinv.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__pinv_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chainjnttojacsolver_8hpp" name="chainjnttojacsolver.hpp" local="yes" imported="no">chainjnttojacsolver.hpp</includes>
    <class kind="class">KDL::ChainIkSolverVel_pinv</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_pinv_givens.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__pinv__givens_8cpp</filename>
    <includes id="chainiksolvervel__pinv__givens_8hpp" name="chainiksolvervel_pinv_givens.hpp" local="yes" imported="no">chainiksolvervel_pinv_givens.hpp</includes>
    <includes id="svd__eigen__Macie_8hpp" name="svd_eigen_Macie.hpp" local="yes" imported="no">utilities/svd_eigen_Macie.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_pinv_givens.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__pinv__givens_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chainjnttojacsolver_8hpp" name="chainjnttojacsolver.hpp" local="yes" imported="no">chainjnttojacsolver.hpp</includes>
    <class kind="class">KDL::ChainIkSolverVel_pinv_givens</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_pinv_nso.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__pinv__nso_8cpp</filename>
    <includes id="chainiksolvervel__pinv__nso_8hpp" name="chainiksolvervel_pinv_nso.hpp" local="yes" imported="no">chainiksolvervel_pinv_nso.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_pinv_nso.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__pinv__nso_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chainjnttojacsolver_8hpp" name="chainjnttojacsolver.hpp" local="yes" imported="no">chainjnttojacsolver.hpp</includes>
    <class kind="class">KDL::ChainIkSolverVel_pinv_nso</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_wdls.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__wdls_8cpp</filename>
    <includes id="chainiksolvervel__wdls_8hpp" name="chainiksolvervel_wdls.hpp" local="yes" imported="no">chainiksolvervel_wdls.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainiksolvervel_wdls.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainiksolvervel__wdls_8hpp</filename>
    <includes id="chainiksolver_8hpp" name="chainiksolver.hpp" local="yes" imported="no">chainiksolver.hpp</includes>
    <includes id="chainjnttojacsolver_8hpp" name="chainjnttojacsolver.hpp" local="yes" imported="no">chainjnttojacsolver.hpp</includes>
    <class kind="class">KDL::ChainIkSolverVel_wdls</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainjnttojacdotsolver.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainjnttojacdotsolver_8cpp</filename>
    <includes id="chainjnttojacdotsolver_8hpp" name="chainjnttojacdotsolver.hpp" local="yes" imported="no">chainjnttojacdotsolver.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainjnttojacdotsolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainjnttojacdotsolver_8hpp</filename>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jntarrayvel_8hpp" name="jntarrayvel.hpp" local="yes" imported="no">jntarrayvel.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <includes id="framevel_8hpp" name="framevel.hpp" local="yes" imported="no">framevel.hpp</includes>
    <includes id="chainjnttojacsolver_8hpp" name="chainjnttojacsolver.hpp" local="yes" imported="no">chainjnttojacsolver.hpp</includes>
    <includes id="chainfksolverpos__recursive_8hpp" name="chainfksolverpos_recursive.hpp" local="yes" imported="no">chainfksolverpos_recursive.hpp</includes>
    <class kind="class">KDL::ChainJntToJacDotSolver</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainjnttojacsolver.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainjnttojacsolver_8cpp</filename>
    <includes id="chainjnttojacsolver_8hpp" name="chainjnttojacsolver.hpp" local="yes" imported="no">chainjnttojacsolver.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>chainjnttojacsolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>chainjnttojacsolver_8hpp</filename>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <class kind="class">KDL::ChainJntToJacSolver</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>frameacc.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frameacc_8cpp</filename>
    <includes id="frameacc_8hpp" name="frameacc.hpp" local="yes" imported="no">frameacc.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>frameacc.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frameacc_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frameacc_8inl" name="frameacc.inl" local="yes" imported="no">frameacc.inl</includes>
    <class kind="class">KDL::VectorAcc</class>
    <class kind="class">KDL::RotationAcc</class>
    <class kind="class">KDL::FrameAcc</class>
    <class kind="class">KDL::TwistAcc</class>
    <namespace>KDL</namespace>
    <member kind="typedef">
      <type>Rall2d&lt; double, double, double &gt;</type>
      <name>doubleAcc</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a931155039a40a3f75d0150bed1055206</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aceb6e09c6452163b3558a3a3cc07218e</anchor>
      <arglist>(const FrameAcc &amp;r1, const FrameAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>adfd020186f84b57bbc3b68ffce524f62</anchor>
      <arglist>(const Frame &amp;r1, const FrameAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a720066d9cded8fbede747b8709346807</anchor>
      <arglist>(const FrameAcc &amp;r1, const Frame &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8a8d76717c6b496e08e425c012f8b89b</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a02b22cc9116b2baca5a86eaee825076e</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8011b8ae760bbe1aa062b699ad93038c</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab62149a668287784cd5695f01c17367d</anchor>
      <arglist>(const TwistAcc &amp;a, const TwistAcc &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab3fb673008c926b747f12842819fb337</anchor>
      <arglist>(const Twist &amp;a, const TwistAcc &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a20ab86ec30519ed0fad9a1d705c829f1</anchor>
      <arglist>(const TwistAcc &amp;a, const Twist &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a900aeddeccd431c5cbf0bdd3156d6f35</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afd3e97a38cc7c47e7b6d07e7e0f466a7</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a597c39d91a1081b5442712f1249d6054</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acab79938e3027d6510cfa4a90720c95f</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a782af317e6d1e7cb312b30ab60c70bd6</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a37489ad00a48b8b652eadc65bebd5ad3</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9554f1e935042c64beac3e7f945f9101</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab56265b003752215f2d94c00493e4c21</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a096678f980702ca962d48014abd10945</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa782630b3a6cc0ba2c84b4e030dcddb7</anchor>
      <arglist>(const VectorAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9e9d745c14edea95c2ebb5cea42de36f</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2fb01a0504479ca09c7bf27e343b8be5</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a32c266cd0cffd38a75c48221ccc25399</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a524c105fb1973d09ecd5cdede4374810</anchor>
      <arglist>(double r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aadc7e8ee3d8788b987dc0f0a4c5f67e3</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9cb7bd269eab198b5145a802b20456d7</anchor>
      <arglist>(const doubleAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a51ac1ce1dbd62896096448a98e209b96</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3fd338e2da27c7bd6ca0e37b0f0df6bc</anchor>
      <arglist>(const VectorAcc &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a107183962fe5c2cb927be493403bb397</anchor>
      <arglist>(const VectorAcc &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a13b5aff556e90ec3023cbb2aa8cab6e3</anchor>
      <arglist>(const Vector &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7dd9ddf5cf0ebc37acb08f33c594f89d</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3a23c4ad11a2c81588b94fbf6e39eb7f</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc6f0d30c6f9d3e92c554585907be39b</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a30128ae85ca846c146f1df52ffd18aa8</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58fadb516d19574d7ac0cb40d1022f3e</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aef301ceb31d21ec006c03b3359673b75</anchor>
      <arglist>(const Rotation &amp;R, const VectorAcc &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8450a02abf20b80c80e444d29ab5304d</anchor>
      <arglist>(const FrameAcc &amp;lhs, const FrameAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad315c19f6564614fd6fe4350fa04885b</anchor>
      <arglist>(const FrameAcc &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aec4b7d8ac5c54d65fa070bd6a189fe26</anchor>
      <arglist>(const Frame &amp;lhs, const FrameAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aaab7b9e81b8789337bdbb13d9fd2e4cd</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af8d405e2914bea19aecfc2aac9143375</anchor>
      <arglist>(double lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15ebfbcd250b2584e798f4955fc6fcba</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8b4f64aa851af027829c24d1d9deefd3</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4164febadd9c9bf7a119cf4223350675</anchor>
      <arglist>(const doubleAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a321a12c7bdb069e7f0a317ef9d778370</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3ab49311febc69235cc75ad7fe81a91</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1edfde5b35133050a8a1d3a5a7a107af</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae5c4196610ec6b1a316b23f144a75090</anchor>
      <arglist>(const TwistAcc &amp;arg)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frameacc.inl</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frameacc_8inl</filename>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>ab79cbde654a8ff51142c16eaefb4b18f</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a6f3c8051d909ff25d801b5db9e3df6b9</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a79dd7b2e17069fd3a6eb0a759976a652</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a4fad23be7904fa133f8ff87b9ae6ec6f</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a8c13f2bce2a6d46226f14d8d5eee1b69</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>af9530d45ed89585eaa39658d10188f4a</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a9b32fe52b03600a2b383c762ba2ec1a6</anchor>
      <arglist>(const VectorAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a3118abc6365c6cf2968d5659ed48b29c</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a167f079cacdcf83c0a53d1c7e0282526</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>ae6e930cd42d2de3d75a8cc4a271e8452</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a1135a7132167cbfcb3a0ede98c616770</anchor>
      <arglist>(double r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aee98b09d28982d274378730d264e4353</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a89ee6739447b86b9abde1788465fe34c</anchor>
      <arglist>(const doubleAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a813759e8c8ab3f1c1b72aa1331a54449</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>ab4ccb72b38c9a0258ccf2f86127f356a</anchor>
      <arglist>(const VectorAcc &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aa77d59aafcfced5850762e08106117b8</anchor>
      <arglist>(const VectorAcc &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a9348d3feeb949ad48287a8db9704ce71</anchor>
      <arglist>(const Vector &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a1a428d79914c26e08be87e8e3ceed6b7</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a23d95358b72f698f771cfad3c4554ec7</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>ae1c4dae74d4466adfa28815de4d8e56f</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator/</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a718ee51f4f456115116dfb40a122c9b3</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator/</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aeeef31a0b07aa528d3002f1d15d84f64</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a666977357c0d1cdfbfdcfb5ecd9e0cde</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a72c3ff56497cdaac25b25ebcab81abff</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a599a368b8310f8ec5c2ee7da3673a7f0</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a7fcb4b8a36312e34fa9bf38fe9dbc30c</anchor>
      <arglist>(const Rotation &amp;R, const VectorAcc &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a69ce3e5feb3e5c145bb763d2dbb7b832</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a9a46edd44fc0dee017650d19bd86d053</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a9e05363495ab57754306c60eef7eec18</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a1adb514d0c1e0fdb4d36a999409e64de</anchor>
      <arglist>(const FrameAcc &amp;lhs, const FrameAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a4a355a5256f5d4e2c0e754f2d99d667a</anchor>
      <arglist>(const FrameAcc &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a9811932bbd23441b35b554cff1793bb2</anchor>
      <arglist>(const Frame &amp;lhs, const FrameAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a139da01e831b08080fe1c481daabaa4c</anchor>
      <arglist>(const FrameAcc &amp;r1, const FrameAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>afff611bd9ed2bc095a2caf213b5c5546</anchor>
      <arglist>(const Frame &amp;r1, const FrameAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aa7e494030fa6b0b0e97f6d1d75d42310</anchor>
      <arglist>(const FrameAcc &amp;r1, const Frame &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a04678da99cc0a64479f7d1e0c6981b4f</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aaa64ed0c7026bef45a72d7dbbba83b2d</anchor>
      <arglist>(double lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator/</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aab67ed8e756c0245b7578d8bf2191077</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a525285439d428b5c23241eb2d7c4713d</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a51b2a484710ae0dfa71fc9669e7f9298</anchor>
      <arglist>(const doubleAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator/</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>ac23e0a1ab270e215c34258145c837756</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator+</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a38331c438e34e1f55c93aa99d6651ad3</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator-</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>aada5bad57428ba3f3ea69ffb024df0d5</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator-</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>accc1660310d17859190d606e6dfe21fb</anchor>
      <arglist>(const TwistAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a87e82d76f07de09ef85710d52f4c6594</anchor>
      <arglist>(const TwistAcc &amp;a, const TwistAcc &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a2d313ff9c4ae7f4b879fb8118d41caa3</anchor>
      <arglist>(const Twist &amp;a, const TwistAcc &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>frameacc_8inl.html</anchorfile>
      <anchor>a251d4ba776ba0a0f3a6857839b1fc00a</anchor>
      <arglist>(const TwistAcc &amp;a, const Twist &amp;b, double eps)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frameacc_io.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frameacc__io_8hpp</filename>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="frameacc_8hpp" name="frameacc.hpp" local="yes" imported="no">frameacc.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a05fc643515b491c7a9938a8f6fd0500f</anchor>
      <arglist>(std::ostream &amp;os, const VectorAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af23846837b43f7eca43c2088148e28fd</anchor>
      <arglist>(std::ostream &amp;os, const RotationAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc1e3573bca3a74daedbe3ab41552e3c</anchor>
      <arglist>(std::ostream &amp;os, const FrameAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac020750892e14e0e4e075efd6bfd3100</anchor>
      <arglist>(std::ostream &amp;os, const TwistAcc &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frames.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frames_8cpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa75157c97981a05a94513ec9a8c40124</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>Rotation</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa9ad476d005ede2a464b048a9b048a96</anchor>
      <arglist>(const Rotation &amp;lhs, const Rotation &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1d076f4eec84df192b9bcfa5740f2ebf</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frames.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frames_8hpp</filename>
    <includes id="frames_8inl" name="frames.inl" local="yes" imported="no">frames.inl</includes>
    <class kind="class">KDL::Vector</class>
    <class kind="class">KDL::Rotation</class>
    <class kind="class">KDL::Frame</class>
    <class kind="class">KDL::Twist</class>
    <class kind="class">KDL::Wrench</class>
    <class kind="class">KDL::Vector2</class>
    <class kind="class">KDL::Rotation2</class>
    <class kind="class">KDL::Frame2</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a267f5edb3111f0f0ba0273099f3fee1e</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af0c5cb20967b3790cf5a534511f64f0a</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad74e1ec324b451246619ec0812c2f9c8</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a71af262c34419a6396d37a3939d2281f</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7e89bf5dfb058ed646d8cd8791c71cb2</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8f002bdc16e0843ec3660aee9bcb24bd</anchor>
      <arglist>(const Rotation2 &amp;a, const Rotation2 &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a96ca52698b11cbddf3176a4af11bd64b</anchor>
      <arglist>(const Frame2 &amp;a, const Frame2 &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1d076f4eec84df192b9bcfa5740f2ebf</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa75157c97981a05a94513ec9a8c40124</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a721ba3f54f506bc1004fb981a9ea7b13</anchor>
      <arglist>(const Vector &amp;p_w_a, const Vector &amp;p_w_b, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad23c4b0b7788db8ecc670b5561dbc427</anchor>
      <arglist>(const Rotation &amp;R_a_b1, const Rotation &amp;R_a_b2, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af738311fdea560d6255894ddc0425095</anchor>
      <arglist>(const Frame &amp;F_a_b1, const Frame &amp;F_a_b2, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a64a30fa7b4a6a532cbd43ad90c93bc5e</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Wrench</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0207da13db4661467e2e8c74cce973a5</anchor>
      <arglist>(const Wrench &amp;W_a_p1, const Wrench &amp;W_a_p2, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac90990ec8c80f1c7a411052f6b1f322b</anchor>
      <arglist>(const Vector &amp;p_w_a, const Vector &amp;p_w_da, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2a84a971a8a4300f6b4dd97f40479029</anchor>
      <arglist>(const Rotation &amp;R_w_a, const Vector &amp;da_w, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a57e682fab9c7fb9fe18145310d9984d5</anchor>
      <arglist>(const Frame &amp;F_w_a, const Twist &amp;da_w, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a32903427965bec95694731b3ad6e4cb0</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;da, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Wrench</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2e1b786a27b63352f5f2c098ef26392d</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;da, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aae21b94ac92952d16ee509a5a4b8c449</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1fce4b4a41dfa403b2a47f7950a602a1</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab5247191df17553320eb1639d901221b</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a357a1574d4d5fa898fc43df23fea8462</anchor>
      <arglist>(double lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aed451d41bd66dbd33a3feb5acb4b1ebe</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3709494d8a02d8757f4b668c452155a</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5c7d683679ab9019a65107e128cd6b88</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae46db8b8cf405b5faf1a89263296d7de</anchor>
      <arglist>(double lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8e4ca54ad9f9b0e5538e4bd3423a87a4</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8e7b9ed5c63404773079ae53ee00d200</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a28f9d98ac28883fba27e18723698d59b</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6188e96ab705622696fabc0bd2c120e7</anchor>
      <arglist>(const Wrench &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f3979c3069f3d6558fc902a86c380d5</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a74682143c6c66632244b5e67cccce8c0</anchor>
      <arglist>(double lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2c10359e471c3cf0dca718798f15d224</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3e1e5d70194d5577e7e5e7c534f9f877</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a78aa25a29bdaa99874ea3fcb128a3553</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a42838c1bd9e803b30a6bd645d150c65c</anchor>
      <arglist>(const Twist &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab85c524cf4f6bd5364363dad1ef08ae5</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aafe32822da77309b7f5c0260aa926886</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af3abf2430995a3cc3c688884e9efe156</anchor>
      <arglist>(const Frame &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6dfc6b5efe37c9bbae876578f2b3a361</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae19bb99f118f93827bbcfd227651028f</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8a95c0c12a9c7d846ac4c2832e03fa6a</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aae6a6cf702dd433fb1cd0cd462068380</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2152fae33fee05d9bf23e9aaf5dfbe91</anchor>
      <arglist>(double lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aefa0b99b58c211a4eff0539f180dcf87</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>adc332c398dc07420ccff5e6d7ee12209</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4ddd74aa0ffa153735c9603b51ea06f</anchor>
      <arglist>(const Rotation2 &amp;lhs, const Rotation2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a00f0baabdb899f295fb9611e0b724560</anchor>
      <arglist>(const Frame2 &amp;lhs, const Frame2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4db9af1413269c11e7d2545598b1007f</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa63cf4bc264d241cd79de32af80d7fdc</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a075c80a9c5b8b4db8221d84dbe16321a</anchor>
      <arglist>(const Wrench &amp;rhs, const Twist &amp;lhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac3750480c481eea276696d3bc4f863cc</anchor>
      <arglist>(Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad8485aa6cdef7323e5139e7197307670</anchor>
      <arglist>(Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aeb3832c7f7dbbb0276a3444dd6d64c4d</anchor>
      <arglist>(Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8299e9971a3f1996d8fd79cdf29fd8d9</anchor>
      <arglist>(Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation</type>
      <name>Rot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2587165b94880d6deaf7fdc5ed5ee06</anchor>
      <arglist>(const Vector &amp;axis_a_b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab659aefd7a8d246aa4940c712b53b151</anchor>
      <arglist>(Vector &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a19a568accb594b3670bddf2a40a33105</anchor>
      <arglist>(Twist &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7a2f7de4c733f4e82af4f8bdd2056fb7</anchor>
      <arglist>(Wrench &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a41009801573404ce30ee8e057fb04ef6</anchor>
      <arglist>(Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aff06e46b989fa6738dd60cf49f6a7ea1</anchor>
      <arglist>(Frame &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac785c7fa89414f9d3c85edca120acc83</anchor>
      <arglist>(Vector &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1532bb6e60e00d6c36b984a3035de126</anchor>
      <arglist>(Twist &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aff1c0c5664a50d4bc85883c636033df5</anchor>
      <arglist>(Wrench &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afb35d4c796c9c993745b83376734d080</anchor>
      <arglist>(Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4e2d06356667a8f3268130e60e13f422</anchor>
      <arglist>(Frame &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a29c2eddcc4d9cfe533e333ecfa1b54a0</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a312b7b900344e2ae17a20876f1df7574</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa24027be36c84617964a2cd6124659f9</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6ae91ebcc5ee2a021fbc153fbc24a01c</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a235efc5e431e6b5375c8360c68d27044</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aace5ddee5968bf1f3baf1b0e1c6ab050</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7ebcdc524db268f5df96f9bced38ad10</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a640b15a9d707c5a81915064d88f30030</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af5e1f5dbc48ea49b0872ac949f47003b</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a12c33f7bc59885551a7c3db86e2becbc</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a035cedf046e497717220dd23543c4571</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frames.inl</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frames_8inl</filename>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>operator+</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a97406eb9ba738a2c68b4374a86ee6cd0</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a3c5faab88483ef8376d30d451b2a423b</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>abe5f3e3747654906e6e2b506947675cd</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>af1b7f920324ab230c303c352421c799a</anchor>
      <arglist>(double lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator/</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a25d9bb5f010ee074e6ae3f1ade146927</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a7cf9d5b6086b4ece4eeeb6ca333906ea</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>accbdf521d6fc163bb229914dfa3e2c20</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ad9270132aa4084d7d61b007374a81883</anchor>
      <arglist>(double lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator/</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a4c875b04aa468b3494b427e3007bb9e6</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator+</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a17d4fccb33a2736468d0645862956cb5</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>aa81947bb6d31729915fc66d59fdf84e6</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>aaa88a5af82234547897ea220ef3cd173</anchor>
      <arglist>(const Wrench &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a04b73370fb4ad857f2b4cb720f3c9113</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ac7e5ad8e49d4f92b49b5d6b16e606158</anchor>
      <arglist>(double lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator/</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a939e42c12cc59ac6eb8f8152c4461ea1</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator+</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ad0f34bc2ed48c3caa688b8e405466985</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a6c7c88bf859de28239ded2fdbcd848bf</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>aa659300da279e4d00b44489a755d4be9</anchor>
      <arglist>(const Twist &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a969cd47ef10751021ada52c678503ce7</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a10f7a1660ecf13906fc0808f9d264d33</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>adb5d8e64590ce61d0ea8fb91a24f674c</anchor>
      <arglist>(const Frame &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a5eff5e8fcf678ef559ff40f236865596</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator+</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ade97f4b94b51acf2c903119245cc9460</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a57612f12d1b3243f58c380934cd8e8ba</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a009647d43a87c207cf3db14ae2c0d594</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a6d344b6cf3f746f3b955630bcb486ce8</anchor>
      <arglist>(double lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator/</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a2c44743ba880da24e916d63364996e7c</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator-</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a36673b1ba385b6b71fdb241be1a4a908</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation2</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a716aecb37fa17be1323ac9d471d740e4</anchor>
      <arglist>(const Rotation2 &amp;lhs, const Rotation2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame2</type>
      <name>operator*</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a505ef08a05a356a972184776b2de4279</anchor>
      <arglist>(const Frame2 &amp;lhs, const Frame2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a838952d8ea25fd9b6543ad08bb9b1479</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a6e701fe8737cc7427c205e27dc57796e</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>aebb8f00a811e38a6a69746bef24097f2</anchor>
      <arglist>(const Wrench &amp;rhs, const Twist &amp;lhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a51ec5cca8075b5fc8449f0ddd65cce11</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a1c67741199b736f7308a0e6f5633c4e6</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a694ad9cc77b7efc98c1578f6aef6cfbf</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a6a19f9532a0494bccc0cddb832e5894b</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ab17cb601b66b7044844f9073f05881f6</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a34b5b4d5624e408a0b3dd64b055e1f7d</anchor>
      <arglist>(const Rotation2 &amp;a, const Rotation2 &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ad088204124856b8a92cb7f58e674302e</anchor>
      <arglist>(const Frame2 &amp;a, const Frame2 &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a73e913de2016bccf9ec44e18dce273b1</anchor>
      <arglist>(Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a023498d76788ecf4ef547d9920ed730c</anchor>
      <arglist>(Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a5421ae642b787f650f47b751c2bb9ab2</anchor>
      <arglist>(Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a9ee4d4cbcc1cf3c7cdaff7199489cfa2</anchor>
      <arglist>(Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation</type>
      <name>Rot</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ae6d17b27737370d8ce326fdac8e1756a</anchor>
      <arglist>(const Vector &amp;axis_a_b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>diff</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a28b09ca6433ffe847b24cb2ac0f4ab6b</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>diff</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a1dfb0c9924a9ec26905dfb0dbc835cf4</anchor>
      <arglist>(const Rotation &amp;R_a_b1, const Rotation &amp;R_a_b2, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>diff</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a06a4a9d54c828d628f398e94a5020d36</anchor>
      <arglist>(const Frame &amp;F_a_b1, const Frame &amp;F_a_b2, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>diff</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ade209c48252e1842b3c7fb1ab83d8fca</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Wrench</type>
      <name>diff</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>aacc179b18d4f8937203b559c831d3e01</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>addDelta</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a781532f5147ffb631ae4a916de9153e3</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;da, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation</type>
      <name>addDelta</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>adc8f82f1370f89d7a03690acbc77b4c1</anchor>
      <arglist>(const Rotation &amp;a, const Vector &amp;da, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame</type>
      <name>addDelta</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ab9f866e7d04e843d4b6d3a4eee6d929a</anchor>
      <arglist>(const Frame &amp;a, const Twist &amp;da, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>addDelta</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a58566d06df4915e96ff21005095b704b</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;da, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Wrench</type>
      <name>addDelta</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a3c8ecf3827cea0e27f27a4c9f77c2813</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;da, double dt)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a9f76654728449cbb330e854b25f77ec3</anchor>
      <arglist>(Vector &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a8132445ff5f3895ee3c6c351f0dd81c1</anchor>
      <arglist>(Twist &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a1d4fb8b8dab175821ea1081156a7877a</anchor>
      <arglist>(Wrench &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a832718cf1ee64bccc3e8488bbeeba6a1</anchor>
      <arglist>(Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a5b17d79b3fa55cd41d50dd43ecff704b</anchor>
      <arglist>(Frame &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a9a2df7414a816c2cddbc3651c2a038a9</anchor>
      <arglist>(Vector &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a195bd544341e9ae9d5c280c522898afe</anchor>
      <arglist>(Twist &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a5a5e3f2020f49b3aae2ced72957279cf</anchor>
      <arglist>(Wrench &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ab0114bb2d980453c0c2ff95c4b5d7e07</anchor>
      <arglist>(Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a5d7e69524a22c9627a4d4c9ef6199573</anchor>
      <arglist>(Frame &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a5a19fb0fca38c4c44ab227cc7e491c84</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a8006f466dfb798c4865bbf99732315c6</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a41442bbd88293936a321db1b7ad4b2c2</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a670300ca0ce9065eab7e2a5e6c70b58a</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a3a35a33e086efdf284e378f461a71cab</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ab89ee6b759e8671de97cf38b3de791fd</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>ad17f03f1acf55ced7634ab2f348a6263</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a8b26dec0f28798c84e0663e70b28c79b</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a7d2da91476413979f41854765fcb285e</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a4fd2a87ee06692b114a108dd3946e994</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>frames_8inl.html</anchorfile>
      <anchor>a6a6390d093f97246c58eb01ca0e57963</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frames_io.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frames__io_8cpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4dde00469dc5fc853343c8ac32efa147</anchor>
      <arglist>(std::ostream &amp;os, const Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2ad7c49487ea4700b039c05fa5d3bb0</anchor>
      <arglist>(std::ostream &amp;os, const Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abdb1c2aa6c78a0a27427849421256152</anchor>
      <arglist>(std::ostream &amp;os, const Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a142dcb0cd026eb30ac3cd5b4525f5090</anchor>
      <arglist>(std::ostream &amp;os, const Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a226695adfb3680921b18f03136ce0273</anchor>
      <arglist>(std::ostream &amp;os, const Frame &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3815b8d46d06c7e3e5ae67cd6e4990b3</anchor>
      <arglist>(std::ostream &amp;os, const Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a24d29a8e06dbaf10d717157f1ba28d9a</anchor>
      <arglist>(std::ostream &amp;os, const Rotation2 &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a63ec444e29aca93f6c23373ef6433601</anchor>
      <arglist>(std::ostream &amp;os, const Frame2 &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afa42ed5643a2891f71a3b6c6a2df285f</anchor>
      <arglist>(std::istream &amp;is, Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99cf8d444d6ece29e81ba106a4b1d48f</anchor>
      <arglist>(std::istream &amp;is, Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4147003cd7f723387395f3f87887fa96</anchor>
      <arglist>(std::istream &amp;is, Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab2c986dc7a5f9e5864938fc2e79dd67a</anchor>
      <arglist>(std::istream &amp;is, Rotation &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab4978efdfafa24e8f1cb78220c643fb8</anchor>
      <arglist>(std::istream &amp;is, Frame &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a614435357b4ef70a4306fb45facbe606</anchor>
      <arglist>(std::istream &amp;is, Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a798f68d899adc2906b5eb1fca8b4b372</anchor>
      <arglist>(std::istream &amp;is, Rotation2 &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a84456402e2d197eae16e609d80596e10</anchor>
      <arglist>(std::istream &amp;is, Frame2 &amp;T)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frames_io.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>frames__io_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4dde00469dc5fc853343c8ac32efa147</anchor>
      <arglist>(std::ostream &amp;os, const Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a142dcb0cd026eb30ac3cd5b4525f5090</anchor>
      <arglist>(std::ostream &amp;os, const Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a226695adfb3680921b18f03136ce0273</anchor>
      <arglist>(std::ostream &amp;os, const Frame &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2ad7c49487ea4700b039c05fa5d3bb0</anchor>
      <arglist>(std::ostream &amp;os, const Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abdb1c2aa6c78a0a27427849421256152</anchor>
      <arglist>(std::ostream &amp;os, const Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3815b8d46d06c7e3e5ae67cd6e4990b3</anchor>
      <arglist>(std::ostream &amp;os, const Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a24d29a8e06dbaf10d717157f1ba28d9a</anchor>
      <arglist>(std::ostream &amp;os, const Rotation2 &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a63ec444e29aca93f6c23373ef6433601</anchor>
      <arglist>(std::ostream &amp;os, const Frame2 &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afa42ed5643a2891f71a3b6c6a2df285f</anchor>
      <arglist>(std::istream &amp;is, Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab2c986dc7a5f9e5864938fc2e79dd67a</anchor>
      <arglist>(std::istream &amp;is, Rotation &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab4978efdfafa24e8f1cb78220c643fb8</anchor>
      <arglist>(std::istream &amp;is, Frame &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99cf8d444d6ece29e81ba106a4b1d48f</anchor>
      <arglist>(std::istream &amp;is, Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4147003cd7f723387395f3f87887fa96</anchor>
      <arglist>(std::istream &amp;is, Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a614435357b4ef70a4306fb45facbe606</anchor>
      <arglist>(std::istream &amp;is, Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a798f68d899adc2906b5eb1fca8b4b372</anchor>
      <arglist>(std::istream &amp;is, Rotation2 &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a84456402e2d197eae16e609d80596e10</anchor>
      <arglist>(std::istream &amp;is, Frame2 &amp;T)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>framevel.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>framevel_8cpp</filename>
    <includes id="framevel_8hpp" name="framevel.hpp" local="yes" imported="no">framevel.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>framevel.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>framevel_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="framevel_8inl" name="framevel.inl" local="yes" imported="no">framevel.inl</includes>
    <class kind="struct">Traits&lt; KDL::doubleVel &gt;</class>
    <class kind="class">KDL::VectorVel</class>
    <class kind="class">KDL::RotationVel</class>
    <class kind="class">KDL::FrameVel</class>
    <class kind="class">KDL::TwistVel</class>
    <namespace>KDL</namespace>
    <member kind="typedef">
      <type>Rall1d&lt; double &gt;</type>
      <name>doubleVel</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6725eee11f82dfb8f65f78b107bbe7e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac33cd30cdcbb2a408118c7f4da33d839</anchor>
      <arglist>(const doubleVel &amp;a, const doubleVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6ac0a4190fd520636b59af8d3c002b49</anchor>
      <arglist>(const doubleVel &amp;a, const doubleVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a910caae27c05e168ff9e13c1e1646319</anchor>
      <arglist>(doubleVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac19da83b9af24139e10645a8d85a46be</anchor>
      <arglist>(doubleVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a429b3dde4f39a3d81fb99cac3879d5d2</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0917bf2a85b30dba6ac3a60131ac0400</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7499a3cd0d3c34bad5a5f844cd9f34e2</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af947e7ffa1e54902b211aebc7d2fbcd3</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3fc2070f69def825fb20806cc70bdec9</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a31f155d33ef1cc21bc6e69a8c27939a8</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae19cba37b0b3a8f17f2426ef2dde7345</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99f1283f4b309d0cfa47032764149d79</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9883f896f965d3b5991a7f229d312014</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad72529712b954d065bb8a04c15281be7</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5c7ac3cd31bc956c067ddab208ffe1ea</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a106e91304c56ac79037adf15aecb04fd</anchor>
      <arglist>(const TwistVel &amp;a, const Twist &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abcbdf134e1245fff7276c09d93bc129e</anchor>
      <arglist>(const VectorVel &amp;a, const VectorVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab8f44efdaa9efac075dabe72b9b1d793</anchor>
      <arglist>(const VectorVel &amp;a, const VectorVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af6fe4108d2d1bc8f56de6ada8b1e02a2</anchor>
      <arglist>(const RotationVel &amp;a, const RotationVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aab054566b4b7c16b491d1fd24a209b8d</anchor>
      <arglist>(const RotationVel &amp;a, const VectorVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4abe67e47461ea82dd1764ff915b8e5f</anchor>
      <arglist>(const FrameVel &amp;a, const FrameVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc209ec5b445dbeb2080f137428469d0</anchor>
      <arglist>(const FrameVel &amp;a, const TwistVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad4bc824b5837adae75f79399bd124804</anchor>
      <arglist>(VectorVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1fdb77353c9152acfebd13a454872ba4</anchor>
      <arglist>(TwistVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a255a6a31ee024f0c265366e89129f564</anchor>
      <arglist>(RotationVel &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a30e4eea768db2597e48833327755dc16</anchor>
      <arglist>(FrameVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a50822c16b76589bb4a41df313d931f9e</anchor>
      <arglist>(VectorVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad28862488c44a3fcd86179b28223b34b</anchor>
      <arglist>(TwistVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5c000a5dfa9cbf912bf67073fb7520fb</anchor>
      <arglist>(RotationVel &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a804501a1fd1b260f9950c36f25377393</anchor>
      <arglist>(FrameVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a142d0102e854fb2d81285b4be9c77403</anchor>
      <arglist>(const FrameVel &amp;lhs, const FrameVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a91614778fd903680d9adc02dc4f9f93e</anchor>
      <arglist>(const FrameVel &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afa2370df86529ccb32adb550a6d68f3c</anchor>
      <arglist>(const Frame &amp;lhs, const FrameVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a39e814b326504c560b6518dd2da0ccc4</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6797c68c09dc61566d2fb2f9f4e1cdac</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4a07ac035490045345ed765f68c78a38</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7201f4380eaa5617668e254554900113</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acedd29a5a64b4cb0c567732eb5f14d21</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b91bdcbbb71af48e324996cdb43e2cb</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5d7163c16649fa3a642aa848324fe9d4</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>adbe94445d0882c39d30eae3dc0cafe87</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5da7749f16d9ee38bfd37e79a4b4d396</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac1f7e351c8fd233adb3ab3a89d344807</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a69ffbfb2913176226fa8b23af43b29c6</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58aec482512a0c59b6c91e937854ca65</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f71bf9fd005cd96217fc323f2da32c9</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a05ce61116e9eb721ff6ce1a3fbc98a43</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a22c094db1c261a306f291f24cd2b3019</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc467fc7b1ba01dd94296fea19de4d1a</anchor>
      <arglist>(const VectorVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68e666e68770d71ad4051e0274dc33c</anchor>
      <arglist>(VectorVel &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae2e894b949233d7a44ae28da39fba9b3</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>addce33b1267ae40397c0868e3494c443</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2ef790489497475f742e991ac055e870</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99600554d49023bd93514a61abec1bb6</anchor>
      <arglist>(double r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aaa72572d20b5e96b3b36b36b99467db4</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abd858f51b9b11ad399be86cfc8f9e488</anchor>
      <arglist>(const doubleVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>add99195f2e34b8ba9680d64463ab237f</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad97597be7b4cfcfb41052ad7f949779c</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7b2b0c8cf567e8d7057341689c186e25</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac87ef443bc4a8a8fcf86551a10b1dbef</anchor>
      <arglist>(const Rotation &amp;R, const VectorVel &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7b6a84cca357b87f150a916e9256cecf</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4a79f55480a4274e2f1902f62b2858e1</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ada8ad69ba57f135c94041e1cf25b469d</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2e72b3c920bce456e44892604f4ee2e6</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6e89a1838d7701b692f8be3a7fee8c35</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a03afc4531913f82469fbd05f7dc19173</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0ad116c77af73be75361551f32c8ab21</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a84b99208df6b6c36c1be64e3190f909a</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68e4b4619a61b10c023d08d13cfc605</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6492e42fafda7e39a64820445da4d1ce</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad8457a250380f149d1eb284ed1b3934f</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af0b2c9e544649739fa85baf3cc415bd7</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a068c61edbb7adfcf0207a7560a2026eb</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b08e47a485ff7688cdec479512d48bf</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af7f550dee6dfe8474b49187d9c1b52c1</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3a4ecba875d6a101af78791765418324</anchor>
      <arglist>(const Twist &amp;r1, const TwistVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3536e25bdf0f28f49dc4f816febf949</anchor>
      <arglist>(const TwistVel &amp;r1, const Twist &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2e27f65e09a955123c7531e9f31364bb</anchor>
      <arglist>(const TwistVel &amp;r1, const Twist &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59eeac3549f0285cf74e1a0cf7d6a252</anchor>
      <arglist>(const VectorVel &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a249338544fa35389e6ef0557ae975b31</anchor>
      <arglist>(const VectorVel &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac268827dde5f83564132e3991e914661</anchor>
      <arglist>(const Vector &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a72c5596a3ca250d8329e774648e9fa91</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a33851c818cc9f12974f3cb29ebc74615</anchor>
      <arglist>(double lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0cf929f37d18dfea115bb8dfe0a9ba75</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f74503124b79423fed9b28b20124361</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a30bd9b19d131e18d55c493a26f69b6b0</anchor>
      <arglist>(const doubleVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3bb62491cc784aff32bdce8971cff262</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a75aac327bb8398b72660f8ff603af0a7</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3965521259dda93424d97d2231d1b3fc</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae749e341f554956882b5656598e11b99</anchor>
      <arglist>(const TwistVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3f23dc88eba26d540cf728e9e0dd85aa</anchor>
      <arglist>(TwistVel &amp;v)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>framevel.inl</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>framevel_8inl</filename>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a1d25281fed75357c072cc3decfd419d8</anchor>
      <arglist>(const FrameVel &amp;lhs, const FrameVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a885aa2f165dc9a4ed15aa667942f4528</anchor>
      <arglist>(const FrameVel &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>aaafede3e557ae5a4fa67e2d3629f47ea</anchor>
      <arglist>(const Frame &amp;lhs, const FrameVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>aa2f36b13490ad24ac922a3013671c6da</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a9082cc405026060c8b553430544a2cd0</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>abbcf61eb209092f2a7447a4d5a2bfdf2</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a76bd4a34de71de0a786b70e7df02a878</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>acbc30d2726ac0d643ae37e36a242a510</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a32b5cfd2afecf0a521bd54baf59cd447</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a9b422bec85757298be35b8ee8412f937</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>aa5a7142ba3421402c0ac5e93472710b8</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a5e2722f7d2da29a9c6956dd230d6950a</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ab953df776c9fa0df68eb6f42e9fc1bb2</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a4c35aa3b5e14b4509ccf84d2927ea5cb</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a5079a683a52fe350d3c3dcebd93e59b5</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a742c31bc54c7b0935eaaa644953285b0</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a388e3cceebf6356ac0be4ab004f967e3</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>aebbd5c8d4349f582119c589a086eddc8</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a0e1ac37993478e0d456c3eede8a2405e</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a98791d684da6186f76635356860d8566</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a14461b135063182a52dccea5f93e2a27</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>abc3f7b2e4ff3289d0b8ac3678c4b4744</anchor>
      <arglist>(const VectorVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a16056f24ee86efdc98656138808e16e8</anchor>
      <arglist>(VectorVel &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a60a05c4c14a243f9705bf559e1d43b58</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a2b2d801e05b04a5ff7a289d64898806f</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ac0284c801afbdce611ba0f4bf01e87c5</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a4e53cebef732328c7649408f1cda01e2</anchor>
      <arglist>(double r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a8f7604b31d0992f031f223bd72a9f536</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ae4d1f168669646c284266973e7d196af</anchor>
      <arglist>(const doubleVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a0baa3c7a18a93d3f623c570f7dbbe4b0</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator/</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a2999e16d0ab35872ea5ab31e02288df8</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator/</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a39917427f4058e722ae43db23556970e</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>afaa2bb35e56cf49ca16850fa85ded1d7</anchor>
      <arglist>(const Rotation &amp;R, const VectorVel &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a65db533288824ff8b59bac2486fb81ad</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a0e57cc06661c81464f1d3453484b19c0</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a255cde0e7fc0d2a66c26e5ea9a75eb63</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a0edc115976f17c2b43c65887a60f3e2c</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a7b607236d8ad8f512fdfcbaf834d5e53</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a8140686eeba5a07d9bda1df1d630658c</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ad052081b751a0f63443d3923cb2e1ca2</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>abf669d09bce84107e0ba06542a89cb6c</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>abfcd577e4bec35dc2f1a197760d79d80</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>af1f0492ef92bcd6a5061e287867356de</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>aeda05130347a56cc656854a26d9ce2a0</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a932d340abdc249f667fc6583516db76f</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a152d12f624b6be15cedf1556510f5eb7</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a75a2974b5c90121e0a98747f83493fa9</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>acebb3ede907321a775d68122dd1a40a8</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a284b31ffd824c5e7025496a9c0e9bdb6</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a7a9ee0e5006279864eb5b678e6d044e7</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a596e653ce001a8283afc835aad69a282</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a4148591885417fd3088c9ea376327aed</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a4a4f0a2a411dfee26a2a8b3829064251</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a92aa0809085c114632767a176f80e999</anchor>
      <arglist>(const TwistVel &amp;a, const Twist &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ab27d55e1029536b86f970d66c85a6dd7</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a9b7d6e43a7fa83de3e7256bd0a5504a8</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ad48f356f94ae241b01967ed496eff092</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>aee0c9994ee9606a97790249ae57130f7</anchor>
      <arglist>(const Twist &amp;r1, const TwistVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a243550519ca17e63431afda81480c0e5</anchor>
      <arglist>(const TwistVel &amp;r1, const Twist &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a106b050c78a0ccc92c5f742e5506e50c</anchor>
      <arglist>(const TwistVel &amp;r1, const Twist &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a52517fdd0668839b4e35f360b3a906b2</anchor>
      <arglist>(const VectorVel &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>adacd080306299b8680f1bf2b7bff1030</anchor>
      <arglist>(const VectorVel &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ac9390fd1e22ca2364e2d7bc045f5b419</anchor>
      <arglist>(const Vector &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>adde1e133f2008c1cc6636c47ca1213f7</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a4b1ea516875d4889c28be34b71833194</anchor>
      <arglist>(double lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator/</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a74969b2abf09079d49d8b5c4a5f315f1</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a49bf02a2bf61674395e8fee267c1a867</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>ac4966917e36119bbc17d79e8b369a7d6</anchor>
      <arglist>(const doubleVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator/</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a851a9366c8edf5d2408acb8b23213a06</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator+</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a4e64c3d4d6ee2a921edb11cac89ea65d</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator-</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a25c9136cb151bff132f5518dd378c028</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator-</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a808e063a233100f6f926c2eb5365fb8f</anchor>
      <arglist>(const TwistVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>framevel_8inl.html</anchorfile>
      <anchor>a1c39182fffa2e50952d2969f2125032e</anchor>
      <arglist>(TwistVel &amp;v)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>framevel_io.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>framevel__io_8hpp</filename>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aad66d20d936c19dc757be3a94cadcace</anchor>
      <arglist>(std::ostream &amp;os, const VectorVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7dc7beffdaf33343803aae8f3729330e</anchor>
      <arglist>(std::ostream &amp;os, const RotationVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad6b4b7d81abe14453de980e479590cd5</anchor>
      <arglist>(std::ostream &amp;os, const FrameVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f27a3f6197596968c14f5976048d0cb</anchor>
      <arglist>(std::ostream &amp;os, const TwistVel &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jacobian.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jacobian_8cpp</filename>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2015ef4bf3ebb5f6defaf8bc1cf5184</anchor>
      <arglist>(Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeRefPoint</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68d5c0d686d03b0a779f595083209c3</anchor>
      <arglist>(const Jacobian &amp;src1, const Vector &amp;base_AB, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeBase</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa440186e9c44a521afa7e2e8816866a5</anchor>
      <arglist>(const Jacobian &amp;src1, const Rotation &amp;rot, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeRefFrame</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a54141738e3da2da7cebea6bd59ed605b</anchor>
      <arglist>(const Jacobian &amp;src1, const Frame &amp;frame, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab56d49bccacc4c7d3725ee1a31a3a686</anchor>
      <arglist>(const Jacobian &amp;a, const Jacobian &amp;b, double eps)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jacobian.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jacobian_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <class kind="class">KDL::Jacobian</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab56d49bccacc4c7d3725ee1a31a3a686</anchor>
      <arglist>(const Jacobian &amp;a, const Jacobian &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2015ef4bf3ebb5f6defaf8bc1cf5184</anchor>
      <arglist>(Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeRefPoint</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68d5c0d686d03b0a779f595083209c3</anchor>
      <arglist>(const Jacobian &amp;src1, const Vector &amp;base_AB, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeBase</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa440186e9c44a521afa7e2e8816866a5</anchor>
      <arglist>(const Jacobian &amp;src1, const Rotation &amp;rot, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeRefFrame</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a54141738e3da2da7cebea6bd59ed605b</anchor>
      <arglist>(const Jacobian &amp;src1, const Frame &amp;frame, Jacobian &amp;dest)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntarray.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntarray_8cpp</filename>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3247ff837ae01a286d6f267f3611bd78</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac44746c206c669411831b6caff88e421</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a65d854aa88f96a677c66b50bc06b54bd</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58ae4682bfa96df290a84bc8764db2f3</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MultiplyJacobian</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac85eca37a300ca3afa534bf3133cd134</anchor>
      <arglist>(const Jacobian &amp;jac, const JntArray &amp;src, Twist &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2f3640f68421949e70b00b7850917ebe</anchor>
      <arglist>(JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a904f9217dcd290d305c59328c0c2a7bd</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4da090fc8773ecb33ea708305f73b0e</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntarray.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntarray_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <class kind="class">KDL::JntArray</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4da090fc8773ecb33ea708305f73b0e</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3247ff837ae01a286d6f267f3611bd78</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac44746c206c669411831b6caff88e421</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a65d854aa88f96a677c66b50bc06b54bd</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58ae4682bfa96df290a84bc8764db2f3</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MultiplyJacobian</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac85eca37a300ca3afa534bf3133cd134</anchor>
      <arglist>(const Jacobian &amp;jac, const JntArray &amp;src, Twist &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2f3640f68421949e70b00b7850917ebe</anchor>
      <arglist>(JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a904f9217dcd290d305c59328c0c2a7bd</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, double eps=epsilon)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntarrayacc.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntarrayacc_8cpp</filename>
    <includes id="jntarrayacc_8hpp" name="jntarrayacc.hpp" local="yes" imported="no">jntarrayacc.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac9ab98846beb21a1e6507218edda37b0</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6267b92f0a4a416a00a1774b5f565d5e</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a576562dc10e56a5f4cd88840031b9714</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a11d30225535a30ab654b8709f63e01f3</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0c8b3f55e1a6fb791e14bcb8e0b5e9d4</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9bac2127ca5bdf3e32005ba6c4b6e7ce</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab32cb0e76ccfdbc012bbdff485fa2e2c</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15f89314c4b049945d7e4566b3bb1459</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b751d3ba37a7ca2ee37b4955b6a1b2c</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a271c55c29a0bbb873d420392f4cd1685</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a29a463da0ea75ee267a9229b6397cff4</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae8b64e8487e3bb3b6a8f2ccf5255c80f</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a11a7cb9d8b92e0170f7bbfa76b378704</anchor>
      <arglist>(JntArrayAcc &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a944126492e3ac5834cde755114151d75</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, double eps)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntarrayacc.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntarrayacc_8hpp</filename>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="jntarrayvel_8hpp" name="jntarrayvel.hpp" local="yes" imported="no">jntarrayvel.hpp</includes>
    <includes id="frameacc_8hpp" name="frameacc.hpp" local="yes" imported="no">frameacc.hpp</includes>
    <class kind="class">KDL::JntArrayAcc</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a944126492e3ac5834cde755114151d75</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac9ab98846beb21a1e6507218edda37b0</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6267b92f0a4a416a00a1774b5f565d5e</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a576562dc10e56a5f4cd88840031b9714</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a11d30225535a30ab654b8709f63e01f3</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0c8b3f55e1a6fb791e14bcb8e0b5e9d4</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9bac2127ca5bdf3e32005ba6c4b6e7ce</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab32cb0e76ccfdbc012bbdff485fa2e2c</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15f89314c4b049945d7e4566b3bb1459</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b751d3ba37a7ca2ee37b4955b6a1b2c</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a271c55c29a0bbb873d420392f4cd1685</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a29a463da0ea75ee267a9229b6397cff4</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae8b64e8487e3bb3b6a8f2ccf5255c80f</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a11a7cb9d8b92e0170f7bbfa76b378704</anchor>
      <arglist>(JntArrayAcc &amp;array)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntarrayvel.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntarrayvel_8cpp</filename>
    <includes id="jntarrayacc_8hpp" name="jntarrayacc.hpp" local="yes" imported="no">jntarrayacc.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a869bd80558b4be8a8481620a47883a53</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8315fb2791bd487674d77c3ad66a7135</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4d61bfbf31b933f7843f71328966e85</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aadbca4bf9398d905195352bb15fffb06</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aecfc62e3d4f3d21b9752669794aac2fb</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3dbaa87cc9453c14a7fd4335ca343c66</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae139248a5f388a7926789e58a1cb192b</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab47fd546752c9082c646e51430daed25</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af728f5fb88f6dfdca91afeae2d036d75</anchor>
      <arglist>(JntArrayVel &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afdfb90a1123ea45e6b0e348aff04b230</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, double eps)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntarrayvel.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntarrayvel_8hpp</filename>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="framevel_8hpp" name="framevel.hpp" local="yes" imported="no">framevel.hpp</includes>
    <class kind="class">KDL::JntArrayVel</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afdfb90a1123ea45e6b0e348aff04b230</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a869bd80558b4be8a8481620a47883a53</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8315fb2791bd487674d77c3ad66a7135</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4d61bfbf31b933f7843f71328966e85</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aadbca4bf9398d905195352bb15fffb06</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aecfc62e3d4f3d21b9752669794aac2fb</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3dbaa87cc9453c14a7fd4335ca343c66</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae139248a5f388a7926789e58a1cb192b</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab47fd546752c9082c646e51430daed25</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af728f5fb88f6dfdca91afeae2d036d75</anchor>
      <arglist>(JntArrayVel &amp;array)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntspaceinertiamatrix.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntspaceinertiamatrix_8cpp</filename>
    <includes id="jntspaceinertiamatrix_8hpp" name="jntspaceinertiamatrix.hpp" local="yes" imported="no">jntspaceinertiamatrix.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af635568f6c7c9d282230d7ef6aaf2c8a</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad7871e05e7ecc703e39a9256dbc3ea4c</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae7a531e845086142255090a67666ec70</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src, const double &amp;factor, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa9dca0c2efb73851970931de9f0daa6e</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src, const double &amp;factor, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1210f7f6f4db1eee2e2c39211c7cb388</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src, const JntArray &amp;vec, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3dd6492d65329fce08a49950b28256ee</anchor>
      <arglist>(JntSpaceInertiaMatrix &amp;mat)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59ea9aebf2aaa6edfd35375dcbcea546</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abbf2ff7d3f960ab4ff33d979d13f591e</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>jntspaceinertiamatrix.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>jntspaceinertiamatrix_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
  </compound>
  <compound kind="file">
    <name>joint.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>joint_8cpp</filename>
    <includes id="joint_8hpp" name="joint.hpp" local="yes" imported="no">joint.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>joint.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>joint_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <class kind="class">KDL::Joint</class>
    <class kind="class">KDL::Joint::joint_type_exception</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>kdl.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>kdl_8hpp</filename>
  </compound>
  <compound kind="file">
    <name>kinfam.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>kinfam_8hpp</filename>
  </compound>
  <compound kind="file">
    <name>kinfam_io.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>kinfam__io_8cpp</filename>
    <includes id="kinfam__io_8hpp" name="kinfam_io.hpp" local="yes" imported="no">kinfam_io.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ada870ba0c32e066ec5bc788b89d74749</anchor>
      <arglist>(std::ostream &amp;os, const Joint &amp;joint)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a14b0994fadb788bdcdb88e9009f5d919</anchor>
      <arglist>(std::istream &amp;is, Joint &amp;joint)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad58c420f0f0975c5cfb6c143d528a0b6</anchor>
      <arglist>(std::ostream &amp;os, const Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a462bc4499da1e5209d5001872632985b</anchor>
      <arglist>(std::istream &amp;is, Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a82e4b532cea22eeed8fbec1bd43181f8</anchor>
      <arglist>(std::ostream &amp;os, const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aba43ee3692a840b29148361f29ddfce5</anchor>
      <arglist>(std::istream &amp;is, Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9d7494dc064cd870a35029348375a838</anchor>
      <arglist>(std::ostream &amp;os, const Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0ff1c2a2597af9f062ddf0358682350e</anchor>
      <arglist>(std::ostream &amp;os, SegmentMap::const_iterator root)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15fc44010bfdca609d7802c8aab91895</anchor>
      <arglist>(std::istream &amp;is, Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9c24a75480dd228cc709f5671a91ad5d</anchor>
      <arglist>(std::ostream &amp;os, const JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3598c2cd0bf08e0d4091b62c3d3e70b</anchor>
      <arglist>(std::istream &amp;is, JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0b1bfa84edf53b8bda42eb5aed25b000</anchor>
      <arglist>(std::ostream &amp;os, const Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a85780256ced2e5f6fba9424699585611</anchor>
      <arglist>(std::istream &amp;is, Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa08626fac3a13378cd8d93ce317f581f</anchor>
      <arglist>(std::ostream &amp;os, const JntSpaceInertiaMatrix &amp;jntspaceinertiamatrix)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59562838391488e5b3aa4b158a090225</anchor>
      <arglist>(std::istream &amp;is, JntSpaceInertiaMatrix &amp;jntspaceinertiamatrix)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>tree2str</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a41887a706e492cdc9233cd8a8d1941fd</anchor>
      <arglist>(const SegmentMap::const_iterator it, const std::string &amp;separator, const std::string &amp;preamble, unsigned int level)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>tree2str</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a47c82d0ef17bb32147727b66899b5a64</anchor>
      <arglist>(const Tree &amp;tree, const std::string &amp;separator, const std::string &amp;preamble)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>kinfam_io.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>kinfam__io_8hpp</filename>
    <includes id="joint_8hpp" name="joint.hpp" local="yes" imported="no">joint.hpp</includes>
    <includes id="segment_8hpp" name="segment.hpp" local="yes" imported="no">segment.hpp</includes>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <includes id="tree_8hpp" name="tree.hpp" local="yes" imported="no">tree.hpp</includes>
    <includes id="jntspaceinertiamatrix_8hpp" name="jntspaceinertiamatrix.hpp" local="yes" imported="no">jntspaceinertiamatrix.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ada870ba0c32e066ec5bc788b89d74749</anchor>
      <arglist>(std::ostream &amp;os, const Joint &amp;joint)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a14b0994fadb788bdcdb88e9009f5d919</anchor>
      <arglist>(std::istream &amp;is, Joint &amp;joint)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad58c420f0f0975c5cfb6c143d528a0b6</anchor>
      <arglist>(std::ostream &amp;os, const Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a462bc4499da1e5209d5001872632985b</anchor>
      <arglist>(std::istream &amp;is, Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a82e4b532cea22eeed8fbec1bd43181f8</anchor>
      <arglist>(std::ostream &amp;os, const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aba43ee3692a840b29148361f29ddfce5</anchor>
      <arglist>(std::istream &amp;is, Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9d7494dc064cd870a35029348375a838</anchor>
      <arglist>(std::ostream &amp;os, const Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15fc44010bfdca609d7802c8aab91895</anchor>
      <arglist>(std::istream &amp;is, Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0ff1c2a2597af9f062ddf0358682350e</anchor>
      <arglist>(std::ostream &amp;os, SegmentMap::const_iterator root)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9c24a75480dd228cc709f5671a91ad5d</anchor>
      <arglist>(std::ostream &amp;os, const JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3598c2cd0bf08e0d4091b62c3d3e70b</anchor>
      <arglist>(std::istream &amp;is, JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0b1bfa84edf53b8bda42eb5aed25b000</anchor>
      <arglist>(std::ostream &amp;os, const Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a85780256ced2e5f6fba9424699585611</anchor>
      <arglist>(std::istream &amp;is, Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa08626fac3a13378cd8d93ce317f581f</anchor>
      <arglist>(std::ostream &amp;os, const JntSpaceInertiaMatrix &amp;jntspaceinertiamatrix)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59562838391488e5b3aa4b158a090225</anchor>
      <arglist>(std::istream &amp;is, JntSpaceInertiaMatrix &amp;jntspaceinertiamatrix)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>tree2str</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a47c82d0ef17bb32147727b66899b5a64</anchor>
      <arglist>(const Tree &amp;tree, const std::string &amp;separator, const std::string &amp;preamble)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>tree2str</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a41887a706e492cdc9233cd8a8d1941fd</anchor>
      <arglist>(const SegmentMap::const_iterator it, const std::string &amp;separator, const std::string &amp;preamble, unsigned int level)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>motion.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>motion_8hpp</filename>
  </compound>
  <compound kind="file">
    <name>path.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path_8cpp</filename>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="path__line_8hpp" name="path_line.hpp" local="yes" imported="no">path_line.hpp</includes>
    <includes id="path__point_8hpp" name="path_point.hpp" local="yes" imported="no">path_point.hpp</includes>
    <includes id="path__circle_8hpp" name="path_circle.hpp" local="yes" imported="no">path_circle.hpp</includes>
    <includes id="path__composite_8hpp" name="path_composite.hpp" local="yes" imported="no">path_composite.hpp</includes>
    <includes id="path__roundedcomposite_8hpp" name="path_roundedcomposite.hpp" local="yes" imported="no">path_roundedcomposite.hpp</includes>
    <includes id="path__cyclic__closed_8hpp" name="path_cyclic_closed.hpp" local="yes" imported="no">path_cyclic_closed.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <class kind="class">KDL::Path</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_circle.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__circle_8cpp</filename>
    <includes id="path__circle_8hpp" name="path_circle.hpp" local="yes" imported="no">path_circle.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_circle.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__circle_8hpp</filename>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="rotational__interpolation_8hpp" name="rotational_interpolation.hpp" local="yes" imported="no">rotational_interpolation.hpp</includes>
    <class kind="class">KDL::Path_Circle</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_composite.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__composite_8cpp</filename>
    <includes id="path__composite_8hpp" name="path_composite.hpp" local="yes" imported="no">path_composite.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_composite.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__composite_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <class kind="class">KDL::Path_Composite</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_cyclic_closed.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__cyclic__closed_8cpp</filename>
    <includes id="path__cyclic__closed_8hpp" name="path_cyclic_closed.hpp" local="yes" imported="no">path_cyclic_closed.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_cyclic_closed.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__cyclic__closed_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <class kind="class">KDL::Path_Cyclic_Closed</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_line.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__line_8cpp</filename>
    <includes id="path__line_8hpp" name="path_line.hpp" local="yes" imported="no">path_line.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_line.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__line_8hpp</filename>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="rotational__interpolation_8hpp" name="rotational_interpolation.hpp" local="yes" imported="no">rotational_interpolation.hpp</includes>
    <class kind="class">KDL::Path_Line</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_point.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__point_8cpp</filename>
    <includes id="path__point_8hpp" name="path_point.hpp" local="yes" imported="no">path_point.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_point.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__point_8hpp</filename>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="rotational__interpolation_8hpp" name="rotational_interpolation.hpp" local="yes" imported="no">rotational_interpolation.hpp</includes>
    <class kind="class">KDL::Path_Point</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_roundedcomposite.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__roundedcomposite_8cpp</filename>
    <includes id="path__roundedcomposite_8hpp" name="path_roundedcomposite.hpp" local="yes" imported="no">path_roundedcomposite.hpp</includes>
    <includes id="path__line_8hpp" name="path_line.hpp" local="yes" imported="no">path_line.hpp</includes>
    <includes id="path__circle_8hpp" name="path_circle.hpp" local="yes" imported="no">path_circle.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>path_roundedcomposite.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>path__roundedcomposite_8hpp</filename>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="path__composite_8hpp" name="path_composite.hpp" local="yes" imported="no">path_composite.hpp</includes>
    <includes id="rotational__interpolation_8hpp" name="rotational_interpolation.hpp" local="yes" imported="no">rotational_interpolation.hpp</includes>
    <class kind="class">KDL::Path_RoundedComposite</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>rigidbodyinertia.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rigidbodyinertia_8cpp</filename>
    <includes id="rigidbodyinertia_8hpp" name="rigidbodyinertia.hpp" local="yes" imported="no">rigidbodyinertia.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>accbcba03cf4c161e16962aa6ede0f71f</anchor>
      <arglist>(double a, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9a48ecd0ba02c61eb30f97b3606a1d10</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aea69709844f7f034d1352c182036b5ac</anchor>
      <arglist>(const RigidBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acbf30c08a930e58f18e6f4b89b4d3fd8</anchor>
      <arglist>(const Frame &amp;T, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7274034ce0edaa31cd6c41b8db4589a7</anchor>
      <arglist>(const Rotation &amp;R, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const bool</type>
      <name>mhi</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa32a96d64e25d59e3587464cbfca82e7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rigidbodyinertia.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rigidbodyinertia_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="rotationalinertia_8hpp" name="rotationalinertia.hpp" local="yes" imported="no">rotationalinertia.hpp</includes>
    <class kind="class">KDL::RigidBodyInertia</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>accbcba03cf4c161e16962aa6ede0f71f</anchor>
      <arglist>(double a, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9a48ecd0ba02c61eb30f97b3606a1d10</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aea69709844f7f034d1352c182036b5ac</anchor>
      <arglist>(const RigidBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acbf30c08a930e58f18e6f4b89b4d3fd8</anchor>
      <arglist>(const Frame &amp;T, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7274034ce0edaa31cd6c41b8db4589a7</anchor>
      <arglist>(const Rotation &amp;R, const RigidBodyInertia &amp;I)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rotational_interpolation.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rotational__interpolation_8cpp</filename>
    <includes id="rotational__interpolation_8hpp" name="rotational_interpolation.hpp" local="yes" imported="no">rotational_interpolation.hpp</includes>
    <includes id="rotational__interpolation__sa_8hpp" name="rotational_interpolation_sa.hpp" local="yes" imported="no">rotational_interpolation_sa.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>rotational_interpolation.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rotational__interpolation_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <class kind="class">KDL::RotationalInterpolation</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>rotational_interpolation_sa.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rotational__interpolation__sa_8cpp</filename>
    <includes id="rotational__interpolation__sa_8hpp" name="rotational_interpolation_sa.hpp" local="yes" imported="no">rotational_interpolation_sa.hpp</includes>
    <includes id="trajectory_8hpp" name="trajectory.hpp" local="yes" imported="no">trajectory.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>rotational_interpolation_sa.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rotational__interpolation__sa_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="rotational__interpolation_8hpp" name="rotational_interpolation.hpp" local="yes" imported="no">rotational_interpolation.hpp</includes>
    <class kind="class">KDL::RotationalInterpolation_SingleAxis</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>rotationalinertia.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rotationalinertia_8cpp</filename>
    <includes id="rotationalinertia_8hpp" name="rotationalinertia.hpp" local="yes" imported="no">rotationalinertia.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af55f79c3adb61f24af891e0a01b1c9da</anchor>
      <arglist>(double a, const RotationalInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abe6b8cfeb5c5230d0641585798889a77</anchor>
      <arglist>(const RotationalInertia &amp;Ia, const RotationalInertia &amp;Ib)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rotationalinertia.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>rotationalinertia_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <class kind="class">KDL::RotationalInertia</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af55f79c3adb61f24af891e0a01b1c9da</anchor>
      <arglist>(double a, const RotationalInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abe6b8cfeb5c5230d0641585798889a77</anchor>
      <arglist>(const RotationalInertia &amp;Ia, const RotationalInertia &amp;Ib)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>segment.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>segment_8cpp</filename>
    <includes id="segment_8hpp" name="segment.hpp" local="yes" imported="no">segment.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>segment.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>segment_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="rigidbodyinertia_8hpp" name="rigidbodyinertia.hpp" local="yes" imported="no">rigidbodyinertia.hpp</includes>
    <includes id="joint_8hpp" name="joint.hpp" local="yes" imported="no">joint.hpp</includes>
    <class kind="class">KDL::Segment</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>solveri.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>solveri_8hpp</filename>
    <class kind="class">KDL::SolverI</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>stiffness.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>stiffness_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <class kind="class">KDL::Stiffness</class>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aaeeb2ef394b9f8e5772d793d9c361530</anchor>
      <arglist>(const Stiffness &amp;s, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>Stiffness</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9c96e2afbe60a8f62893843c08895a35</anchor>
      <arglist>(const Stiffness &amp;s1, const Stiffness &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8139fb4347d29af451e019f5d54f5268</anchor>
      <arglist>(Stiffness &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acedf7ab3ea2f5f02a51c0509a406ef33</anchor>
      <arglist>(Stiffness &amp;F)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>trajectory.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory_8cpp</filename>
    <includes id="trajectory_8hpp" name="trajectory.hpp" local="yes" imported="no">trajectory.hpp</includes>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="trajectory__segment_8hpp" name="trajectory_segment.hpp" local="yes" imported="no">trajectory_segment.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::Trajectory</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory_composite.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory__composite_8cpp</filename>
    <includes id="trajectory__composite_8hpp" name="trajectory_composite.hpp" local="yes" imported="no">trajectory_composite.hpp</includes>
    <includes id="path__composite_8hpp" name="path_composite.hpp" local="yes" imported="no">path_composite.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory_composite.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory__composite_8hpp</filename>
    <includes id="trajectory_8hpp" name="trajectory.hpp" local="yes" imported="no">trajectory.hpp</includes>
    <includes id="path__composite_8hpp" name="path_composite.hpp" local="yes" imported="no">path_composite.hpp</includes>
    <class kind="class">KDL::Trajectory_Composite</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory_segment.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory__segment_8cpp</filename>
    <includes id="trajectory__segment_8hpp" name="trajectory_segment.hpp" local="yes" imported="no">trajectory_segment.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory_segment.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory__segment_8hpp</filename>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <includes id="trajectory_8hpp" name="trajectory.hpp" local="yes" imported="no">trajectory.hpp</includes>
    <includes id="path_8hpp" name="path.hpp" local="yes" imported="no">path.hpp</includes>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::Trajectory_Segment</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory_stationary.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory__stationary_8cpp</filename>
    <includes id="trajectory__stationary_8hpp" name="trajectory_stationary.hpp" local="yes" imported="no">trajectory_stationary.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>trajectory_stationary.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>trajectory__stationary_8hpp</filename>
    <includes id="trajectory_8hpp" name="trajectory.hpp" local="yes" imported="no">trajectory.hpp</includes>
    <class kind="class">KDL::Trajectory_Stationary</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>tree.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>tree_8cpp</filename>
    <includes id="tree_8hpp" name="tree.hpp" local="yes" imported="no">tree.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>tree.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>tree_8hpp</filename>
    <includes id="segment_8hpp" name="segment.hpp" local="yes" imported="no">segment.hpp</includes>
    <includes id="chain_8hpp" name="chain.hpp" local="yes" imported="no">chain.hpp</includes>
    <class kind="class">KDL::TreeElement</class>
    <class kind="class">KDL::Tree</class>
    <namespace>KDL</namespace>
    <member kind="define">
      <type>#define</type>
      <name>GetTreeElementChildren</name>
      <anchorfile>tree_8hpp.html</anchorfile>
      <anchor>a241a44dc00df371b6342f3232d1867cb</anchor>
      <arglist>(tree_element)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GetTreeElementParent</name>
      <anchorfile>tree_8hpp.html</anchorfile>
      <anchor>abf0914fd1c8a61fe228cbaef5376884d</anchor>
      <arglist>(tree_element)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GetTreeElementQNr</name>
      <anchorfile>tree_8hpp.html</anchorfile>
      <anchor>aa8b8b99a82c86dccffa9bc7b5e620699</anchor>
      <arglist>(tree_element)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GetTreeElementSegment</name>
      <anchorfile>tree_8hpp.html</anchorfile>
      <anchor>a3850788311af4457b6ccbe8303919e70</anchor>
      <arglist>(tree_element)</arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, TreeElement &gt;</type>
      <name>SegmentMap</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6bfcccbcc840654a88822ddd0ee6bdaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TreeElement</type>
      <name>TreeElementType</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3816afaee547d0e1a8e3acc39e6ed0d9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>treefksolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treefksolver_8hpp</filename>
    <includes id="tree_8hpp" name="tree.hpp" local="yes" imported="no">tree.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <class kind="class">KDL::TreeFkSolverPos</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treefksolverpos_recursive.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treefksolverpos__recursive_8cpp</filename>
    <includes id="treefksolverpos__recursive_8hpp" name="treefksolverpos_recursive.hpp" local="yes" imported="no">treefksolverpos_recursive.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treefksolverpos_recursive.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treefksolverpos__recursive_8hpp</filename>
    <includes id="treefksolver_8hpp" name="treefksolver.hpp" local="yes" imported="no">treefksolver.hpp</includes>
    <class kind="class">KDL::TreeFkSolverPos_recursive</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeidsolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeidsolver_8hpp</filename>
    <includes id="tree_8hpp" name="tree.hpp" local="yes" imported="no">tree.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="solveri_8hpp" name="solveri.hpp" local="yes" imported="no">solveri.hpp</includes>
    <class kind="class">KDL::TreeIdSolver</class>
    <namespace>KDL</namespace>
    <member kind="typedef">
      <type>std::map&lt; std::string, Wrench &gt;</type>
      <name>WrenchMap</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6461f6198aeae25076631dfd74486f8f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>treeidsolver_recursive_newton_euler.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeidsolver__recursive__newton__euler_8cpp</filename>
    <includes id="treeidsolver__recursive__newton__euler_8hpp" name="treeidsolver_recursive_newton_euler.hpp" local="yes" imported="no">treeidsolver_recursive_newton_euler.hpp</includes>
    <includes id="frames__io_8hpp" name="frames_io.hpp" local="yes" imported="no">frames_io.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeidsolver_recursive_newton_euler.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeidsolver__recursive__newton__euler_8hpp</filename>
    <includes id="treeidsolver_8hpp" name="treeidsolver.hpp" local="yes" imported="no">treeidsolver.hpp</includes>
    <class kind="class">KDL::TreeIdSolver_RNE</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeiksolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolver_8hpp</filename>
    <includes id="tree_8hpp" name="tree.hpp" local="yes" imported="no">tree.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <includes id="frames_8hpp" name="frames.hpp" local="yes" imported="no">frames.hpp</includes>
    <class kind="class">KDL::TreeIkSolverPos</class>
    <class kind="class">KDL::TreeIkSolverVel</class>
    <namespace>KDL</namespace>
    <member kind="typedef">
      <type>std::map&lt; std::string, Twist &gt;</type>
      <name>Twists</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a48ceacb8e88b1c7009802cdf75ac5b87</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, Jacobian &gt;</type>
      <name>Jacobians</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad23eebdce1073711bb4db8f9fa568362</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, Frame &gt;</type>
      <name>Frames</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a19abc72c063bbf7718e2299712003478</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>treeiksolverpos_nr_jl.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolverpos__nr__jl_8cpp</filename>
    <includes id="treeiksolverpos__nr__jl_8hpp" name="treeiksolverpos_nr_jl.hpp" local="yes" imported="no">treeiksolverpos_nr_jl.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeiksolverpos_nr_jl.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolverpos__nr__jl_8hpp</filename>
    <includes id="treeiksolver_8hpp" name="treeiksolver.hpp" local="yes" imported="no">treeiksolver.hpp</includes>
    <includes id="treefksolver_8hpp" name="treefksolver.hpp" local="yes" imported="no">treefksolver.hpp</includes>
    <class kind="class">KDL::TreeIkSolverPos_NR_JL</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeiksolverpos_online.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolverpos__online_8cpp</filename>
    <includes id="treeiksolverpos__online_8hpp" name="treeiksolverpos_online.hpp" local="yes" imported="no">treeiksolverpos_online.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeiksolverpos_online.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolverpos__online_8hpp</filename>
    <includes id="treeiksolver_8hpp" name="treeiksolver.hpp" local="yes" imported="no">treeiksolver.hpp</includes>
    <includes id="treefksolver_8hpp" name="treefksolver.hpp" local="yes" imported="no">treefksolver.hpp</includes>
    <class kind="class">KDL::TreeIkSolverPos_Online</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeiksolvervel_wdls.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolvervel__wdls_8cpp</filename>
    <includes id="treeiksolvervel__wdls_8hpp" name="treeiksolvervel_wdls.hpp" local="yes" imported="no">treeiksolvervel_wdls.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treeiksolvervel_wdls.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treeiksolvervel__wdls_8hpp</filename>
    <includes id="treeiksolver_8hpp" name="treeiksolver.hpp" local="yes" imported="no">treeiksolver.hpp</includes>
    <includes id="treejnttojacsolver_8hpp" name="treejnttojacsolver.hpp" local="yes" imported="no">treejnttojacsolver.hpp</includes>
    <class kind="class">KDL::TreeIkSolverVel_wdls</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treejnttojacsolver.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treejnttojacsolver_8cpp</filename>
    <includes id="treejnttojacsolver_8hpp" name="treejnttojacsolver.hpp" local="yes" imported="no">treejnttojacsolver.hpp</includes>
    <includes id="kinfam__io_8hpp" name="kinfam_io.hpp" local="yes" imported="no">kinfam_io.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>treejnttojacsolver.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>treejnttojacsolver_8hpp</filename>
    <includes id="tree_8hpp" name="tree.hpp" local="yes" imported="no">tree.hpp</includes>
    <includes id="jacobian_8hpp" name="jacobian.hpp" local="yes" imported="no">jacobian.hpp</includes>
    <includes id="jntarray_8hpp" name="jntarray.hpp" local="yes" imported="no">jntarray.hpp</includes>
    <class kind="class">KDL::TreeJntToJacSolver</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>svd_eigen_Macie.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/utilities/</path>
    <filename>svd__eigen__Macie_8hpp</filename>
    <namespace>KDL</namespace>
    <member kind="function">
      <type>int</type>
      <name>svd_eigen_Macie</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1ffa30e1db026c43a7a6fe8b3e2f866c</anchor>
      <arglist>(const Eigen::MatrixXd &amp;A, Eigen::MatrixXd &amp;U, Eigen::VectorXd &amp;S, Eigen::MatrixXd &amp;V, Eigen::MatrixXd &amp;B, Eigen::VectorXd &amp;tempi, double threshold, bool toggle)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>velocityprofile.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile_8cpp</filename>
    <includes id="velocityprofile__rect_8hpp" name="velocityprofile_rect.hpp" local="yes" imported="no">velocityprofile_rect.hpp</includes>
    <includes id="velocityprofile__dirac_8hpp" name="velocityprofile_dirac.hpp" local="yes" imported="no">velocityprofile_dirac.hpp</includes>
    <includes id="velocityprofile__trap_8hpp" name="velocityprofile_trap.hpp" local="yes" imported="no">velocityprofile_trap.hpp</includes>
    <includes id="velocityprofile__traphalf_8hpp" name="velocityprofile_traphalf.hpp" local="yes" imported="no">velocityprofile_traphalf.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile_8hpp</filename>
    <class kind="class">KDL::VelocityProfile</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_dirac.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__dirac_8cpp</filename>
    <includes id="velocityprofile__dirac_8hpp" name="velocityprofile_dirac.hpp" local="yes" imported="no">velocityprofile_dirac.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_dirac.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__dirac_8hpp</filename>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::VelocityProfile_Dirac</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_rect.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__rect_8cpp</filename>
    <includes id="velocityprofile__rect_8hpp" name="velocityprofile_rect.hpp" local="yes" imported="no">velocityprofile_rect.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_rect.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__rect_8hpp</filename>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::VelocityProfile_Rectangular</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_spline.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__spline_8cpp</filename>
    <includes id="velocityprofile__spline_8hpp" name="velocityprofile_spline.hpp" local="yes" imported="no">velocityprofile_spline.hpp</includes>
    <namespace>KDL</namespace>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>generatePowers</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a94c4e9f0c4e9790ec33e72003bd13fdc</anchor>
      <arglist>(int n, double x, double *powers)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>velocityprofile_spline.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__spline_8hpp</filename>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::VelocityProfile_Spline</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_trap.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__trap_8cpp</filename>
    <includes id="velocityprofile__trap_8hpp" name="velocityprofile_trap.hpp" local="yes" imported="no">velocityprofile_trap.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_trap.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__trap_8hpp</filename>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::VelocityProfile_Trap</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_traphalf.cpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__traphalf_8cpp</filename>
    <includes id="velocityprofile__traphalf_8hpp" name="velocityprofile_traphalf.hpp" local="yes" imported="no">velocityprofile_traphalf.hpp</includes>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="file">
    <name>velocityprofile_traphalf.hpp</name>
    <path>/home/sheldon/kdl_ws/orocos_kinematics_dynamics/orocos_kdl/src/</path>
    <filename>velocityprofile__traphalf_8hpp</filename>
    <includes id="velocityprofile_8hpp" name="velocityprofile.hpp" local="yes" imported="no">velocityprofile.hpp</includes>
    <class kind="class">KDL::VelocityProfile_TrapHalf</class>
    <namespace>KDL</namespace>
  </compound>
  <compound kind="class">
    <name>KDL::ArticulatedBodyInertia</name>
    <filename>classKDL_1_1ArticulatedBodyInertia.html</filename>
    <member kind="function">
      <type></type>
      <name>ArticulatedBodyInertia</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a1687a92d745541fcc41a977f38750eab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ArticulatedBodyInertia</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a9307edd093b5ab4f46d88e30ebede7f2</anchor>
      <arglist>(const RigidBodyInertia &amp;rbi)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ArticulatedBodyInertia</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a655a11f4f0f3dfc3bd8281cb7d959a35</anchor>
      <arglist>(double m, const Vector &amp;oc=Vector::Zero(), const RotationalInertia &amp;Ic=RotationalInertia::Zero())</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ArticulatedBodyInertia</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>aed6b8f04c1b53b5ac52165f075031aeb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>RefPoint</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a079cf1b582f5b7abe3c6f0ee5903bff1</anchor>
      <arglist>(const Vector &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ArticulatedBodyInertia</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a514d696939be523d8bfc60120f98a0cc</anchor>
      <arglist>(const Eigen::Matrix3d &amp;M, const Eigen::Matrix3d &amp;H, const Eigen::Matrix3d &amp;I)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ArticulatedBodyInertia</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>af552f6e6fd54f714b4ac3cba2ca1afc4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Eigen::Matrix3d</type>
      <name>M</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a4554945bd26747db6b3e5a66c8d41a48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Eigen::Matrix3d</type>
      <name>H</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>ad50ff6e5a4b88e4f4f783d66ae550738</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Eigen::Matrix3d</type>
      <name>I</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a10c72eceeae5dcc9ddabc503c1cac8d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a0f37f3ab2d7c263d6d1aa06573ad1a3c</anchor>
      <arglist>(double a, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a6d5bb62d9ec093e70df7c591ce0bceac</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a357613d4b45f8ef6ee511ab6a82fa61a</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a315c737b3a7c78d2264e0c635f8da8d3</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a872088f66e94007216f27d229b8e0034</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>a1876000de094f72c8caa38a9dd01e433</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>ad8daf12963cceeccc090763622e352c5</anchor>
      <arglist>(const Frame &amp;T, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1ArticulatedBodyInertia.html</anchorfile>
      <anchor>ada2c2677db8424b306313c0e5a76ddbf</anchor>
      <arglist>(const Rotation &amp;R, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Chain</name>
    <filename>classKDL_1_1Chain.html</filename>
    <member kind="function">
      <type></type>
      <name>Chain</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a2074fe813f089504598eebb9088cd37c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Chain</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a52c4e72b7f952bf472cf4762d2d43c90</anchor>
      <arglist>(const Chain &amp;in)</arglist>
    </member>
    <member kind="function">
      <type>Chain &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a87864c34e0937940aa6ca71faa929518</anchor>
      <arglist>(const Chain &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addSegment</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>aa0f094560074c30d2b9a03381df60885</anchor>
      <arglist>(const Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addChain</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a010981b0af4ecb950478ebcf995bcad7</anchor>
      <arglist>(const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNrOfJoints</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a24915919dabc4ea58600a38882445cd8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNrOfSegments</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>ab5b0574fe08bfbd16f5c9f6e664a2a01</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const Segment &amp;</type>
      <name>getSegment</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a07a9792d442b7712335417a9eef81cbb</anchor>
      <arglist>(unsigned int nr) const</arglist>
    </member>
    <member kind="function">
      <type>Segment &amp;</type>
      <name>getSegment</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a94d3f924725f0db5e65ba76b34399dba</anchor>
      <arglist>(unsigned int nr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Chain</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a73bb1d4911724c1849ae72eec7af8623</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>std::vector&lt; Segment &gt;</type>
      <name>segments</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>ac10d5385dccd1fa6ebe85d56746d5257</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nrOfJoints</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>a1617a23fb9a633b4aa23b517c3370d30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nrOfSegments</name>
      <anchorfile>classKDL_1_1Chain.html</anchorfile>
      <anchor>aff6dbd02a5ccefe76eccd001dde4332c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainDynParam</name>
    <filename>classKDL_1_1ChainDynParam.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainDynParam</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>af6e215b8c5f055025cdd90f2b6277c9d</anchor>
      <arglist>(const Chain &amp;chain, Vector _grav)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainDynParam</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a95b95994c188a6d4a5a68e60db5ff667</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToCoriolis</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a616876214cb26793cedeed01e5093b3a</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, JntArray &amp;coriolis)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToMass</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a452ff0523f877bdd62715380553cf106</anchor>
      <arglist>(const JntArray &amp;q, JntSpaceInertiaMatrix &amp;H)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToGravity</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>ad71feeedf84067cd454bd194ddc7656b</anchor>
      <arglist>(const JntArray &amp;q, JntArray &amp;gravity)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a6c8dcaf5fd22bf4da412894633c69ad5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a248a0c0794a78da468fc7275b67c9a77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>nr</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a9d43932d12cd114afa0a4c02d1a376f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a157c9e6fcf96e3b51bcb2373df489934</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>ns</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a6f41b9e2f33019e9b862f3ffdabdb9f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>grav</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a34fd7c51a483b909b23a52a842fd49db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>vectornull</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>aa647c8dd1c229079dba4254a0d8be0a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>jntarraynull</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>ad50f4f1babd15cde6e10cb0d3d3796af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainIdSolver_RNE</type>
      <name>chainidsolver_coriolis</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a0bb02d30307640b2a7e5b7515a98a5a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainIdSolver_RNE</type>
      <name>chainidsolver_gravity</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>aab4dbc3ab38d82fa232c40caf5d45fc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Wrench &gt;</type>
      <name>wrenchnull</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>ad583323f459a4d86f58f088e907ff29f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Frame &gt;</type>
      <name>X</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>abd7f3f79d59ba94f116dd775bc6a06d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Twist &gt;</type>
      <name>S</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a1b6fb4ba6450a97082575cc3e8d727ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; ArticulatedBodyInertia, Eigen::aligned_allocator&lt; ArticulatedBodyInertia &gt; &gt;</type>
      <name>Ic</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a8acdde321a8d59453b0c9a6c7054dbe0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Wrench</type>
      <name>F</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a288400e32926a1e8b95463bda124f1f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>ag</name>
      <anchorfile>classKDL_1_1ChainDynParam.html</anchorfile>
      <anchor>a7ade37f48f85ddcd5c6f836404cd20f7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFdSolver</name>
    <filename>classKDL_1_1ChainFdSolver.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainFdSolver.html</anchorfile>
      <anchor>a1b7e13d5976c271c6765eb4cc0b3794d</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;torques, const Wrenches &amp;f_ext, JntArray &amp;q_dotdot)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a15c4651a994d1c767e14494b37791e79</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFdSolver_RNE</name>
    <filename>classKDL_1_1ChainFdSolver__RNE.html</filename>
    <base>KDL::ChainFdSolver</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainFdSolver_RNE</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a372b45c7456f474deb1c711973b87713</anchor>
      <arglist>(const Chain &amp;chain, Vector grav)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainFdSolver_RNE</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>ae5c2b7ad84422fd4bfe5d4d323826064</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a19016902a70478a43a5e9baf3fbdfc98</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;torques, const Wrenches &amp;f_ext, JntArray &amp;q_dotdot)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a24f475bd6ff51cccb07f78452f8a40ab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>RK4Integrator</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a91da53454dce97e2b9ed4fee6426eac0</anchor>
      <arglist>(unsigned int &amp;nj, const double &amp;t, double &amp;dt, KDL::JntArray &amp;q, KDL::JntArray &amp;q_dot, KDL::JntArray &amp;torques, KDL::Wrenches &amp;f_ext, KDL::ChainFdSolver_RNE &amp;fdsolver, KDL::JntArray &amp;q_dotdot, KDL::JntArray &amp;dq, KDL::JntArray &amp;dq_dot, KDL::JntArray &amp;q_temp, KDL::JntArray &amp;q_dot_temp)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a3cf8d8345cd3870142646d127ab13a5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainDynParam</type>
      <name>DynSolver</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a6baa40d3a37c6d72a06243066577b869</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainIdSolver_RNE</type>
      <name>IdSolver</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>ad5186bb11d180b4dbf381f0c788ea8cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a6929f30dd5d7cbce5b18f97fc7f0d3a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>ns</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a9b6f38818d617113bb0f5b198349722f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntSpaceInertiaMatrix</type>
      <name>H</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a31b2173b3698b06eb30e846e583696c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>Tzeroacc</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a22a9c899d7b5adf8b1fd2b02be1f2cc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>H_eig</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>aeba1201e6e48ac7d1719c9800ba35e3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>Tzeroacc_eig</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a3e03535743050684860a83b77affd4d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>L_eig</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>ad60b86ab846cd0bf326c2ce023365d7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>D_eig</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>a8290c15051e5480f944522410331b92b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>r_eig</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>ae74691a8c44815fc64328ddd57b27d53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>acc_eig</name>
      <anchorfile>classKDL_1_1ChainFdSolver__RNE.html</anchorfile>
      <anchor>acdeae7414ef75b3c3cb7531ebf193c9d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFkSolverAcc</name>
    <filename>classKDL_1_1ChainFkSolverAcc.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverAcc.html</anchorfile>
      <anchor>a81d7e2d955d6a63e44dfa201a68e782c</anchor>
      <arglist>(const JntArrayAcc &amp;q_in, FrameAcc &amp;out, int segmentNr=-1)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverAcc.html</anchorfile>
      <anchor>a79c6939188593b1ed61f0a43dab49c4c</anchor>
      <arglist>(const JntArrayAcc &amp;q_in, std::vector&lt; FrameAcc &gt; &amp;out, int segmentNr=-1)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainFkSolverAcc.html</anchorfile>
      <anchor>aa6d4d5fd0bffcd34e01ec9329e810eb8</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ChainFkSolverAcc</name>
      <anchorfile>classKDL_1_1ChainFkSolverAcc.html</anchorfile>
      <anchor>a15b4753c34d2c53cfc45583befd24c26</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFkSolverPos</name>
    <filename>classKDL_1_1ChainFkSolverPos.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos.html</anchorfile>
      <anchor>aee36d4b6ef10c9776e6cd0c2a105606e</anchor>
      <arglist>(const JntArray &amp;q_in, Frame &amp;p_out, int segmentNr=-1)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos.html</anchorfile>
      <anchor>a3bf2d933b1d7c7b011e84e2c6bd1caea</anchor>
      <arglist>(const JntArray &amp;q_in, std::vector&lt; KDL::Frame &gt; &amp;p_out, int segmentNr=-1)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos.html</anchorfile>
      <anchor>ab45b6f23b4f05e402000af66c7c3d25a</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainFkSolverPos</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos.html</anchorfile>
      <anchor>a68dcdf4c69a6dd3dc9b04f4dfe43bd6a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFkSolverPos_recursive</name>
    <filename>classKDL_1_1ChainFkSolverPos__recursive.html</filename>
    <base>KDL::ChainFkSolverPos</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainFkSolverPos_recursive</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos__recursive.html</anchorfile>
      <anchor>ab710e9b2e4b6e2daa09ef3e139c4554e</anchor>
      <arglist>(const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainFkSolverPos_recursive</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos__recursive.html</anchorfile>
      <anchor>a865a04321e9bf79d56c691445f14d457</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos__recursive.html</anchorfile>
      <anchor>a2b34c9fae293b9866ede9df203ec1fc8</anchor>
      <arglist>(const JntArray &amp;q_in, Frame &amp;p_out, int segmentNr=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos__recursive.html</anchorfile>
      <anchor>a80e2107f662af8783ad0738fcb4b0718</anchor>
      <arglist>(const JntArray &amp;q_in, std::vector&lt; Frame &gt; &amp;p_out, int segmentNr=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos__recursive.html</anchorfile>
      <anchor>add89f7d75ae7c0c971bb958dda01643c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainFkSolverPos__recursive.html</anchorfile>
      <anchor>af6ca8b78affdae1139c732689dba6c7b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFkSolverVel</name>
    <filename>classKDL_1_1ChainFkSolverVel.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel.html</anchorfile>
      <anchor>a7ae7b44890420e9459a3e8da73994edb</anchor>
      <arglist>(const JntArrayVel &amp;q_in, FrameVel &amp;out, int segmentNr=-1)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel.html</anchorfile>
      <anchor>addd81ffa87f3320526d6eae5cd5b00f6</anchor>
      <arglist>(const JntArrayVel &amp;q_in, std::vector&lt; KDL::FrameVel &gt; &amp;out, int segmentNr=-1)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel.html</anchorfile>
      <anchor>ac4390272a86bb3353bf8465150f4c376</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainFkSolverVel</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel.html</anchorfile>
      <anchor>a0f16ca3887783696d1b310adbd36f635</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainFkSolverVel_recursive</name>
    <filename>classKDL_1_1ChainFkSolverVel__recursive.html</filename>
    <base>KDL::ChainFkSolverVel</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainFkSolverVel_recursive</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel__recursive.html</anchorfile>
      <anchor>ad00ad7c025ca439ac6caed3de23cfca2</anchor>
      <arglist>(const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainFkSolverVel_recursive</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel__recursive.html</anchorfile>
      <anchor>adde61a798998341b493b29b7a91ced83</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel__recursive.html</anchorfile>
      <anchor>adacf6fa9df12ab1876859d3296f22400</anchor>
      <arglist>(const JntArrayVel &amp;q_in, FrameVel &amp;out, int segmentNr=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel__recursive.html</anchorfile>
      <anchor>a9426f36b788628088e07013e73ce8302</anchor>
      <arglist>(const JntArrayVel &amp;q_in, std::vector&lt; FrameVel &gt; &amp;out, int segmentNr=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel__recursive.html</anchorfile>
      <anchor>a7c366eee0c84a9c7972eb0988cfacae2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainFkSolverVel__recursive.html</anchorfile>
      <anchor>ae0534c06c0ccbd0e6d374c576c56ac03</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainHdSolver_Vereshchagin</name>
    <filename>classKDL_1_1ChainHdSolver__Vereshchagin.html</filename>
    <base protection="private">KDL::SolverI</base>
    <class kind="struct">KDL::ChainHdSolver_Vereshchagin::segment_info</class>
    <member kind="function">
      <type></type>
      <name>ChainHdSolver_Vereshchagin</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a2c3cf54bd2f3f4a41e682b5fb3850345</anchor>
      <arglist>(const Chain &amp;chain, const Twist &amp;root_acc, const unsigned int nc)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainHdSolver_Vereshchagin</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a7b9751243f1a9be9dabf65da582f514e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a6d48fd72f1e3fa117dba444edb0d5653</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, JntArray &amp;q_dotdot, const Jacobian &amp;alfa, const JntArray &amp;beta, const Wrenches &amp;f_ext, const JntArray &amp;ff_torques, JntArray &amp;constraint_torques)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ac7c90c38d928d5bb337a0098ed7bd743</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getTransformedLinkAcceleration</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>aacddb2d51c10a9f29775306728a621d6</anchor>
      <arglist>(Twists &amp;x_dotdot)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getTotalTorque</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a1ce68d9c9974648498a7e28ab8cebb48</anchor>
      <arglist>(JntArray &amp;total_tau)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getContraintForceMagnitude</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a99676a8e2f3690041e5e609d6808b50e</anchor>
      <arglist>(Eigen::VectorXd &amp;nu_)</arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; Twist &gt;</type>
      <name>Twists</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ae83c1528f9de89ed49de9d6bdcb36b51</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; Frame &gt;</type>
      <name>Frames</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>aa371b4dfcc062fac73a6ff606b207eec</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>Eigen::Matrix&lt; double, 6, 1 &gt;</type>
      <name>Vector6d</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a1843697965a4b576c5de1fdb1a0b9e0f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>Eigen::Matrix&lt; double, 6, 6 &gt;</type>
      <name>Matrix6d</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a46c31b38dc73e613cabb94a6a8dc6cec</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>Eigen::Matrix&lt; double, 6, Eigen::Dynamic &gt;</type>
      <name>Matrix6Xd</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ad7633c8e999db7a29eee10abc215c59e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>initial_upwards_sweep</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>abac5099e549d272e73525fa10145e79c</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;q_dotdot, const Wrenches &amp;f_ext)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>downwards_sweep</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>af1ecda96a43e1bba22628559e6476647</anchor>
      <arglist>(const Jacobian &amp;alfa, const JntArray &amp;ff_torques)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>constraint_calculation</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>aa7141a076a659b749078eb96e32bb643</anchor>
      <arglist>(const JntArray &amp;beta)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>final_upwards_sweep</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a1673eaf57a79e6bb3ef1d009bd9d70e4</anchor>
      <arglist>(JntArray &amp;q_dotdot, JntArray &amp;constraint_torques)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a666f7f03947e8d6af7a6a0f34b187f39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a43c2223d9ab060bc26bfaf0b0c87e9f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>ns</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ac7909354ecaad6b628066de8794b3678</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nc</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a978760871e0c047d8af6d3769b1a5017</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>acc_root</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>aba437b36078a7a5bbdfa2f47528b867b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>alfa_N</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ab02eb0b4e94ebdeab903d27d7d876cf6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>alfa_N2</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a863423828321f8b7c4d3ecac68ca8e6b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>M_0_inverse</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>adb8a0dc3ec545bc9e1dde369908c6bcb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>Um</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ac4bde5d96159b6287e91ebcd71f6806a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>Vm</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>abc5a2daa9a957d31a50da6fa48dd9519</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>beta_N</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ad21a053c569a5e87833dfc54fee2338c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>nu</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ab4acd2baccbe9851a48a8be542f41769</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>nu_sum</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ac7ff4cb952f9a644a9e248e864a10c8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>Sm</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a47b4a7c7b7e12dc6eb44de4921e8588a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>tmpm</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a7bdacc6035db9e281786af0a3f415e29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>total_torques</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a9b951d790bf39fd418208872d390cea4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Wrench</type>
      <name>qdotdot_sum</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a4b56988614de9d28d7e2d736b15802ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>F_total</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a8b7150f6004603becc0426d132db6127</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; segment_info, Eigen::aligned_allocator&lt; segment_info &gt; &gt;</type>
      <name>results</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a0d3bc25675c2118627ee86e1dd47d09b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIdSolver</name>
    <filename>classKDL_1_1ChainIdSolver.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIdSolver.html</anchorfile>
      <anchor>a1a226b8bc3c23fc8ce499b9c96fde149</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;q_dotdot, const Wrenches &amp;f_ext, JntArray &amp;torques)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a15c4651a994d1c767e14494b37791e79</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIdSolver_RNE</name>
    <filename>classKDL_1_1ChainIdSolver__RNE.html</filename>
    <base>KDL::ChainIdSolver</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIdSolver_RNE</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a1c7883e126beaa34a226f5bb71d35739</anchor>
      <arglist>(const Chain &amp;chain, Vector grav)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIdSolver_RNE</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a3e0bb2147c9cede51e81a7c3f55c4b37</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a517c0314490c32848e2b8e29ecac997e</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;q_dotdot, const Wrenches &amp;f_ext, JntArray &amp;torques)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>aa939c7f6490b216cf7c89f72d4a114b8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a50600a7551d4b4f1b7736049b7b5fad6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a8857dd1a3df9c62c96d7d1394c080804</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>ns</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a771c49e2932feefda2bd3fffdc11a22f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Frame &gt;</type>
      <name>X</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a8f08f7e5feb7774179323c0fcf037f87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Twist &gt;</type>
      <name>S</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a3e65f55c116e066f6f8309283c60c20f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Twist &gt;</type>
      <name>v</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>ad0c5e30eff13458d667fd30ca8a9b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Twist &gt;</type>
      <name>a</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>ab604785f1c7630a708fe23fe0a8ebe29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; Wrench &gt;</type>
      <name>f</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a378a04bd68be517db50497ea2527746a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>ag</name>
      <anchorfile>classKDL_1_1ChainIdSolver__RNE.html</anchorfile>
      <anchor>a6c214b3ae84ab3c013105054106fbb2e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIdSolver_Vereshchagin</name>
    <filename>classKDL_1_1ChainIdSolver__Vereshchagin.html</filename>
    <base>KDL::ChainHdSolver_Vereshchagin</base>
    <member kind="function">
      <type></type>
      <name>ChainIdSolver_Vereshchagin</name>
      <anchorfile>classKDL_1_1ChainIdSolver__Vereshchagin.html</anchorfile>
      <anchor>a6f00fe0088b3e04139c8139164571cdb</anchor>
      <arglist>(const Chain &amp;chain, const Twist &amp;root_acc, const unsigned int nc)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a6d48fd72f1e3fa117dba444edb0d5653</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, JntArray &amp;q_dotdot, const Jacobian &amp;alfa, const JntArray &amp;beta, const Wrenches &amp;f_ext, const JntArray &amp;ff_torques, JntArray &amp;constraint_torques)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>ac7c90c38d928d5bb337a0098ed7bd743</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getTransformedLinkAcceleration</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>aacddb2d51c10a9f29775306728a621d6</anchor>
      <arglist>(Twists &amp;x_dotdot)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getTotalTorque</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a1ce68d9c9974648498a7e28ab8cebb48</anchor>
      <arglist>(JntArray &amp;total_tau)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getContraintForceMagnitude</name>
      <anchorfile>classKDL_1_1ChainHdSolver__Vereshchagin.html</anchorfile>
      <anchor>a99676a8e2f3690041e5e609d6808b50e</anchor>
      <arglist>(Eigen::VectorXd &amp;nu_)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverAcc</name>
    <filename>classKDL_1_1ChainIkSolverAcc.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverAcc.html</anchorfile>
      <anchor>a3734dea5b9ecaa2712dbc2fb70f121cc</anchor>
      <arglist>(const JntArray &amp;q_in, const JntArray &amp;qdot_in, const Twist a_in, JntArray &amp;qdotdot_out)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartTojnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverAcc.html</anchorfile>
      <anchor>aa8d83c3c404f7546f2e428d2bce43e4d</anchor>
      <arglist>(const JntArray &amp;q_init, const FrameAcc &amp;a_in, JntArrayAcc &amp;q_out)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverAcc.html</anchorfile>
      <anchor>a8611376206bbf0061ee1ad016e8f08d5</anchor>
      <arglist>(const JntArray &amp;q_in, const Twist &amp;v_in, const Twist &amp;a_in, JntArray &amp;qdot_out, JntArray &amp;qdotdot_out)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartTojnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverAcc.html</anchorfile>
      <anchor>ac4b6b4d3cada06f050aec6e7aaf0f28d</anchor>
      <arglist>(const JntArray &amp;q_init, const Frame &amp;p_in, const JntArray &amp;qdot_in, const Twist &amp;a_in, JntArray &amp;q_out, JntArray &amp;qdotdot_out)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverAcc.html</anchorfile>
      <anchor>adcf69e260d86f8416469a0edad4683f9</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainIkSolverAcc</name>
      <anchorfile>classKDL_1_1ChainIkSolverAcc.html</anchorfile>
      <anchor>a797ce72522bd3bcb303581806c0afff9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverPos</name>
    <filename>classKDL_1_1ChainIkSolverPos.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos.html</anchorfile>
      <anchor>a4781229863bfda0a6ebb6e6768fa2033</anchor>
      <arglist>(const JntArray &amp;q_init, const Frame &amp;p_in, JntArray &amp;q_out)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainIkSolverPos</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos.html</anchorfile>
      <anchor>a4a2d89c5b79458f55ed0248f12e5d785</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos.html</anchorfile>
      <anchor>a96d3d8e3edd4ad51da1237c8fb11f98d</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverPos_LMA</name>
    <filename>classKDL_1_1ChainIkSolverPos__LMA.html</filename>
    <base>KDL::ChainIkSolverPos</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverPos_LMA</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a5322326848d618e0ec2af8683344274e</anchor>
      <arglist>(const KDL::Chain &amp;_chain, const Eigen::Matrix&lt; double, 6, 1 &gt; &amp;_L, double _eps=1E-5, int _maxiter=500, double _eps_joints=1E-15)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverPos_LMA</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a1e83b8d5bb692211d4216e491253afa4</anchor>
      <arglist>(const KDL::Chain &amp;_chain, double _eps=1E-5, int _maxiter=500, double _eps_joints=1E-15)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a51e0cd14d0b764eab96150ca868a1346</anchor>
      <arglist>(const KDL::JntArray &amp;q_init, const KDL::Frame &amp;T_base_goal, KDL::JntArray &amp;q_out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainIkSolverPos_LMA</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>af0f67544c22164785fe757a5ff0cc794</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>compute_fwdpos</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ab33b1610b326104dff16cb45bada3825</anchor>
      <arglist>(const VectorXq &amp;q)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>compute_jacobian</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a0a0a7f86ca5aa3406f36d6f32f272c7b</anchor>
      <arglist>(const VectorXq &amp;q)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>display_jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ae0278b1db83ccc223b696cd131b8cd99</anchor>
      <arglist>(const KDL::JntArray &amp;jval)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a068a7af864c449f5053e3ba528c849fb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a77ef2ace32163f2ccf89f94279cbd1cb</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>lastNrOfIter</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ab6a344ef0c94d6320d7a86ec136d23da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>lastDifference</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ab149fda24b8e6b2699e4f59eef9ec646</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>lastTransDiff</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a95ed8c825ba467640ddc258c02ed4c61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>lastRotDiff</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ae591ad3c9c8d84905e274874f56fe4b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>VectorXq</type>
      <name>lastSV</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a9632701d5faf0fff25fa1af51cc22a5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MatrixXq</type>
      <name>jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>adedd8324f75d411a1e97812069ea9836</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>VectorXq</type>
      <name>grad</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>aedff5af51355728570ec59a4e7368418</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>KDL::Frame</type>
      <name>T_base_head</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a4a45ccb2451c711fe094b68827034959</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>display_information</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a50e76a385d6918aa5e5ebf4b6b7a65db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_GRADIENT_JOINTS_TOO_SMALL</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a5a5349f540a8c42507366efa925531fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_INCREMENT_JOINTS_TOO_SMALL</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a2a0f8f310630786737828d54a8367cbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>double</type>
      <name>ScalarType</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>afa904aaecee51dc2210eb3738424d3dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>Eigen::Matrix&lt; ScalarType, Eigen::Dynamic, Eigen::Dynamic &gt;</type>
      <name>MatrixXq</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>aeb0d8a81d41ee6f93c92d730efe7c4b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>Eigen::Matrix&lt; ScalarType, Eigen::Dynamic, 1 &gt;</type>
      <name>VectorXq</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>aca5baea165045f93ab97be80ed7a1274</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const KDL::Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a752dac11f5eddf2c1daae7ec098881d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ad8dfd3919639a87cf4845f29caf7ab56</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>ns</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ac15c790d1170e6f3bca0ab4c1b378a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a7b6cff87a7e815405c7e666e6a48219c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ac8f587341eeefb5c5ae3de38f6f87a54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps_joints</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ab355dbfff6b4d3dde78e1400bcad2152</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::Matrix&lt; ScalarType, 6, 1 &gt;</type>
      <name>L</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>ab39b5377dfa7f9087394d4906e58597d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; KDL::Frame &gt;</type>
      <name>T_base_jointroot</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a7d18b8cfd0574d0f7db6af97bcaab175</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; KDL::Frame &gt;</type>
      <name>T_base_jointtip</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a9a6e6491e2480c834d3e78fc5a75e17d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXq</type>
      <name>q</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a7a99e6911345a16636044f7af1802731</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXq</type>
      <name>A</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a3a7dd394362823016aed4fc5dc919530</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXq</type>
      <name>tmp</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a9a50fd4b93f12f5e2937a04c544147a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::LDLT&lt; MatrixXq &gt;</type>
      <name>ldlt</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a4323e934aab8948824ecd648d435d1f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::JacobiSVD&lt; MatrixXq &gt;</type>
      <name>svd</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a6e1c8f67cda26c94fedd04ffcd96617a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXq</type>
      <name>diffq</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a7537185c87fce950f7370b6214062f2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXq</type>
      <name>q_new</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>aa583631b1f436dbd68b3be6e5ba2f628</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXq</type>
      <name>original_Aii</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__LMA.html</anchorfile>
      <anchor>a1afe0da18a08de6a38867eeac55c18bf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverPos_NR</name>
    <filename>classKDL_1_1ChainIkSolverPos__NR.html</filename>
    <base>KDL::ChainIkSolverPos</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverPos_NR</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a440a63b376afea02177976d6ba1215c8</anchor>
      <arglist>(const Chain &amp;chain, ChainFkSolverPos &amp;fksolver, ChainIkSolverVel &amp;iksolver, unsigned int maxiter=100, double eps=1e-6)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIkSolverPos_NR</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a3d4fe303f37a14707409835af989677e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a3058bdb9e57a4b9e20672ac30fdfb010</anchor>
      <arglist>(const JntArray &amp;q_init, const Frame &amp;p_in, JntArray &amp;q_out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>ac0b74cb167e5c2d4b98ddcb2f6955121</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a5f3f444352531e50a84f73686e01cf03</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_IKSOLVER_FAILED</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>ac193008c361ff47424dd409e8ebb0152</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_FKSOLVERPOS_FAILED</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a11eae64a2f44ec930d453ed05073e30d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>ae6e74fdeacb15ad26d2a8c39a3f4996f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a161a8c657fbdb29d20b8dafe0190a40c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainIkSolverVel &amp;</type>
      <name>iksolver</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a0dd624bad4749b77f1b3eebb3cc66d34</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainFkSolverPos &amp;</type>
      <name>fksolver</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>afb2f408cf5360a4115c3cb88c838536e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>delta_q</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a2aaa4a6dfd4b3c3efa03cb6c24bb1f3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>f</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a8ee37f9951e05b6434246f7e07f05ba4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>delta_twist</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a698d98530e2657af531dcf1e3f7ced8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a08222d875940fa2a11c10dca4013d309</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR.html</anchorfile>
      <anchor>a1f4b7b8b458faf671a35346e452af8fd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverPos_NR_JL</name>
    <filename>classKDL_1_1ChainIkSolverPos__NR__JL.html</filename>
    <base>KDL::ChainIkSolverPos</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverPos_NR_JL</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a5f6d22a47659005408dce6ae0937f7e1</anchor>
      <arglist>(const Chain &amp;chain, const JntArray &amp;q_min, const JntArray &amp;q_max, ChainFkSolverPos &amp;fksolver, ChainIkSolverVel &amp;iksolver, unsigned int maxiter=100, double eps=1e-6)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverPos_NR_JL</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a6a27998f8c7b192e8d96cbfd86c6f2bd</anchor>
      <arglist>(const Chain &amp;chain, ChainFkSolverPos &amp;fksolver, ChainIkSolverVel &amp;iksolver, unsigned int maxiter=100, double eps=1e-6)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIkSolverPos_NR_JL</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a355b700bc0d01b78e89d21270f1ccc1d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a094de2ebc84cf280e1d91ffe30d7a6d4</anchor>
      <arglist>(const JntArray &amp;q_init, const Frame &amp;p_in, JntArray &amp;q_out)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setJointLimits</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a16b77d84d199b46f9b32e3fbc029cef4</anchor>
      <arglist>(const JntArray &amp;q_min, const JntArray &amp;q_max)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a9f1d384cbdbc99735678726213249147</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>ac07452dccc8f5dbb3bcdab73cdfb9135</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_IKSOLVERVEL_FAILED</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>ad7bdb5a09cf7d7bb52cf54285aa3dc26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_FKSOLVERPOS_FAILED</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a536f08455ba9a6ac5bc08270ee78abd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>af00d183da3d0376247cfa8c62c2b6242</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a3d693cfdbcbe0a663d29507d78d7310a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_min</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a0c48be47a5c2130e929ecb7387cb40ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_max</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a5ec92669ab13a55fd3f22efe792a5d71</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainIkSolverVel &amp;</type>
      <name>iksolver</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a1aebc3f8cfb5dbc46e1137336add6e03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainFkSolverPos &amp;</type>
      <name>fksolver</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>af8067f9ad019c6516a4de02c4b568ce0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>delta_q</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a2e8e1b59a2e6353b16aa93fa80efb46e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a87778230ac30a939e34140391555cfcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>aed9343d6e09182074bace3947d1cc48f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>f</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>ab7e2a467763624c824a4d77486f7a8aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>delta_twist</name>
      <anchorfile>classKDL_1_1ChainIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a8c61c2bfa6dcfbd8cda02bf2a9f8ff42</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverVel</name>
    <filename>classKDL_1_1ChainIkSolverVel.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel.html</anchorfile>
      <anchor>a761853db487c901485737c6334953cbe</anchor>
      <arglist>(const JntArray &amp;q_in, const Twist &amp;v_in, JntArray &amp;qdot_out)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel.html</anchorfile>
      <anchor>a50009426df14377d417396596dc48c2a</anchor>
      <arglist>(const JntArray &amp;q_init, const FrameVel &amp;v_in, JntArrayVel &amp;q_out)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainIkSolverVel</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel.html</anchorfile>
      <anchor>ad9499ad2dfd55a21ae6e3ecf233e49be</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel.html</anchorfile>
      <anchor>a174a1c69f3a2ffca72de3448311e93e5</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverVel_pinv</name>
    <filename>classKDL_1_1ChainIkSolverVel__pinv.html</filename>
    <base>KDL::ChainIkSolverVel</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverVel_pinv</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a3a8f66b7d3c05ec2f0bcccbd7790f401</anchor>
      <arglist>(const Chain &amp;chain, double eps=0.00001, int maxiter=150)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIkSolverVel_pinv</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a6b84a108236d152c1aa3e8d42bab4df8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a202bae1336d36647917b761ee8d5f7ea</anchor>
      <arglist>(const JntArray &amp;q_in, const Twist &amp;v_in, JntArray &amp;qdot_out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a1a61506b8dc256e52a6c924987014eac</anchor>
      <arglist>(const JntArray &amp;, const FrameVel &amp;, JntArrayVel &amp;)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNrZeroSigmas</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a11d9df2fdfea7c7d616298c907ce672a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getSVDResult</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a3e5125ad0249c6b0227b687f5b269ece</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>abc41e45b6a29f461755e2aa9ffd70b56</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>adfbf3b47f5f4aaf94df885adac06cad1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_CONVERGE_PINV_SINGULAR</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a5c3646dc5104390e7d6a92490b2785e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>ae15d4865aa87eed56119383e285b15f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainJntToJacSolver</type>
      <name>jnt2jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a5a5db8bae9e8d072f38e6d099b24ac3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a25bdc9ae589ead9552edcfca97dc4d04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a791d302c1b7c9ff069cc95753e545372</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>SVD_HH</type>
      <name>svd</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a448317e52547e8113d460c00c90e5425</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; JntArray &gt;</type>
      <name>U</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a066f9a8b464e5dd5a9ab49e3b72d43e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>S</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a9fe563b395d48ce3bbd9b80a4fee485f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; JntArray &gt;</type>
      <name>V</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a4d223e586714627dd109b3072d7d6ea5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>tmp</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a77b203bedac04433f540562bfe091a1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a899ca50575fa2174bb72f8df7a054cd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>aecff45cca9a71c1f9d05b667e745440c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nrZeroSigmas</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>a1770935b3f28015b17e9a2e6c84ec438</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>svdResult</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv.html</anchorfile>
      <anchor>adc14c8852cd3c9d5e8a3e14d1832f081</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverVel_pinv_givens</name>
    <filename>classKDL_1_1ChainIkSolverVel__pinv__givens.html</filename>
    <base>KDL::ChainIkSolverVel</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverVel_pinv_givens</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a634cddcea313935d38568c25378d05d8</anchor>
      <arglist>(const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIkSolverVel_pinv_givens</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a5ca0d15a30e3e262809203289403556a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a3d19e3f2e36a0e82c44d139f1056065b</anchor>
      <arglist>(const JntArray &amp;q_in, const Twist &amp;v_in, JntArray &amp;qdot_out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a974fa7445ea3ef08aabe4728d94b0684</anchor>
      <arglist>(const JntArray &amp;, const FrameVel &amp;, JntArrayVel &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a993d8e4233b7e1095b3ee2d11c40c335</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a68828eeac014f09fdd8d52e35d364010</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a76aeb1dd6f4ed93f73e8a95bf5c541f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainJntToJacSolver</type>
      <name>jnt2jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a34c673857f6db67e6f960990e1311fd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a7861a56b9728a16cbc7552338a0de402</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>transpose</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a5caf0d5fbacb39092375fcb2e2a8ac91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>toggle</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>aea62a3f8460801916f34096744281ea0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>m</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>ab57a8928e936c89544f26db52f7a10cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>n</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a6be933ca68b854f62a01be30eb7c4b11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>jac_eigen</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a52b89e73b049024b57b3cd67b16cde5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>U</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>aec5477f7d30d6d61bcfb11a089f063ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>V</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>ab5c73f2986cfd0c2b7c9228da6f13f43</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>B</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a314406294c61cf668354f5343a82326a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>S</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a150e31eaf047200f44f8438b719c2784</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>tempi</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a21a481e1d00e6cce469f7bab363ebcea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>UY</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a00fb3fb2d42ce83cf7b3b60e0d11982c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>SUY</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a9f45914b1da396fc1fe3c8aaf74499b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>qdot_eigen</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>a022fd0b3ab094d1d71ac698a3f0e4ee2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>v_in_eigen</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__givens.html</anchorfile>
      <anchor>ad915b6d48edf32e61a742c76ce9bc878</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverVel_pinv_nso</name>
    <filename>classKDL_1_1ChainIkSolverVel__pinv__nso.html</filename>
    <base>KDL::ChainIkSolverVel</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverVel_pinv_nso</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>ae0d17b252323699610b74a250ff09d5c</anchor>
      <arglist>(const Chain &amp;chain, const JntArray &amp;opt_pos, const JntArray &amp;weights, double eps=0.00001, int maxiter=150, double alpha=0.25)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverVel_pinv_nso</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a782d6678dd98605ca178310e6ad56246</anchor>
      <arglist>(const Chain &amp;chain, double eps=0.00001, int maxiter=150, double alpha=0.25)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIkSolverVel_pinv_nso</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a02787f977861b038ceef4f32c4a9877e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>ae4689c53089eb8af85e347d5f61b3892</anchor>
      <arglist>(const JntArray &amp;q_in, const Twist &amp;v_in, JntArray &amp;qdot_out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a0c893be2870d7f45f29f82e1f368c62b</anchor>
      <arglist>(const JntArray &amp;, const FrameVel &amp;, JntArrayVel &amp;)</arglist>
    </member>
    <member kind="function">
      <type>const JntArray &amp;</type>
      <name>getWeights</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>abb87b0d61e0671cf03d353a79518e421</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const JntArray &amp;</type>
      <name>getOptPos</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a9726304f56b8871396fe3b52d5f4dac8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>getAlpha</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a49bf4fd25e094b69c31d792f62381d66</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setWeights</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a991d5587fc51207edbc64671b3881dc0</anchor>
      <arglist>(const JntArray &amp;weights)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setOptPos</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>ac287e0c600fe7c5996dcbfc33d4ee179</anchor>
      <arglist>(const JntArray &amp;opt_pos)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setAlpha</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a39822145e8cc1f2a19d8b26992eeb813</anchor>
      <arglist>(const double alpha)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getSVDResult</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a127ea4e79964bba9a7158d26ab3402ae</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a24f21a9fef5411449552a63c60e883ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a75f9ccf75108f77d38006f09d986336b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainJntToJacSolver</type>
      <name>jnt2jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>ac752dfe139e7664ed9daec3b8d145122</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>aac97b5b29cd2c0460d994833251fad94</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a41ef166e218c34462d0fba63adc3de68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>U</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a04ee8f8628a0502e66170c24e1bb5480</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>S</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a38f3ed38ed51e14eac4e47a7e3257831</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>Sinv</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a6aa8b73e4302b5fcb3db57a9030350f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>V</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a701b7cf4edccbfa6c26df77cfacff1a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>tmp</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>adaaafbd3ab16cf560a0da3c95bb83e74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>tmp2</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>aa26ebe9eaa06220805531cbf4f0187d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a5ceb8e516a333c98238aef4b55405b44</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>aea2ecb76d7c8c37588dbde28cb44accc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>svdResult</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a4b738b6c252bc400235a6c50f747754c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>alpha</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a481678f2e0633a23204b960a3caa2ddf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>weights</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a8b862ea7815eabf1ba1b174e266f8c8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>opt_pos</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__pinv__nso.html</anchorfile>
      <anchor>a247baf9ceb404ccf0cc101405150df05</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainIkSolverVel_wdls</name>
    <filename>classKDL_1_1ChainIkSolverVel__wdls.html</filename>
    <base>KDL::ChainIkSolverVel</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainIkSolverVel_wdls</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ab4595a4bfb75e1b941c37ffc226d24e4</anchor>
      <arglist>(const Chain &amp;chain, double eps=0.00001, int maxiter=150)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ChainIkSolverVel_wdls</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a19e3463732c52875823df1380c5cd5e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a3076f9888b9e3905abbadf37cfa0e692</anchor>
      <arglist>(const JntArray &amp;q_in, const Twist &amp;v_in, JntArray &amp;qdot_out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>aa4ffe2d3d6d1d015b4a0fdf3dcc48ec1</anchor>
      <arglist>(const JntArray &amp;, const FrameVel &amp;, JntArrayVel &amp;)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setWeightJS</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>af8176314e82309489e4087888d488acd</anchor>
      <arglist>(const Eigen::MatrixXd &amp;Mq)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setWeightTS</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ae1b05a989d6e0fb29fa763a24d9e112c</anchor>
      <arglist>(const Eigen::MatrixXd &amp;Mx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLambda</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>aae31a982ea6a043a37592329cc51fab4</anchor>
      <arglist>(const double lambda)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEps</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ac0671b5612e17c1bbe942ab591159607</anchor>
      <arglist>(const double eps_in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMaxIter</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a4c4e3125e980f4085c6c9f96fffad231</anchor>
      <arglist>(const int maxiter_in)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNrZeroSigmas</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ab27c3a6690943b78673b386884794a65</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getSigmaMin</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a44685c39e2cc8e65c3565fdaadb96a75</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getSigma</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a80147eb86301b71df08d450855d78d4b</anchor>
      <arglist>(Eigen::VectorXd &amp;Sout)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getEps</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a3a9c88ff9df9e99b41bae1128d6d3c3c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLambda</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a9a2d3d473c84e0ae952f2d72db5cb9c7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLambdaScaled</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>afc24c8c3e751a2e663080b00924bc9a9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getSVDResult</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a212013a7540fad2921d1fa847709b566</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a233d66f30b218edff6619c7aa21aec17</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a30247d462ff6438cd6fb1d552c9866a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_CONVERGE_PINV_SINGULAR</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a740d84e22565a0fcf73dd834e4152fbf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a740ab879917a5a23997a4a77198a0c20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainJntToJacSolver</type>
      <name>jnt2jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a8796ef16f6cd2830e3a43c9eb8ff88e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a021ceab3f844d7900134cd4ccb2a28bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ac9299ef563ec5815499f2c35ce0b883e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>U</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a89fd8e0a34b6c574efed0a9141489417</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>S</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ad94b2a63197896582aad47602c5b084d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>V</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ac1c7f7091da0a3b419399b9944ca5dc7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a7bf9cd814386299d25aa3568d27072ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ad0f5514e9e2a16f08fee14c88036c18f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>tmp</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ac1cb14a25dbe53fa78a4b7c2b278292f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>tmp_jac</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>aefd27c642fc0e793a18e9cdac6cf3ac2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>tmp_jac_weight1</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ae9fba66e3d579e64d3f565a8445225f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>tmp_jac_weight2</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>aa8214cd2b7a4c3975dc349866616a2cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>tmp_ts</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a42647f11371d7c5321c177f17091ab46</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>tmp_js</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a01d81182077b1106dd5f3e7557f769f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>weight_ts</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ab3f86f99a1660a8eddbfa325f83d8c31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::MatrixXd</type>
      <name>weight_js</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>ab90f39f954fbd6ba7c342c556bf069e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>lambda</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>aeba04bde651f4277dad25c8955cd69ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>lambda_scaled</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>af175343fb975a5c945ff8685d757112a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nrZeroSigmas</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a363e75fec6563ede5b459e1f031c592d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>svdResult</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a3a2889789ba0f8a625ec5046a1a7f6c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>sigmaMin</name>
      <anchorfile>classKDL_1_1ChainIkSolverVel__wdls.html</anchorfile>
      <anchor>a06bcbfed8887292f167934f920dd40ed</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainJntToJacDotSolver</name>
    <filename>classKDL_1_1ChainJntToJacDotSolver.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainJntToJacDotSolver</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a6e8ea7ebcb030b3e0140659ae2094b4f</anchor>
      <arglist>(const Chain &amp;chain)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainJntToJacDotSolver</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a9b33fa8fd0c7427630d0a55a6267584a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToJacDot</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>ad284ffc96433e7b7bed652a5c564f8ea</anchor>
      <arglist>(const KDL::JntArrayVel &amp;q_in, KDL::Twist &amp;jac_dot_q_dot, int seg_nr=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToJacDot</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a6beff18ae53f28bc7d2fb179861ad1b2</anchor>
      <arglist>(const KDL::JntArrayVel &amp;q_in, KDL::Jacobian &amp;jdot, int seg_nr=-1)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setLockedJoints</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aabaacbf786f2212310a098382e2940a5</anchor>
      <arglist>(const std::vector&lt; bool &gt; &amp;locked_joints)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setHybridRepresentation</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a4372a1110d73e8d06f8fc3b9af3d7a69</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBodyFixedRepresentation</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a9c8dca1d13a07c64e36f8e36469f6457</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setInertialRepresentation</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a63c2d4f4371ab083edc9ddbf5e1b94fb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRepresentation</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>ad7d9701ed8822d9c40ce514ff007eb75</anchor>
      <arglist>(const int &amp;representation)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>abf33f1cf45e7c3f97bb12f7f2a370c4a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a639902ebdacd0369dd3c16252cf27f2f</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_JAC_DOT_FAILED</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a8980dab80c64840a11d602e53707daa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_JACSOLVER_FAILED</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>ac3c1e2d331dbf315bde5b25a5a9cfc6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_FKSOLVERPOS_FAILED</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a318ac0b1007631044138f5d7b807c175</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>HYBRID</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a7b5110209dd98908ca1ae355689204c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>BODYFIXED</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aba6343c8e3e3e70de9cdaa9184cddfd6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>INERTIAL</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aca8a0d514a2e5c199e29c4b84d220d4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const Twist &amp;</type>
      <name>getPartialDerivativeHybrid</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a8d31da39b18d4bf3c9197534156c0c81</anchor>
      <arglist>(const Jacobian &amp;bs_J_ee, const unsigned int &amp;joint_idx, const unsigned int &amp;column_idx)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const Twist &amp;</type>
      <name>getPartialDerivativeBodyFixed</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a943afe70e6e32efaf9b00a3ba055321b</anchor>
      <arglist>(const Jacobian &amp;ee_J_ee, const unsigned int &amp;joint_idx, const unsigned int &amp;column_idx)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const Twist &amp;</type>
      <name>getPartialDerivativeInertial</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>adb260c52adf1352f5a68f83653dbc1a5</anchor>
      <arglist>(const Jacobian &amp;bs_J_bs, const unsigned int &amp;joint_idx, const unsigned int &amp;column_idx)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const Twist &amp;</type>
      <name>getPartialDerivative</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a3ca412ce22cc43d0c29074ea3d6dead3</anchor>
      <arglist>(const Jacobian &amp;J, const unsigned int &amp;joint_idx, const unsigned int &amp;column_idx, const int &amp;representation)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aae2072e7941a3874c24576b0419d0919</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; bool &gt;</type>
      <name>locked_joints_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a6b68fea4bd837439b2b5576a923cbbbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nr_of_unlocked_joints_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aea8055f196acca134904e5c252385f42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainJntToJacSolver</type>
      <name>jac_solver_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a1fb4d45f66ae0aaebdc8b8916ea483e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>jac_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a0e97f9d3be506761ccd1b2e4b7541fd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobian</type>
      <name>jac_dot_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a9d0aadc2dd39d3c4198c70b8f74b87a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>representation_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a9a3aef34edef230b83c565dd70f02757</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ChainFkSolverPos_recursive</type>
      <name>fk_solver_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a531b90990545a6b4df2c7f42e4803ecc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>F_bs_ee_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>abd68f0dc06252e866905de7d0d9de453</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>jac_dot_k_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>a12e45bede97e7b44f586dd7e095a14b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>jac_j_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>afc0ce448f418efcb63debb1c6bcf73bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>jac_i_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aca1112d1b9f02a41110ec1dfebb68f25</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>t_djdq_</name>
      <anchorfile>classKDL_1_1ChainJntToJacDotSolver.html</anchorfile>
      <anchor>aab717bfd92e0dae8bf685153429d1c06</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::ChainJntToJacSolver</name>
    <filename>classKDL_1_1ChainJntToJacSolver.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ChainJntToJacSolver</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>ab4d12f62a2319ce069c5ef364238f5b3</anchor>
      <arglist>(const Chain &amp;chain)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ChainJntToJacSolver</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a1a9341a35f41bc6263678b1bcf4d4046</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToJac</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a1e714cdb2b915a9774fe7e0eafd4b8f9</anchor>
      <arglist>(const JntArray &amp;q_in, Jacobian &amp;jac, int seg_nr=-1)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setLockedJoints</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a3f1db6899335862a2ee048fc117a0c5a</anchor>
      <arglist>(const std::vector&lt; bool &gt; locked_joints)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a8c6fe8ec5cd73c65699143e4a5df9bef</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Chain &amp;</type>
      <name>chain</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a31bcea17d64bc7715ca109f60adb050a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>t_tmp</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>afdcf524848d4927f21f284b0056bf97f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>T_tmp</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a8786385514e5251fa3858dddce475ee2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; bool &gt;</type>
      <name>locked_joints_</name>
      <anchorfile>classKDL_1_1ChainJntToJacSolver.html</anchorfile>
      <anchor>a86f73d126e2b3042cb6a09015fd7c2aa</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Frame</name>
    <filename>classKDL_1_1Frame.html</filename>
    <member kind="function">
      <type></type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a7583694e3ea56e0edecbd9d02aa4a3e0</anchor>
      <arglist>(const Rotation &amp;R, const Vector &amp;V)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>afb8da9aa2cc86a2082cbd469067bbcca</anchor>
      <arglist>(const Vector &amp;V)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>aba40e19275ca4ddd13bd8e05eadc8320</anchor>
      <arglist>(const Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>af2f3fe6d30be4717eb0a4a74bc4bb444</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a290d44405783f7854611ac082a63bdd4</anchor>
      <arglist>(const Frame &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Make4x4</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a4109f8e1cd1e48bb957de4ef6796bea2</anchor>
      <arglist>(double *d)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>ade9b0946226f7cea4aa0e30650119b79</anchor>
      <arglist>(int i, int j)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>afdea2b0e23f712757d2e7fbad95e3440</anchor>
      <arglist>(int i, int j) const</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>ac508fa4e7c59527f8f377a3c6c225d12</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>adcf60bbe39270e84a8fe664e3e17f73a</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>ae9eeb43943d237da3116b142d209d9ec</anchor>
      <arglist>(const Wrench &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>abf87d299d64beaa06e2903ee9983d244</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Frame &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a68eeae7af154df2a649ed09b6043f663</anchor>
      <arglist>(const Frame &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>aa5bf6ef398b04a482ac5fdbbd35c7c06</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a021bab736839bc1c655619beb209cc66</anchor>
      <arglist>(const Wrench &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a402eea637834d2643c67da1a5f1fe495</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Integrate</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a67ad926d5d8cc58d6feace213708de5f</anchor>
      <arglist>(const Twist &amp;t_this, double frequency)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Frame</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a21cc8438f71b522154d2ef4cd6933d69</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Frame</type>
      <name>DH_Craig1989</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a0185c3081fd5459ae0a6081bf6fd5474</anchor>
      <arglist>(double a, double alpha, double d, double theta)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Frame</type>
      <name>DH</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a80ee82a53ab3ceb0aa79b7b5892a14eb</anchor>
      <arglist>(double a, double alpha, double d, double theta)</arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>p</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>abc00c3817f7baa985b67077479617866</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Rotation</type>
      <name>M</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a367668b3344ccfd50410ccc1ed30fa6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Frame</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>adb5d8e64590ce61d0ea8fb91a24f674c</anchor>
      <arglist>(const Frame &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>aae3c1055b58bbe6a9c6c64eea6a11552</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>a98b80cd709a822855103e3a621bd885a</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Frame.html</anchorfile>
      <anchor>af66428b996121af486bf990048360ebf</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Frame2</name>
    <filename>classKDL_1_1Frame2.html</filename>
    <member kind="function">
      <type></type>
      <name>Frame2</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a6c00703a027780ab480b73292ed2d594</anchor>
      <arglist>(const Rotation2 &amp;R, const Vector2 &amp;V)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame2</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a715a2d3497e2bedc6c4117613bce297e</anchor>
      <arglist>(const Vector2 &amp;V)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame2</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>aabf1e7b7243dcdd66c1a38a55ff39d9d</anchor>
      <arglist>(const Rotation2 &amp;R)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame2</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a9d63ecf2ea17d40317e462650860ff16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Frame2</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a528fc3652c18efe3f89eaf7ce4724129</anchor>
      <arglist>(const Frame2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Make4x4</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>acab15e245c3fd8148a7a999611a37c61</anchor>
      <arglist>(double *d)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a60dcde9c649b001f9a56526ee6f793fa</anchor>
      <arglist>(int i, int j)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a4c8a0be6804d748370e5d77cbe601990</anchor>
      <arglist>(int i, int j) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetInverse</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>ac59dfa60bfd38d03a49343ce068b6ddb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Frame2</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>af9db6979bec9cc9b2ae889e65e95cd8a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector2</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a4ed60a07cda019ce7fdb90c3daffedd8</anchor>
      <arglist>(const Vector2 &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Frame2 &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a899a0738adfe9342fc3a2d6110a6730c</anchor>
      <arglist>(const Frame2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a4bd2f662b762feedc4869c3fc7167e7b</anchor>
      <arglist>(const Vector2 &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetIdentity</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a37809903d37cf549d110ce10e71b3ee9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Integrate</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a8d62ebe6b0cc152806a95a0412981c4f</anchor>
      <arglist>(const Twist &amp;t_this, double frequency)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Frame2</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a892d5dcb5d4580f0b42b25f2fd892f9f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Vector2</type>
      <name>p</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>ac53f050e83f8fa87267bdc194cb68d7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Rotation2</type>
      <name>M</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>ab77981911496a659b7fa878886dbe40b</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Frame2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>a817c85ff90cc5343bba9839f25ccd6e4</anchor>
      <arglist>(const Frame2 &amp;lhs, const Frame2 &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Frame2.html</anchorfile>
      <anchor>abb8f48e53e1905e29aa699228bed05b8</anchor>
      <arglist>(const Frame2 &amp;a, const Frame2 &amp;b, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::FrameAcc</name>
    <filename>classKDL_1_1FrameAcc.html</filename>
    <member kind="function">
      <type></type>
      <name>FrameAcc</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ad26c65d1089e074b4a3995639324ff2f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FrameAcc</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a6ea1a2d74e50f531398070657691d227</anchor>
      <arglist>(const Frame &amp;_T)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FrameAcc</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>aab342e68642ea0d1c6dda3d5b109306e</anchor>
      <arglist>(const Frame &amp;_T, const Twist &amp;_t, const Twist &amp;_dt)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FrameAcc</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ae8d8c16613a26a101e1136507cec004e</anchor>
      <arglist>(const RotationAcc &amp;_M, const VectorAcc &amp;_p)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameAcc &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a0a111f439e476325b92ac9729493cf12</anchor>
      <arglist>(const FrameAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameAcc &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a5286d54077cb368c1ab7d19e45f482f1</anchor>
      <arglist>(const Frame &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a259389c88e66f988ec6ad7db4592d86b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ac3c98e24bfd5bc4c5edefe788658176d</anchor>
      <arglist>(const VectorAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>aa9539c84d061a2e9ef3762739d8eb928</anchor>
      <arglist>(const VectorAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a9f33a5fc36861c84142c781bbd7d4b5f</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>afbd5a199a48bff191ca6e42305f8f101</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame</type>
      <name>GetFrame</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a931940f5ff3bc8beccf0b68bc8642fa3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetTwist</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a1c6d7c3c5eb9e0d25bf26f0614595f92</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetAccTwist</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ad92cc790c601db4cb2f2d28b32f219f0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ad5aa445e32e31d55582320f6a69d7fe6</anchor>
      <arglist>(const TwistAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>af80dd68fa5590c284dfe25492e802bf4</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a8beddbcf3ab43a9331229c7601bf7cf9</anchor>
      <arglist>(const TwistAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ab71decb8f88ed2ef430c1a047a46d386</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD FrameAcc</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a74a129a305717d134feb7ef42c565dba</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>RotationAcc</type>
      <name>M</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a8fa28ed2c8f491e3ac6df1aad6996ccc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>VectorAcc</type>
      <name>p</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ab4de5af6f211fba06cd0f4d60d036d7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend FrameAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>afbf0914117b3a0052f8dc78e0052a0ef</anchor>
      <arglist>(const FrameAcc &amp;f1, const FrameAcc &amp;f2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend FrameAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>aee75d01313f0e10c427e08ca7712f6f9</anchor>
      <arglist>(const Frame &amp;f1, const FrameAcc &amp;f2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend FrameAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>ae16f85b8390b77244c86110e63bb9fed</anchor>
      <arglist>(const FrameAcc &amp;f1, const Frame &amp;f2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a96b149cf60f5b665ba77a99d4ddb3dac</anchor>
      <arglist>(const FrameAcc &amp;r1, const FrameAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>afc37bd5b6610be2aba497cdd1f67bcd8</anchor>
      <arglist>(const Frame &amp;r1, const FrameAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1FrameAcc.html</anchorfile>
      <anchor>a425682431a70dff7bd161443eb0393b4</anchor>
      <arglist>(const FrameAcc &amp;r1, const Frame &amp;r2, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::FrameVel</name>
    <filename>classKDL_1_1FrameVel.html</filename>
    <member kind="function">
      <type></type>
      <name>FrameVel</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a6f825ee011a4aa66f3c6b5a2c07380a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FrameVel</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a4d2e0efc96a119a15e6bd28645755d8a</anchor>
      <arglist>(const Frame &amp;_T)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FrameVel</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a4f849f21cedcb011eccce950cc4c4c08</anchor>
      <arglist>(const Frame &amp;_T, const Twist &amp;_t)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FrameVel</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a0c905537c7bafa337bcb26236e83c4b5</anchor>
      <arglist>(const RotationVel &amp;_M, const VectorVel &amp;_p)</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>value</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a3f29856ae068c08c5cc91463ae871668</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>deriv</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a4e063497fd4fb7bdaa79034553939a70</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameVel &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a4be56391f662d0f2fce3eb8cb357d786</anchor>
      <arglist>(const Frame &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameVel &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a156f686cb031938448d1c017b9efeb9b</anchor>
      <arglist>(const FrameVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>adddccc935a2c110febf266ad7803af73</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a9b1aed44efabc0ee3837770f5a2ba375</anchor>
      <arglist>(const VectorVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>ad1aa4559b85572a34dc732bfe8a90736</anchor>
      <arglist>(const VectorVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a1b628bbb6a810c492366fe919bb26b82</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a4bbf37d0509a66dbb133a5fb0390ef4b</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame</type>
      <name>GetFrame</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a869e1673f01b4f03bceab27383a47dc1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetTwist</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a51b70e2a7dc3199bd9ab63606963f36a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a8fb34ed59fc7571c4999670234b3b766</anchor>
      <arglist>(const TwistVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a0f116e2dc14b1f3b14051b4b84d7e9d5</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a24fe164dbc2ab0ec53caa6c6bfeb0b2f</anchor>
      <arglist>(const TwistVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>af074e7ea86f5dff0fba17ce0f81fec26</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD FrameVel</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>ae07b0ea4771ae617f84ba0cc3a5a5941</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>RotationVel</type>
      <name>M</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>ade8978389940d4c483fad35d9146f3ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>VectorVel</type>
      <name>p</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a6f35dccc9d7716199e75c9cef0125af2</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend FrameVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a0052f608eb2d13062ffdd2595e185e56</anchor>
      <arglist>(const FrameVel &amp;f1, const FrameVel &amp;f2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend FrameVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>abc886e40e25939c3383c95bf81e85fc0</anchor>
      <arglist>(const Frame &amp;f1, const FrameVel &amp;f2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend FrameVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a635046342dc15f2c5f65e59dcf89149d</anchor>
      <arglist>(const FrameVel &amp;f1, const Frame &amp;f2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a176a28063fee5b9aa59686971ac8fff0</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a52759e2748fcfe0f659645c5cebd6b71</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a6423a8a42d6c1934330f507578775bee</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a47316e5a23c710596f82fe46f87985a0</anchor>
      <arglist>(const FrameVel &amp;a, const FrameVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a93615968ffbf2b8b3e14184072d92796</anchor>
      <arglist>(const FrameVel &amp;a, const FrameVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a0e5c73feb390aa1ab6f748f4114ed0f9</anchor>
      <arglist>(const Frame &amp;a, const FrameVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>ae22788dc1a10656871d4f4c68eaedd6d</anchor>
      <arglist>(const Frame &amp;a, const FrameVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>ac1cae7a2406787389ba64b05f4e0c829</anchor>
      <arglist>(const FrameVel &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1FrameVel.html</anchorfile>
      <anchor>a1747bac2e9858e4d6ed8eee59882b049</anchor>
      <arglist>(const FrameVel &amp;a, const Frame &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Jacobian</name>
    <filename>classKDL_1_1Jacobian.html</filename>
    <member kind="function">
      <type></type>
      <name>Jacobian</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a7c31b866a79a9e20b9ace52654ad5da9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Jacobian</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a8ec8969578a37ecc4ec0970699efa827</anchor>
      <arglist>(unsigned int nr_of_columns)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Jacobian</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a2337e899a223ddda2298e40f1f07408d</anchor>
      <arglist>(const Jacobian &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a296c2e29811beb1769221f26d3e6556b</anchor>
      <arglist>(unsigned int newNrOfColumns)</arglist>
    </member>
    <member kind="function">
      <type>Jacobian &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>ab95a6f65d3bcb8b5da78675269ba8c19</anchor>
      <arglist>(const Jacobian &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>aa1775b56d478901f1c2a8f45e8596ea9</anchor>
      <arglist>(const Jacobian &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>aab6805004b0d808aae598c4ae5f62b39</anchor>
      <arglist>(const Jacobian &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Jacobian</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a0b490c8dbac5d3c5359b0852fd7d60dc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a7e2f4f5e97aea744adfc317ebcf419a5</anchor>
      <arglist>(unsigned int i, unsigned int j) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>ae2068e50defa55976433185af2d7edc5</anchor>
      <arglist>(unsigned int i, unsigned int j)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>rows</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>aceb13ee968c4b162b1f944539a5e0616</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>columns</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a8a49fa5fc952d21c4bbda5eb7c9e1e3a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>getColumn</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>aa09bdd0332f437bd2db55a62f750aced</anchor>
      <arglist>(unsigned int i) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumn</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a3979dcece692c902643548f8979f6ca2</anchor>
      <arglist>(unsigned int i, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>changeRefPoint</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a1002c33bdcab53e26c98d1521eb3ac7d</anchor>
      <arglist>(const Vector &amp;base_AB)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>changeBase</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>ae435c8487ef02ae21276084d3e8bbb13</anchor>
      <arglist>(const Rotation &amp;rot)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>changeRefFrame</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>aabd1e9f0b2ff5f1dead2376958d27c95</anchor>
      <arglist>(const Frame &amp;frame)</arglist>
    </member>
    <member kind="variable">
      <type>EIGEN_MAKE_ALIGNED_OPERATOR_NEW Eigen::Matrix&lt; double, 6, Eigen::Dynamic &gt;</type>
      <name>data</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a73cf18ac91b146f6be631a941d5bee3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a8ced141c7bfa86fa4060e4aba25c25bc</anchor>
      <arglist>(const Jacobian &amp;a, const Jacobian &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a8221041dd47084d0d186ec31ad2a4ccd</anchor>
      <arglist>(Jacobian &amp;jac)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>changeRefPoint</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a3fd746c265191f8a79ab9fae0d137479</anchor>
      <arglist>(const Jacobian &amp;src1, const Vector &amp;base_AB, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>changeBase</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>afa20159619bb7d3ab4faae7fd0c03691</anchor>
      <arglist>(const Jacobian &amp;src1, const Rotation &amp;rot, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>changeRefFrame</name>
      <anchorfile>classKDL_1_1Jacobian.html</anchorfile>
      <anchor>a902ce9b838d432690e2a681c5796eddf</anchor>
      <arglist>(const Jacobian &amp;src1, const Frame &amp;frame, Jacobian &amp;dest)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::JntArray</name>
    <filename>classKDL_1_1JntArray.html</filename>
    <member kind="function">
      <type></type>
      <name>JntArray</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a6dd1e5a2252a36eb48b386c8bc6224b5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArray</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a39f6e6a9780ad92d97cc42a425805b7a</anchor>
      <arglist>(unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArray</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>aeed3edc383df36b8cbd68090893cb029</anchor>
      <arglist>(const JntArray &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~JntArray</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>ad0d4d930850828925df8cd6cbb5cc31d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a4ea82246fd0aa8badff28deb24c2e629</anchor>
      <arglist>(unsigned int newSize)</arglist>
    </member>
    <member kind="function">
      <type>JntArray &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a40261a60987c77724f1e18247bee6eae</anchor>
      <arglist>(const JntArray &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a250bd634d127c6aceb1b9c73e372b129</anchor>
      <arglist>(unsigned int i, unsigned int j=0) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>af528b93031f53438df622c214fcf1b07</anchor>
      <arglist>(unsigned int i, unsigned int j=0)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>rows</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a3176b3c2ebbeeca6e45a3e8d4d692e5b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>columns</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>aeeeb3fde6ed6188d96a4f0afe517d644</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable">
      <type>Eigen::VectorXd</type>
      <name>data</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a59dff4a2f3fa4adedb55c3384238dc74</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>ab1c08f03ff6f9abe10eacd1164cfbddc</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Subtract</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a54d78f9a555efd3dcbdb7833ed855ac9</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Multiply</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a6956918c0e57ed9be52d5d16d82abc55</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Divide</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a8814ef73b965e185b0b36fba5e15a886</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>MultiplyJacobian</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a548bc4404c259688a4132ff430feb989</anchor>
      <arglist>(const Jacobian &amp;jac, const JntArray &amp;src, Twist &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a37bc48b9845e8d493ffd247c0e5f19f0</anchor>
      <arglist>(JntArray &amp;array)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>aad5dfe5f81cdc68b34e2552b742811f2</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1JntArray.html</anchorfile>
      <anchor>a38b0c4bb6970ad5ba73aab199afbb4fb</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::JntArrayAcc</name>
    <filename>classKDL_1_1JntArrayAcc.html</filename>
    <member kind="function">
      <type></type>
      <name>JntArrayAcc</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a2684216e831cb706dfceb10f75a203d1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayAcc</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a7dabbc11ff3ff9ea2676460cd529c0c7</anchor>
      <arglist>(unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayAcc</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a79855c54dc984f4bf54d16a21fd55761</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;qdot, const JntArray &amp;qdotdot)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayAcc</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a46517422fd385350d1b40539e3feb373</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;qdot)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayAcc</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a3799ec327daeca3fb2998ecda8c3c0bc</anchor>
      <arglist>(const JntArray &amp;q)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>ac2369e4f52e4a620cc922d907841bb1b</anchor>
      <arglist>(unsigned int newSize)</arglist>
    </member>
    <member kind="function">
      <type>JntArray</type>
      <name>value</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a481c53cdb1b536f08bd17a4fa149ba93</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>JntArray</type>
      <name>deriv</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a0f1f2a7b19de07b8a2d4fed345165aa4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>JntArray</type>
      <name>dderiv</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a35c91b5c00522986188b6466c1817bb2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable">
      <type>JntArray</type>
      <name>q</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a013c7e143935331236ea7f3d7d4fe01c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>JntArray</type>
      <name>qdot</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>abf9b4563323cf85f61c31d7ac4d85550</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>JntArray</type>
      <name>qdotdot</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a789e6f304326f6386f3fe5001a93f0ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>aba1af02fae645ed9edd8419d94529bfe</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a428357a7f67f7aa23f95d9afac2d254f</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>ae40e46d979cfcf38b92e0f1207ddac26</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Subtract</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a5e4fb055c75da0c00dee863676a181b1</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Subtract</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a5010390579016f1d363d2aa577dc1ece</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Subtract</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a0d17cb7c43c4764acd67f3e7f04b6285</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Multiply</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a2a90fbb08d13a73c73aac69fc4583250</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Multiply</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a747ad8c62679952ec300592efb3321dd</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Multiply</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a187f91b60defcedeba3ca32145e5f466</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Divide</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>ac91c79427e7f83ee49394241f2ee76cc</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Divide</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>ab89646d94b6040c954c246609650ed00</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Divide</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a532aa6dee390776b91b94aa37e68488d</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>a5c6507a8a31940edfc66c66540774010</anchor>
      <arglist>(JntArrayAcc &amp;array)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1JntArrayAcc.html</anchorfile>
      <anchor>add8ae3aeba218dc121cfc6b2bb1f4c1f</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::JntArrayVel</name>
    <filename>classKDL_1_1JntArrayVel.html</filename>
    <member kind="function">
      <type></type>
      <name>JntArrayVel</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a4e7332430725f7e7f175b23b43b239eb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayVel</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>ae3f1d5ceb27ac5eb7395ff8998f10277</anchor>
      <arglist>(unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayVel</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>adf34e8e832db619091806fac9d7bf02e</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;qdot)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>JntArrayVel</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>abb7bc0e17d9fb21275eac33f74c3c8ed</anchor>
      <arglist>(const JntArray &amp;q)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a8a10270f9a701b50cc8dcaa61fc9f538</anchor>
      <arglist>(unsigned int newSize)</arglist>
    </member>
    <member kind="function">
      <type>JntArray</type>
      <name>value</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a995fc40c6c084cb2f18875ee7ef7f000</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>JntArray</type>
      <name>deriv</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a00edc595e5950fa9993f7912e9f890d3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable">
      <type>JntArray</type>
      <name>q</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a3d1c16da97a33260f4e6ee867bc357b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>JntArray</type>
      <name>qdot</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a4cedcb3da3af96a6934fa3cefc5be371</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>ac9811b95852dc20a79162538ef50e073</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a7bb822ff044c345cc1ce8fbf0ebf156e</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Subtract</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a3b136d5185f2ce6673ba5a1755e64d40</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Subtract</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a4ff01c1770f79f28403fd956e0e491dd</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Multiply</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a50f46239a4c0a437c8232d0dc9036e10</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Multiply</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>aecdacfc74f5fbc0c992c02f7899c8fb3</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Divide</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a6b6818ec51f0076daa31271438903095</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>Divide</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a7e0f334f61148ef3269297d13a5e5aa0</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a6f3354065f708ebaefca5186b329456a</anchor>
      <arglist>(JntArrayVel &amp;array)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1JntArrayVel.html</anchorfile>
      <anchor>a6d8afe50f29c96132b9796b15ba61539</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Joint</name>
    <filename>classKDL_1_1Joint.html</filename>
    <class kind="class">KDL::Joint::joint_type_exception</class>
    <member kind="enumeration">
      <type></type>
      <name>JointType</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotAxis</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544eaad375ba3ac2b5a6864dbb7e246f3b242</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotX</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea87b4021f0c0b1d9e8e21c7eb222a9f75</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotY</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea82ced6110c39092f0073540c041275e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotZ</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544eac218b252dc3dbaa7468cb23634e2392f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransAxis</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea0580ff75910267d4a9b5f42a16cc7f22</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransX</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544eaabd1b7dda2870d5f0d85f394fe6ea12f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransY</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea5118e6fc6a5deee920b1378a17d7c29c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransZ</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea23571c2d723e2607a0e0ab65c106e3c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>Fixed</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea96cef8f256bab905b5dc29ebbb54d089</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>None</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea4c8d7947a02e72496641ea3bac5c7b84</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotAxis</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544eaad375ba3ac2b5a6864dbb7e246f3b242</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotX</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea87b4021f0c0b1d9e8e21c7eb222a9f75</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotY</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea82ced6110c39092f0073540c041275e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RotZ</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544eac218b252dc3dbaa7468cb23634e2392f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransAxis</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea0580ff75910267d4a9b5f42a16cc7f22</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransX</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544eaabd1b7dda2870d5f0d85f394fe6ea12f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransY</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea5118e6fc6a5deee920b1378a17d7c29c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TransZ</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea23571c2d723e2607a0e0ab65c106e3c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>Fixed</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea96cef8f256bab905b5dc29ebbb54d089</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>None</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad05f78142c8b73c3977f038a7a2c544ea4c8d7947a02e72496641ea3bac5c7b84</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Joint</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>af011fb473e501109bb9ce9a326a9b6d0</anchor>
      <arglist>(const std::string &amp;name, const JointType &amp;type=Fixed, const double &amp;scale=1, const double &amp;offset=0, const double &amp;inertia=0, const double &amp;damping=0, const double &amp;stiffness=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Joint</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a222e2b158ffd8de605ac7c9f04fc73e3</anchor>
      <arglist>(const JointType &amp;type=Fixed, const double &amp;scale=1, const double &amp;offset=0, const double &amp;inertia=0, const double &amp;damping=0, const double &amp;stiffness=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Joint</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a3ecb4f99030e80dc406b0995778b338a</anchor>
      <arglist>(const std::string &amp;name, const Vector &amp;_origin, const Vector &amp;_axis, const JointType &amp;type, const double &amp;_scale=1, const double &amp;_offset=0, const double &amp;_inertia=0, const double &amp;_damping=0, const double &amp;_stiffness=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Joint</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a0b5faaeebf0f81c3c1e69fd8e3b70a57</anchor>
      <arglist>(const Vector &amp;_origin, const Vector &amp;_axis, const JointType &amp;type, const double &amp;_scale=1, const double &amp;_offset=0, const double &amp;_inertia=0, const double &amp;_damping=0, const double &amp;_stiffness=0)</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>pose</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>acc34535f75e83db7912801b8bb3bf05d</anchor>
      <arglist>(const double &amp;q) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>twist</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a69c126cd749155dacce696a3e8dcdb06</anchor>
      <arglist>(const double &amp;qdot) const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>JointAxis</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a7fd61cf0f5de6b90f0a5db04597a6473</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>JointOrigin</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a1a6ceb3d68e37f95838bcdfb02413cd4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>getName</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a6a133d8735e73896cd955a8e818b34e9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const JointType &amp;</type>
      <name>getType</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>af85628b8637dd0458cae8b393f266ee9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const std::string</type>
      <name>getTypeName</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a9d04861cf4cefc5a24597c8ecaf54415</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>getInertia</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a2347eef9e468ff86371f3f8bf7493cd9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>getDamping</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ae967d3a31fc4c32d9c1ad2a88d1e4c21</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>getStiffness</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a400d79e68832ab5ef9639e9ea8244252</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Joint</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad52fb0fad2d0e2c7d5cb18c53867e63e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>name</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a1a17b1582ac6496600da7d082a396f8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Joint::JointType</type>
      <name>type</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ac15f6c9388820da1360d8f84d65c8a3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>scale</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a72598a5b2efa311bb2c0d41ea3df3add</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>offset</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>aa941287320d14affd0402d61cc651f37</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>inertia</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a5cf831b847695046de25563e9de89e08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>damping</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a8b802b3f4d9ac035e8e27967b5ed7a6b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>stiffness</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ad230cf2c80e1ee66130823d3c219f944</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>axis</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>aac581e273661e2687eafc0c3a769b01c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>origin</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>ab998797f085d01b29d8199430cefd2f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>joint_pose</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>af4ed1ab2c7007bb54ed960b496d60ce0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>q_previous</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a1e336e1ad89d6165b73426cb1a2b8aed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>KDL::Joint::joint_type_exception</type>
      <name>joint_type_ex</name>
      <anchorfile>classKDL_1_1Joint.html</anchorfile>
      <anchor>a93b973deadae14dacd8ab24a3a6977c4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Joint::joint_type_exception</name>
    <filename>classKDL_1_1Joint_1_1joint__type__exception.html</filename>
    <member kind="function" protection="private" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classKDL_1_1Joint_1_1joint__type__exception.html</anchorfile>
      <anchor>af66c016d978d126ddbc2aaccd97ebd32</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path</name>
    <filename>classKDL_1_1Path.html</filename>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>LengthToS</name>
      <anchorfile>group__Motion.html</anchorfile>
      <anchor>gad7f55a1d6f7a076b0959c76c29cc323d</anchor>
      <arglist>(double length)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a095d3ce8d48bd9f8953793c60532cd1a</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>ab0121ec33eee9525bd3c883a1631bf6c</anchor>
      <arglist>(double s) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a6982dc012ef4299cffc1be99ef225d98</anchor>
      <arglist>(double s, double sd) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a274dd481c1ab921f898cddb618e7e42b</anchor>
      <arglist>(double s, double sd, double sdd) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a3c1c34464d34183fc965af1ea260879d</anchor>
      <arglist>(std::ostream &amp;os)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a06926be0592bbe853ee9d040a4e420d3</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>aa28b0993963870a6c754b19e5cd06fec</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a10f16828c888527755e8a59c906b5a57</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a15dfd941258db019a5b30c666e51b358</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path_Circle</name>
    <filename>classKDL_1_1Path__Circle.html</filename>
    <base>KDL::Path</base>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_Circle</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a2ea743324c49ce71ce07b8add71590ca</anchor>
      <arglist>(const Frame &amp;F_base_start, const Vector &amp;V_base_center, const Vector &amp;V_base_p, const Rotation &amp;R_base_end, double alpha, RotationalInterpolation *otraj, double eqradius, bool _aggregate=true)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>LengthToS</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a9ee876743434ad8c232dc693f237d60d</anchor>
      <arglist>(double length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a33e50afc4d0d03475ee65d3ee9dfb4f7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>aea97235e3dcc3e4d1e8339de3dd3e445</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a6d12cf804729d6d88b9741d5ad0c30f8</anchor>
      <arglist>(double s, double sd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a518a52ffff1e348bf6d63751b583538c</anchor>
      <arglist>(double s, double sd, double sdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>aecea40890bda02ff12af808b00ea6f83</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a20176764e85bc180024b45ac336e37a3</anchor>
      <arglist>(std::ostream &amp;os)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>abc318bc561a6fc96d589f2ee54f46c73</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path_Circle</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a7884241172d2a08d3fe97ffcf3e5b5f3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a15dfd941258db019a5b30c666e51b358</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>RotationalInterpolation *</type>
      <name>orient</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a28ab38824d05ec0dce4e788c202bb721</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>radius</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a5c20ed64d1a038dda98293837745d22f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>F_base_center</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a7d8959c4fcfff7447e4b7d3579db1986</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eqradius</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a54fe75952f21dc4d63d43bd22a64c239</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>pathlength</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>ac800c1849eadc199c507fee8c95ce135</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>scalelin</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>aec8e7b778de7f8768618b7527a4957f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>scalerot</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>acc8c849025f0ef75083eb98c1d360725</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>aggregate</name>
      <anchorfile>classKDL_1_1Path__Circle.html</anchorfile>
      <anchor>a1873c3889b106676fe8d90802d8df096</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path_Composite</name>
    <filename>classKDL_1_1Path__Composite.html</filename>
    <base>KDL::Path</base>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_Composite</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a8dbfb9a72e821839ce491a9add98b3ea</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a679f396ba2f9f0b83213f88d895ac1c6</anchor>
      <arglist>(Path *geom, bool aggregate=true)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>LengthToS</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a77a6568ab90b5778a3239d43bb05071d</anchor>
      <arglist>(double length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a466d5ba0411bfcc6def2db149d9de225</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a506faf2f4d52c5d374e021a31d65aab0</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a2836bf1c9ba8f89c8ec1f6dc79e32b06</anchor>
      <arglist>(double s, double sd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a5acfb048ac1c00850dfbde09c5c9198c</anchor>
      <arglist>(double s, double sd, double sdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>aee441fb0bbb122b4798273f0cc4fa731</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>aaaf25f08ed9de56d89f2c0b91e924eb2</anchor>
      <arglist>(std::ostream &amp;os)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>GetNrOfSegments</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a5788086a6f9b678e797383a3534938af</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>GetSegment</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a11e28d11f967a77d82167ecb77497de5</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>GetLengthToEndOfSegment</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a9b4cfb8ab9e47f66f9aa6b24bc8b67eb</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>GetCurrentSegmentLocation</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>aa002edee28c5ff6006271daddb436ab2</anchor>
      <arglist>(double s, int &amp;segment_number, double &amp;inner_s)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>ae079edab6b343eb42ddc9251f0103172</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path_Composite</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a2634b9540a6d417d0fd4a4f571064043</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a15dfd941258db019a5b30c666e51b358</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; std::pair&lt; Path *, bool &gt; &gt;</type>
      <name>PathVector</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>aad3fbd29cbb70a11a0d18fa6a971f536</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; double &gt;</type>
      <name>DoubleVector</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a43b4fe18f0584cb61f5d2e80b6dc8e8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>double</type>
      <name>Lookup</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>abf873591b2ca9354b90b082cc6e9d071</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>PathVector</type>
      <name>gv</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>aa7f67a8bc3ced143153fe969fc1df3b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>DoubleVector</type>
      <name>dv</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a6c487a4be9cb79ae5630ad8ed7fdd136</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>pathlength</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a8a26dd4e83aad5698d7a8d5e934e5b61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>cached_starts</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a307bb88dc0a0b07907da9b86d07c0760</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>cached_ends</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>ad80c5ed91ffb87736dfc66837d0729b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>cached_index</name>
      <anchorfile>classKDL_1_1Path__Composite.html</anchorfile>
      <anchor>a2618c98caa0e9ca06bb9741ffa78a9bd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path_Cyclic_Closed</name>
    <filename>classKDL_1_1Path__Cyclic__Closed.html</filename>
    <base>KDL::Path</base>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_Cyclic_Closed</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>ad227379563ca9403c19bfbf723a76931</anchor>
      <arglist>(Path *_geom, int _times, bool _aggregate=true)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>LengthToS</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>affc8e733ebea2cc953c3ede63e98bcf1</anchor>
      <arglist>(double length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>aef75d2cc39bb3430a7bd9cb9197eb4c9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a9e2f85d9dc600ec162f3e9a9e0a8ab9b</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a05c85d260ab99935f05cbb88423fe595</anchor>
      <arglist>(double s, double sd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a84cb03dce61a749298028c47d890775d</anchor>
      <arglist>(double s, double sd, double sdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>acc4367cce744f63cd9fe0872efc787ce</anchor>
      <arglist>(std::ostream &amp;os)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a627b15d0c226295fc5239a55bbe7de9e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>acda44d9c32ae5a7f9ba0b9a3a7152c83</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path_Cyclic_Closed</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a5ac8e6be3c0059c0d37855b580706a07</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a8da7f91527e4593999ec2a3475458d42</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>times</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a8313827496af74a6493ff82054fedb33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Path *</type>
      <name>geom</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a7e507d9b082bdd30293107ed2a54b577</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>aggregate</name>
      <anchorfile>classKDL_1_1Path__Cyclic__Closed.html</anchorfile>
      <anchor>a87138143960206b6d82f9f7158970a43</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path_Line</name>
    <filename>classKDL_1_1Path__Line.html</filename>
    <base>KDL::Path</base>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_Line</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a1ea3f21f577aee2a4252c5a802b6a7f2</anchor>
      <arglist>(const Frame &amp;F_base_start, const Frame &amp;F_base_end, RotationalInterpolation *orient, double eqradius, bool _aggregate=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_Line</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>aad9dcba467fad065263f3d07f3b76b6c</anchor>
      <arglist>(const Frame &amp;F_base_start, const Twist &amp;twist_in_base, RotationalInterpolation *orient, double eqradius, bool _aggregate=true)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>LengthToS</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a972c1d45a18ff464da6ed01fb8613d27</anchor>
      <arglist>(double length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a47c2bb2d49e35ab901765f488608ab7e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>af7cd0542bae1752e8340db9b3182bb33</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a69b0f00c5c61c633390c76b9a93bc6c8</anchor>
      <arglist>(double s, double sd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>acb27d85f86eab3b0946835746665c1ff</anchor>
      <arglist>(double s, double sd, double sdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>ab475571f13fca95765696dcc23e84db8</anchor>
      <arglist>(std::ostream &amp;os)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>ace0ec0812ca24700061af1b7fe5e898c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>ab8345944b208bf4715df86ed99982a8b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path_Line</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a84f6a9593a8b67868fa07929ae6c4e79</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a15dfd941258db019a5b30c666e51b358</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>RotationalInterpolation *</type>
      <name>orient</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a907dd36ae9b96312d04b22934f2ecd72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>V_base_start</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a81c8bba71c110bb33f08f6e405ad8ca5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>V_base_end</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a86856f07c1e7062d1faa1c891c77e461</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>V_start_end</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a6a5400b8308eaef00de2377f44bbed00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eqradius</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a4ae08c6b523e1ff5b7481e644cb88a77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>pathlength</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>a2f3bea5155b5cb8216ed0de5a173364f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>scalelin</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>ad544981b25c332713885934091534e48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>scalerot</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>adbcf86b75f3c8fe740f3a02407c0098f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>aggregate</name>
      <anchorfile>classKDL_1_1Path__Line.html</anchorfile>
      <anchor>ad9fbf372c9cb56f92dbf6d45ffd81755</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path_Point</name>
    <filename>classKDL_1_1Path__Point.html</filename>
    <base>KDL::Path</base>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_Point</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a3ce8e76365cc81c92f6285e5ba5feaf1</anchor>
      <arglist>(const Frame &amp;F_base_start)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>LengthToS</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a920f57134fdf4234dd04c7728f978567</anchor>
      <arglist>(double length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a2fc2b2a544257183d4d21bb23029e6ee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>aecdb16b134d27bb0c6f457e0f340699e</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a849e3c029cfd21f7488b57c2da79b809</anchor>
      <arglist>(double s, double sd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a67ad2f25fbe4c5c6cc5fe17bdc122fab</anchor>
      <arglist>(double s, double sd, double sdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>aaee84835ba0e8fc0c39bf48b2e4a681a</anchor>
      <arglist>(std::ostream &amp;os)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a54b78f0225a17c2e384fdca0267ebe72</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>a1f0df92db10b750a1ecc11635bf96115</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path_Point</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>ab2f4ecd33e3769e3f56044167eb592a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a15dfd941258db019a5b30c666e51b358</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>F_base_start</name>
      <anchorfile>classKDL_1_1Path__Point.html</anchorfile>
      <anchor>aac2750961582b732c6628ceedad71271</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Path_RoundedComposite</name>
    <filename>classKDL_1_1Path__RoundedComposite.html</filename>
    <base>KDL::Path</base>
    <member kind="enumeration">
      <type></type>
      <name>IdentifierType</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_LINE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a4f9ed1827474558375d8fdcc6fa22a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CIRCLE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0ce2e4f0f5a61c01cecafbe0084682cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a0e63c4744e46f92e2599ca9fbf50f6a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_ROUNDED_COMPOSITE</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09a6458e9e3355fb8ebdcd540ae753aadbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_POINT</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ad0c76d25569cecb6d38bce3ec92cd8eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID_CYCLIC_CLOSED</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a8f75e07f7fc75646e0db7e6b4a1c3f09ae0cd5b91c304ea865d3e2ffe642a47d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Path_RoundedComposite</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a7daf7e92a48c18b06aeab6bb50883e8e</anchor>
      <arglist>(double radius, double eqradius, RotationalInterpolation *orient, bool aggregate=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a85d9f42a52e5704b33629355f2157be4</anchor>
      <arglist>(const Frame &amp;F_base_point)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Finish</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>ad88828a48011d4b8ef775ff8fb22dff6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>LengthToS</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>ae2a676790cdf8b7356eb7327eb14fde3</anchor>
      <arglist>(double length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>PathLength</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a858f7fb29c997e9332c4f56b6b1364d3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>ac8580b5928a8a1e0aa8a7ec63c7167d5</anchor>
      <arglist>(double s) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a4178b9c0a175466f655a9a2ede71bccc</anchor>
      <arglist>(double s, double sd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a22d5cd9898c8b6ad83b71d18ad371156</anchor>
      <arglist>(double s, double sd, double sdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a120b469f82f6e3ce9b940348b0874398</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a72004b635a931a44161ba0677c9f5e73</anchor>
      <arglist>(std::ostream &amp;os)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>GetNrOfSegments</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a67f00e07cb66d4d475e26bc69f612947</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>GetSegment</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a4016b9f5bbacb80464e55cae44d70f33</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>GetLengthToEndOfSegment</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a1a7251edb23c2203e0661917e0624235</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>GetCurrentSegmentLocation</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>ac3e92378de6aa98a8f210901938bbf70</anchor>
      <arglist>(double s, int &amp;segment_number, double &amp;inner_s)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IdentifierType</type>
      <name>getIdentifier</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a0c2a6d363090e47378c87f8812150244</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Path_RoundedComposite</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a3b2bba0b18663c4be8aed87a144cd890</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Path *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Path.html</anchorfile>
      <anchor>a15dfd941258db019a5b30c666e51b358</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Path_RoundedComposite</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a61b2c39726adb41c5311034555c08076</anchor>
      <arglist>(Path_Composite *comp, double radius, double eqradius, RotationalInterpolation *orient, bool aggregate, int nrofpoints)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Path_Composite *</type>
      <name>comp</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a3ab3fea1818172b298289d0e22788ba7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>radius</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a9caffac2bd59ba759918a987506f1fff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eqradius</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>ab8dbfad1e15e26bc4e96429406fbb4e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>RotationalInterpolation *</type>
      <name>orient</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a57097ef3b613d4a40bf3faed92758332</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>F_base_start</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>ae61919434682ff75aa5dff58085ba590</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>F_base_via</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a2ce2efb19a7a668ea97f3ab84128e69a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>nrofpoints</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>a7ae030a97ecda4384b09336c401db4db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>aggregate</name>
      <anchorfile>classKDL_1_1Path__RoundedComposite.html</anchorfile>
      <anchor>aa0f19713e3930f863ec2c07804845167</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::RigidBodyInertia</name>
    <filename>classKDL_1_1RigidBodyInertia.html</filename>
    <member kind="function">
      <type></type>
      <name>RigidBodyInertia</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a1b7ca1ec61df504f4db07cb5f98bdabe</anchor>
      <arglist>(double m=0, const Vector &amp;oc=Vector::Zero(), const RotationalInertia &amp;Ic=RotationalInertia::Zero())</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RigidBodyInertia</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a728ff068183282ac4c2774db64f6eb45</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>RefPoint</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a4349dc26f4e538e7630fd5de18484d83</anchor>
      <arglist>(const Vector &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getMass</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>ae1c13abc7c9cf39b8767f6f6a076f10e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>getCOG</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a89c5adb42c867ac824d39a248fb7345a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>getRotationalInertia</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a0b1e6ebb0d63dd66c9079683f11f277b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static RigidBodyInertia</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a6684b59d8359f9e4c305b709188049f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>RigidBodyInertia</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>ace6c0fdeccce132891735ed23dfd92c1</anchor>
      <arglist>(double m, const Vector &amp;h, const RotationalInertia &amp;I, bool mhi)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>m</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a8feefa9f3bfbbfd4bf163c05081a8438</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>h</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a8fb1c9e2b6d45f87c533046f1e742716</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>RotationalInertia</type>
      <name>I</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>ade2ddec821af54bff08b6061ab46472a</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>ArticulatedBodyInertia</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a26a8b6cf42ab0d7a17909656a9ff16b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a04507a0c6bfbd2fabd4178be65989a42</anchor>
      <arglist>(double a, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a81525c4002e3725a67dd0f730b7e35b4</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a053fe8890d6c3a5fafd5dc7fa65b1b9a</anchor>
      <arglist>(const RigidBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a356b6345fac27c647f94eed62265a4e3</anchor>
      <arglist>(const Frame &amp;T, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RigidBodyInertia.html</anchorfile>
      <anchor>a8299aeb0c4514205697a571004ece305</anchor>
      <arglist>(const Rotation &amp;R, const RigidBodyInertia &amp;I)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Rotation</name>
    <filename>classKDL_1_1Rotation.html</filename>
    <member kind="function">
      <type></type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a2e2696a35bc3bdce4db0d9ed958966d9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ad059305eb21561628f4c1a172b30e24c</anchor>
      <arglist>(double Xx, double Yx, double Zx, double Xy, double Yy, double Zy, double Xz, double Yz, double Zz)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>acabb1e35f448ce9377c2e3e164f287db</anchor>
      <arglist>(const Vector &amp;x, const Vector &amp;y, const Vector &amp;z)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a4862d8604c2766dd7393dcf26a18280e</anchor>
      <arglist>(const Rotation &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Rotation &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a111886c82b66d6425d24fb7dbb276e92</anchor>
      <arglist>(const Rotation &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a130a3edf5e37a9d2b9817093a7c02deb</anchor>
      <arglist>(const Vector &amp;v) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>af1b1952b99b4cb13e36f465f57a55c46</anchor>
      <arglist>(int i, int j)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a546f32a66fbd57273f226569ccebc8f8</anchor>
      <arglist>(int i, int j) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetInverse</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>aca0b79dafe708d4623d16c15c239854f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Rotation</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a09a2ee554e814222ef86a8d1ce3267b1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a4e7028b1ed3ded74761155a00bbd7222</anchor>
      <arglist>(const Vector &amp;v) const</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a139ee9c400685a75c4f6fd3acc1ef8ec</anchor>
      <arglist>(const Wrench &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a1e229277228e2a0c0f3e3faea9dbb79a</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>DoRotX</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>aa1a0ca08f29877875e3c78127266354e</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>DoRotY</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>af6b09f3f066b67e03d17cd2cb3c74b73</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>DoRotZ</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a08fa60d7a860a6f7077ed5adf428ded4</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>GetRot</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a0602575044d3b1fdcb4608443f4bff7d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetRotAngle</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a34f8fdc2586b09f59c880bed076cdea5</anchor>
      <arglist>(Vector &amp;axis, double eps=epsilon) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>GetEulerZYZ</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a01af0b828cb08e3dcca40ece62b77ddf</anchor>
      <arglist>(double &amp;alpha, double &amp;beta, double &amp;gamma) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>GetQuaternion</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ac8e51b8dce630de273d054710f7458fb</anchor>
      <arglist>(double &amp;x, double &amp;y, double &amp;z, double &amp;w) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>GetRPY</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a077721e9049f4ed6c927da6f17c70572</anchor>
      <arglist>(double &amp;roll, double &amp;pitch, double &amp;yaw) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>GetEulerZYX</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ad826f59ad7a5efa10c549e5577d2f7d9</anchor>
      <arglist>(double &amp;Alfa, double &amp;Beta, double &amp;Gamma) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ac9062a29beb152edd602121a7fac6558</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>adf64f458e61f28f18fb37e5a963ff8aa</anchor>
      <arglist>(const Wrench &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>UnitX</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a281f21f3d632bd84a44fa5caaaebf8e6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>UnitX</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a8da753f2dac3d1d19c5c4add10b27720</anchor>
      <arglist>(const Vector &amp;X)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>UnitY</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a197ba79e104bb6ff43994fceed8f7672</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>UnitY</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ad84b2efc831af4c9a408a93f702bb087</anchor>
      <arglist>(const Vector &amp;X)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>UnitZ</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a1fc6a54d079f1ded3414b870b7607a60</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>UnitZ</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a1ab4feb72d6be853a4dd5ee30427cb3e</anchor>
      <arglist>(const Vector &amp;X)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a5a5d40d8e6cf179cac35bc378c83017c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>RotX</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a60d5c0a5b439a0c2413e94aa45db8cc1</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>RotY</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ac37c940f7c95f8e2ee84c5f66e7b648e</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>RotZ</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>aeaa7d2485bb79c3a5be0046eed71c9ce</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>Rot</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ad05c91ff1d5bab2c51b92e349ff9bebb</anchor>
      <arglist>(const Vector &amp;rotvec, double angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>Rot2</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a4e909036d2aad30b631884daa3c15b3b</anchor>
      <arglist>(const Vector &amp;rotvec, double angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>EulerZYZ</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>ad671cdd779a469544b1d903420d0ded9</anchor>
      <arglist>(double Alfa, double Beta, double Gamma)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>Quaternion</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a1b1c1e1843d10ac70043d3c3d0358b2f</anchor>
      <arglist>(double x, double y, double z, double w)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>RPY</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>afbe17f3c9249078626fba1736aed8d31</anchor>
      <arglist>(double roll, double pitch, double yaw)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation</type>
      <name>EulerZYX</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a39de86d0df854dda05aa9d8516b8e119</anchor>
      <arglist>(double Alfa, double Beta, double Gamma)</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>data</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>aad4572c3cd7591216d5dc561abbcbdb6</anchor>
      <arglist>[9]</arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>aee3a66b0ddf3b769f015c89b610db0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Rotation</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a58290aa6fd60b6103a52cd0dddc695bb</anchor>
      <arglist>(const Rotation &amp;lhs, const Rotation &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a9cbb064bc8224853b87dea0dc029fcdb</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a6731a7dd43c9617569769ab35aba81a8</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Rotation.html</anchorfile>
      <anchor>a79bfadea66e1395bbfb4e41c91730b8f</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Rotation2</name>
    <filename>classKDL_1_1Rotation2.html</filename>
    <member kind="function">
      <type></type>
      <name>Rotation2</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a890b05669eacd0f9779d66e636a74d61</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rotation2</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>af13f975f4bfc4701eb62f933e7e11d61</anchor>
      <arglist>(double angle_rad)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rotation2</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a3f24f9401b3dd67b827cb7308bd6f556</anchor>
      <arglist>(double ca, double sa)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rotation2</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a0db98f9f643bfee889d1c70ce72b06bd</anchor>
      <arglist>(const Rotation2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Rotation2 &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>afde0136496eee42795baf646a373009a</anchor>
      <arglist>(const Rotation2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a395f1086334ca19bb771e0e605895a9d</anchor>
      <arglist>(const Vector2 &amp;v) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a3a5339ae85aadda3a2c2f6dd922f1fe8</anchor>
      <arglist>(int i, int j) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetInverse</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a75aa830c61b9a1174df5c4db7d662c61</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Rotation2</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>af69ef92755dab0e10609a069645977cf</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector2</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a663e69fa1597aa2e14459a2881c16ac3</anchor>
      <arglist>(const Vector2 &amp;v) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetIdentity</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>ae780b003b6e5a040fb98cba32aecc1ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetRot</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>afafdf07b32fd44aaab3ad3854502f4de</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetRot</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a29eefa76dec3acabc4ed3d99612e1b7f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation2</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a9574a771c52178e733c431c9b58ea835</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Rotation2</type>
      <name>Rot</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a6a0561775350b56e5f57a87b9274cc65</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>s</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>ad4496f5010eeaf68ad1fa50820146809</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>ade7b905e59ed018da75357bec8207b66</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Rotation2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>ac3360a43a99f9c17949a7703662c7534</anchor>
      <arglist>(const Rotation2 &amp;lhs, const Rotation2 &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Rotation2.html</anchorfile>
      <anchor>a9d12bcb79fbef1f1efe3bca4ebe1eceb</anchor>
      <arglist>(const Rotation2 &amp;a, const Rotation2 &amp;b, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::RotationAcc</name>
    <filename>classKDL_1_1RotationAcc.html</filename>
    <member kind="function">
      <type></type>
      <name>RotationAcc</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>ae6536333801786e451f65d1a30c19048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RotationAcc</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a834faa29f99c6c4ad7cf7ab494ac714e</anchor>
      <arglist>(const Rotation &amp;_R)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RotationAcc</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>adc741305bc99972583ace26f51f07b44</anchor>
      <arglist>(const Rotation &amp;_R, const Vector &amp;_w, const Vector &amp;_dw)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationAcc &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a5687f41fd88e9289cb300d461d963445</anchor>
      <arglist>(const RotationAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationAcc &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>ad8db79a3dd2fd95f2c51c634f086b257</anchor>
      <arglist>(const Rotation &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a105a484b84a3382044898f205278308e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a488d4c702929630bfd7d9ad8ca910a69</anchor>
      <arglist>(const VectorAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a20ff2cfbbf856d1fdb4b468df085c9a8</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>ae0b1ccd11ff5c64ddf1758453cbd694e</anchor>
      <arglist>(const VectorAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a02d3152197c615963872f01b6600c268</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a714288693f9ebb35ce94d6c6ff607cf9</anchor>
      <arglist>(const TwistAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a051c42338a69c39623c0dd7e9a4ccf4b</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a7080fbc169eb1603b23cb4c2c90f7f8f</anchor>
      <arglist>(const TwistAcc &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>acca5f65b70ffaf9f878a8bf14ca38d25</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationAcc</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a41bf2ed95d3a6c5e14adf7a743d876dc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Rotation</type>
      <name>R</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>af717191b6e458da8ae41dfe8bdb34ede</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>w</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a9871c84d692338b3c3bf7a60d141b09a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>dw</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a891c7d785ee8f3f0725cfe649ff945b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend RotationAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a1a1883141130dce5fd3c5dc7cfce846c</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend RotationAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>a64d40731d0c239503100ea98cbb0bc9e</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend RotationAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>ad81fe43874ebf62056def95db2bd5a91</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>adf5d4bf2cc93a2847acc9efa6097ee7d</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>ab2e6777c34e98bebffda528a6cd102e7</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1RotationAcc.html</anchorfile>
      <anchor>acc1c78a8b13e3b0636ae1338b9cc5a3d</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::RotationalInertia</name>
    <filename>classKDL_1_1RotationalInertia.html</filename>
    <member kind="function">
      <type></type>
      <name>RotationalInertia</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a9aeb48fd7b9d44cb5bc1284cd8410382</anchor>
      <arglist>(double Ixx=0, double Iyy=0, double Izz=0, double Ixy=0, double Ixz=0, double Iyz=0)</arglist>
    </member>
    <member kind="function">
      <type>KDL::Vector</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a965f2ee7b35e52949da72da4eba0886d</anchor>
      <arglist>(const KDL::Vector &amp;omega) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RotationalInertia</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a60935f7bdebbd8fd6a2dcd694e794189</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static RotationalInertia</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a50fbe96830ed0c31a9de7528c859ae32</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>data</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a84d956cfe35692bc64cf90f8b0923ef3</anchor>
      <arglist>[9]</arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>RigidBodyInertia</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a220ff47720a5ea22d70befb61bf5ba32</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend RotationalInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a7f6a4e6436ac8e81ccd6634e4ed90e4d</anchor>
      <arglist>(double a, const RotationalInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend RotationalInertia</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>ad0005da22a34748cf2780d97a82ef868</anchor>
      <arglist>(const RotationalInertia &amp;Ia, const RotationalInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a04507a0c6bfbd2fabd4178be65989a42</anchor>
      <arglist>(double a, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a81525c4002e3725a67dd0f730b7e35b4</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a053fe8890d6c3a5fafd5dc7fa65b1b9a</anchor>
      <arglist>(const RigidBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a356b6345fac27c647f94eed62265a4e3</anchor>
      <arglist>(const Frame &amp;T, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="friend">
      <type>friend RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationalInertia.html</anchorfile>
      <anchor>a8299aeb0c4514205697a571004ece305</anchor>
      <arglist>(const Rotation &amp;R, const RigidBodyInertia &amp;I)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::RotationalInterpolation</name>
    <filename>classKDL_1_1RotationalInterpolation.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>SetStartEnd</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>af6ce679181c35f721b88a289dc9b2e52</anchor>
      <arglist>(Rotation start, Rotation end)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>Angle</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>a7dbf969c071c5b414e84386ac9967963</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Rotation</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>a62d9494047e32abc8e8cf8e389c75eb1</anchor>
      <arglist>(double theta) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Vector</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>a1fcf542f02ab4308b4d71b130f5c5bd3</anchor>
      <arglist>(double theta, double thetad) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Vector</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>ae251ab468aa089bddf6fec758d154dc5</anchor>
      <arglist>(double theta, double thetad, double thetadd) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>a2ca5fd8005512f180fd12a49806bca06</anchor>
      <arglist>(std::ostream &amp;os) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual RotationalInterpolation *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>a22c768e89a2c79c3fefec5a9600fa90f</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RotationalInterpolation</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>a561bad750afa7f214aa6805109f4ecff</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static RotationalInterpolation *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>aecafc8b2ee40b8c2f6624711c0df34d3</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::RotationalInterpolation_SingleAxis</name>
    <filename>classKDL_1_1RotationalInterpolation__SingleAxis.html</filename>
    <base>KDL::RotationalInterpolation</base>
    <member kind="function">
      <type></type>
      <name>RotationalInterpolation_SingleAxis</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>aa8479bf0cad238fa6bf7fe9933fa8515</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetStartEnd</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a90fadf08e5a6a242713e2ef62a998e25</anchor>
      <arglist>(Rotation start, Rotation end)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Angle</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a8d85deaf915c30d7f1bec7af0530cb7f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Rotation</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>ad9e8466ea20d2fb43850853dd2e0ecfc</anchor>
      <arglist>(double th) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Vector</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a0ff831fe3ac847ae0ec42775dad73f27</anchor>
      <arglist>(double th, double thd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Vector</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a0b38f1fe0f36855b5c06e750b2c47314</anchor>
      <arglist>(double th, double thd, double thdd) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a74141103bbe01d3fb16695f5eba3dd27</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual RotationalInterpolation *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a63ad631bb62bd3e2609aa93dbe296da1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RotationalInterpolation_SingleAxis</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>ac3ee2d3d05317fee9ed52f85c82d0dc9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static RotationalInterpolation *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1RotationalInterpolation.html</anchorfile>
      <anchor>aecafc8b2ee40b8c2f6624711c0df34d3</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Rotation</type>
      <name>R_base_start</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a436ec709bd34c0f6519ef0ad304d63c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Rotation</type>
      <name>R_base_end</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a0898f0552c7ad31a6dbfe421d34fad16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Vector</type>
      <name>rot_start_end</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a746301c8c246b9a69a02cea2cc98eeac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>angle</name>
      <anchorfile>classKDL_1_1RotationalInterpolation__SingleAxis.html</anchorfile>
      <anchor>a360cd7fd7fe55b16f20659f68fc3a38a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::RotationVel</name>
    <filename>classKDL_1_1RotationVel.html</filename>
    <member kind="function">
      <type></type>
      <name>RotationVel</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a9b9dd57f815c0e36f2067867dc090778</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RotationVel</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>acd5d416a2922afc581f244cf7b7993cf</anchor>
      <arglist>(const Rotation &amp;_R)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RotationVel</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a3680af08ae2318bf86e793d7785dc37a</anchor>
      <arglist>(const Rotation &amp;_R, const Vector &amp;_w)</arglist>
    </member>
    <member kind="function">
      <type>Rotation</type>
      <name>value</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ada54e6c417507aac053e6a3c15e3fd8b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>deriv</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a40958600a097df56867c477e20738696</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationVel &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a36978b5fbc14047fdba3f10ea7d78daf</anchor>
      <arglist>(const RotationVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationVel &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a6b913e295aac5a439995d99f6a04b627</anchor>
      <arglist>(const Rotation &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>UnitX</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a460c61bcf94b9782695f7adc3324376a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>UnitY</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a1185bac322af677712a8cec6e3070557</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>UnitZ</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a8f5b07d6f26e9cebacfea5ef0305c3e6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a3b08ee648757e2cebc6a19fdd508ce9f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a90f8b6dc2b81e7ffd888b8fc0926d5d9</anchor>
      <arglist>(const VectorVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a59526e654b12f2aebeb6a28687f03e12</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ae6b986c0c33460438978b786ffb18867</anchor>
      <arglist>(const VectorVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a0f0a14113b94df7371adc7010b98c3d7</anchor>
      <arglist>(const Vector &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>DoRotX</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ab46bacd9316fbce13fed525c1e6c8223</anchor>
      <arglist>(const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>DoRotY</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ab65743af4d6caa11f500b5aa2023d410</anchor>
      <arglist>(const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>DoRotZ</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ac37639bf292a7076025dfb382f1ee874</anchor>
      <arglist>(const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ad390e0fb49d8860a9445044a182e778d</anchor>
      <arglist>(const TwistVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a5cafbeb61d5c6a6fbeac95c5ce8e3b84</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a48e2deaeb3111f9c4b3bd8735a52441f</anchor>
      <arglist>(const TwistVel &amp;arg) const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>abc1e5dd5ebf0295215e0610f041441db</anchor>
      <arglist>(const Twist &amp;arg) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationVel</type>
      <name>Identity</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a4f04b2e1f5b6bc15f75cc3430644324e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationVel</type>
      <name>RotX</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a5093811dbac9b5dbbd717bb241376f24</anchor>
      <arglist>(const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationVel</type>
      <name>RotY</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ace38098fd10b8a8ccbe5abbb3198d5e9</anchor>
      <arglist>(const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationVel</type>
      <name>RotZ</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a22630379ffe864673bb003adf85a4483</anchor>
      <arglist>(const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationVel</type>
      <name>Rot</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a656cd1c47442d72f3c2fc9be017558f8</anchor>
      <arglist>(const Vector &amp;rotvec, const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD RotationVel</type>
      <name>Rot2</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>abea45a6dabc8afd7bce83055cf5265f5</anchor>
      <arglist>(const Vector &amp;rotvec, const doubleVel &amp;angle)</arglist>
    </member>
    <member kind="variable">
      <type>Rotation</type>
      <name>R</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>abedea5aebf8b52c940c2fe0d31888fda</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>w</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>abb9af995b6b6e823d84f730c85d337e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend RotationVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>aca7e61229634c8da283dbe0593bbca24</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend RotationVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a0752b1c5da48d41eb7299921757f432f</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend RotationVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a0df98fafa80d9423317e0533aac2bde5</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a5de55dd5b2ab677385aab17ec44aa59b</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a8c3603deb8779771b9f7aa3d2c0abbf8</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>aab9627c8f9f2cc1fdbfb7420298aa41b</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a3c1b4a9eb847d9bb524dfc6fe830863c</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a9861a9cf65d60b4d7f4bfc8b0523f5d9</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>af8a397a66ab8e7c884b7017c71409927</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a0c7ba87f8bd9371ceb56ebd95878fe39</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>ab49f91ca85ef1cb62803886850c7252f</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1RotationVel.html</anchorfile>
      <anchor>a8a9765dd0afb58e723bbf41ce2362511</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Segment</name>
    <filename>classKDL_1_1Segment.html</filename>
    <member kind="function">
      <type></type>
      <name>Segment</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>ab75739d8cfebb681fe9f06e66fcf1775</anchor>
      <arglist>(const std::string &amp;name, const Joint &amp;joint=Joint(Joint::Fixed), const Frame &amp;f_tip=Frame::Identity(), const RigidBodyInertia &amp;I=RigidBodyInertia::Zero())</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Segment</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a6e68112a9d0aab00af3355aea22bd58e</anchor>
      <arglist>(const Joint &amp;joint=Joint(Joint::Fixed), const Frame &amp;f_tip=Frame::Identity(), const RigidBodyInertia &amp;I=RigidBodyInertia::Zero())</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Segment</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a4f96f291be0b25053c70cf9c4ccd0e97</anchor>
      <arglist>(const Segment &amp;in)</arglist>
    </member>
    <member kind="function">
      <type>Segment &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a2bafa6ce8ec812ff301af0b559788ddc</anchor>
      <arglist>(const Segment &amp;arg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Segment</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a1a887b70a78c25445662c5c08e67185b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>pose</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>af2996e484750859d30e36c07b1b230a9</anchor>
      <arglist>(const double &amp;q) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>twist</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a891f8f4c0747035a4be845b68e345d01</anchor>
      <arglist>(const double &amp;q, const double &amp;qdot) const</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>getName</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a96ac31d50b811ab006e3020b741dfc4c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const Joint &amp;</type>
      <name>getJoint</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>af91efa92f093de9d3faee52b519fa505</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const RigidBodyInertia &amp;</type>
      <name>getInertia</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>ab446f0a1b302f854dd970b7062b47f33</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setInertia</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>ac376a3d7eb6af5fc3c6dc885b6aa2e75</anchor>
      <arglist>(const RigidBodyInertia &amp;Iin)</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>getFrameToTip</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a6a37cfbe5ec3ee4f9a311a17fd96c10d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFrameToTip</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>aef892d1d3c8a36ec85be1bcc3a25adf7</anchor>
      <arglist>(const Frame &amp;f_tip_new)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>name</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a9ce5414b02b566c103686dfbd33053e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Joint</type>
      <name>joint</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>ae8981fb3ce8029e9a8a08b0d0676be9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>RigidBodyInertia</type>
      <name>I</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a3ffb70cbe17486953f7750bb14abd08b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>f_tip</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a8a9aa3f8213da9ec0af2175202d607b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>Chain</name>
      <anchorfile>classKDL_1_1Segment.html</anchorfile>
      <anchor>a65813570c30a3e0656fa523793ff1b86</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>KDL::ChainHdSolver_Vereshchagin::segment_info</name>
    <filename>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</filename>
    <member kind="function">
      <type></type>
      <name>segment_info</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>aa2e4a49ea43906e8ab936fae03692dd0</anchor>
      <arglist>(unsigned int nc)</arglist>
    </member>
    <member kind="variable">
      <type>Frame</type>
      <name>F</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a457a240a1b26201a0b234fac1440390c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Frame</type>
      <name>F_base</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a63520a1c62d1ae2015307bd51f982f3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Twist</type>
      <name>Z</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a7f186f40e148292974b8b8bdb7e72d40</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Twist</type>
      <name>v</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a1cb8a02184e769cae974972a5de73b1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Twist</type>
      <name>acc</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a56734b332c5764f1819f21b900ef7f82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Wrench</type>
      <name>U</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>af9873ee0645a80971fa67b7750a11543</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Wrench</type>
      <name>R</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a449391bbb164eaa133809581f9393910</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Wrench</type>
      <name>R_tilde</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a760dbd17a8fe6f9a0db20c3cadd00c25</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Twist</type>
      <name>C</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>ad49020c77474e81396b5b8afb9134011</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Twist</type>
      <name>A</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a8ebfd6b3a418d5556fe10e97c73c47be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ArticulatedBodyInertia</type>
      <name>H</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a39f58acb118630987d2f394fa8c6237e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ArticulatedBodyInertia</type>
      <name>P</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>af33b218dea4a1f73a3918f087e9d78e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ArticulatedBodyInertia</type>
      <name>P_tilde</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>ab4d835f6d7815268eadd9f7980bb2994</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Wrench</type>
      <name>PZ</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>ab0b0f8c176fb8e4f713300648e3aa49c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Wrench</type>
      <name>PC</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a5cb5388f5c1fbbcbecee6b79ba4d3861</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>D</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a132a817c2f2ea6843248692c5cdaa5f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Matrix6Xd</type>
      <name>E</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a4c3f3097172691fccb14c5442ab4c758</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Matrix6Xd</type>
      <name>E_tilde</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>ac8348e4c7a71acedcaf35593b1136103</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Eigen::MatrixXd</type>
      <name>M</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a587e5a94a7c9df9d766d9a4452f89bcb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Eigen::VectorXd</type>
      <name>G</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>ad50131f62f7d44006cc075683824b07f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Eigen::VectorXd</type>
      <name>EZ</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a8b067919c8c046f3d9134c042c99ffe1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>nullspaceAccComp</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>abb007ef84f8cef456fca26c10c1e5cee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>constAccComp</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a2177d7318b5885ffce1b2b384303df6d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>biasAccComp</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a4a9dd91f780a088188a6790d27285f08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>totalBias</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>aae5819aa1f4c67603a8efc1f9419ad1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>u</name>
      <anchorfile>structKDL_1_1ChainHdSolver__Vereshchagin_1_1segment__info.html</anchorfile>
      <anchor>a54bdfff587c8883d7dfe5ccc7d05ad38</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::SolverI</name>
    <filename>classKDL_1_1SolverI.html</filename>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SolverI</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a2fd94680969bab93b792dabfdcfc9a80</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SolverI</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>ab70782f0d3632c22fcd430ef719d0f2f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a15c4651a994d1c767e14494b37791e79</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Stiffness</name>
    <filename>classKDL_1_1Stiffness.html</filename>
    <member kind="function">
      <type></type>
      <name>Stiffness</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>ae3c8057cabecf153f4396589584d1f37</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Stiffness</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>a8819fb776e0f653aad41edb6e11a7f0c</anchor>
      <arglist>(double *d)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Stiffness</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>a2b49811126d67a3288ff94dd3febe00c</anchor>
      <arglist>(double x, double y, double z, double rx, double ry, double rz)</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>a08bce72f9057c08ba35a692a8a22306a</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>a8b4e438265ae2a90a9104fedd6b9b54d</anchor>
      <arglist>(int i) const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>Inverse</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>a3389cf42d4d822b3a1e1b50dfaf27bf7</anchor>
      <arglist>(const Wrench &amp;w) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>data</name>
      <anchorfile>classKDL_1_1Stiffness.html</anchorfile>
      <anchor>a2c15a0add6f032471e878108d8db4f89</anchor>
      <arglist>[6]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Traits&lt; KDL::doubleVel &gt;</name>
    <filename>structTraits_3_01KDL_1_1doubleVel_01_4.html</filename>
    <member kind="typedef">
      <type>double</type>
      <name>valueType</name>
      <anchorfile>structTraits_3_01KDL_1_1doubleVel_01_4.html</anchorfile>
      <anchor>a97cb0ae5f6c5fa1a72843dabde5201db</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>KDL::doubleVel</type>
      <name>derivType</name>
      <anchorfile>structTraits_3_01KDL_1_1doubleVel_01_4.html</anchorfile>
      <anchor>af1170a6d4ab0c52a8a955862ce31b6ab</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Trajectory</name>
    <filename>classKDL_1_1Trajectory.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>ad8ae3e3bbf67472d7f42c38e899f96dd</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>ad1c506bc9036d6c925aad427f7e879a3</anchor>
      <arglist>(double time) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a3096f422a0cb12afc5072dd202d0bc63</anchor>
      <arglist>(double time) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a7da75e3b7fcc3b64bab8ea59f6a92eb6</anchor>
      <arglist>(double time) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Trajectory *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>ab09b7c631b0fe463d582a68132888347</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>aacbd88537d3e858be3469bb3662c7423</anchor>
      <arglist>(std::ostream &amp;os) const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Trajectory</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a536019d230147eff39bd6f883ec3e799</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Trajectory *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a484266a3723014d32b08e47a0c91507f</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Trajectory_Composite</name>
    <filename>classKDL_1_1Trajectory__Composite.html</filename>
    <base>KDL::Trajectory</base>
    <member kind="function">
      <type></type>
      <name>Trajectory_Composite</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>ae14308ed70509890d74f60667a433eef</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>ad80203c952378126a5f234d89378b629</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a3bad1c85cb6278c22e3c5899249615c8</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a33b9f5a88ccd1d1361cd79ba64a50f97</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>aeba2c09d6bd0bc4fc4b9aed0b9aae146</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Add</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>aeb3addb579922c1b92f1ea9287e0a4ff</anchor>
      <arglist>(Trajectory *elem)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Destroy</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a936fbaf867bbb2a0638d6a8ee7cf5427</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a01647a5e6467d3babe65514e16df87e6</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Trajectory *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>ad8587058de510762437e5f21fef22759</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Trajectory_Composite</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>af06533f6ff751269eca9fecaaf7096c3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Trajectory *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a484266a3723014d32b08e47a0c91507f</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; Trajectory * &gt;</type>
      <name>VectorTraj</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a8b553fb9bdd42abfed3ce1c6162a514f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; double &gt;</type>
      <name>VectorDouble</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a89ba2e2bb00cd3f35612b3e49565bf47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorTraj</type>
      <name>vt</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a98f5d5577d6cbb746ef751fe1a7c1725</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorDouble</type>
      <name>vd</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>aaeb4cfc7d962f5f3f13b66929752b2a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>duration</name>
      <anchorfile>classKDL_1_1Trajectory__Composite.html</anchorfile>
      <anchor>a4ecd3e72d6cec94ad1c12e273fe6e178</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Trajectory_Segment</name>
    <filename>classKDL_1_1Trajectory__Segment.html</filename>
    <base>KDL::Trajectory</base>
    <member kind="function">
      <type></type>
      <name>Trajectory_Segment</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a8cb4b5e40c86319d30b556be8762332f</anchor>
      <arglist>(Path *_geom, VelocityProfile *_motprof, bool _aggregate=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Trajectory_Segment</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a0597ff3647eea94bc4c891d223e1b64b</anchor>
      <arglist>(Path *_geom, VelocityProfile *_motprof, double duration, bool _aggregate=true)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a58f8c8219a952197af059808c2b9c280</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>aa1f83bbfe03238a84dd3f73280703a52</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>ab97f19403883f56aa43f647e3dfffc77</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>aca274f2ae167b9c83eaa24c7f5d44207</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Trajectory *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>abf8db202c2a64f7c4f08ae2947848209</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>abacfbca87fb80791ce64a2ebafdc5de3</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Path *</type>
      <name>GetPath</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a11079bd01a89a0eda80982078f3b8980</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual VelocityProfile *</type>
      <name>GetProfile</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a537731509905693e293c6aac22ae1214</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Trajectory_Segment</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a14a00aafe3ad26baf11240f138c24804</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Trajectory *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a484266a3723014d32b08e47a0c91507f</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VelocityProfile *</type>
      <name>motprof</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a2f3f407a26759dd4e461861fa330d998</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Path *</type>
      <name>geom</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a408b02ea21af479b9ada26a7cd70e57b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>aggregate</name>
      <anchorfile>classKDL_1_1Trajectory__Segment.html</anchorfile>
      <anchor>a37b6f4e849beb7aa22275c895c5a6855</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Trajectory_Stationary</name>
    <filename>classKDL_1_1Trajectory__Stationary.html</filename>
    <base>KDL::Trajectory</base>
    <member kind="function">
      <type></type>
      <name>Trajectory_Stationary</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>aec186b66aa093ca1e43ab7fb24cc5b91</anchor>
      <arglist>(double _duration, const Frame &amp;_pos)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>afac070608af534e42e37adb4b16ff7b2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Frame</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>af3695ed188cdb7d6276187a072a32901</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>ad064a15c39729cabd7b355378c7c155c</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Twist</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>ad21c3b45921d0ffcc42f319fdbc659d6</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>ae16e7210aeb50bf8314243c9053666c8</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Trajectory *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>ac7a576a9bd621ba73786098b277a6925</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Trajectory_Stationary</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>ab9a3dfd6f667b2dd7250ba8f200eb87d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Trajectory *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1Trajectory.html</anchorfile>
      <anchor>a484266a3723014d32b08e47a0c91507f</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>duration</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>a3909744ffb8c685da89d890ea8ce4609</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frame</type>
      <name>pos</name>
      <anchorfile>classKDL_1_1Trajectory__Stationary.html</anchorfile>
      <anchor>a2dccf74509bf5d4e9918479493311112</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Tree</name>
    <filename>classKDL_1_1Tree.html</filename>
    <member kind="function">
      <type></type>
      <name>Tree</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>acdc877b83d656b85ac5e8d9a1f162f3c</anchor>
      <arglist>(const std::string &amp;root_name=&quot;root&quot;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Tree</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>adb37b7fbd9be35e875efc3c84af67090</anchor>
      <arglist>(const Tree &amp;in)</arglist>
    </member>
    <member kind="function">
      <type>Tree &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a0bae12b4952112c15c3647ae04dd35e9</anchor>
      <arglist>(const Tree &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addSegment</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a6a0b05c008c3d1d64696560bd30df666</anchor>
      <arglist>(const Segment &amp;segment, const std::string &amp;hook_name)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addChain</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a64846c4151ff7ef97897ae4b462a23c4</anchor>
      <arglist>(const Chain &amp;chain, const std::string &amp;hook_name)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addTree</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a8696ea29e3e98668f37b4ba937d0e9ba</anchor>
      <arglist>(const Tree &amp;tree, const std::string &amp;hook_name)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNrOfJoints</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>afd53537e6aeacc9f8a524f6ea90d1360</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNrOfSegments</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a654283bac6ca20937f32c728188204e6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>SegmentMap::const_iterator</type>
      <name>getSegment</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a492af8de617b36db29cbbda7d79e2be8</anchor>
      <arglist>(const std::string &amp;segment_name) const</arglist>
    </member>
    <member kind="function">
      <type>SegmentMap::const_iterator</type>
      <name>getRootSegment</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a5e09f42e17a4916ddb82467f07c3b777</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getChain</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a8f68dc4d321c6c74a35f30fb1966b1e7</anchor>
      <arglist>(const std::string &amp;chain_root, const std::string &amp;chain_tip, Chain &amp;chain) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getSubTree</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>acf6603c458e8ebbc86e20e4185b2c42c</anchor>
      <arglist>(const std::string &amp;segment_name, Tree &amp;tree) const</arglist>
    </member>
    <member kind="function">
      <type>const SegmentMap &amp;</type>
      <name>getSegments</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a311a9126ac60f87246223ef584df49c1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Tree</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a992c012dce434166eebaa759087e5fdb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>addTreeRecursive</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a825fb0cbb281afd4dd03fe7efe1974f0</anchor>
      <arglist>(SegmentMap::const_iterator root, const std::string &amp;hook_name)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>SegmentMap</type>
      <name>segments</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a5004f557bed3267e3a501fa8bcd6bba2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nrOfJoints</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a2ceab0992f079a0c660ecea04adc0c5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nrOfSegments</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a8243891d120587880d5c0208a5e4c41d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>root_name</name>
      <anchorfile>classKDL_1_1Tree.html</anchorfile>
      <anchor>a44ddc18522a5cd2ea096dce215f309ec</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeElement</name>
    <filename>classKDL_1_1TreeElement.html</filename>
    <member kind="function">
      <type></type>
      <name>TreeElement</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>a9305dfb254ef08249d2f2ef2e59d3f0a</anchor>
      <arglist>(const Segment &amp;segment_in, const SegmentMap::const_iterator &amp;parent_in, unsigned int q_nr_in)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static TreeElementType</type>
      <name>Root</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>aecc54c66c2b34d382db30fb6b33dfe45</anchor>
      <arglist>(const std::string &amp;root_name)</arglist>
    </member>
    <member kind="variable">
      <type>Segment</type>
      <name>segment</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>a9cb3f19941e41a5d629da36d2a632dd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>q_nr</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>a675746fbafaaa804cc738e011648a033</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SegmentMap::const_iterator</type>
      <name>parent</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>a97b917483495572c1974cdb42be1f90f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::vector&lt; SegmentMap::const_iterator &gt;</type>
      <name>children</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>abfe162c8158fc7e3c4f756a0c3f263b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>TreeElement</name>
      <anchorfile>classKDL_1_1TreeElement.html</anchorfile>
      <anchor>a57fb29e6706d756f73251fc8b3577550</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeFkSolverPos</name>
    <filename>classKDL_1_1TreeFkSolverPos.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos.html</anchorfile>
      <anchor>a67adfad687f9f1e2e9fd5bca8eb5bb9a</anchor>
      <arglist>(const JntArray &amp;q_in, Frame &amp;p_out, std::string segmentName)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeFkSolverPos</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos.html</anchorfile>
      <anchor>a405729e9f7b7dc4efd10169ddd17002c</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeFkSolverPos_recursive</name>
    <filename>classKDL_1_1TreeFkSolverPos__recursive.html</filename>
    <base>KDL::TreeFkSolverPos</base>
    <member kind="function">
      <type></type>
      <name>TreeFkSolverPos_recursive</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos__recursive.html</anchorfile>
      <anchor>a229604f04eeb4a546b6b05f03d4f9239</anchor>
      <arglist>(const Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TreeFkSolverPos_recursive</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos__recursive.html</anchorfile>
      <anchor>a564f632bc2ecdc6dc42413fc5c54ab55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>JntToCart</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos__recursive.html</anchorfile>
      <anchor>a1d88124902985f80eb5144ac78cd9ab6</anchor>
      <arglist>(const JntArray &amp;q_in, Frame &amp;p_out, std::string segmentName)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Frame</type>
      <name>recursiveFk</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos__recursive.html</anchorfile>
      <anchor>a8cce7769402bf3af7a269d0b0da65e50</anchor>
      <arglist>(const JntArray &amp;q_in, const SegmentMap::const_iterator &amp;it)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Tree</type>
      <name>tree</name>
      <anchorfile>classKDL_1_1TreeFkSolverPos__recursive.html</anchorfile>
      <anchor>a32e764248fe50e2f5558cb8aee85d1e1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIdSolver</name>
    <filename>classKDL_1_1TreeIdSolver.html</filename>
    <base>KDL::SolverI</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIdSolver.html</anchorfile>
      <anchor>a2124bba6e94b9d83534113fd372eb653</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;q_dotdot, const WrenchMap &amp;f_ext, JntArray &amp;torques)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a15c4651a994d1c767e14494b37791e79</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIdSolver_RNE</name>
    <filename>classKDL_1_1TreeIdSolver__RNE.html</filename>
    <base>KDL::TreeIdSolver</base>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_DEGRADED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a037090bae35fcc0264c70287d3b926d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOERROR</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a95f2e049884a3a08fc4f839e4cbf6191</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NO_CONVERGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148aa19df6d3f1007614f98aadbaea84d89f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_UNDEFINED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a4ad4b1f9f4f4c7dd43898c06ecc73c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_UP_TO_DATE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a1803914d79d602cbc5ffced121c5278c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SIZE_MISMATCH</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a713b62c139a0caee351f94aa7598e56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_MAX_ITERATIONS_EXCEEDED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a17178be368599dd456b54c2d37c4fb50</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_OUT_OF_RANGE</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148af7440fec45c6d1657a89d344ff5b6583</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_NOT_IMPLEMENTED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148a749aec827a10228473b653f18bc20197</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a73d6b62495bbc2626a85004002b2c148ac70eed0a4997fd525b00e5eddeb39ba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TreeIdSolver_RNE</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a1ed0550833118fc583823d99bb2f29b3</anchor>
      <arglist>(const Tree &amp;tree, Vector grav)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a75267397fac4995f58af1f006e0a18ad</anchor>
      <arglist>(const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;q_dotdot, const WrenchMap &amp;f_ext, JntArray &amp;torques)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateInternalDataStructures</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a1a2850b7607a176313f03f7fa61d6814</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a0473a25058060878b90ace7324ae1d47</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>strError</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a5f9c4f020d4d609d8d10a7a949e8195c</anchor>
      <arglist>(const int error) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>error</name>
      <anchorfile>classKDL_1_1SolverI.html</anchorfile>
      <anchor>a62d29639f6396a0660ce7e3958d14718</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>initAuxVariables</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>abb1444e39ff3dac14e7484464e486720</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>rne_step</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a4a876eda53317784644758022e12c298</anchor>
      <arglist>(SegmentMap::const_iterator segment, const JntArray &amp;q, const JntArray &amp;q_dot, const JntArray &amp;q_dotdot, const WrenchMap &amp;f_ext, JntArray &amp;torques)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Tree &amp;</type>
      <name>tree</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>afacdc675649fef061300789a98f42abc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>nj</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a380a2d726491855beae017c7e2576c86</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>ns</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a85d747210462c0ccf108165fce24b452</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; std::string, Frame &gt;</type>
      <name>X</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a4699de17a1caca970add4feda464da81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; std::string, Twist &gt;</type>
      <name>S</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a6469f77cd47bea95975c0e544a5c2441</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; std::string, Twist &gt;</type>
      <name>v</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>aaebe43d51338496265478bde334169ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; std::string, Twist &gt;</type>
      <name>a</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a47aa943ffc89504001e403a6026f576d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; std::string, Wrench &gt;</type>
      <name>f</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a4820c36c37c53ea7c75462566d78f966</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>ag</name>
      <anchorfile>classKDL_1_1TreeIdSolver__RNE.html</anchorfile>
      <anchor>a58885d9cd050863cb3222afa05ee14e4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIkSolverPos</name>
    <filename>classKDL_1_1TreeIkSolverPos.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos.html</anchorfile>
      <anchor>a77795829bd2d1fd8fe1a56a733fea37f</anchor>
      <arglist>(const JntArray &amp;q_init, const Frames &amp;p_in, JntArray &amp;q_out)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeIkSolverPos</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos.html</anchorfile>
      <anchor>a0fae35ba2aeb4ec2ab0ef55d077177e6</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIkSolverPos_NR_JL</name>
    <filename>classKDL_1_1TreeIkSolverPos__NR__JL.html</filename>
    <base>KDL::TreeIkSolverPos</base>
    <member kind="function">
      <type></type>
      <name>TreeIkSolverPos_NR_JL</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a3cc4f4023f588eaf7f8458a0da0cd6d5</anchor>
      <arglist>(const Tree &amp;tree, const std::vector&lt; std::string &gt; &amp;endpoints, const JntArray &amp;q_min, const JntArray &amp;q_max, TreeFkSolverPos &amp;fksolver, TreeIkSolverVel &amp;iksolver, unsigned int maxiter=100, double eps=1e-6)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TreeIkSolverPos_NR_JL</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a868976a0d7499c0d620c5c349ae28fe1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a21593faff46cb29d28674de48fb0fa45</anchor>
      <arglist>(const JntArray &amp;q_init, const Frames &amp;p_in, JntArray &amp;q_out)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const Tree</type>
      <name>tree</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>ac0ea3150a0576ec82ce1ebc7f6ec23f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_min</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>acc5ea1a01ec3350fc14370d4e3c03669</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_max</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>ad0d4ce5c070e78329255efb56afc5063</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TreeIkSolverVel &amp;</type>
      <name>iksolver</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>aec6d9e353ef054c63b1e9f61187b39cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TreeFkSolverPos &amp;</type>
      <name>fksolver</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>ad3a75e059477022391a9208240bd7e86</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>delta_q</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a41b28d349dcb140bb5bb4c915fcd12f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frames</type>
      <name>frames</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a53eae1a00c9f812ebb4531e0ab5f897f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twists</type>
      <name>delta_twists</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a0338c7b679c8098fed2a9174734d6b64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; std::string &gt;</type>
      <name>endpoints</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a5df2096269e5ea970afb7e4fa715c185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>maxiter</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a50a8c815ac8df7064a94e56862be52d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>eps</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__NR__JL.html</anchorfile>
      <anchor>a6e593b2fd2228bb6ebef50765885c619</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIkSolverPos_Online</name>
    <filename>classKDL_1_1TreeIkSolverPos__Online.html</filename>
    <base>KDL::TreeIkSolverPos</base>
    <member kind="function">
      <type></type>
      <name>TreeIkSolverPos_Online</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>af32d06d9ddea007429be06cdf1148a0d</anchor>
      <arglist>(const double &amp;nr_of_jnts, const std::vector&lt; std::string &gt; &amp;endpoints, const JntArray &amp;q_min, const JntArray &amp;q_max, const JntArray &amp;q_dot_max, const double x_dot_trans_max, const double x_dot_rot_max, TreeFkSolverPos &amp;fksolver, TreeIkSolverVel &amp;iksolver)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TreeIkSolverPos_Online</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>ab733f78c6e42e04173b1958f51350f0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>a70423f4ab98d4d1d536a31eb97ef8313</anchor>
      <arglist>(const JntArray &amp;q_in, const Frames &amp;p_in, JntArray &amp;q_out)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>enforceJointVelLimits</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>a17ff01805255ce10b32517c483fe9292</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>enforceCartVelLimits</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>ace2f80facce701f37444ad2ed0c95af7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_min_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>ad20789b436ccd0a2bb47e9e34193cb4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_max_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>aae026737b65358e7ce39a290188112c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_dot_max_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>a08f08e27fab6562b9d5e98597b96e0cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>x_dot_trans_max_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>a799c3980c341d1e503541922617208f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>x_dot_rot_max_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>ac4438b9862216ac66062b8db20dae6e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TreeFkSolverPos &amp;</type>
      <name>fksolver_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>af4741d06d4a624164e5503b43366eaeb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TreeIkSolverVel &amp;</type>
      <name>iksolver_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>acdc359e2ded29e09fd4c39bed8befb30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>JntArray</type>
      <name>q_dot_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>a6fd90b7fe6c1e9895788f90d53f8f26b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twist</type>
      <name>twist_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>af060ac0b793d8b6281581be37ccfec3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Frames</type>
      <name>frames_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>a754d7752b838578e0118b0ced19c61f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Twists</type>
      <name>delta_twists_</name>
      <anchorfile>classKDL_1_1TreeIkSolverPos__Online.html</anchorfile>
      <anchor>afd4833fbffcaccb14df1ca11e30ff3b1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIkSolverVel</name>
    <filename>classKDL_1_1TreeIkSolverVel.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel.html</anchorfile>
      <anchor>aba23834412d2361335b188aee8dfb4fd</anchor>
      <arglist>(const JntArray &amp;q_in, const Twists &amp;v_in, JntArray &amp;qdot_out)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeIkSolverVel</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel.html</anchorfile>
      <anchor>aea2a6a717589be92b83d1685539bd081</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeIkSolverVel_wdls</name>
    <filename>classKDL_1_1TreeIkSolverVel__wdls.html</filename>
    <base>KDL::TreeIkSolverVel</base>
    <member kind="function">
      <type></type>
      <name>TreeIkSolverVel_wdls</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a63a76294e5e67ff40ba3206e950bdb8f</anchor>
      <arglist>(const Tree &amp;tree, const std::vector&lt; std::string &gt; &amp;endpoints)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeIkSolverVel_wdls</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a1f283c3a0acadd376eb7d5654369bd04</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>CartToJnt</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>abf66f6cf12b0198206672a3162995f71</anchor>
      <arglist>(const JntArray &amp;q_in, const Twists &amp;v_in, JntArray &amp;qdot_out)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWeightJS</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a02fee598ee007d6335f19621fba64f2e</anchor>
      <arglist>(const MatrixXd &amp;Mq)</arglist>
    </member>
    <member kind="function">
      <type>const MatrixXd &amp;</type>
      <name>getWeightJS</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>ad092a16c17ad0238af957bbfda48a85a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWeightTS</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a4e617df577aa819ea6d791c401c1dc3b</anchor>
      <arglist>(const MatrixXd &amp;Mx)</arglist>
    </member>
    <member kind="function">
      <type>const MatrixXd &amp;</type>
      <name>getWeightTS</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>acdf133cd6673452f506837280726774c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLambda</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>aa8a224fd34a83b8040705cf9e791d03a</anchor>
      <arglist>(const double &amp;lambda)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLambda</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>ab211120bc152408c60a52450e2be01f8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>E_SVD_FAILED</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a532c5be4d009613a9a52bef66c736160</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Tree</type>
      <name>tree</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a88d05ff2a4d04de7f342e59e5d5fed4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TreeJntToJacSolver</type>
      <name>jnttojacsolver</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a57b38bdee58095fdd2d090209d98bc3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Jacobians</type>
      <name>jacobians</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a685cb7e634ae290656508981d0796c39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>J</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>aca9440d0755ab260560e04e36bf7f071</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>Wy</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a8626762181127ead4c3e7468f417fca3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>Wq</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>afcaaaa4faf893f2dee0f1f6a5a52ec9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>J_Wq</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>ac5c83ba1426cc41a5bc2abe9f80cb7fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>Wy_J_Wq</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a35c92985da7946a964b1844d1257818a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>U</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>ac83a5dce7a79de9175874d83f420de63</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>V</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a2277e467f24dd0c2e4ae7409c349404d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>Wy_U</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a0fc25743a9dbf519d2cfc6b583c2a69d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MatrixXd</type>
      <name>Wq_V</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a6a1ff17d8f597f3789d58e4f51ad4826</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>t</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>ac6cecd11c6ba36ab47dcbccd3ceef50a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>Wy_t</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a3a0307b8653123a60688971d3eaf0769</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>qdot</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>aa7144b58059d65d9e424afd9927fbebd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>tmp</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a50fc39350dd53c9379953fbd1eb1d74a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>VectorXd</type>
      <name>S</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>ace4486dc3eea51b760c38622baee16e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>lambda</name>
      <anchorfile>classKDL_1_1TreeIkSolverVel__wdls.html</anchorfile>
      <anchor>a759b7e23c93a430fb64791133095ef09</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TreeJntToJacSolver</name>
    <filename>classKDL_1_1TreeJntToJacSolver.html</filename>
    <member kind="function">
      <type></type>
      <name>TreeJntToJacSolver</name>
      <anchorfile>classKDL_1_1TreeJntToJacSolver.html</anchorfile>
      <anchor>a00bd62bc545ed743d5892e4f0a10d167</anchor>
      <arglist>(const Tree &amp;tree)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeJntToJacSolver</name>
      <anchorfile>classKDL_1_1TreeJntToJacSolver.html</anchorfile>
      <anchor>a97d25e590fc7946d756408bb54af8dc8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>JntToJac</name>
      <anchorfile>classKDL_1_1TreeJntToJacSolver.html</anchorfile>
      <anchor>a81ea65b5ea13f9fd9e99a612fe5b6171</anchor>
      <arglist>(const JntArray &amp;q_in, Jacobian &amp;jac, const std::string &amp;segmentname)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>KDL::Tree</type>
      <name>tree</name>
      <anchorfile>classKDL_1_1TreeJntToJacSolver.html</anchorfile>
      <anchor>afb235a2b69405819547718721935f17b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Twist</name>
    <filename>classKDL_1_1Twist.html</filename>
    <member kind="function">
      <type></type>
      <name>Twist</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a78cd07ebe62d640d862c7e46e0063837</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Twist</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a14c164a7b0e81336d1e3e15a2585e150</anchor>
      <arglist>(const Vector &amp;_vel, const Vector &amp;_rot)</arglist>
    </member>
    <member kind="function">
      <type>Twist &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>ad357a06d42137c4973ac6b368fd6be74</anchor>
      <arglist>(const Twist &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a34b35ebb6c8e2ac3b19ca7d0aac5f467</anchor>
      <arglist>(const Twist &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a35ff2697b863859d0c1d63b48120b406</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a8b509ec22cf6bfbf46f533882d923409</anchor>
      <arglist>(int i) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>ad526767d8b1369ff2493680f1df15ddf</anchor>
      <arglist>(int index) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>ab044b0f28eccd7a452a644c311242a13</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>aaa84dee400c40843546885ee6d7f8ec7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>RefPoint</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>abd257927af744c4b6e985edc22f0b667</anchor>
      <arglist>(const Vector &amp;v_base_AB) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Twist</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>aeb2250f1de9e0c6f9fe738dc8c083bc9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>vel</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>adda560fbd643ba2448d519fce626b680</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>rot</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a5ab2bb436b67c902e9c7735c4df16eba</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>aa9d2bf0f1d1d2655fb37b513d3159be3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>aee3a66b0ddf3b769f015c89b610db0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a04b73370fb4ad857f2b4cb720f3c9113</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>ac7e5ad8e49d4f92b49b5d6b16e606158</anchor>
      <arglist>(double lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a939e42c12cc59ac6eb8f8152c4461ea1</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>ad0f34bc2ed48c3caa688b8e405466985</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a6c7c88bf859de28239ded2fdbcd848bf</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>aa659300da279e4d00b44489a755d4be9</anchor>
      <arglist>(const Twist &amp;arg)</arglist>
    </member>
    <member kind="friend">
      <type>friend double</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a429650b165c7435c0eacfd7777c0ed8a</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend double</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a4aacbaba41da650a85bd3c1348839472</anchor>
      <arglist>(const Wrench &amp;rhs, const Twist &amp;lhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a8a39c17bd375db7c35e9d8f475770234</anchor>
      <arglist>(Twist &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>friend Twist</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a969cd47ef10751021ada52c678503ce7</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a10f7a1660ecf13906fc0808f9d264d33</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a4d2986be7f6dd2251b5202b94d777cc9</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>a5a541a88ae93c7a7735857a3d5bf257e</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Twist.html</anchorfile>
      <anchor>afd3d551a546d21e9e3fd58d370cdc597</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TwistAcc</name>
    <filename>classKDL_1_1TwistAcc.html</filename>
    <member kind="function">
      <type></type>
      <name>TwistAcc</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>aa24af378a857c3a1f115b0de27c3c623</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TwistAcc</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>ad42cc23572d4a1cf85b820fff33155dc</anchor>
      <arglist>(const VectorAcc &amp;_vel, const VectorAcc &amp;_rot)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a96cd87ecd3ccf98094c41d180cc25b3f</anchor>
      <arglist>(const TwistAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a597927985f5c69ad7d0dac2a2a3a094a</anchor>
      <arglist>(const TwistAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a6ac917b8759615f0b6e487fcbb4bd62c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistAcc</type>
      <name>RefPoint</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>aca9339a9242b9ca4db1660e5e434e4df</anchor>
      <arglist>(const VectorAcc &amp;v_base_AB)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetTwist</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>ad0a317be374b9414e73c972514720cd6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetTwistDot</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a998e8685995caf362ee12c91e6cddb10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD TwistAcc</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a8a9f5ab853ae1e720b7c4864142b3cdc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>VectorAcc</type>
      <name>vel</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>ad94248f183c058e5d2322d27eb9e7b47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>VectorAcc</type>
      <name>rot</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a4ba630f00bd559a480eec878cb8a2682</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>RotationAcc</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a528d540fc075889e7e7e3ba804c3408e</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>FrameAcc</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>ae88ad734b0aa0d8d7da499bf68785f75</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a627e8cf60b86b20edd6e80a5e2f7ba29</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a867fd098ebef44ced40a1dc36f77ec8c</anchor>
      <arglist>(double lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>af60504d37c7dc5a0513742ef364b288b</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>aec82b348bd30c28c461e47967c0de0f8</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a459bfe7bb8978d8afa862d823c947e71</anchor>
      <arglist>(const doubleAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a6caa63bc280aca87efedbacca5675407</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a3c56004df28596ae4b0242151bc8eb97</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a480791c94b8262b5d9507b10d477b423</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistAcc</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a4ac332fcd4b1924890d58132fcbbd185</anchor>
      <arglist>(const TwistAcc &amp;arg)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a65ea9513d85baa1191650eed6cae2ef8</anchor>
      <arglist>(TwistAcc &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a4ed942a12f9b38bf7b240229a6ca526a</anchor>
      <arglist>(const TwistAcc &amp;a, const TwistAcc &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a2e1a2a5094630f0482d1eb57c035b03d</anchor>
      <arglist>(const Twist &amp;a, const TwistAcc &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1TwistAcc.html</anchorfile>
      <anchor>a8adbc38751b0fe0b17c7cfdb826f9ba6</anchor>
      <arglist>(const TwistAcc &amp;a, const Twist &amp;b, double eps)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::TwistVel</name>
    <filename>classKDL_1_1TwistVel.html</filename>
    <member kind="function">
      <type></type>
      <name>TwistVel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>aead0c7a1cf2cf08e31a82dfc5a2aeb00</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TwistVel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>afdc49c504bbeec753f7525e0e0051665</anchor>
      <arglist>(const VectorVel &amp;_vel, const VectorVel &amp;_rot)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TwistVel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a32c40e67d9dfb8d2071f7a46036cd12c</anchor>
      <arglist>(const Twist &amp;p, const Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TwistVel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a8ef2a1b969d3fd2813e07510ff7f1956</anchor>
      <arglist>(const Twist &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>value</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a51ebc789ff87ade9ca38f85fb99b28f0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>deriv</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a1ec210b59ed94f07506604f51e6040be</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ab0a5cf2bbbe689ce5a2e748999a025a3</anchor>
      <arglist>(const TwistVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a3fde598746a106cb75f2f256d4036284</anchor>
      <arglist>(const TwistVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a66c9e0046f2a4d65dde897e5cad4e246</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>RefPoint</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ad740e29afce9114035fa66ad8184fce8</anchor>
      <arglist>(const VectorVel &amp;v_base_AB)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetTwist</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a6026aec60ee1a155f852bf87dc7f9a2e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>GetTwistDot</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a911420803a6b3c82df564c4f1277a112</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD TwistVel</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a261c9168c653f34eb67f0679ef43507c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>VectorVel</type>
      <name>vel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a795a8e31b689557d518ce5c6a2eb7ee8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>VectorVel</type>
      <name>rot</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ada2aaceb2bda6f65edf236d4bc6590e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>RotationVel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>accbca000f837dffa7d6ed9513636a489</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>FrameVel</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a92eff68ecdc06f1feaee4e7cadcff82d</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ac5fd497893784560d52df09c7c3b2490</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a49a2035e7df3e65b4ef38700d42311cb</anchor>
      <arglist>(double lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a15de062492f775ea2b39f196f4bfcd36</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>aded5556f6f0bf68f28d4e47f6401cdd1</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a5b8e4e97309ee3afa80204661f585723</anchor>
      <arglist>(const doubleVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ae19fdafe289d0d30f78cb3f05dbad5fc</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>aa491de4c4c876ce0e196e10e787129d3</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a45b8824f34f499e41d6898d6d1e52146</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend TwistVel</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ac4a345510ed14d82e9dd639bbfed29b2</anchor>
      <arglist>(const TwistVel &amp;arg)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a2924272808fa00c3e3f6c18a6173d286</anchor>
      <arglist>(TwistVel &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>aedf55f074ee29ed865c347416ff30e83</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a143a04c1c3e61dcbd2e785d55f1d7a54</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>ac87bb664949308155df8130c8723543e</anchor>
      <arglist>(const TwistVel &amp;a, const Twist &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a07f5ed401b9e0f039c46b3ce96e9bb6f</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>aca4b5f084c74a32b9def3ef8d55645b4</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a9148d5a625fb8312e17bcccb246e6cc1</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a172b29429afb7e3ba00ebdb56797eead</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a0f327945243888386e0ad187da3742fd</anchor>
      <arglist>(const TwistVel &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1TwistVel.html</anchorfile>
      <anchor>a2bcade1aafb4a2ed02267be51d754cea</anchor>
      <arglist>(const TwistVel &amp;a, const Twist &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Vector</name>
    <filename>classKDL_1_1Vector.html</filename>
    <member kind="function">
      <type></type>
      <name>Vector</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a8e7413d32d76152fb64dbb440ce34fd5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Vector</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a05d50ffeedd10ed4758fa102a047f085</anchor>
      <arglist>(double x, double y, double z)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Vector</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a25eb8c0bef6d3a3fb521fc13b7b0415e</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a7de07a01933c474bba6406d9392a6839</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>ab2446f1e1c0a1ec8fc42f29259f43b23</anchor>
      <arglist>(int index) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a3897f8e1b819ac710918030f70db0c12</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a4a05df28b5418bb198859c17cc01ee3f</anchor>
      <arglist>(int index) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>ad61e6cfc1d4fb17192c3e57ebd957a1b</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>x</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a9a07c1943fa9132a95ab98069d976c80</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>y</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a5177abd2f89d6f3bc891306083e62075</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>z</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a443e864c08b2cbd2b48b1d85b1da8ea5</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>x</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a880fa3dee62db46bc15544759ba1a18d</anchor>
      <arglist>(double)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>y</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>aa3edd424488185d6324179c1ae8b9492</anchor>
      <arglist>(double)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>z</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a996c860124c1ae5c3ceac2744c74a20f</anchor>
      <arglist>(double)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a18b996436214594500892b6cfd5e1aad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Vector &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a20668af899021cbd59dc92211a32a2c8</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a6e70ce6aa6a38df00e518857b3aa4115</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>Normalize</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a82226cbbe86665615c3548cad5d8855f</anchor>
      <arglist>(double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>Norm</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>ade3f16bb567c5f4ab314346605c66056</anchor>
      <arglist>(double eps=epsilon) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set2DXY</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>aaf4b99e0da51be7806ac5aaeb8c353aa</anchor>
      <arglist>(const Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set2DYZ</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>aee5feebe23a0f950dcb24e3c9e158879</anchor>
      <arglist>(const Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set2DZX</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a6d695cbbecbb108ba01d34ac26429960</anchor>
      <arglist>(const Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set2DPlane</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a005f4c09544fbe00f8fd59e9793d07e0</anchor>
      <arglist>(const Frame &amp;F_someframe_XY, const Vector2 &amp;v_XY)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Vector</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>aac50a5f60447f9cb7b4a510c4695ab89</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>data</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a97106b4583f8e2ecf39ed7682b945bd1</anchor>
      <arglist>[3]</arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>aa9d2bf0f1d1d2655fb37b513d3159be3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>aee3a66b0ddf3b769f015c89b610db0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>abe5f3e3747654906e6e2b506947675cd</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>af1b7f920324ab230c303c352421c799a</anchor>
      <arglist>(double lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a25d9bb5f010ee074e6ae3f1ade146927</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a20bc1d82d45f4a1be572ee0131e221e5</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>ac05824c584cfc758e7c79e215ebda4ec</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a7cf9d5b6086b4ece4eeeb6ca333906ea</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a5eff5e8fcf678ef559ff40f236865596</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="friend">
      <type>friend double</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a05cf85096758f8283563aa8e98f05590</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a19c2eb030bca79fcb5456642f0f2f55d</anchor>
      <arglist>(Vector &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a3fc448bfad4d9cdc3daa7067d5a53cda</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>a3c0498fec3046f477a2399a21ab921ff</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Vector.html</anchorfile>
      <anchor>ae46ad0d04e82adad56d33036cb25d35b</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Vector2</name>
    <filename>classKDL_1_1Vector2.html</filename>
    <member kind="function">
      <type></type>
      <name>Vector2</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a61947284267a38dcf7bec4ef2e3c27e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Vector2</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a3a10b552eeb77bbddd7ee91d88347be0</anchor>
      <arglist>(double x, double y)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Vector2</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a4d5aec0791020652d9ad88d7af9e4d49</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector2 &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a2c95e2dcd894593c8ada80d82002cd63</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>adc0127710b5feb3d9125408230805c79</anchor>
      <arglist>(int index) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a5b6a7898dbaeda3e1cb01e46a984528c</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a3734a36ad91a26249178b6524fcf823f</anchor>
      <arglist>(int index) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a6730420b6a720acf420af6fa43e09b0b</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>x</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a2a764bf9b8a955f73b2ab4fe9afb73ea</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>y</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>ae294c39e8513564475e25364fa5e73a2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>x</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>af8206f6ac8b066274b8c6bb493be462e</anchor>
      <arglist>(double)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>y</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>ab0416b9804fdb30ebd93f60e432fccdc</anchor>
      <arglist>(double)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a17a8dca236c36d4439e4ac23e44d1267</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Vector2 &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>abd79d1ba9dc9216ca25dd6084252672c</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Vector2 &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a8826f328a3f6a7384422015bd2accbe6</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>Normalize</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a40f74420af6ffb178f7a8550a07508c1</anchor>
      <arglist>(double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>Norm</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>ac94ac7bcbb534395ead55de5c71dbdba</anchor>
      <arglist>(double eps=epsilon) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set3DXY</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a4afdc0ed3f56cb909bfadb8aedfce821</anchor>
      <arglist>(const Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set3DYZ</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a8e6163f1b083033a7811e6f91ac48231</anchor>
      <arglist>(const Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set3DZX</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a2ab51d98ce92821f3a14695d19eb506e</anchor>
      <arglist>(const Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set3DPlane</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>ae78a8356c4eeaa405467305a663f8c58</anchor>
      <arglist>(const Frame &amp;F_someframe_XY, const Vector &amp;v_someframe)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Vector2</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a0674450ce292d200c8f5f42a02d8640b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>data</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>afbc4d03121bf64ef1ba33c4dbe9a4b2e</anchor>
      <arglist>[2]</arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Rotation2</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a87923ee3b2646a8c3e7afb670fffdfc7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a1ef3d0cc8e3dd6cefa95547833663ae5</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>af22f271f2b701d51f44af41cbf2302d6</anchor>
      <arglist>(double lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a7495f460f356a1ce0578eca886d9f4a0</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>aaebb3c4810741b93b24774477e9f6df1</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a15d6c1a731e630639da3fe879b06d995</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>aa9b8ef35e3a946a280975941be5ddd6f</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Vector2</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a08a32eda7d30cd9e54881485f0c0cf6a</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a94411312136a13e94e0d4741becfca2f</anchor>
      <arglist>(Vector2 &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>ac2a4e8efcac69ef3a6a040b02a7de214</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a2a345fcc6cd429f920e382803125977c</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Vector2.html</anchorfile>
      <anchor>a03fc91b62c31dc6b5c99956b8e76b62e</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VectorAcc</name>
    <filename>classKDL_1_1VectorAcc.html</filename>
    <member kind="function">
      <type></type>
      <name>VectorAcc</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a62670785f61a910aeafe485b2c97ab92</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VectorAcc</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a2b6c09431ee57b0b2e553e06fb7115e8</anchor>
      <arglist>(const Vector &amp;_p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VectorAcc</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>aa532092c83c3fb3bb55ca152324887f6</anchor>
      <arglist>(const Vector &amp;_p, const Vector &amp;_v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VectorAcc</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>ac0bf9e0b0e3d9cd57c392933dc0c9521</anchor>
      <arglist>(const Vector &amp;_p, const Vector &amp;_v, const Vector &amp;_dv)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>aca3f5fd92b7e16aeeb0ed68e3d5197b9</anchor>
      <arglist>(const VectorAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>af78c3a90f9de475c884e2a6a6484df25</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a734056d50ab1a42d130b6ff33361f048</anchor>
      <arglist>(const VectorAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorAcc &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a6a82be46f9acfb85a2a704210ff31b9a</anchor>
      <arglist>(const VectorAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a84952bdaa7ceca4553998bc9d1049b7b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleAcc</type>
      <name>Norm</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>ac38d5fbfa4532093dc562b52acf8e287</anchor>
      <arglist>(double eps=epsilon)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD VectorAcc</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>af8d2e783edfb7c0bd1c65d4dff4d5fe0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>p</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a2462caa3ae6901a62f1f1f892c574e68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>v</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a6bc29ad66bf41cee375ae6f765f05d31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>dv</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a6225055dc646eb6c30cc6a8a576585d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a2cfd0e2d4d04cc779157c0d888e64969</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>aad0799c4dab7af3f88a4e236dca1d700</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a183d111871f9430ee1b7e2753ffe20bb</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a94e367a93e8f2745abe96f55734e34b8</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a27a23fdbbabd9913f2501fead5575f7f</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a2a3f5867d1c9ee9804cb243815c91803</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>afdc27f049d49ccfc0bd9fd9c3834156b</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a154263bc80f0b4cd6fb4e1a9302b0e0c</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a177ac9dfc3b61a4b99a7bdaeff399ea2</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a0f96e99ac574ccc464745ce2f797c108</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>ad92fcec589ed89a6598cf83d3bc96e6f</anchor>
      <arglist>(double r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a78e980909f239e1f86134ceee21f8098</anchor>
      <arglist>(const doubleAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a745e144ec5e387fc644c433cffcd057c</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a4227892f247309971bdb78bc180e40eb</anchor>
      <arglist>(const Rotation &amp;R, const VectorAcc &amp;x)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a29fd501dc8df9c3790ec370ddb76ecc6</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>abbb0360076efe556997f4a1a31443b5d</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a7929a1f429cdcb18f1bd9dbaebab8580</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>aa304a5b1fa588da5f2e17dc08ca61b46</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a1eb0e4f741ed26fe89c6d543c62148df</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorAcc</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a6bfc073458cded5a324205be4603c750</anchor>
      <arglist>(const VectorAcc &amp;r)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend doubleAcc</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>aac366b7021fe4e8f119576eb00ec998b</anchor>
      <arglist>(const VectorAcc &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend doubleAcc</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a47017a542f166aa916b314ff0e86d32e</anchor>
      <arglist>(const VectorAcc &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend doubleAcc</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1VectorAcc.html</anchorfile>
      <anchor>a302295196d98c011eca88ad7969fc32b</anchor>
      <arglist>(const Vector &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VectorVel</name>
    <filename>classKDL_1_1VectorVel.html</filename>
    <member kind="function">
      <type></type>
      <name>VectorVel</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ac720b1b6e50c6e4c9854c392fad0600b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VectorVel</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a11cba08e19ecc4af114fec5ac610a8a0</anchor>
      <arglist>(const Vector &amp;_p, const Vector &amp;_v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VectorVel</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a4b1bb40b55ad949768d5db8d4b556cbf</anchor>
      <arglist>(const Vector &amp;_p)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>value</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a182db5e443a174a33148057cd855aa36</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>deriv</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a404a334b59064a8f0fac7ed552d51749</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a80167d51e0e21173ea0e8d957eaabd72</anchor>
      <arglist>(const VectorVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel &amp;</type>
      <name>operator=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>aa05a92ea1d8d0fcf17d90a11adfe0f61</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>afa59012d44981c5d76f05ea8bed3ffa9</anchor>
      <arglist>(const VectorVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ac7047032ef5e65789252fab619e8f760</anchor>
      <arglist>(const VectorVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>aee631b59b42bf30d9eed5f16a2ff1ef8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>Norm</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ab373cf3392d99d471fad992b4d0db529</anchor>
      <arglist>(double eps=epsilon) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IMETHOD VectorVel</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a099bf8c8e23409321451ac3498d5dce1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>p</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a34b253c5a762fe8c4f8c8718578156d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>v</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a3c4ed9d12d84f39153b5be985436214e</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a11fd8083f5afca4f0ba16105d5fb26f7</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a41fa5e2c9b206bbd1493b56dfa0f4a42</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a716d73bde25265c248277d6a222a1d9d</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>aab7667649bcb71552659da1da377c73c</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a8e02c3ca515642cb2e25028f465a7fed</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a89c57c1b72490b003e7643286de4828d</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ab759a7e3da18091b524ca0df43f8768e</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a914e77a41e4ac211cfc77e2106719bcf</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>afe38d956aa708016ff9356f221168a7e</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ae38377c45a56ccfb50d1bb601cb4482e</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a1a2a1dfc6e809b33fa32427dda794a53</anchor>
      <arglist>(double r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a888c4d3659c26fed20e6ec84ec32aedb</anchor>
      <arglist>(const doubleVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a9427c0818d105b3ace7fad271c98713c</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a3a0bb345cfd27a7658a05b614ab96c8e</anchor>
      <arglist>(const Rotation &amp;R, const VectorVel &amp;x)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a5262adc24e3ef49d881dbb7295827489</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a62e520f0c36afdd146ab108a1d0596fd</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a14b2b4a73f0e17a6940d7cdb8f8b1d39</anchor>
      <arglist>(VectorVel &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ac2d29fa02f737b5eb162732ad439ab41</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a25154bcbceb4959e0447c2ebc348cd2f</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a83b99b7463074151150c2fe7841f230a</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a930479209bf7f078dfa2228710bbcfe6</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>aa6780c8c639ab862f3a973dfde9e0dfb</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>ab3ba094007e3d967c5bb6d1bc317dead</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a920407d7dff4697f432f01e662393473</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>aaf9a36916c9dbcd765e45e99591f8ca7</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>af9b7d0672a4475ead08faf1853ad6c3d</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend VectorVel</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>af19fde54348ebbc99a66986cd5afd85a</anchor>
      <arglist>(const VectorVel &amp;r)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend doubleVel</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>aac7ded4f79eb2f43788e0a707bf8271a</anchor>
      <arglist>(const VectorVel &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend doubleVel</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a0faf5164fc7d1802e4ed01ea3bc43834</anchor>
      <arglist>(const VectorVel &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>IMETHOD friend doubleVel</type>
      <name>dot</name>
      <anchorfile>classKDL_1_1VectorVel.html</anchorfile>
      <anchor>a511b2fc09821c5a600b66d7a277ebc3c</anchor>
      <arglist>(const Vector &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VelocityProfile</name>
    <filename>classKDL_1_1VelocityProfile.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>SetProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a0f32a33e30181d066e737dcdd258c1dd</anchor>
      <arglist>(double pos1, double pos2)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a6015d8799098d04f0a9f0a8caef654ff</anchor>
      <arglist>(double pos1, double pos2, double duration)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a66e7eafa2706960b3ef27bcdbf76a406</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>aeb6fe08bb393ec44950d0f20336f04ba</anchor>
      <arglist>(double time) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>af308d831e1a5402ec4d01231a0d02c87</anchor>
      <arglist>(double time) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>af1eecd45f9bfb33799d45d011498712d</anchor>
      <arglist>(double time) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>ad64ebff8851535f52c72811d1cc9db72</anchor>
      <arglist>(std::ostream &amp;os) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual VelocityProfile *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a18a9e02a402fadc76c35394d931849d1</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VelocityProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>ac7716def2a3af9075d0a944dafea923a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static VelocityProfile *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a49092bd847e26705eb22715f68ec58be</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VelocityProfile_Dirac</name>
    <filename>classKDL_1_1VelocityProfile__Dirac.html</filename>
    <base>KDL::VelocityProfile</base>
    <member kind="function">
      <type>void</type>
      <name>SetProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a09218f2529fb3f2c5f548d75d1a953f6</anchor>
      <arglist>(double pos1, double pos2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a9f8f2ef58f16338b31db678f8b5738e5</anchor>
      <arglist>(double pos1, double pos2, double duration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a11b61ed5f378b85c014cf8689fbcf155</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>ac5c98c8a522368eadcaee5812766c0b6</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a6a1df2885014017cd68fe9a959ef84ee</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a24c1061c5e4f18a67601fe06958182e6</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a70f87853fea4322eb980ae4bd9d49d8d</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual VelocityProfile *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>ac6efce021aeba2e949d2d4b034c30b18</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VelocityProfile_Dirac</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>aba8fb5c8ed76bfd812f0cc47f19418ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static VelocityProfile *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a49092bd847e26705eb22715f68ec58be</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>p1</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>af98861202efe290f7e946288d4cee17e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>p2</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>a0c7dfbcc7b7ad5c0492e9c34ff78ac3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>t</name>
      <anchorfile>classKDL_1_1VelocityProfile__Dirac.html</anchorfile>
      <anchor>ad21ebddbd18b5c19a5498d911405f608</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VelocityProfile_Rectangular</name>
    <filename>classKDL_1_1VelocityProfile__Rectangular.html</filename>
    <base>KDL::VelocityProfile</base>
    <member kind="function">
      <type></type>
      <name>VelocityProfile_Rectangular</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>aab80774ac20c62d63e42ba624e14540b</anchor>
      <arglist>(double _maxvel=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetMax</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a0be44624f019b908af7c4fda5d763e7a</anchor>
      <arglist>(double _maxvel)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>ab8124614a7e2856484555d3b9f5de57e</anchor>
      <arglist>(double pos1, double pos2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>aab071f66195c91730fca12e62c880db0</anchor>
      <arglist>(double pos1, double pos2, double duration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a6b22ed78a35820ae9f008656f3783549</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a99de5d2f09dabc8a39ca2172cf1ea5cd</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a0ed4c236eaded23cbdb0e765e0fc48b7</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>ae3bcf63a5aa2fcb3e5c7348df46bb44e</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>aa2655930f148ff63e7f7737a29a9ed88</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual VelocityProfile *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a1b68bfab9207f5c299267962589528b6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VelocityProfile_Rectangular</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a69cba13264c2e8acb0f3f5a04e8e96d6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static VelocityProfile *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a49092bd847e26705eb22715f68ec58be</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>maxvel</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a60862551afe38b9085015359c31ffc90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>d</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>aa4bd83d646dc5592b16a7caa8cea8506</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>p</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>a7609f466d241a04c5c39583fa94480bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>v</name>
      <anchorfile>classKDL_1_1VelocityProfile__Rectangular.html</anchorfile>
      <anchor>ac4885e2d691a23f32646dcc7a1ef2bb8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VelocityProfile_Spline</name>
    <filename>classKDL_1_1VelocityProfile__Spline.html</filename>
    <base>KDL::VelocityProfile</base>
    <member kind="function">
      <type></type>
      <name>VelocityProfile_Spline</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a1989f5d9b0080f24ac4d727ac8b33cc8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VelocityProfile_Spline</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a925eb3d9bee1474879aca1a98dd555c4</anchor>
      <arglist>(const VelocityProfile_Spline &amp;p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VelocityProfile_Spline</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a0a05731657f9315c00ea6cd127c4849f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a07ca00b587ed67a0433a1244392ffdf4</anchor>
      <arglist>(double pos1, double pos2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a5e80a2b0fece796615f611f1a229a187</anchor>
      <arglist>(double pos1, double pos2, double duration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>acd80fc84a4178a09d242e87ebf51a201</anchor>
      <arglist>(double pos1, double vel1, double pos2, double vel2, double duration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a90d8ad7187764e192d162d10818bb416</anchor>
      <arglist>(double pos1, double vel1, double acc1, double pos2, double vel2, double acc2, double duration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a90b9d2a71c2ea13ed24adcdd86de0ec4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a959b823b058d1f88c4604a7648773f7a</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a6c46753f569904ab4d67ccda6b771fbc</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a3d16880a8c6207a6e09a218a928aae01</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a67b618f9e12fc2012d70fba8d8881958</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual VelocityProfile *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>a6a8ce5389631e35ab377b7056e8ee565</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static VelocityProfile *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a49092bd847e26705eb22715f68ec58be</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>coeff_</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>aea4937538ff52c9dff21dbdf3dd5ab47</anchor>
      <arglist>[6]</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>duration_</name>
      <anchorfile>classKDL_1_1VelocityProfile__Spline.html</anchorfile>
      <anchor>ae81a605423b004818d8dd3987f677663</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VelocityProfile_Trap</name>
    <filename>classKDL_1_1VelocityProfile__Trap.html</filename>
    <base>KDL::VelocityProfile</base>
    <member kind="function">
      <type></type>
      <name>VelocityProfile_Trap</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>aaa358143e388e53c3ca5798c841db72d</anchor>
      <arglist>(double _maxvel=0, double _maxacc=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>aca3df7abf8bab8c12f929222d565b859</anchor>
      <arglist>(double pos1, double pos2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>abafbd9e83c261fb2b688e582235b8bfb</anchor>
      <arglist>(double pos1, double pos2, double newduration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileVelocity</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a2430037871ef41dc7b7059af180598a1</anchor>
      <arglist>(double pos1, double pos2, double newvelocity)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetMax</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a48edc0f42aaf30f00c0170a7423df005</anchor>
      <arglist>(double _maxvel, double _maxacc)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>ae940bf88396a1d3942554d34f0a95b1c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a1122c1fca4307ce6027ca7589a3dd1f3</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a413f4529eadf04c8c748e6e9644ccdc4</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a29320ca1378cf107d321af06451644c2</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a7aa5d88c4daeae38cfa4be22c68eda7d</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual VelocityProfile *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a0283b75a6f458d20f2c50c1a6e311f63</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VelocityProfile_Trap</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>afdc27db8c27e08b1fb1fb6463eee521a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static VelocityProfile *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a49092bd847e26705eb22715f68ec58be</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>a1</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a9b0a3da0460977311e236b42709defcc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>a2</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>ae14ddbc1d3bb915dcd56b75ef788fc65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>a3</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a494a64f5f570de60d3eff2a31581e4d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>b1</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a196b36f99f24c6bf231f76e86c11aa82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>b2</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a9f6331c06a5f992b6215c0d44df60cb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>b3</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a655c6a03acfcd2f68ac3bd35cb03374b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c1</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>aefac534b34e99b3e832a2a237ca1e776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c2</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a358d2e382c4a57051cd4bfc0cd86edf4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c3</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a0ce9c1261bb16e0c6bd8519720186264</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a3957fbc9ec60b5074d1f01ac101103cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>t1</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>ab7c8c38fbafe406c277aa302c096a846</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>t2</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a44060ce7511af06e9f0ea409fe9e34e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>maxvel</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>abc5db357d1772338ef66208fea0fe0ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>maxacc</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>ad17233b0b5a462ca8ea40bf9679eddd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>startpos</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>aed7dfa886a56ccee6bf585efd009d801</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>endpos</name>
      <anchorfile>classKDL_1_1VelocityProfile__Trap.html</anchorfile>
      <anchor>a4a078959222c7aacc1886672de1536dc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::VelocityProfile_TrapHalf</name>
    <filename>classKDL_1_1VelocityProfile__TrapHalf.html</filename>
    <base>KDL::VelocityProfile</base>
    <member kind="function">
      <type></type>
      <name>VelocityProfile_TrapHalf</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a36939f96756f2a729464cd44a62b094e</anchor>
      <arglist>(double _maxvel=0, double _maxacc=0, bool _starting=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetMax</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a22c4b84723eadd24944e7023da2879f9</anchor>
      <arglist>(double _maxvel, double _maxacc, bool _starting)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfile</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a12a5f9a9fe83a00f71672083656c4285</anchor>
      <arglist>(double pos1, double pos2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>SetProfileDuration</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a32e9a8cacfe90d1b230bd77d5da1ce39</anchor>
      <arglist>(double pos1, double pos2, double newduration)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>aea6e4832fe50a5bb020e1f4a81a5e49c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Pos</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>abeb2def5f9eea900462c511a4a8e62a0</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Vel</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a6d3d42064e26de5168e040f9fe1e8d98</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>Acc</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>addc30ac56bc603a59116aa4cc9724839</anchor>
      <arglist>(double time) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>Write</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ae8756be3649d3b02e7bc6a8fb598107a</anchor>
      <arglist>(std::ostream &amp;os) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual VelocityProfile *</type>
      <name>Clone</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a3d5cc0e2766e6f871cc8b5320a93c38d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VelocityProfile_TrapHalf</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ae238049f06de4d84e8b419ed264e017f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static VelocityProfile *</type>
      <name>Read</name>
      <anchorfile>classKDL_1_1VelocityProfile.html</anchorfile>
      <anchor>a49092bd847e26705eb22715f68ec58be</anchor>
      <arglist>(std::istream &amp;is)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>PlanProfile1</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>aa91360c86b91cc3c91cc3e9f8a17fcf5</anchor>
      <arglist>(double v, double a)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>PlanProfile2</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a9fa97b0567341e26a42e18f1cfef30ac</anchor>
      <arglist>(double v, double a)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>a1</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a2ff72d0373cb883bf0161d3573d53385</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>a2</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a4215986d853f1c6d7d83f5d23b95f5b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>a3</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>aa23d657aa6621bf272b21ff8bd0ba35a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>b1</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ab3cb6306dd4fa60828cb55fe72ddb59e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>b2</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>aac9b997992b809fdbcf025c4a891a908</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>b3</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a6aa7d63aec01ac9324a4b97910e5dc99</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c1</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a61768054e5dc2d443ae7eb04c78af7e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c2</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a7b0c10547e38f8d88e112ff04c9389c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>c3</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ad25e912c94aa251579aa3d3b90faa7ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>duration</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ae39e15da90591a114402dde30bb1bd5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>t1</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a4b75d4959f76f88008a37d073da083e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>t2</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a21b0d1abc3a4b8a48517b7f274b1567f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>startpos</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a385cd7dd24698b38700d0a4908e04c41</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>endpos</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ae576ed07d682cce111ab803a7ee3a098</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>maxvel</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>afad17810007ee287b9026ecb79ce06d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>double</type>
      <name>maxacc</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>ab4daddc48c4e50c1d803990076f81fa7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>starting</name>
      <anchorfile>classKDL_1_1VelocityProfile__TrapHalf.html</anchorfile>
      <anchor>a774451be484696872f72fb28b5fb85d6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>KDL::Wrench</name>
    <filename>classKDL_1_1Wrench.html</filename>
    <member kind="function">
      <type></type>
      <name>Wrench</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a4ee5e7b7fbbd59c2ad81137ea2eca9d1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Wrench</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a7eace46e99879997458fc4b42e4d447b</anchor>
      <arglist>(const Vector &amp;_force, const Vector &amp;_torque)</arglist>
    </member>
    <member kind="function">
      <type>Wrench &amp;</type>
      <name>operator-=</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a3d53d5f8ae0a7ea995b33d525152b55e</anchor>
      <arglist>(const Wrench &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Wrench &amp;</type>
      <name>operator+=</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a133c392f51dbc8f368f15255833e71cb</anchor>
      <arglist>(const Wrench &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a976ba92ead3f1a91cec72a5c4268fb2c</anchor>
      <arglist>(int i)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a0014bc437c99886888122f8343f287d8</anchor>
      <arglist>(int i) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ac005fdb2ae56f67943232946d04362e8</anchor>
      <arglist>(int index) const</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator[]</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ad5a1f06642c2f5d060707427870bf1cc</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ReverseSign</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>af38ab9d4d4e87cfa3505118351b1ed26</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>RefPoint</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ac84fd36d8238a48b750de87ec16ff01a</anchor>
      <arglist>(const Vector &amp;v_base_AB) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Wrench</type>
      <name>Zero</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a5f331d9253cdfe634a8df55dfd158730</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>force</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a3f8bee8b5afd64870bf187fa6a4ea3fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Vector</type>
      <name>torque</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ab725bbdf755cadd4a6718ea1f2ed1c1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Rotation</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>aa9d2bf0f1d1d2655fb37b513d3159be3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Frame</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>aee3a66b0ddf3b769f015c89b610db0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>accbdf521d6fc163bb229914dfa3e2c20</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator*</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ad9270132aa4084d7d61b007374a81883</anchor>
      <arglist>(double lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator/</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a4c875b04aa468b3494b427e3007bb9e6</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator+</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a17d4fccb33a2736468d0645862956cb5</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>aa81947bb6d31729915fc66d59fdf84e6</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="friend">
      <type>friend Wrench</type>
      <name>operator-</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>aaa88a5af82234547897ea220ef3cd173</anchor>
      <arglist>(const Wrench &amp;arg)</arglist>
    </member>
    <member kind="friend">
      <type>friend void</type>
      <name>SetToZero</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ae9c9bc666b3fa58c6164f2d4b0588146</anchor>
      <arglist>(Wrench &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>Equal</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a034291d6c9dc6a03e93b86ff71aa0315</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b, double eps)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator==</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>a42be75b813fda510521ea4052ab0fd71</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="friend">
      <type>friend bool</type>
      <name>operator!=</name>
      <anchorfile>classKDL_1_1Wrench.html</anchorfile>
      <anchor>ab2633edb946009d63578990c33e899da</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>KDL</name>
    <filename>namespaceKDL.html</filename>
    <class kind="class">KDL::ArticulatedBodyInertia</class>
    <class kind="class">KDL::Chain</class>
    <class kind="class">KDL::ChainDynParam</class>
    <class kind="class">KDL::ChainFdSolver</class>
    <class kind="class">KDL::ChainFdSolver_RNE</class>
    <class kind="class">KDL::ChainFkSolverAcc</class>
    <class kind="class">KDL::ChainFkSolverPos</class>
    <class kind="class">KDL::ChainFkSolverPos_recursive</class>
    <class kind="class">KDL::ChainFkSolverVel</class>
    <class kind="class">KDL::ChainFkSolverVel_recursive</class>
    <class kind="class">KDL::ChainHdSolver_Vereshchagin</class>
    <class kind="class">KDL::ChainIdSolver</class>
    <class kind="class">KDL::ChainIdSolver_RNE</class>
    <class kind="class">KDL::ChainIdSolver_Vereshchagin</class>
    <class kind="class">KDL::ChainIkSolverAcc</class>
    <class kind="class">KDL::ChainIkSolverPos</class>
    <class kind="class">KDL::ChainIkSolverPos_LMA</class>
    <class kind="class">KDL::ChainIkSolverPos_NR</class>
    <class kind="class">KDL::ChainIkSolverPos_NR_JL</class>
    <class kind="class">KDL::ChainIkSolverVel</class>
    <class kind="class">KDL::ChainIkSolverVel_pinv</class>
    <class kind="class">KDL::ChainIkSolverVel_pinv_givens</class>
    <class kind="class">KDL::ChainIkSolverVel_pinv_nso</class>
    <class kind="class">KDL::ChainIkSolverVel_wdls</class>
    <class kind="class">KDL::ChainJntToJacDotSolver</class>
    <class kind="class">KDL::ChainJntToJacSolver</class>
    <class kind="class">KDL::Frame</class>
    <class kind="class">KDL::Frame2</class>
    <class kind="class">KDL::FrameAcc</class>
    <class kind="class">KDL::FrameVel</class>
    <class kind="class">KDL::Jacobian</class>
    <class kind="class">KDL::JntArray</class>
    <class kind="class">KDL::JntArrayAcc</class>
    <class kind="class">KDL::JntArrayVel</class>
    <class kind="class">KDL::Joint</class>
    <class kind="class">KDL::Path</class>
    <class kind="class">KDL::Path_Circle</class>
    <class kind="class">KDL::Path_Composite</class>
    <class kind="class">KDL::Path_Cyclic_Closed</class>
    <class kind="class">KDL::Path_Line</class>
    <class kind="class">KDL::Path_Point</class>
    <class kind="class">KDL::Path_RoundedComposite</class>
    <class kind="class">KDL::RigidBodyInertia</class>
    <class kind="class">KDL::Rotation</class>
    <class kind="class">KDL::Rotation2</class>
    <class kind="class">KDL::RotationAcc</class>
    <class kind="class">KDL::RotationalInertia</class>
    <class kind="class">KDL::RotationalInterpolation</class>
    <class kind="class">KDL::RotationalInterpolation_SingleAxis</class>
    <class kind="class">KDL::RotationVel</class>
    <class kind="class">KDL::Segment</class>
    <class kind="class">KDL::SolverI</class>
    <class kind="class">KDL::Stiffness</class>
    <class kind="class">KDL::Trajectory</class>
    <class kind="class">KDL::Trajectory_Composite</class>
    <class kind="class">KDL::Trajectory_Segment</class>
    <class kind="class">KDL::Trajectory_Stationary</class>
    <class kind="class">KDL::Tree</class>
    <class kind="class">KDL::TreeElement</class>
    <class kind="class">KDL::TreeFkSolverPos</class>
    <class kind="class">KDL::TreeFkSolverPos_recursive</class>
    <class kind="class">KDL::TreeIdSolver</class>
    <class kind="class">KDL::TreeIdSolver_RNE</class>
    <class kind="class">KDL::TreeIkSolverPos</class>
    <class kind="class">KDL::TreeIkSolverPos_NR_JL</class>
    <class kind="class">KDL::TreeIkSolverPos_Online</class>
    <class kind="class">KDL::TreeIkSolverVel</class>
    <class kind="class">KDL::TreeIkSolverVel_wdls</class>
    <class kind="class">KDL::TreeJntToJacSolver</class>
    <class kind="class">KDL::Twist</class>
    <class kind="class">KDL::TwistAcc</class>
    <class kind="class">KDL::TwistVel</class>
    <class kind="class">KDL::Vector</class>
    <class kind="class">KDL::Vector2</class>
    <class kind="class">KDL::VectorAcc</class>
    <class kind="class">KDL::VectorVel</class>
    <class kind="class">KDL::VelocityProfile</class>
    <class kind="class">KDL::VelocityProfile_Dirac</class>
    <class kind="class">KDL::VelocityProfile_Rectangular</class>
    <class kind="class">KDL::VelocityProfile_Spline</class>
    <class kind="class">KDL::VelocityProfile_Trap</class>
    <class kind="class">KDL::VelocityProfile_TrapHalf</class>
    <class kind="class">KDL::Wrench</class>
    <member kind="typedef">
      <type>std::vector&lt; Wrench &gt;</type>
      <name>Wrenches</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afeffe2d8d9e5e5cfbad0fc90b720c264</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Rall2d&lt; double, double, double &gt;</type>
      <name>doubleAcc</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a931155039a40a3f75d0150bed1055206</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Rall1d&lt; double &gt;</type>
      <name>doubleVel</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6725eee11f82dfb8f65f78b107bbe7e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, TreeElement &gt;</type>
      <name>SegmentMap</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6bfcccbcc840654a88822ddd0ee6bdaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TreeElement</type>
      <name>TreeElementType</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3816afaee547d0e1a8e3acc39e6ed0d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, Wrench &gt;</type>
      <name>WrenchMap</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6461f6198aeae25076631dfd74486f8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, Twist &gt;</type>
      <name>Twists</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a48ceacb8e88b1c7009802cdf75ac5b87</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, Jacobian &gt;</type>
      <name>Jacobians</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad23eebdce1073711bb4db8f9fa568362</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; std::string, Frame &gt;</type>
      <name>Frames</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a19abc72c063bbf7718e2299712003478</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa7100a66f621fadcd96168a97d27784d</anchor>
      <arglist>(double a, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3bc91024ee0a8b23fa94b74fa7c952f0</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af14129ba902ec31f692ae97e29c033ef</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a148a5015338fa55d58b91dc7b9bb9983</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2dfa94ee82b9d4f12d9c4ee2b79a43b6</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const ArticulatedBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a57e5b07873e812f8d7f94d5ca1acd229</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab60953771d5ef2a0ef08cf7e8266473f</anchor>
      <arglist>(const Frame &amp;T, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a786c8142a2aad06781373faeccbfd353</anchor>
      <arglist>(const Rotation &amp;R, const ArticulatedBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a698a887bd036f999ead109cb2f29c5e5</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>ArticulatedBodyInertia</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8b9e70a1774fb129e540065eb6b263e3</anchor>
      <arglist>(const ArticulatedBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Twist_to_Eigen</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad99081b5fff0a9d43dfc07a3f64ee714</anchor>
      <arglist>(const KDL::Twist &amp;t, Eigen::MatrixBase&lt; Derived &gt; &amp;e)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aceb6e09c6452163b3558a3a3cc07218e</anchor>
      <arglist>(const FrameAcc &amp;r1, const FrameAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>adfd020186f84b57bbc3b68ffce524f62</anchor>
      <arglist>(const Frame &amp;r1, const FrameAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a720066d9cded8fbede747b8709346807</anchor>
      <arglist>(const FrameAcc &amp;r1, const Frame &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8a8d76717c6b496e08e425c012f8b89b</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a02b22cc9116b2baca5a86eaee825076e</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8011b8ae760bbe1aa062b699ad93038c</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab62149a668287784cd5695f01c17367d</anchor>
      <arglist>(const TwistAcc &amp;a, const TwistAcc &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab3fb673008c926b747f12842819fb337</anchor>
      <arglist>(const Twist &amp;a, const TwistAcc &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a20ab86ec30519ed0fad9a1d705c829f1</anchor>
      <arglist>(const TwistAcc &amp;a, const Twist &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a900aeddeccd431c5cbf0bdd3156d6f35</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afd3e97a38cc7c47e7b6d07e7e0f466a7</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a597c39d91a1081b5442712f1249d6054</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acab79938e3027d6510cfa4a90720c95f</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a782af317e6d1e7cb312b30ab60c70bd6</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a37489ad00a48b8b652eadc65bebd5ad3</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9554f1e935042c64beac3e7f945f9101</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab56265b003752215f2d94c00493e4c21</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a096678f980702ca962d48014abd10945</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa782630b3a6cc0ba2c84b4e030dcddb7</anchor>
      <arglist>(const VectorAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9e9d745c14edea95c2ebb5cea42de36f</anchor>
      <arglist>(const VectorAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2fb01a0504479ca09c7bf27e343b8be5</anchor>
      <arglist>(const VectorAcc &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a32c266cd0cffd38a75c48221ccc25399</anchor>
      <arglist>(const Vector &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a524c105fb1973d09ecd5cdede4374810</anchor>
      <arglist>(double r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aadc7e8ee3d8788b987dc0f0a4c5f67e3</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9cb7bd269eab198b5145a802b20456d7</anchor>
      <arglist>(const doubleAcc &amp;r1, const VectorAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a51ac1ce1dbd62896096448a98e209b96</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3fd338e2da27c7bd6ca0e37b0f0df6bc</anchor>
      <arglist>(const VectorAcc &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a107183962fe5c2cb927be493403bb397</anchor>
      <arglist>(const VectorAcc &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>doubleAcc</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a13b5aff556e90ec3023cbb2aa8cab6e3</anchor>
      <arglist>(const Vector &amp;lhs, const VectorAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7dd9ddf5cf0ebc37acb08f33c594f89d</anchor>
      <arglist>(const VectorAcc &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3a23c4ad11a2c81588b94fbf6e39eb7f</anchor>
      <arglist>(const VectorAcc &amp;r2, const doubleAcc &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc6f0d30c6f9d3e92c554585907be39b</anchor>
      <arglist>(const RotationAcc &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a30128ae85ca846c146f1df52ffd18aa8</anchor>
      <arglist>(const Rotation &amp;r1, const RotationAcc &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58fadb516d19574d7ac0cb40d1022f3e</anchor>
      <arglist>(const RotationAcc &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aef301ceb31d21ec006c03b3359673b75</anchor>
      <arglist>(const Rotation &amp;R, const VectorAcc &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8450a02abf20b80c80e444d29ab5304d</anchor>
      <arglist>(const FrameAcc &amp;lhs, const FrameAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad315c19f6564614fd6fe4350fa04885b</anchor>
      <arglist>(const FrameAcc &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aec4b7d8ac5c54d65fa070bd6a189fe26</anchor>
      <arglist>(const Frame &amp;lhs, const FrameAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aaab7b9e81b8789337bdbb13d9fd2e4cd</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af8d405e2914bea19aecfc2aac9143375</anchor>
      <arglist>(double lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15ebfbcd250b2584e798f4955fc6fcba</anchor>
      <arglist>(const TwistAcc &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8b4f64aa851af027829c24d1d9deefd3</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4164febadd9c9bf7a119cf4223350675</anchor>
      <arglist>(const doubleAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a321a12c7bdb069e7f0a317ef9d778370</anchor>
      <arglist>(const TwistAcc &amp;lhs, const doubleAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3ab49311febc69235cc75ad7fe81a91</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1edfde5b35133050a8a1d3a5a7a107af</anchor>
      <arglist>(const TwistAcc &amp;lhs, const TwistAcc &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistAcc</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae5c4196610ec6b1a316b23f144a75090</anchor>
      <arglist>(const TwistAcc &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a05fc643515b491c7a9938a8f6fd0500f</anchor>
      <arglist>(std::ostream &amp;os, const VectorAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af23846837b43f7eca43c2088148e28fd</anchor>
      <arglist>(std::ostream &amp;os, const RotationAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc1e3573bca3a74daedbe3ab41552e3c</anchor>
      <arglist>(std::ostream &amp;os, const FrameAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac020750892e14e0e4e075efd6bfd3100</anchor>
      <arglist>(std::ostream &amp;os, const TwistAcc &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa75157c97981a05a94513ec9a8c40124</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>Rotation</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa9ad476d005ede2a464b048a9b048a96</anchor>
      <arglist>(const Rotation &amp;lhs, const Rotation &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1d076f4eec84df192b9bcfa5740f2ebf</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a267f5edb3111f0f0ba0273099f3fee1e</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af0c5cb20967b3790cf5a534511f64f0a</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad74e1ec324b451246619ec0812c2f9c8</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a71af262c34419a6396d37a3939d2281f</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7e89bf5dfb058ed646d8cd8791c71cb2</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8f002bdc16e0843ec3660aee9bcb24bd</anchor>
      <arglist>(const Rotation2 &amp;a, const Rotation2 &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a96ca52698b11cbddf3176a4af11bd64b</anchor>
      <arglist>(const Frame2 &amp;a, const Frame2 &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a721ba3f54f506bc1004fb981a9ea7b13</anchor>
      <arglist>(const Vector &amp;p_w_a, const Vector &amp;p_w_b, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad23c4b0b7788db8ecc670b5561dbc427</anchor>
      <arglist>(const Rotation &amp;R_a_b1, const Rotation &amp;R_a_b2, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af738311fdea560d6255894ddc0425095</anchor>
      <arglist>(const Frame &amp;F_a_b1, const Frame &amp;F_a_b2, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a64a30fa7b4a6a532cbd43ad90c93bc5e</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Wrench</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0207da13db4661467e2e8c74cce973a5</anchor>
      <arglist>(const Wrench &amp;W_a_p1, const Wrench &amp;W_a_p2, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac90990ec8c80f1c7a411052f6b1f322b</anchor>
      <arglist>(const Vector &amp;p_w_a, const Vector &amp;p_w_da, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2a84a971a8a4300f6b4dd97f40479029</anchor>
      <arglist>(const Rotation &amp;R_w_a, const Vector &amp;da_w, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a57e682fab9c7fb9fe18145310d9984d5</anchor>
      <arglist>(const Frame &amp;F_w_a, const Twist &amp;da_w, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Twist</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a32903427965bec95694731b3ad6e4cb0</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;da, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Wrench</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2e1b786a27b63352f5f2c098ef26392d</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;da, double dt=1)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aae21b94ac92952d16ee509a5a4b8c449</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1fce4b4a41dfa403b2a47f7950a602a1</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab5247191df17553320eb1639d901221b</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a357a1574d4d5fa898fc43df23fea8462</anchor>
      <arglist>(double lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aed451d41bd66dbd33a3feb5acb4b1ebe</anchor>
      <arglist>(const Vector &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3709494d8a02d8757f4b668c452155a</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5c7d683679ab9019a65107e128cd6b88</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae46db8b8cf405b5faf1a89263296d7de</anchor>
      <arglist>(double lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8e4ca54ad9f9b0e5538e4bd3423a87a4</anchor>
      <arglist>(const Wrench &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8e7b9ed5c63404773079ae53ee00d200</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a28f9d98ac28883fba27e18723698d59b</anchor>
      <arglist>(const Wrench &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6188e96ab705622696fabc0bd2c120e7</anchor>
      <arglist>(const Wrench &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f3979c3069f3d6558fc902a86c380d5</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a74682143c6c66632244b5e67cccce8c0</anchor>
      <arglist>(double lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2c10359e471c3cf0dca718798f15d224</anchor>
      <arglist>(const Twist &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3e1e5d70194d5577e7e5e7c534f9f877</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a78aa25a29bdaa99874ea3fcb128a3553</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a42838c1bd9e803b30a6bd645d150c65c</anchor>
      <arglist>(const Twist &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>Twist</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab85c524cf4f6bd5364363dad1ef08ae5</anchor>
      <arglist>(const Twist &amp;lhs, const Twist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aafe32822da77309b7f5c0260aa926886</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Frame</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af3abf2430995a3cc3c688884e9efe156</anchor>
      <arglist>(const Frame &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>Vector</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6dfc6b5efe37c9bbae876578f2b3a361</anchor>
      <arglist>(const Vector &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae19bb99f118f93827bbcfd227651028f</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8a95c0c12a9c7d846ac4c2832e03fa6a</anchor>
      <arglist>(const Vector2 &amp;lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aae6a6cf702dd433fb1cd0cd462068380</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2152fae33fee05d9bf23e9aaf5dfbe91</anchor>
      <arglist>(double lhs, const Vector2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aefa0b99b58c211a4eff0539f180dcf87</anchor>
      <arglist>(const Vector2 &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Vector2</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>adc332c398dc07420ccff5e6d7ee12209</anchor>
      <arglist>(const Vector2 &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4ddd74aa0ffa153735c9603b51ea06f</anchor>
      <arglist>(const Rotation2 &amp;lhs, const Rotation2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Frame2</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a00f0baabdb899f295fb9611e0b724560</anchor>
      <arglist>(const Frame2 &amp;lhs, const Frame2 &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4db9af1413269c11e7d2545598b1007f</anchor>
      <arglist>(const Vector &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa63cf4bc264d241cd79de32af80d7fdc</anchor>
      <arglist>(const Twist &amp;lhs, const Wrench &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD double</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a075c80a9c5b8b4db8221d84dbe16321a</anchor>
      <arglist>(const Wrench &amp;rhs, const Twist &amp;lhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac3750480c481eea276696d3bc4f863cc</anchor>
      <arglist>(Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad8485aa6cdef7323e5139e7197307670</anchor>
      <arglist>(Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aeb3832c7f7dbbb0276a3444dd6d64c4d</anchor>
      <arglist>(Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8299e9971a3f1996d8fd79cdf29fd8d9</anchor>
      <arglist>(Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD Rotation</type>
      <name>Rot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2587165b94880d6deaf7fdc5ed5ee06</anchor>
      <arglist>(const Vector &amp;axis_a_b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab659aefd7a8d246aa4940c712b53b151</anchor>
      <arglist>(Vector &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a19a568accb594b3670bddf2a40a33105</anchor>
      <arglist>(Twist &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7a2f7de4c733f4e82af4f8bdd2056fb7</anchor>
      <arglist>(Wrench &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a41009801573404ce30ee8e057fb04ef6</anchor>
      <arglist>(Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aff06e46b989fa6738dd60cf49f6a7ea1</anchor>
      <arglist>(Frame &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac785c7fa89414f9d3c85edca120acc83</anchor>
      <arglist>(Vector &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1532bb6e60e00d6c36b984a3035de126</anchor>
      <arglist>(Twist &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aff1c0c5664a50d4bc85883c636033df5</anchor>
      <arglist>(Wrench &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afb35d4c796c9c993745b83376734d080</anchor>
      <arglist>(Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4e2d06356667a8f3268130e60e13f422</anchor>
      <arglist>(Frame &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a29c2eddcc4d9cfe533e333ecfa1b54a0</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a312b7b900344e2ae17a20876f1df7574</anchor>
      <arglist>(const Frame &amp;a, const Frame &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa24027be36c84617964a2cd6124659f9</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6ae91ebcc5ee2a021fbc153fbc24a01c</anchor>
      <arglist>(const Vector &amp;a, const Vector &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a235efc5e431e6b5375c8360c68d27044</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aace5ddee5968bf1f3baf1b0e1c6ab050</anchor>
      <arglist>(const Twist &amp;a, const Twist &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7ebcdc524db268f5df96f9bced38ad10</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a640b15a9d707c5a81915064d88f30030</anchor>
      <arglist>(const Wrench &amp;a, const Wrench &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af5e1f5dbc48ea49b0872ac949f47003b</anchor>
      <arglist>(const Rotation &amp;a, const Rotation &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a12c33f7bc59885551a7c3db86e2becbc</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a035cedf046e497717220dd23543c4571</anchor>
      <arglist>(const Vector2 &amp;a, const Vector2 &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4dde00469dc5fc853343c8ac32efa147</anchor>
      <arglist>(std::ostream &amp;os, const Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2ad7c49487ea4700b039c05fa5d3bb0</anchor>
      <arglist>(std::ostream &amp;os, const Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abdb1c2aa6c78a0a27427849421256152</anchor>
      <arglist>(std::ostream &amp;os, const Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a142dcb0cd026eb30ac3cd5b4525f5090</anchor>
      <arglist>(std::ostream &amp;os, const Rotation &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a226695adfb3680921b18f03136ce0273</anchor>
      <arglist>(std::ostream &amp;os, const Frame &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3815b8d46d06c7e3e5ae67cd6e4990b3</anchor>
      <arglist>(std::ostream &amp;os, const Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a24d29a8e06dbaf10d717157f1ba28d9a</anchor>
      <arglist>(std::ostream &amp;os, const Rotation2 &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a63ec444e29aca93f6c23373ef6433601</anchor>
      <arglist>(std::ostream &amp;os, const Frame2 &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afa42ed5643a2891f71a3b6c6a2df285f</anchor>
      <arglist>(std::istream &amp;is, Vector &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99cf8d444d6ece29e81ba106a4b1d48f</anchor>
      <arglist>(std::istream &amp;is, Twist &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4147003cd7f723387395f3f87887fa96</anchor>
      <arglist>(std::istream &amp;is, Wrench &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab2c986dc7a5f9e5864938fc2e79dd67a</anchor>
      <arglist>(std::istream &amp;is, Rotation &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab4978efdfafa24e8f1cb78220c643fb8</anchor>
      <arglist>(std::istream &amp;is, Frame &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a614435357b4ef70a4306fb45facbe606</anchor>
      <arglist>(std::istream &amp;is, Vector2 &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a798f68d899adc2906b5eb1fca8b4b372</anchor>
      <arglist>(std::istream &amp;is, Rotation2 &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a84456402e2d197eae16e609d80596e10</anchor>
      <arglist>(std::istream &amp;is, Frame2 &amp;T)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac33cd30cdcbb2a408118c7f4da33d839</anchor>
      <arglist>(const doubleVel &amp;a, const doubleVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6ac0a4190fd520636b59af8d3c002b49</anchor>
      <arglist>(const doubleVel &amp;a, const doubleVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a910caae27c05e168ff9e13c1e1646319</anchor>
      <arglist>(doubleVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac19da83b9af24139e10645a8d85a46be</anchor>
      <arglist>(doubleVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a429b3dde4f39a3d81fb99cac3879d5d2</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0917bf2a85b30dba6ac3a60131ac0400</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7499a3cd0d3c34bad5a5f844cd9f34e2</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af947e7ffa1e54902b211aebc7d2fbcd3</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3fc2070f69def825fb20806cc70bdec9</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a31f155d33ef1cc21bc6e69a8c27939a8</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae19cba37b0b3a8f17f2426ef2dde7345</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99f1283f4b309d0cfa47032764149d79</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9883f896f965d3b5991a7f229d312014</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad72529712b954d065bb8a04c15281be7</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5c7ac3cd31bc956c067ddab208ffe1ea</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a106e91304c56ac79037adf15aecb04fd</anchor>
      <arglist>(const TwistVel &amp;a, const Twist &amp;b, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abcbdf134e1245fff7276c09d93bc129e</anchor>
      <arglist>(const VectorVel &amp;a, const VectorVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab8f44efdaa9efac075dabe72b9b1d793</anchor>
      <arglist>(const VectorVel &amp;a, const VectorVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD VectorVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af6fe4108d2d1bc8f56de6ada8b1e02a2</anchor>
      <arglist>(const RotationVel &amp;a, const RotationVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD RotationVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aab054566b4b7c16b491d1fd24a209b8d</anchor>
      <arglist>(const RotationVel &amp;a, const VectorVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD TwistVel</type>
      <name>diff</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4abe67e47461ea82dd1764ff915b8e5f</anchor>
      <arglist>(const FrameVel &amp;a, const FrameVel &amp;b, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD FrameVel</type>
      <name>addDelta</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc209ec5b445dbeb2080f137428469d0</anchor>
      <arglist>(const FrameVel &amp;a, const TwistVel &amp;da, double dt=1.0)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad4bc824b5837adae75f79399bd124804</anchor>
      <arglist>(VectorVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1fdb77353c9152acfebd13a454872ba4</anchor>
      <arglist>(TwistVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a255a6a31ee024f0c265366e89129f564</anchor>
      <arglist>(RotationVel &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a30e4eea768db2597e48833327755dc16</anchor>
      <arglist>(FrameVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a50822c16b76589bb4a41df313d931f9e</anchor>
      <arglist>(VectorVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad28862488c44a3fcd86179b28223b34b</anchor>
      <arglist>(TwistVel &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5c000a5dfa9cbf912bf67073fb7520fb</anchor>
      <arglist>(RotationVel &amp;R)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a804501a1fd1b260f9950c36f25377393</anchor>
      <arglist>(FrameVel &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a142d0102e854fb2d81285b4be9c77403</anchor>
      <arglist>(const FrameVel &amp;lhs, const FrameVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a91614778fd903680d9adc02dc4f9f93e</anchor>
      <arglist>(const FrameVel &amp;lhs, const Frame &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>FrameVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afa2370df86529ccb32adb550a6d68f3c</anchor>
      <arglist>(const Frame &amp;lhs, const FrameVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a39e814b326504c560b6518dd2da0ccc4</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6797c68c09dc61566d2fb2f9f4e1cdac</anchor>
      <arglist>(const FrameVel &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4a07ac035490045345ed765f68c78a38</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7201f4380eaa5617668e254554900113</anchor>
      <arglist>(const Frame &amp;r1, const FrameVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acedd29a5a64b4cb0c567732eb5f14d21</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b91bdcbbb71af48e324996cdb43e2cb</anchor>
      <arglist>(const FrameVel &amp;r1, const Frame &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5d7163c16649fa3a642aa848324fe9d4</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>adbe94445d0882c39d30eae3dc0cafe87</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>RotationVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a5da7749f16d9ee38bfd37e79a4b4d396</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac1f7e351c8fd233adb3ab3a89d344807</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a69ffbfb2913176226fa8b23af43b29c6</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58aec482512a0c59b6c91e937854ca65</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f71bf9fd005cd96217fc323f2da32c9</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a05ce61116e9eb721ff6ce1a3fbc98a43</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a22c094db1c261a306f291f24cd2b3019</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afc467fc7b1ba01dd94296fea19de4d1a</anchor>
      <arglist>(const VectorVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68e666e68770d71ad4051e0274dc33c</anchor>
      <arglist>(VectorVel &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae2e894b949233d7a44ae28da39fba9b3</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>addce33b1267ae40397c0868e3494c443</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2ef790489497475f742e991ac055e870</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a99600554d49023bd93514a61abec1bb6</anchor>
      <arglist>(double r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aaa72572d20b5e96b3b36b36b99467db4</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abd858f51b9b11ad399be86cfc8f9e488</anchor>
      <arglist>(const doubleVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>add99195f2e34b8ba9680d64463ab237f</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad97597be7b4cfcfb41052ad7f949779c</anchor>
      <arglist>(const VectorVel &amp;r1, double r2)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7b2b0c8cf567e8d7057341689c186e25</anchor>
      <arglist>(const VectorVel &amp;r2, const doubleVel &amp;r1)</arglist>
    </member>
    <member kind="function">
      <type>VectorVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac87ef443bc4a8a8fcf86551a10b1dbef</anchor>
      <arglist>(const Rotation &amp;R, const VectorVel &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7b6a84cca357b87f150a916e9256cecf</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4a79f55480a4274e2f1902f62b2858e1</anchor>
      <arglist>(const VectorVel &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ada8ad69ba57f135c94041e1cf25b469d</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2e72b3c920bce456e44892604f4ee2e6</anchor>
      <arglist>(const Vector &amp;r1, const VectorVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6e89a1838d7701b692f8be3a7fee8c35</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a03afc4531913f82469fbd05f7dc19173</anchor>
      <arglist>(const VectorVel &amp;r1, const Vector &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0ad116c77af73be75361551f32c8ab21</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a84b99208df6b6c36c1be64e3190f909a</anchor>
      <arglist>(const RotationVel &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68e4b4619a61b10c023d08d13cfc605</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6492e42fafda7e39a64820445da4d1ce</anchor>
      <arglist>(const Rotation &amp;r1, const RotationVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad8457a250380f149d1eb284ed1b3934f</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af0b2c9e544649739fa85baf3cc415bd7</anchor>
      <arglist>(const RotationVel &amp;r1, const Rotation &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a068c61edbb7adfcf0207a7560a2026eb</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b08e47a485ff7688cdec479512d48bf</anchor>
      <arglist>(const TwistVel &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af7f550dee6dfe8474b49187d9c1b52c1</anchor>
      <arglist>(const Twist &amp;a, const TwistVel &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3a4ecba875d6a101af78791765418324</anchor>
      <arglist>(const Twist &amp;r1, const TwistVel &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3536e25bdf0f28f49dc4f816febf949</anchor>
      <arglist>(const TwistVel &amp;r1, const Twist &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2e27f65e09a955123c7531e9f31364bb</anchor>
      <arglist>(const TwistVel &amp;r1, const Twist &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59eeac3549f0285cf74e1a0cf7d6a252</anchor>
      <arglist>(const VectorVel &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a249338544fa35389e6ef0557ae975b31</anchor>
      <arglist>(const VectorVel &amp;lhs, const Vector &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>IMETHOD doubleVel</type>
      <name>dot</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac268827dde5f83564132e3991e914661</anchor>
      <arglist>(const Vector &amp;lhs, const VectorVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a72c5596a3ca250d8329e774648e9fa91</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a33851c818cc9f12974f3cb29ebc74615</anchor>
      <arglist>(double lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0cf929f37d18dfea115bb8dfe0a9ba75</anchor>
      <arglist>(const TwistVel &amp;lhs, double rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f74503124b79423fed9b28b20124361</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a30bd9b19d131e18d55c493a26f69b6b0</anchor>
      <arglist>(const doubleVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator/</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3bb62491cc784aff32bdce8971cff262</anchor>
      <arglist>(const TwistVel &amp;lhs, const doubleVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a75aac327bb8398b72660f8ff603af0a7</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3965521259dda93424d97d2231d1b3fc</anchor>
      <arglist>(const TwistVel &amp;lhs, const TwistVel &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TwistVel</type>
      <name>operator-</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae749e341f554956882b5656598e11b99</anchor>
      <arglist>(const TwistVel &amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3f23dc88eba26d540cf728e9e0dd85aa</anchor>
      <arglist>(TwistVel &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aad66d20d936c19dc757be3a94cadcace</anchor>
      <arglist>(std::ostream &amp;os, const VectorVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7dc7beffdaf33343803aae8f3729330e</anchor>
      <arglist>(std::ostream &amp;os, const RotationVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad6b4b7d81abe14453de980e479590cd5</anchor>
      <arglist>(std::ostream &amp;os, const FrameVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6f27a3f6197596968c14f5976048d0cb</anchor>
      <arglist>(std::ostream &amp;os, const TwistVel &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa2015ef4bf3ebb5f6defaf8bc1cf5184</anchor>
      <arglist>(Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeRefPoint</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae68d5c0d686d03b0a779f595083209c3</anchor>
      <arglist>(const Jacobian &amp;src1, const Vector &amp;base_AB, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeBase</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa440186e9c44a521afa7e2e8816866a5</anchor>
      <arglist>(const Jacobian &amp;src1, const Rotation &amp;rot, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>changeRefFrame</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a54141738e3da2da7cebea6bd59ed605b</anchor>
      <arglist>(const Jacobian &amp;src1, const Frame &amp;frame, Jacobian &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab56d49bccacc4c7d3725ee1a31a3a686</anchor>
      <arglist>(const Jacobian &amp;a, const Jacobian &amp;b, double eps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3247ff837ae01a286d6f267f3611bd78</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac44746c206c669411831b6caff88e421</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a65d854aa88f96a677c66b50bc06b54bd</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a58ae4682bfa96df290a84bc8764db2f3</anchor>
      <arglist>(const JntArray &amp;src, const double &amp;factor, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MultiplyJacobian</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac85eca37a300ca3afa534bf3133cd134</anchor>
      <arglist>(const Jacobian &amp;jac, const JntArray &amp;src, Twist &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a2f3640f68421949e70b00b7850917ebe</anchor>
      <arglist>(JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a904f9217dcd290d305c59328c0c2a7bd</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2, double eps=epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4da090fc8773ecb33ea708305f73b0e</anchor>
      <arglist>(const JntArray &amp;src1, const JntArray &amp;src2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ac9ab98846beb21a1e6507218edda37b0</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a6267b92f0a4a416a00a1774b5f565d5e</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a576562dc10e56a5f4cd88840031b9714</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a11d30225535a30ab654b8709f63e01f3</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0c8b3f55e1a6fb791e14bcb8e0b5e9d4</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayVel &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9bac2127ca5bdf3e32005ba6c4b6e7ce</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArray &amp;src2, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab32cb0e76ccfdbc012bbdff485fa2e2c</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15f89314c4b049945d7e4566b3bb1459</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a4b751d3ba37a7ca2ee37b4955b6a1b2c</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a271c55c29a0bbb873d420392f4cd1685</anchor>
      <arglist>(const JntArrayAcc &amp;src, const double &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a29a463da0ea75ee267a9229b6397cff4</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleVel &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae8b64e8487e3bb3b6a8f2ccf5255c80f</anchor>
      <arglist>(const JntArrayAcc &amp;src, const doubleAcc &amp;factor, JntArrayAcc &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a11a7cb9d8b92e0170f7bbfa76b378704</anchor>
      <arglist>(JntArrayAcc &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a944126492e3ac5834cde755114151d75</anchor>
      <arglist>(const JntArrayAcc &amp;src1, const JntArrayAcc &amp;src2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a869bd80558b4be8a8481620a47883a53</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8315fb2791bd487674d77c3ad66a7135</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae4d61bfbf31b933f7843f71328966e85</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aadbca4bf9398d905195352bb15fffb06</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArray &amp;src2, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aecfc62e3d4f3d21b9752669794aac2fb</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3dbaa87cc9453c14a7fd4335ca343c66</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae139248a5f388a7926789e58a1cb192b</anchor>
      <arglist>(const JntArrayVel &amp;src, const double &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ab47fd546752c9082c646e51430daed25</anchor>
      <arglist>(const JntArrayVel &amp;src, const doubleVel &amp;factor, JntArrayVel &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af728f5fb88f6dfdca91afeae2d036d75</anchor>
      <arglist>(JntArrayVel &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>afdfb90a1123ea45e6b0e348aff04b230</anchor>
      <arglist>(const JntArrayVel &amp;src1, const JntArrayVel &amp;src2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Add</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af635568f6c7c9d282230d7ef6aaf2c8a</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Subtract</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad7871e05e7ecc703e39a9256dbc3ea4c</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ae7a531e845086142255090a67666ec70</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src, const double &amp;factor, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Divide</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa9dca0c2efb73851970931de9f0daa6e</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src, const double &amp;factor, JntSpaceInertiaMatrix &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Multiply</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1210f7f6f4db1eee2e2c39211c7cb388</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src, const JntArray &amp;vec, JntArray &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetToZero</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a3dd6492d65329fce08a49950b28256ee</anchor>
      <arglist>(JntSpaceInertiaMatrix &amp;mat)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Equal</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59ea9aebf2aaa6edfd35375dcbcea546</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2, double eps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abbf2ff7d3f960ab4ff33d979d13f591e</anchor>
      <arglist>(const JntSpaceInertiaMatrix &amp;src1, const JntSpaceInertiaMatrix &amp;src2)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ada870ba0c32e066ec5bc788b89d74749</anchor>
      <arglist>(std::ostream &amp;os, const Joint &amp;joint)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a14b0994fadb788bdcdb88e9009f5d919</anchor>
      <arglist>(std::istream &amp;is, Joint &amp;joint)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>ad58c420f0f0975c5cfb6c143d528a0b6</anchor>
      <arglist>(std::ostream &amp;os, const Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a462bc4499da1e5209d5001872632985b</anchor>
      <arglist>(std::istream &amp;is, Segment &amp;segment)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a82e4b532cea22eeed8fbec1bd43181f8</anchor>
      <arglist>(std::ostream &amp;os, const Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aba43ee3692a840b29148361f29ddfce5</anchor>
      <arglist>(std::istream &amp;is, Chain &amp;chain)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9d7494dc064cd870a35029348375a838</anchor>
      <arglist>(std::ostream &amp;os, const Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0ff1c2a2597af9f062ddf0358682350e</anchor>
      <arglist>(std::ostream &amp;os, SegmentMap::const_iterator root)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a15fc44010bfdca609d7802c8aab91895</anchor>
      <arglist>(std::istream &amp;is, Tree &amp;tree)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9c24a75480dd228cc709f5671a91ad5d</anchor>
      <arglist>(std::ostream &amp;os, const JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa3598c2cd0bf08e0d4091b62c3d3e70b</anchor>
      <arglist>(std::istream &amp;is, JntArray &amp;array)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a0b1bfa84edf53b8bda42eb5aed25b000</anchor>
      <arglist>(std::ostream &amp;os, const Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a85780256ced2e5f6fba9424699585611</anchor>
      <arglist>(std::istream &amp;is, Jacobian &amp;jac)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa08626fac3a13378cd8d93ce317f581f</anchor>
      <arglist>(std::ostream &amp;os, const JntSpaceInertiaMatrix &amp;jntspaceinertiamatrix)</arglist>
    </member>
    <member kind="function">
      <type>std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a59562838391488e5b3aa4b158a090225</anchor>
      <arglist>(std::istream &amp;is, JntSpaceInertiaMatrix &amp;jntspaceinertiamatrix)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>tree2str</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a41887a706e492cdc9233cd8a8d1941fd</anchor>
      <arglist>(const SegmentMap::const_iterator it, const std::string &amp;separator, const std::string &amp;preamble, unsigned int level)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>tree2str</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a47c82d0ef17bb32147727b66899b5a64</anchor>
      <arglist>(const Tree &amp;tree, const std::string &amp;separator, const std::string &amp;preamble)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>accbcba03cf4c161e16962aa6ede0f71f</anchor>
      <arglist>(double a, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9a48ecd0ba02c61eb30f97b3606a1d10</anchor>
      <arglist>(const RigidBodyInertia &amp;Ia, const RigidBodyInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aea69709844f7f034d1352c182036b5ac</anchor>
      <arglist>(const RigidBodyInertia &amp;I, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acbf30c08a930e58f18e6f4b89b4d3fd8</anchor>
      <arglist>(const Frame &amp;T, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RigidBodyInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a7274034ce0edaa31cd6c41b8db4589a7</anchor>
      <arglist>(const Rotation &amp;R, const RigidBodyInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>af55f79c3adb61f24af891e0a01b1c9da</anchor>
      <arglist>(double a, const RotationalInertia &amp;I)</arglist>
    </member>
    <member kind="function">
      <type>RotationalInertia</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>abe6b8cfeb5c5230d0641585798889a77</anchor>
      <arglist>(const RotationalInertia &amp;Ia, const RotationalInertia &amp;Ib)</arglist>
    </member>
    <member kind="function">
      <type>Wrench</type>
      <name>operator*</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aaeeb2ef394b9f8e5772d793d9c361530</anchor>
      <arglist>(const Stiffness &amp;s, const Twist &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>Stiffness</type>
      <name>operator+</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a9c96e2afbe60a8f62893843c08895a35</anchor>
      <arglist>(const Stiffness &amp;s1, const Stiffness &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>posrandom</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a8139fb4347d29af451e019f5d54f5268</anchor>
      <arglist>(Stiffness &amp;F)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>random</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>acedf7ab3ea2f5f02a51c0509a406ef33</anchor>
      <arglist>(Stiffness &amp;F)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>generatePowers</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a94c4e9f0c4e9790ec33e72003bd13fdc</anchor>
      <arglist>(int n, double x, double *powers)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>svd_eigen_Macie</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>a1ffa30e1db026c43a7a6fe8b3e2f866c</anchor>
      <arglist>(const Eigen::MatrixXd &amp;A, Eigen::MatrixXd &amp;U, Eigen::VectorXd &amp;S, Eigen::MatrixXd &amp;V, Eigen::MatrixXd &amp;B, Eigen::VectorXd &amp;tempi, double threshold, bool toggle)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const bool</type>
      <name>mhi</name>
      <anchorfile>namespaceKDL.html</anchorfile>
      <anchor>aa32a96d64e25d59e3587464cbfca82e7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>KinematicFamily</name>
    <title>Kinematic Families</title>
    <filename>group__KinematicFamily.html</filename>
    <class kind="class">KDL::Chain</class>
    <class kind="class">KDL::ChainFkSolverPos</class>
    <class kind="class">KDL::ChainFkSolverVel</class>
    <class kind="class">KDL::ChainFkSolverAcc</class>
    <class kind="class">KDL::ChainFkSolverPos_recursive</class>
    <class kind="class">KDL::ChainFkSolverVel_recursive</class>
    <class kind="class">KDL::ChainHdSolver_Vereshchagin</class>
    <class kind="class">KDL::ChainIkSolverPos</class>
    <class kind="class">KDL::ChainIkSolverVel</class>
    <class kind="class">KDL::ChainIkSolverAcc</class>
    <class kind="class">KDL::ChainIkSolverPos_LMA</class>
    <class kind="class">KDL::ChainIkSolverPos_NR</class>
    <class kind="class">KDL::ChainIkSolverPos_NR_JL</class>
    <class kind="class">KDL::ChainIkSolverVel_pinv</class>
    <class kind="class">KDL::ChainIkSolverVel_pinv_givens</class>
    <class kind="class">KDL::ChainIkSolverVel_pinv_nso</class>
    <class kind="class">KDL::ChainIkSolverVel_wdls</class>
    <class kind="class">KDL::Joint</class>
    <class kind="class">KDL::Segment</class>
    <class kind="class">KDL::Tree</class>
    <class kind="class">KDL::TreeFkSolverPos</class>
    <class kind="class">KDL::TreeFkSolverPos_recursive</class>
    <class kind="class">KDL::TreeIkSolverPos</class>
    <class kind="class">KDL::TreeIkSolverVel</class>
    <class kind="class">KDL::TreeIkSolverPos_NR_JL</class>
    <class kind="class">KDL::TreeIkSolverPos_Online</class>
  </compound>
  <compound kind="group">
    <name>Motion</name>
    <title>Motion</title>
    <filename>group__Motion.html</filename>
    <class kind="class">KDL::Path_Circle</class>
    <class kind="class">KDL::Path_Composite</class>
    <class kind="class">KDL::Path_Cyclic_Closed</class>
    <class kind="class">KDL::Path_Line</class>
    <class kind="class">KDL::Path_Point</class>
    <class kind="class">KDL::Path_RoundedComposite</class>
    <class kind="class">KDL::RotationalInterpolation</class>
    <class kind="class">KDL::RotationalInterpolation_SingleAxis</class>
    <class kind="class">KDL::Trajectory</class>
    <class kind="class">KDL::Trajectory_Composite</class>
    <class kind="class">KDL::Trajectory_Segment</class>
    <class kind="class">KDL::Trajectory_Stationary</class>
    <class kind="class">KDL::VelocityProfile</class>
    <class kind="class">KDL::VelocityProfile_Dirac</class>
    <class kind="class">KDL::VelocityProfile_Rectangular</class>
    <class kind="class">KDL::VelocityProfile_Spline</class>
    <class kind="class">KDL::VelocityProfile_Trap</class>
    <class kind="class">KDL::VelocityProfile_TrapHalf</class>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>LengthToS</name>
      <anchorfile>group__Motion.html</anchorfile>
      <anchor>gad7f55a1d6f7a076b0959c76c29cc323d</anchor>
      <arglist>(double length)=0</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>geomprim</name>
    <title>Geometric Primitives</title>
    <filename>geomprim</filename>
    <docanchor file="geomprim">Introduction</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>KDL</title>
    <filename>index</filename>
  </compound>
</tagfile>
