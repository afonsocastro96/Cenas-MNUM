#include <iostream>
#include <stdio.h>
#include <cmath>

#define PASSO 		0.1
#define XINICIAL 	1
#define XFINAL 		2
#define YINICIAL	0 //Condicoes iniciais: y(1) = 0

#define EPSILON		0.0001 //Usado para erros na conversao de decimal para binario


#define TMAX 	120//7200
#define KET		0.093
#define KA      100

using namespace std;

long double euler(long double passo);
void quocienteConvergencia();

int main(){

	cout << "Metodo: " << endl << endl;
	cout << "1. Euler" << endl;
	cout << "2. Euler melhorado" << endl;
	cout << "3. Runge Kutta" << endl;
	cout << "4. Sair" << endl;

	char opt;
	cin >> opt;

	switch (opt){
	case '1':{
		quocienteConvergencia();
		break;
	}
	case '2':{

	}
	case '3':{

	}
	case '4':{
		return 0;
	}
	default:{
		main();
		break;
	}
	}
}

long double D(long double x, long double y, long double passo){

	return y + passo * ((y / x) + exp(-x));
}

long double euler(long double passo){
	//Xn+1 = Xn + h
	//Yn+1 = Yn + h * f(xn,yn)

	long double x = XINICIAL;
	long double y = YINICIAL;

	cout << "Passo: " << passo << endl << endl;

	while(x <= (XFINAL+EPSILON)) {
		cout << "x: " << x << " y: " << y << endl;
		y = D(x,y,passo);
		x = x + passo;
	}

	return y;
}

void quocienteConvergencia(){
	long double y1 = euler(PASSO);
	long double y2 = euler(PASSO / 2);
	long double y3 = euler(PASSO / 4);

	cout << endl << "Quociente de convergência: " << (y2 - y1) / (y3 - y2) << endl << "Erro: " << abs(y3-y2);
}
