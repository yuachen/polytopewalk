#include "ball_walker.hpp"

#include <cmath>

namespace pwalk {

template <typename Dtype>
bool BallWalker<Dtype>::doSample(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample, const Dtype lazy){
  proposal(new_sample);
  this->nb_curr_samples_ += 1;
  // for lazy markov chain
  Dtype random_num = rng_uniform<Dtype>(0., 1.);
  // check balance and check in polytope
  if (random_num < lazy &&  this->checkInPolytope(new_sample) && acceptRejectReverse(new_sample)){
    this->curr_sample_ = new_sample;
    return true;
  } else {
    new_sample = this->curr_sample_;
    return false;
  }
}

template <typename Dtype>
void BallWalker<Dtype>::proposal(Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample){
  Eigen::Matrix<Dtype, Eigen::Dynamic, 1> gaussian_step = Eigen::Matrix<Dtype, Eigen::Dynamic, 1>::Zero(this->nb_dim_);
  sample_gaussian<Dtype>(this->nb_dim_, 0., 1., gaussian_step);
  new_sample = this->curr_sample_ + r_/std::sqrt(Dtype(this->nb_dim_)) * gaussian_step;
}

template <typename Dtype>
bool BallWalker<Dtype>::acceptRejectReverse(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& new_sample){
  Dtype random_num = rng_uniform<Dtype>(0., 1.);
  // lazy version of the walk
  if (random_num > 0.99) {
    return false;
  }

  return true;
}


INSTANTIATE_CLASS(BallWalker);

} // namespace pwalk
