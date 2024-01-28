#ifndef BAYES_FILTER_PARTICLE_FILTER_HPP
#define BAYES_FILTER_PARTICLE_FILTER_HPP

namespace stdmath
{

namespace bayes_filter
{

template <class T>
class ParticleFilter
{
  private:
    T* data;

  public:
    ParticleFilter();
    ~ParticleFilter();
};

}  // namespace bayes_filter

}  // namespace stdmath

#endif