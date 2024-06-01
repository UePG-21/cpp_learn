/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/12/21
 */
#ifndef NormalGenerator_hpp
#define NormalGenreator_hpp

// boost
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

class NormalGenerator
{
public:
    virtual ~NormalGenerator() {};
    // Empty at the moment
    virtual double getNormal() const = 0;
};

class BoostNormal : public NormalGenerator
{
private:
    boost::lagged_fibonacci607 rng;
    boost::normal_distribution<> nor;
    boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<>>* myRandom;

public:
    BoostNormal();  // NB no uniform parameters
    virtual ~BoostNormal();

    // Implement (variant) hook function
    virtual double getNormal() const;
};

#endif
