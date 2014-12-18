#include <iostream> //cout
#include <cmath> //

#define TMAX 	7200
#define KET		0.093

long double funcao(long double x) {
	long double y;
	long double temp = -TMAX * x;

	y = exp(temp);
	y = y * x;
	y = y - KET* exp(-TMAX * KET);
}
