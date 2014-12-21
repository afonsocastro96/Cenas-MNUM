#include <iostream> //cout
#include <cmath> //contas

using namespace std;

#define TMAX 	7200
#define KET		0.093

#define GUESSA	0
#define GUESSB	1.5
#define EPSILON 0.00001

long double funcao(long double x);
void bissec();
void corda();
long double banana(long double x);
long double media(long double a, long double b);

/*int main(){

	int metodo = -1;

	do{
		//system("CLS");
		cout << "Funcao: x^6-x-cos(0.2x+1)" << endl;
		cout << "Escolher o metodo de calculo:" << endl;
		cout << "[0]Exit" << endl << "[1]Bissecao" << endl << "[2]METHOD2" << endl << "[3]METHOD3" << endl;
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
		break;
	case 3:
		//METHOD3
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
	else do{
		cout << endl << endl << "VOLTAR AO MENU? (s/n)";
		cin >> exit;
		if (exit == 'n'){
			cout << "O programa vai sair" << endl;
			//Sleep(1000);
			return 0;
		}
		else if (exit == 's'){
			main();
		}
	} while (exit != 's' && exit != 'n');

	int gelado = 0;
	return gelado;
}*/

int main() {
	bissec();
}
long double f(long double x) {
	return pow(x,6)-x-cos(0.2*x+1);
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

	while (i < 100){
		cout << "n: " << i << " a: " << a << " b: " << b << " x: " << x << " f(a)= " << fa << " f(b)= " << fb << " f(x)= " << fx << endl;

		if (fa*fx < 0)
			a = x;
		else
			b = x;

		fa = f(a);
		fb = f(b);

		xanterior = x;

		x = (a+b) / 2;
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

	long double xn = (a * f(b) - b * f(a)) / (fb-fa);
	long double fxn = f(xn);

	long double xnanterior;
	long double erro = 1;
	int i = 1;

	while(erro > EPSILON) {
		cout << "n: " << i << " a: " << a << " b: " << b << " xn: " << xn << " f(a)= " << fa << " f(b)= " << fb << " f(xn)= " << fxn << endl;

		if((fa / fxn) > 0){
			a = xn;
		}
		else {
			b = xn;
		}

		fa = f(a);
		fb = f(b);

		xnanterior = xn;

		xn = (a * f(b) - b * f(a)) / (fb-fa);
		fxn = f(xn);


		erro = abs((xn - xnanterior)/xn);
		i++;
	}
}

long double banana(long double x){
	return x - log(x) - 10;
}

long double media(long double a, long double b){
	return (a + b) / 2;
}
