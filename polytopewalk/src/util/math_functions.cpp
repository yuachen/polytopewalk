#include <boost/random.hpp>
#include <eigen/Dense>

#include "math_functions.hpp"
#include <cmath>

namespace pwalk {

// Define random number generator type
typedef boost::mt19937 rng_t;

template <typename Dtype>
void sample_gaussian(const int n, const Dtype a,
                        const Dtype sigma, Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& r) {
  static rng_t gen(1234567);
  static boost::normal_distribution<Dtype> random_distribution(a, sigma);
  static boost::variate_generator<rng_t&, boost::normal_distribution<Dtype> >
      variate_generator(gen, random_distribution);

  for (int i = 0; i < n; ++i) {
    r[i] = variate_generator();
  }
}

template <typename Dtype>
Dtype rng_uniform(const Dtype a, const Dtype b) {
  static rng_t gen(1234567);
  static boost::uniform_real<Dtype> random_distribution(a, b);
  static boost::variate_generator<rng_t&, boost::uniform_real<Dtype> >
      variate_generator(gen, random_distribution);

  return variate_generator();
}

template <typename Dtype>
Dtype gaussian_density(const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& x, const Eigen::Matrix<Dtype, Eigen::Dynamic, 1>& mu, const Eigen::Matrix<Dtype, Eigen::Dynamic, Eigen::Dynamic>& sqrt_cov) {
  Eigen::Matrix<Dtype, Eigen::Dynamic, 1> c = sqrt_cov * (x - mu);
  return std::exp(-0.5*c.dot(c)) * sqrt_cov.determinant();
}

template
void sample_gaussian<float>(const int n, const float mu,
                               const float sigma, Eigen::Matrix<float, Eigen::Dynamic, 1>& r);

template
void sample_gaussian<double>(const int n, const double mu,
                                const double sigma, Eigen::Matrix<double, Eigen::Dynamic, 1>& r);


template
float rng_uniform<float>(const float a, const float b);

template
double rng_uniform<double>(const double a, const double b);


template
float gaussian_density(const Eigen::Matrix<float, Eigen::Dynamic, 1>& x, const Eigen::Matrix<float, Eigen::Dynamic, 1>& mu, const Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>& sqrt_inv_cov);


template
double gaussian_density(const Eigen::Matrix<double, Eigen::Dynamic, 1>& x, const Eigen::Matrix<double, Eigen::Dynamic, 1>& mu, const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>& sqrt_inv_cov);

} // namespace pwalk
