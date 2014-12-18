#include <iostream> //cout
#include <cmath> //contas
#include <Windows.h>

using namespace std;

#define TMAX 	7200
#define KET		0.093

long double funcao(long double x);
void bissec();
long double banana();

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
		cout << "O programa vai sair";
		Sleep(1);
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

	int gelado = 0;
	return gelado;
}

long double funcao(long double x) {
	long double y;
	long double temp = -TMAX * x;

	y = exp(temp);
	y = y * x;
	y = y - KET* exp(-TMAX * KET);

	return y;
}

void bissec(){
	long double a, b, x, fa, fb, fx, e;

	cout << "Guess a: ";
	cin >> a;
	cout << "Guess b: ";
	cin >> b;

	x = (a + b) / 2;

	fa = banana(a);
	fb = banana(b);
	fx = banana(x);


}

long double banana(long double x){
	return pow(x, 6) - x - cos(0.2*x + 1);
}