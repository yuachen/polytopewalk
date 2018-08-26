#ifndef PWALK_BALL_WALKER_HPP_
#define PWALK_BALL_WALKER_HPP_

#include <Eigen/Dense>
#include "util/math_functions.hpp"
#include "walker.hpp"

namespace pwalk {

template <typename Dtype>
class BallWalker: public Walker<Dtype> {
public:
  BallWalker(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& initialization, const Eigen::Matrix<Dtype, Eigen::Dynamic, Eigen::Dynamic>& cons_A, const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& cons_b, const Dtype r) : Walker<Dtype>(initialization, cons_A, cons_b), r_(r){}

  // getter for radius
  Dtype getRadius() {
    return r_;
  }

  void proposal(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample);

  bool acceptRejectReverse(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample);

  bool doSample(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample, const Dtype lazy = Dtype(0.5));



private:
  const Dtype r_;
};

} // namespace pwalk

#endif // PWALK_BALL_WALKER_HPP_
