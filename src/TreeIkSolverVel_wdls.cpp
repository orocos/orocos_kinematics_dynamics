/*
 * TreeIkSolverVel_wdls.cpp
 *
 *  Created on: Nov 28, 2008
 *      Author: rubensmits
 */

#include "TreeIkSolverVel_wdls.hpp"
#include <kdl/utilities/svd_boost_HH.hpp>

namespace KDL {
using namespace std;

TreeIkSolverVel_wdls::TreeIkSolverVel_wdls(const Tree& tree_in, std::vector<
        std::string> endpoints) :
    tree(tree_in), jnttojacsolver(tree),
    J(ublas::zero_matrix<double>(6 * endpoints.size(), tree.getNrOfJoints())),
    Wy(ublas::identity_matrix<double>(J.size1(),J.size1())),
    Wq(ublas::identity_matrix<double>(J.size2(),J.size2())),
    J_Wq(J.size1(),J.size2()),Wy_J_Wq(J.size1(),J.size2()),
    U(ublas::identity_matrix<double>(J.size1(),J.size2())),
    V(ublas::identity_matrix<double>(J.size2(),J.size2())),
    Wy_U(J.size1(),J.size1()),Wq_V(J.size2(),J.size2()),
    t(ublas::zero_vector<double>(J.size1())), qdot(ublas::zero_vector<double>(J.size2())),
    tmp(ublas::zero_vector<double>(J.size2())),S(ublas::zero_vector<double>(J.size2()))
    {

    for (size_t i = 0; i < endpoints.size(); ++i) {
        jacobians.insert(Jacobians::value_type(endpoints[i], Jacobian(
                tree.getNrOfJoints())));
    }

}

TreeIkSolverVel_wdls::~TreeIkSolverVel_wdls() {
}

void TreeIkSolverVel_wdls::setWeightJS(const ublas::symmetric_matrix<double> Mq) {
    Wq = Mq;
}

void TreeIkSolverVel_wdls::setWeightTS(
        const ublas::symmetric_matrix<double> Mx) {
    Wy = Mx;
}

void TreeIkSolverVel_wdls::setLambda(const double& lambda_in) {
    lambda = lambda_in;
}

int TreeIkSolverVel_wdls::CartToJnt(const JntArray& q_in, const Twists& v_in,
        JntArray& qdot_out) {

    //First check if we are configured for this Twists:
    for (Twists::const_iterator v_it = v_in.begin(); v_it != v_in.end(); ++v_it) {
        if (jacobians.find(v_it->first) == jacobians.end())
            return -2;
    }
    //Check if q_in has the right size
    if (q_in.rows() != tree.getNrOfJoints())
        return -1;

    //Lets get all the jacobians we need:
    unsigned int k = 0;
    for (Jacobians::iterator jac_it = jacobians.begin(); jac_it
            != jacobians.end(); ++jac_it) {
        int ret = jnttojacsolver.JntToJac(q_in, jac_it->second, jac_it->first);
        if (ret < 0)
            return ret;
        else {
            //lets put the jacobian in the big matrix and put the twist in the big t:
            for (unsigned int i = 0; i < 6; ++i)
                for (unsigned int j = 0; j < tree.getNrOfJoints(); ++j) {
                    J(i + 6 * k, j) = jac_it->second(i, j);
                    t(i + 6 * k) = v_in.find(jac_it->first)->second(i);
                }
        }
        ++k;
    }

    //Lets use the wdls algorithm to find the qdot:
    // Create the Weighted jacobian
    noalias( J_Wq) = prod(J, Wq);
    noalias( Wy_J_Wq) = prod(Wy, J_Wq);

    // Compute the SVD of the weighted jacobian
    int ret = svd_boost_HH(Wy_J_Wq, U, S, V, tmp);

    //Pre-multiply U and V by the task space and joint space weighting matrix respectively
    noalias( Wy_U) = prod(Wy,
            project(U, range(0, t.size()), range(0, t.size())));
    noalias( Wq_V) = prod(Wq, V);

    // tmp = (Si*Wy*U'*y),
    for (unsigned int i = 0; i < J.size2(); i++) {
        double sum = 0.0;
        for (unsigned int j = 0; j < J.size1(); j++) {
            if (i < t.size())
                sum += Wy_U(j, i) * t(j);
            else
                sum += 0.0;
        }
        tmp( i) = sum * ((S(i) / (S(i) * S(i) + lambda * lambda)));
    }

    // x = Lx^-1*V*tmp + x
    for (unsigned int i = 0; i < J.size2(); i++) {
        double sum = 0.0;
        for (unsigned int j = 0; j < J.size2(); j++) {
            sum += Wq_V(i, j) * tmp(j);
        }
        qdot_out( i) = sum;
    }
    return ret;
}
}
