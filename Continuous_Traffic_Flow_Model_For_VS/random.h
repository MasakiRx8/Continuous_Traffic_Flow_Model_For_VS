/*
	This is header file of the class of "Random" that provides uniform random numbers using Mersenne twister.
*/

#ifndef RANDOM_H
#define RANDOM_H
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <string>

class Random {
public:
	Random();	//constructor
	Random(const int& seedAuxiliaryValue);	//constructor
	~Random();	//destructor

	int operator()(const int& N) const;
	int operator()(const int& Nmin, const int& Nmax) const;
	double operator()(const double& D) const;
	double operator()(const double& Dmin, const double& Dmax) const;
private:
	std::mt19937* mt;

	void Initialize_mt19937(const int& seedAuxiliaryValue);
	int create_int_rand(const int& xmin, const int& xmax) const;
	double create_double_rand(const double& xmin, const double& xmax) const;
};

#endif	//RANDOM_H