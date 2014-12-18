#include <iostream> //cout
#include <cmath> //contas
#include <Windows.h>

using namespace std;

#define TMAX 	7200
#define KET		0.093

long double funcao(long double x);
void bissec();
void corda();
long double banana(long double x);
long double media(long double a, long double b);

int main(){

	int metodo = -1;

	do{
		system("CLS");
		cout << "Funcao: x^6-x-cos(0.2x+1)" << endl;
		cout << "Escolher o metodo de calculo:" << endl;
		cout << "[0]Exit" << endl << "[1]Bissecao" << endl << "[2]METHOD2" << endl << "[3]METHOD3" << endl;
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
		Sleep(1000);
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
			Sleep(1000);
			return 0;
		}
		else if (exit == 's'){
			main();
		}
	} while (exit != 's' && exit != 'n');

	int gelado = 0;
	return gelado;
}

long double funcao(long double x) {
	return x*exp(-7200 * x) - 0.053*exp(-669.6);
}

void bissec(){
	long double a, b, x, fa, fb, fx, e = 1;

	cout << "Guess a: ";
	cin >> a;
	cout << "Guess b: ";
	cin >> b;

	while (e >= 0.0000001){
		x = (a + b) / 2;
		fa = banana(a);
		fb = banana(b);
		fx = banana(x);

		cout << a << " | " << b << " | " << x << " | " << fa << " | " << fb << " | " << fx << " | " << e << endl;

		if (fa*fx < 0)
			a = x;
		if (fb*fx > 0)
			b = x;

		e = abs((media(a, b) - x) / media(a, b));
	}
}

void corda(){

}

long double banana(long double x){
	return x - log(x) - 10;
}

long double media(long double a, long double b){
	return (a + b) / 2;
}