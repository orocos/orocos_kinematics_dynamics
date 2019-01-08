#ifndef KDL_EIGEN_TYPES_H
#define KDL_EIGEN_TYPES_H

#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace KDL
{

//
// Eigen type alias
// For the purpose of Eigen::DontAlign, please refer to:
// http://eigen.tuxfamily.org/dox/group__TopicStructHavingEigenMembers.html
template <typename T, int Row, int Col>
using Mat = Eigen::Matrix<T, Row, Col, Eigen::DontAlign>;

// NOTE: By default Eigen uses ColumnMajor, here we use RowMajor, Be careful about this.

template <typename T, int Row>
using Vec = Eigen::Matrix<T, Row, 1, Eigen::DontAlign>;


//  alias for double type
using Vec2d = Vec<double, 2>;
using Vec3d = Vec<double, 3>;
using Vec4d = Vec<double, 4>;
using Vec5d = Vec<double, 5>;
using Vec6d = Vec<double, 6>;
using Vec7d = Vec<double, 7>;
using Vec8d = Vec<double, 8>;
using VecXd = Vec<double, Eigen::Dynamic>;

using Mat2d = Mat<double, 2, 2>;
using Mat3d = Mat<double, 3, 3>;
using Mat4d = Mat<double, 4, 4>;
using Mat5d = Mat<double, 5, 5>;
using Mat6d = Mat<double, 6, 6>;
using Mat68d = Mat<double, 6, 8>;
using MatXd = Mat<double, Eigen::Dynamic, Eigen::Dynamic>;

using Vec2f = Vec<float, 2>;
using Vec3f = Vec<float, 3>;
using Vec4f = Vec<float, 4>;
using Vec5f = Vec<float, 5>;
using Vec6f = Vec<float, 6>;
using Vec7f = Vec<float, 7>;
using Vec8f = Vec<float, 8>;
using VecXf = Vec<float, Eigen::Dynamic>;

using Mat2f = Mat<float, 2, 2>;
using Mat3f = Mat<float, 3, 3>;
using Mat4f = Mat<float, 4, 4>;
using Mat5f = Mat<float, 5, 5>;
using Mat6f = Mat<float, 6, 6>;
using Mat68f = Mat<float, 6, 8>;
using MatXf = Mat<float, Eigen::Dynamic, Eigen::Dynamic>;

}  // namespace KDL



#endif 
