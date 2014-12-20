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
void quocienteConvergencia(int n);
long double eulerModificado(long double passo);
long double rungeKutta4(long double passo);

int main() {

	cout << "Metodo: " << endl << endl;
	cout << "1. Euler" << endl;
	cout << "2. Euler melhorado" << endl;
	cout << "3. Runge Kutta" << endl;
	cout << "4. Sair" << endl;

	int opt;
	cin >> opt;

	switch (opt) {
	case 1: {
		quocienteConvergencia(opt);
		break;
	}
	case 2: {
		quocienteConvergencia(opt);
	}
	case 3: {
		quocienteConvergencia(opt);
	}
	case 4: {
		return 0;
	}
	default: {
		main();
		break;
	}
	}
}

long double D(long double x, long double y) {

	return (y / x) + exp(-x);
}

long double euler(long double passo) {
	//Xn+1 = Xn + h
	//Yn+1 = Yn + h * f(xn,yn)

	long double x = XINICIAL;
	long double y = YINICIAL;
	int i = 1;

	cout << endl << "MÉTODO DE EULER" << endl;
	cout << "Passo: " << passo << endl << endl;

	while (x <= (XFINAL + EPSILON)) {
		cout << "n: " << i << " x: " << x << " y: " << y << endl;
		y = y + passo * D(x, y);
		x = x + passo;
		i++;
	}

	return y;
}

void quocienteConvergencia(int n) {
	long double y1;
	long double y2;
	long double y3;

	if (n == 1) {
		y1 = euler(PASSO);
		y2 = euler(PASSO / 2);
		y3 = euler(PASSO / 4);
	}

	if (n == 2) {
		y1 = eulerModificado(PASSO);
		y2 = eulerModificado(PASSO / 2);
		y3 = eulerModificado(PASSO / 4);
	}

	if (n == 3) {
		y1 = rungeKutta4(PASSO);
		y2 = rungeKutta4(PASSO / 2);
		y3 = rungeKutta4(PASSO / 4);
	}
	cout << endl << "Quociente de convergência: " << (y2 - y1) / (y3 - y2)
			<< endl << "Erro: " << abs(y3 - y2);
}

long double eulerModificado(long double passo) {

	long double x = XINICIAL - passo;
	long double y = YINICIAL;
	long double yn = D(XINICIAL, y);
	y = YINICIAL - (passo * yn);
	long double yanterior = y;
	long double pn;

	cout << endl << "MÉTODO DE EULER MELHORADO" << endl;
	cout << "Passo: " << passo << endl << endl;

	for (int i = 0; x < (XFINAL + EPSILON); i++, x += passo) {
		cout << "n: " << i << " x: " << x << " y: " << y << endl;
		if (x >= (XINICIAL - passo + EPSILON)) {
			yn = D(x, y);
			pn = D(x + passo, yanterior + 2 * passo * yn);
			yanterior = y;
			y = y + passo * ((pn + yn) / 2);
			//cout << "Loopa aqui" << endl;
		} else
			y = YINICIAL;
	}

	return y;
}

long double rungeKutta4(long double passo) {
	int i = 1;
	long double x = XINICIAL;
	long double y = YINICIAL;
	long double d1 = 0;
	long double d2 = 0;
	long double d3 = 0;
	long double d4 = 0;

	cout << endl << "MÉTODO DE RUNGE-KUTTA DE 4ª ORDEM" << endl;
	cout << "Passo: " << passo << endl << endl;

	while (x <= (XFINAL + EPSILON)) {
		d1 = passo * D(x, y);
		d2 = passo * D(x + passo / 2, y + d1 / 2);
		d3 = passo * D(x + passo / 2, y + d2 / 2);
		d4 = passo * D(x + passo, y + d3);
		cout << "n: " << i << " x: " << x << " y: " << y << " d1: " << d1
				<< " d2: " << d2 << " d3: " << d3 << " d4: " << d4 << endl;
		x = x + passo;
		y = y + d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		i++;
	}

	return y;
}
