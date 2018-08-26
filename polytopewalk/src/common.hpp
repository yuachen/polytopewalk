#ifndef PWALK_COMMON_HPP_
#define PWALK_COMMON_HPP_

// Instantiate a class with float and double specifications.
#define INSTANTIATE_CLASS(classname) \
  char gInstantiationGuard##classname; \
  template class classname<float>; \
  template class classname<double>

#endif  // PWALK_COMMON_HPP_
