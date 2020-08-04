
# Documentation on the Vereshchagin solver
### Author of this document:  Djordje Vukcevic (GitHub account: `djoleMNE`)

## This solver is also known under the following names:
* Acceleration Constrained Hybrid Dynamics (ACHD) solver
* Popov-Vereshchagin solver
---------------------



INTRODUCTION
------------

In 1970', researchers [1], [2] have developed a hybrid dynamics algorithm for computing the required joint control commands given the task specification defined by the Cartesian acceleration constraints, feed-forward joint torques and external Cartesian forces from the environment. The solver is derived from a well-known principle of mechanics - **Gauss' principle of least constraint** [6] and provides a solution to the hybrid dynamics problem with linear-time, **O(n)** complexity [3].

In general, the Gauss' principle states that the true motion (acceleration) of a system/body is defined by the minimum of a quadratic function that is subject to linear geometric motion constraints [7], [6]. The result of this Gauss function represents the **acceleration energy** of a body, which is defined by the product of its mass and the squared distance between its allowed (constrained) acceleration and its free (unconstrained) acceleration [10]. In the case of originally derived Popov-Vereshchagin algorithm [1], geometric motion constraints are Cartesian acceleration constraints imposed on the robot's end-effector. This domain-specific solver minimizes the acceleration energy by performing computational (outward and inward) sweeps along robot kinematic chain [3]. Furthermore, by computing the minimum of Gauss function, the Popov-Vereshchagin solver resolves the kinematic redundancy of the robot, when a partial motion (task) specification is provided [2].

For evaluating robot dynamics, i.e. resolving its constrained motion, the Popov-Vereshchagin solver is performing three computational sweeps (recursions), along the kinematic chain [3]. More specifically, two sweeps in **outward** and one sweep in **inward** direction. In the case of robot dynamics algorithms, the outward sweep refers to a recursion that is covering a kinematic chain from proximal to distal segments, while the inward sweep is covering a kinematic chain from distal to proximal segments [5]. Additionally, after completing the recursion in the second sweep and before starting the recursion in the last sweep, the solver is computing magnitudes of constraint forces. More specifically, this operation is performed when the algorithm reaches segment (link) **{0}**, namely the base segment. In this formulation of the solver, the gravity effects are taken into account by setting the acceleration of the base link  **{0}** equal to gravitational acceleration [3].

For more detailed description of the algorithm and its representation, the reader can refer to [3], [5].

## INTERFACES
--------------
### **Solver's Input**:

For computing solutions to the constrained hybrid dynamics problem, this original derivation of the Popov-Vereshchagin solver [3] takes into account the following inputs:
* The robot's **dynamics model** that is defined by: kinematic parameters of the robot chain, mass and rigid body inertia of each segment, and inertia of each joint rotor -> (**chain** parameter in solver's constructor)
* **Gravitational acceleration** of the robot base segment -> (**root_acc** parameter in solver's constructor)
* Current joint configuration (positions) -> (**q** parameter in the **CartToJnt** function)
* Current joint velocities -> (**q_dot** parameter in the **CartToJnt** function)
* Motion drivers (task input): 
  - **Cartesian Acceleration constraints** imposed on the end-effector segment ->(**alpha** and **beta** parameters in the **CartToJnt** function)
  - **Cartesian External forces** acting on each segment -> (**f_ext** parameter in the **CartToJnt** function)
  - **Feed-forward joint torques** -> (**ff_torques** parameter in the **CartToJnt** function)
------------------------------------



 The following outlines the above-listed task interfaces in more detail.

#### **Cartesian Acceleration Constraints: alpha & beta** 
This first type of motion driver can be used for specifying **physical** constraints such as contacts with environment [3], or **artificial** constraints defined by the operational space task definition for the end-effector (tool-tip) segment. To use this interface, a user should define **i)** the active constraint directions via **alpha** parameter, which is a **6 x m** matrix of spatial unit constraint forces, and **ii)** acceleration energy setpoints via **beta**, which is a **m x 1** vector. Here, the number of constraints **m**, or in another words number of spatial unit constraint forces is not required to always be equal to **m**, which means that a human programmer can leave some of the degrees of freedom unspecified [2] for this motion driver, and still produce valid control commands [5]. For example, if we want to constrain the motion of the end-effector segment in only one direction, namely linear **x**-direction, we can define the constraint as [3]:

