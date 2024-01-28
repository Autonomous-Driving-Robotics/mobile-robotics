#include "gtest/gtest.h"
#include "particle_filter.hpp"

TEST(BayesFilterTest, ParticleFilterInitialisation)
{
    stdmath::bayes_filter::ParticleFilter<double> particle_filter_double;
    stdmath::bayes_filter::ParticleFilter<float> particle_filter_float;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}