#include <iostream> //cout
#include <cmath> //contas

#include "zeros.h"

using namespace std;

#define TMAX 	120
#define KET		0.093

#define GUESSA	-0.2
#define GUESSB	0.001

#define GUESSNEWTON	0

#define EPSILON 0.00001


int zeros() {
	cout << endl << endl << "Metodo: " << endl << endl;
	cout << "1. Bisseccao" << endl;
	cout << "2. Corda" << endl;
	cout << "3. Newton" << endl;
	cout << "4. Sair" << endl;

	int opt;
	cin >> opt;

	switch (opt) {
	case 1: {
		bissec();
		return 0;
	}
	case 2: {
		corda();
		return 0;
	}
	case 3: {
		newton();
		return 0;
	}
	case 4: {
		return 0;
	}
	default: {
		zeros();
		break;
	}
	}

	return 0;
}
long double f(long double x) {
	return x * exp(-TMAX * x) - KET * exp(-KET*TMAX);
	//return x - 2 * log(x) - 5;
}
long double df(long double x) {
	return exp(-TMAX * x) - TMAX * exp(-TMAX * x);
	//return 1 - 2/x;
}

void bissec() {
	long double a = GUESSA;
	long double b = GUESSB;
	long double fa = f(a);
	long double fb = f(b);

	long double x = (a + b) / 2;
	long double fx = f(x);

	long double xanterior;

	long double erro = 1;

	int i = 1;

	while (erro > EPSILON) {
		cout << "n: " << i << " a: " << a << " b: " << b << " x: " << x
				<< " f(a)= " << fa << " f(b)= " << fb << " f(x)= " << fx
				<< " erro: " << erro << endl;

		if (fa * fx > 0)
			a = x;
		else
			b = x;

		fa = f(a);
		fb = f(b);

		xanterior = x;

		x = (a + b) / 2;
		fx = f(x);

		erro = abs((x - xanterior) / x);
		i++;
	}
}

void corda() {
	long double a = GUESSA;
	long double b = GUESSB;

	long double fa = f(a);
	long double fb = f(b);

	long double xn = (a * f(b) - b * f(a)) / (fb - fa);
	long double fxn = f(xn);

	long double xnanterior;
	long double erro = 1;
	int i = 1;

	while (erro > EPSILON) {
		cout << "n: " << i << " a: " << a << " b: " << b << " xn: " << xn
				<< " f(a)= " << fa << " f(b)= " << fb << " f(xn)= " << fxn
				<< endl;

		if ((fa / fxn) > 0) {
			a = xn;
		} else {
			b = xn;
		}

		fa = f(a);
		fb = f(b);

		xnanterior = xn;

		xn = (a * f(b) - b * f(a)) / (fb - fa);
		fxn = f(xn);

		erro = abs((xn - xnanterior) / xn);
		i++;
	}
}

void newton() {
	int i = 1;

	long double xn = GUESSNEWTON;
	long double fxn = f(xn);
	long double dfxn = df(xn);

	long double xnmaisum = xn - (fxn / dfxn);
	long double erro = 1;

	while (erro > EPSILON) {
		erro = abs(xnmaisum - xn);
		cout << "n: " << i << " xn: " << xn << " f(xn): " << fxn << " df(xn): "
				<< dfxn << " x(n+1): " << xnmaisum << " Erro: " << erro << endl;
		xn = xnmaisum;
		fxn = f(xn);
		dfxn = df(xn);
		xnmaisum = xn - (fxn / dfxn);
		i++;
	}
}

