#include "particle_filter.hpp"

namespace stdmath
{

namespace bayes_filter
{

template <class T>
ParticleFilter<T>::ParticleFilter()
{
    data = new T[10];
}

template <class T>
ParticleFilter<T>::~ParticleFilter()
{
    delete[] data;
}

// Specify all possible template arguments. This hack is required
// to separate template class in cpp and hpp files.
// Refer: https://blog.modest-destiny.com/posts/split-cpp-template-declaration-and-implementation/
// https://stackoverflow.com/questions/1724036/splitting-templated-c-classes-into-hpp-cpp-files-is-it-possible
template class ParticleFilter<float>;
template class ParticleFilter<double>;

}  // namespace bayes_filter

}  // namespace stdmath