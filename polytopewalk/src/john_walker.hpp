#ifndef PWALK_JOHN_WALKER_HPP_
#define PWALK_JOHN_WALKER_HPP_

#include <cmath>
#include <Eigen/Dense>
#include "util/math_functions.hpp"
#include "walker.hpp"

namespace pwalk {

template <typename Dtype>
class JohnWalker: public Walker<Dtype> {
public:
  JohnWalker(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& initialization, const Eigen::Matrix<Dtype, Eigen::Dynamic, Eigen::Dynamic>& cons_A, const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& cons_b, const Dtype r) : Walker<Dtype>(initialization, cons_A, cons_b), r_(r), alpha_(1. - 1. / std::log2(2.*Dtype(cons_A.rows())/Dtype(cons_A.cols()))), beta_(Dtype(cons_A.cols())/2./Dtype(cons_A.rows())), curr_weight_(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>::Ones(cons_A.rows())){}

  // getter for radius
  Dtype getRadius() {
    return r_;
  }

  void proposal(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample);

  bool acceptRejectReverse(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample);

  bool doSample(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample, const Dtype lazy = Dtype(0.5));

  void sqrtInvHessBarrier(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample, Eigen::Matrix<Dtype, Eigen::Dynamic, Eigen::Dynamic>& new_sqrt_inv_hess);

private:
  const Dtype r_;
  const Dtype alpha_;
  const Dtype beta_;

  Eigen::Matrix<Dtype, Eigen::Dynamic, 1> curr_weight_;
};

} // namespace pwalk

#endif // PWALK_JOHN_WALKER_HPP_

