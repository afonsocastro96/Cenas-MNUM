#include <iostream>
#include <cmath>

using namespace std;

long double func1(long double x);
long double func2(long double x);
long double func3(long double x);

int main() {

	int f;
	long double a, b, n;
	long double fa, fb, fn;
	long double e;

	cout << "Função 1: x⁶-x-cos(0.2x+1)\n";
	cout << "Função 2: x*sin(x)-1\n";
	cout << "Função 3: x-ln(x)-10\n" << endl;

	cout << "Insira a função a utilizar: ";
	cin >> f;
	cout << "\nInsira o erro absoluto: ";
	cin >> e;
	if (e <= 0) {
		cout << "O erro absoluto tem de ser positivo";
		return 1;
	}

	switch (f) {
	case 1:
		cout << "Função: x⁶ - x * cos(0.2x + 1)" << endl;
		cout << "Insira os valores de a e b" << endl;
		cout << "a: ";
		cin >> a;
		cout << endl << "b: ";
		cin >> b;
		fa = func1(a);
		fb = func1(b);
		if (fa * fb > 0) {
			cout << endl
					<< "Ambos os valores tem o mesmo sinal, escolha um novo intervalo";
			return 1;
		}
		cout << endl << "f(a)= " << fa;
		cout << endl << "f(b)= " << fb;
		do {
			cout << endl << "Insira um valor para n: ";
			cin >> n;
			fn = func1(n);
			cout << endl << "f(n)= " << fn;
			if (fa * fn > 0) {
				a = n;
				cout << endl << "f(n) < 0, a substituir a por n";
				cout << endl
						<< "Sugestao: Inserir um valor para n maior que o anterior";
			} else {
				b = n;
				cout << endl << "f(n) > 0, a substituir b por n";
				cout << endl
						<< "Sugestao: Inserir um valor para n menor que o anterior";
			}
		} while (abs(fn) > e);
		cout << endl << endl << "O zero e aproximadamente igual a " << n;
		break;
	case 2:
		cout << "Função: x*sin(x) - 1" << endl;
		cout << "Insira os valores de a e b" << endl;
		cout << "a: ";
		cin >> a;
		cout << endl << "b: ";
		cin >> b;
		fa = func2(a);
		fb = func2(b);
		if (fa * fb > 0) {
			cout << endl
					<< "Ambos os valores tem o mesmo sinal, escolha um novo intervalo";
			return 1;
		}
		cout << endl << "f(a)= " << fa;
		cout << endl << "f(b)= " << fb;
		do {
			cout << endl << "Insira um valor para n: ";
			cin >> n;
			fn = func2(n);
			cout << endl << "f(n)= " << fn;
			if (fa * fn > 0) {
				a = n;
				cout << endl << "f(n) < 0, a substituir a por n";
				cout << endl
						<< "Sugestao: Inserir um valor para n maior que o anterior";
			} else {
				b = n;
				cout << endl << "f(n) > 0, a substituir b por n";
				cout << endl
						<< "Sugestao: Inserir um valor para n menor que o anterior";
			}
		} while (abs(fn) > e);
		cout << endl << endl << "O zero e aproximadamente igual a " << n;
		break;
	case 3:
		cout << "Função: x - ln(x) - 10" << endl;
		cout << "Insira os valores de a e b" << endl;
		cout << "a: ";
		cin >> a;
		cout << endl << "b: ";
		cin >> b;
		if (a <= 0 || b <= 0) {
			cout << endl << "A funcao so tem dominio em R+";
			return 1;
		}
		fa = func3(a);
		fb = func3(b);
		if (fa * fb > 0) {
			cout << endl
					<< "Ambos os valores tem o mesmo sinal, escolha um novo intervalo";
			return 1;
		}
		cout << endl << "f(a)= " << fa;
		cout << endl << "f(b)= " << fb;
		do {
			cout << endl << "Insira um valor para n: ";
			cin >> n;
			fn = func3(n);
			cout << endl << "f(n)= " << fn;
			if (fa * fn > 0) {
				a = n;
				cout << endl << "f(n) < 0, a substituir a por n";
				cout << endl
						<< "Sugestao: Inserir um valor para n maior que o anterior";
			} else {
				b = n;
				cout << endl << "f(n) > 0, a substituir b por n";
				cout << endl
						<< "Sugestao: Inserir um valor para n menor que o anterior";
			}
		} while (abs(fn) > e);
		cout << endl << endl << "O zero e aproximadamente igual a " << n;
		break;
	}

	return 0;
}

long double func1(long double x) {
	long double r;

	r = x * x * x * x * x * x;
	r = r - x;
	r = r - cos(0.2 * x + 1);

	return r;
}

long double func2(long double x) {
	long double r;

	r = x * sin(x);
	r--;

	return r;
}

long double func3(long double x) {
	long double r;

	r = x;
	r = r - log(x);
	r = r - 10;

	return r;
}
