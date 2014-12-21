#include <iostream> //cout
#include <cmath> //contas
#include <Windows.h>

using namespace std;

#define TMAX 	7200
#define KET		0.093

long double func(long double);
long double dfunc(long double);
void bissec();
void corda();
void newton();
long double media(long double, long double);

int main(){

	int metodo = -1;

	do{
		system("CLS");
		cout << "Funcao: x^6-x-cos(0.2x+1)" << endl;
		cout << "Escolher o metodo de calculo:" << endl;
		cout << "[0]Exit" << endl << "[1]Bissecao" << endl << "[2]Corda" << endl << "[3]Newton" << endl;
		cin >> metodo;
	} while (cin.fail() || metodo < 0 || metodo > 3);

	switch (metodo){
	case 0:
		cout << "O programa vai sair" << endl;
		Sleep(1000);
		return 0;
		break;
	case 1:
		//METHOD1
		bissec();
		break;
	case 2:
		//METHOD2
		corda();
		break;
	case 3:
		//METHOD3
		newton();
		break;
	}

	char exit = 'n';

	cout << endl << "Voltar ao menu? (s/n)";
	cin >> exit;
	if (exit == 'n'){
		return 0;
	}
	else if (exit == 's'){
		main();
	}
	return metodo;
}

void bissec(){
	long double a, b, x, fa, fb, fx, e = 1,xn1;

	cout << "Guess a: ";
	cin >> a;
	cout << "Guess b: ";
	cin >> b;

	while (e >= 0.0000001){
		x = media(a, b);
		fa = func(a);
		fb = func(b);
		fx = func(x);
		xn1 = media(fa, fb);
		cout << a << " | " << b << " | " << x << " | " << fa << " | " << fb << " | " << fx << " | ";

		if (fx < 0)
			a = x;
		if (fx > 0)
			b = x;

		e = abs((xn1 - x) / xn1);
		cout << e << endl;
	}
}

void corda(){
	long double a, b, x, fa, fb, fx, e = 1, xn1;

	do{
		cout << "Guess a: ";
		cin >> a;
		cout << "Guess b: ";
		cin >> b;

		if (fa*fb > 0)
			cout << "Ambos os valores tem o mesmo sinal. Insira novo intervalo" << endl;
	} while (fa*fb > 0);

	x = (a + b) / 2;

	while (e >= 0.0000001){
		fa = func(a);
		fb = func(b);
		fx = func(x);

		xn1 = ((a*fb) - (b*fa)) / (fb - fa);

		cout << a << " | " << b << " | " << x << " | " << fa << " | " << fb << " | " << fx << " | ";

		if (fa*fx > 0)
			a = x;
		if (fb*fx > 0)
			b = x;

		e = abs((xn1 - x) / xn1);
		cout << e << endl;

	}
}

void newton(){

	long double xn, e;

	unsigned i = 0;

	cout << "Insira um guess: " << endl;
	cin >> xn;
	cout << "Insira um erro absoluto positivo";
	cin >> e;

	long double fxn = func(xn);
	long double dfxn = dfunc(xn);
	long double xnmaisum = xn - (fxn / dfxn);
	long double erro;

	cout << " I |  Xn  |  F(Xn)  |  F'(Xn)  |  X(n+1)  |  X(n+1)-x(n)  " << endl;


	do{
		erro = xnmaisum - xn;
		cout << " " << i << " |" << xn << " |" << fxn << " |" << dfxn << " |" << xnmaisum << " |" << erro << endl;
		xn = xnmaisum;
		i++;
		fxn = func(xn);
		dfxn = dfunc(xn);
		xnmaisum = xn - (fxn / dfxn);
	} while (erro > e);

	cout << endl << "O zero aproximado e: " << xnmaisum;
}

long double func(long double x){
	return x;
}

long double dfunc(long double x){
	return x;
}

long double media(long double a, long double b){
	return (a + b) / 2;
}