**alpha** = 
|   |
| --|
| 1 |
| 0 | 
| 0 |
| 0 |
| 0 | 
| 0 |

**beta** = 0


Note that here, the first three rows of matrix **alpha** represent linear elements and the last three rows represent angular elements,  of the spatial unit force defined in Pl{\"u}cker coordinates [4]. By giving zero value to acceleration energy setpoint (**beta**), we are defining that the end-effector is not allowed to have linear acceleration in **x** direction. Or in other words, we are restricting the robot from producing any acceleration energy in that specified direction.

Another example includes the specification of constraints in **5 DOFs**. We can constrain the motion of robot's end-effector, such that it is only allowed to  **freely** move in the linear **z**-direction, without performing linear motions in **x** and **y** and angular motions in **x**, **y** and **z** directions:

**alpha** = 
|   |   |   |   |   |
| --| --| --| --| --|
| 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 1 |

**beta** = 
|   |
| --|
| 0 | 
| 0 |
| 0 |
| 0 | 
| 0 |


For both above-described task examples, the Accereleration Constrained Hybrid Dynamics (ACHD) solver will compute valid control joint torques, even though some of the Cartesian DOFs are left unspecified (e.g. in the case of the second example that would be end-effector's **z**-direction). More specifically: ``Underconstrained motion specifications are naturally resolved using Gauss' principle of least constraint`` [5]. For instance, in the second example, natural resolution of the robot motion would define that the end-effector "**falls**" in the linear **z** direction due to effects of gravity, with the assumption that gravity forces are acting along $z$-direction.

Moreover, the motion specification in the second example is equivalent to:

**alpha** = (note that elements in the thid column are all zeros, meaning z-linear constraint is deactivated)
|   |   |   |   |   |   |
| --| --| --| --| --| --|
| 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 1 |

**beta** = 
|   |
| --|
| 0 | 
| 0 |
| 0 |
| 0 | 
| 0 |
| 0 |

The last example involves the specification of desired end-effecor motion (in this case, non-zero accelerations) in all 6 **DOFs**:

**alpha** = 
|   |   |   |   |   |   |
| --| --| --| --| --| --|
| 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 1 |

**beta** = **alpha^T * X_dotdot_N**

The reader should note that we can directly assign values (magnitudes) of spatial acceleration **6 x 1** vector **X_dotdot_N** to the **6 x 1** vector of acceleration energy (**beta**) [3]. Even though physical dimensions (units) of these two vectors are not the same, the property of matrix **alpha** (it contains **unit** vectors), permits that we can assign values of desired accelerations to acceleration energy setpoints, in respective directions. Namely, each column of matrix **alpha** has the value of **1** in the respective direction in which constraint force works, thus it follows that the value of acceleration energy setpoint is the same as the value of Cartesian acceleration, in the respective direction. Here, **N** stands for the index of the last robot's segment, end-effector(tool-tip).

#### **External Forces: f_ext**
This type of driver can be used for specifying **physical** Cartesian forces acting on each of the robot's segments. Examples for a **physical** force on a segment can be: **i)** a known weight at the robot's gripper, for instance, a grasped cup or **ii)** a force from a human pushing the robot [5].

#### **Feed-Forward Joint Torques: ff_torque**
This type of motion driver can be used for specifying **physical** joint torques, for example, dynamic friction (joint velocity dependent) effects in robot's joints. 

Additional examples on using these input interfaces can be found in:
* ../examples/vereshchagin_solver_demo.cpp
* ../tests/solvertest.cpp

-----------------------------------

### **Solver's Output**:
This recursive dynamics solver is computing several quantities that represent solutions to both, inverse and forward dynamics problems, or in other words solutions to the constrained hybrid dynamics problem. More specifically, the output interface of the original Popov-Vereshchagin algorithm consists of of [3], [5]: 
 * Magnitudes of constraint forces that act on the end-effector, denoted by the Lagrange multiplier **nu** in the solver's implementation.
	
* Joint space control commands, i.e. joint torques required for achieving the desired (task-defined) behaviour of the robot: **ctrl_torque**. These torques represent commands that should be sent to the robot's joint drivers.
	
* Argument that defines the solution to the originally formulated optimization problem in **Gauss' principle**. In other words, a set of joint accelerations **q_dotdot** resulting from the aforementioned control torques and all natural and external forces acting on the system, i.e. **total_torque**.
	
* The resulting and complete spatial accelerations of each segment in the kinematic chain: **X_dotdot**

Furthermore, a complete spatial vector of imposed constraint forces can be computed [3], from the following relation: **alpha * nu**. However, this option is not yet implemented in the KDL.

The reader should note that this **ctrl_torque** is the **necessary** control command that a user is supposed to send to robot's joints, to achieve the motion that is computed (resolved) by the Popov-Vereshchagin solver. More specifically, here **ctrl_torque** represent solution to the **Inverse Dynamics (ID)** problem. Nevertheless, the reason why a user is not supposed to use the **total_torque** values as the control commands for robot's joints, is the fact that the torque contributions that represent the difference between **total_torque** and **ctrl_torque** already exist (act) on robot joints. More specifically, these **additional (resudual)** contributions are produced on the joints by the already existing natural forces that act on the system.

On the other side, joint and segment accelerations, namely  **q_dotdot** provide solution to the **Forward Dynamics (FD)** and these quantities can be used for both control (integrate to joint positions/velocities) and simulation purposes. 

The Popov-Vereshchagin hybrid dynamics solver enables a user to achieve many types of operational space tasks. In other words, various controllers can be implemented **around** the aforementioned interfaces of the algorithm. Examples can be controllers for hybrid force/position control, impedance control, etc.


## REFERENCES
-------------

[1] E. P. Popov, A. F. Vereshchagin, and S. L. Zenkevich, “Manipulyatsionnye roboty: Dinamika i algoritmy”, Nauka, Moscow, 1978.

[2] A. F. Vereshchagin, “Modelling and control of motion of manipulation robots”, Soviet Journal of Computer and Systems Sciences, vol. 27, pp. 29–38, 1989.

[3] A. Shakhimardanov, “Composable robot motion stack: Implementing constrained hybrid dynamics using semantic models of kinematic chains”, PhD thesis, KU Leuven, 2015.

[4] R. Featherstone, Rigid body dynamics algorithms. Springer, 2008.

[5] S. Schneider and H. Bruyninckx, “Exploiting linearity in dynamics solvers for the design of composable robotic manipulation architectures”, in IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS), 2019.

[6] H. Bruyninckx and O. Khatib, "Gauss’ principle and the dynamics of redundant and constrained manipulators", in IEEE International Conference on Robotics and Automation, 2000.

[7] C. F. Gauß, "Über ein neues allgemeines Grundgesetz der Mechanik.", Journal für die reine und angewandte Mathematik, vol. 4, pp. 232–235, 1829.

[8] A. F. Vereshchagin, “Computer simulation of the dynamics of complicated mechanisms of robot-manipulators”, Engineering Cybernetics, 12(6), pp. 65–70, 1974.

[9] E. P. Popov, "Control of robots-manipulators", Engineering Cybernetics, 1974.

[10] E. Ramm, “Principles of least action and of least constraint”, GAMM-Mitteilungen, vol. 34, pp. 164–182, 2011.