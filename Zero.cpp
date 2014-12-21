#include <iostream> //cout
#include <cmath> //contas

using namespace std;

#define TMAX 	7200
#define KET		0.093

long double func(long double);
long double dfunc(long double);

#define GUESSA	0
#define GUESSB	1.5
#define EPSILON 0.00001

long double funcao(long double x);

void bissec();
void corda();
void newton();
long double media(long double, long double);

/*int main(){

	int metodo = -1;

	do{
	//system("CLS");
	cout << "Funcao: x^6-x-cos(0.2x+1)" << endl;
	cout << "Escolher o metodo de calculo:" << endl;
	cout << "[0]Exit" << endl << "[1]Bissecao" << endl << "[2]Corda" << endl << "[3]Newton" << endl;
	cin >> metodo;
	} while (cin.fail() || metodo < 0 || metodo > 3);

	switch (metodo){
	case 0:
	cout << "O programa vai sair" << endl;
	//Sleep(1000);
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
	cout << "O programa vai sair" << endl;
	//Sleep(1000);
	return 0;
	}
	else if (exit == 's'){
	main();
	}
	return metodo;
	}*/

int main() {
	bissec();
}
long double f(long double x) {
	return pow(x, 6) - x - cos(0.2*x + 1);
}

void bissec(){
	long double a = GUESSA;
	long double b = GUESSB;
	long double fa = f(a);
	long double fb = f(b);

	long double x = (a + b) / 2;
	long double fx = f(x);
	long double xanterior;

	long double erro = 1;

	int i = 1;

	while (erro > EPSILON){
		cout << "n: " << i << " a: " << a << " b: " << b << " x: " << x << " f(a)= " << fa << " f(b)= " << fb << " f(x)= " << fx << " erro: " << erro << endl;
		fa = f(a);
		fb = f(b);

		xanterior = x;

		x = (a + b) / 2;
		fx = f(x);

		erro = abs((x - xanterior) / x);
		i++;
	}
}


void corda(){
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
		cout << "n: " << i << " a: " << a << " b: " << b << " xn: " << xn << " f(a)= " << fa << " f(b)= " << fb << " f(xn)= " << fxn << endl;

		if ((fa / fxn) > 0){
			a = xn;
		}
		else {
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

long double dfunc(long double x){
	return x;
}

long double media(long double a, long double b){
	return (a + b) / 2;
}
