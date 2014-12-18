#include <iostream>
#include <cmath>

using namespace std;

long double dfunc1(long double x) {
	return 1 - 2/x;
}

long double func1 (long double x) {
	long double r;

	r = x;
	r = r - 2* log(x);
	r = r - 5;

	return r;
}

long double dfunc2 (long double x) {
	return pow(2,sqrt(x)) * (log(x) / 2 * sqrt(x) + 1 / sqrt(x)) - 10;
}

long double func2 (long double x) {
	return pow(2,sqrt(x)) - 10 * x + 1;
}

long double func3 (long double x) {
	return sin(3*x)/tan(x)- x + 1;
}
void newton(long double e)
{
	long double xn;

	unsigned i = 0;

	cout << "Insira um guess: " << endl;
	cin >> xn;

	long double fxn = func1(xn);
	long double dfxn = dfunc1(xn);
	long double xnmaisum = xn - (fxn / dfxn);
	long double erro;

	cout << " I |  Xn  |  F(Xn)  |  F'(Xn)  |  X(n+1)  |  X(n+1)-x(n)  " <<endl;


	do{
		erro = xnmaisum - xn;
		cout << " " << i << " |" << xn << " |" << fxn << " |" << dfxn << " |" << xnmaisum << " |"  << erro << endl;
		xn = xnmaisum;
		i++;
		fxn = func1(xn);
		dfxn = dfunc1(xn);
		xnmaisum = xn - (fxn / dfxn);
	}while (erro>e);

	cout << endl << "O zero aproximado e: " << xnmaisum;

}

int main() {

	long double e;

	cout << "Função: x-2*ln(x)-5\n";

	cout << "\nInsira o erro absoluto: ";
	cin >> e;
	if (e<=0){
		cout << "O erro absoluto tem de ser positivo";
		return 1;
	}
	newton(e);
}
