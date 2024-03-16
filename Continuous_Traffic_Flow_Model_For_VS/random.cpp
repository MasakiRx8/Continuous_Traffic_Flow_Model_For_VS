/*
	This is header file of the class of "Random" that provides uniform random numbers using Mersenne twister.
*/

#include "random.h"

//constructor
Random::Random() {
	Initialize_mt19937(0);
}

//constructor
Random::Random(const int& seedAuxiliaryValue) {
	Initialize_mt19937(seedAuxiliaryValue);
}

//destructor
Random::~Random() {
	if (mt != nullptr) {
		delete mt;
		mt = nullptr;
	}
}

int Random::operator()(const int& N) const {
	return create_int_rand(0, N);
}

int Random::operator()(const int& Nmin, const int& Nmax) const {
	return create_int_rand(Nmin, Nmax);
}

double Random::operator()(const double& D) const {
	return create_double_rand(0.0, D);
}

double Random::operator()(const double& Dmin, const double& Dmax) const {
	return create_double_rand(Dmin, Dmax);
}

void Random::Initialize_mt19937(const int& seedAuxiliaryValue) {
	std::array<std::seed_seq::result_type, std::mt19937::state_size> seed_data;
	std::random_device seed_gen(std::to_string(seedAuxiliaryValue));
	std::generate(seed_data.begin(), seed_data.end(), std::ref(seed_gen));
	std::seed_seq seq(seed_data.begin(), seed_data.end());
	mt = new std::mt19937(seq);
}

int Random::create_int_rand(const int& xmin, const int& xmax) const {
	std::uniform_int_distribution<> rd(xmin, xmax);
	return rd(*mt);
}

double Random::create_double_rand(const double& xmin, const double& xmax) const {
	std::uniform_real_distribution<> rd(xmin, xmax);
	return rd(*mt);
}