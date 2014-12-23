#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip> 

#define H 		0.1667
#define T_INICIAL 	0
#define T_FINAL 	60*24*3
#define MI_INICIAL	5

#define MP_INICIAL  0

#define EPSILON		0.0001 //Usado para erros na conversao de decimal para binario


#define TMAX 	120
#define KET		0.093
#define KA      0.093

using namespace std;

long double euler(long double passo);
void quocienteConvergencia(int n);

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
		quocienteConvergencia(1);
		break;
	}
	case '2':{
		quocienteConvergencia(2);
		break;
	}
	case '3':{
		quocienteConvergencia(3);
		break;
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
long double D(int t){

	if (t < 1 / 6)
		return 120 * t;
	if (t > 1 / 6 && t < 1 / 2)
		return 30 - 60 * t;
	return 0;
}

long double f1(long double t, long double mi){

	return D(t) - KA*mi;
}

long double f2(long double mi, long double mp){

	return KA*mi - KET*mp;
}

long double euler(long double h){

	long double t = T_INICIAL;
	long double mi = MI_INICIAL;

	long double mp = MP_INICIAL;

	cout << "Passo: " << h << endl << endl;

	while (t < (T_FINAL + EPSILON)) {

		mi = mi + h * f1(t, mi);
		t = t + h;
		mp = mp + h * f2(mi, mp);

		cout << "t: " << t << " mi: " << mi << " mp: " << mp << endl;

	}

	return mi;
}


long double eulerModificado(long double passo) {

	long double t = T_INICIAL - passo;
	long double mi = MI_INICIAL;
	long double mi_n = f1(T_INICIAL, MI_INICIAL);
	mi = MI_INICIAL - (passo * mi_n);
	long double mi_anterior = mi;
	long double pn;

	long double mp=MP_INICIAL;

	cout << endl << "MÉTODO DE EULER MELHORADO" << endl;
	cout << "Passo: " << passo << endl << endl;

	for (int i = 0; t < (T_FINAL + EPSILON); i++, t += passo) {
		cout << "n: " << i << " x: " << t << " mi: " << mi << " mp: " << mp << endl;
		if (t >= (T_INICIAL - passo + EPSILON)) {
			mi_n = f1(t, mi);
			pn = f1(t + passo, mi_anterior + 2 * passo * mi_n);
			mi_anterior = mi;
			mi = mi + passo * ((pn + mi_n) / 2);
			mp = mp + passo * f2(mi, mp);
		}
		else
			mi = MI_INICIAL;
	}

	return mi;
}

long double rungeKutta4(long double h) {
	int i = 1;
	long double t = T_INICIAL;
	long double mi = MI_INICIAL;
	long double mp = MP_INICIAL;

	long double dmi1 = 0;
	long double dmi2 = 0;
	long double dmi3 = 0;
	long double dmi4 = 0;

	long double dmp1 = 0;
	long double dmp2 = 0;
	long double dmp3 = 0;
	long double dmp4 = 0;

	cout << endl << "MÉTODO DE RUNGE-KUTTA DE 4ª ORDEM" << endl;
	cout << "Passo: " << h << endl << endl;

	while (t <= (T_FINAL + EPSILON)) {

		dmi1 = h * f1(t, mi);
		dmi2 = h * f1(t + h / 2, mi + dmi1 / 2);
		dmi3 = h * f1(t + h / 2, mi + dmi2 / 2);
		dmi4 = h * f1(t + h, mi + dmi3);

		dmp1 = h * f2(mi, mp);
		dmp2 = h * f2(mi + h / 2, mp + dmp1 / 2);
		dmp3 = h * f2(mi + h / 2, mp + dmp2 / 2);
		dmp4 = h * f2(mi + h, mp + dmp3);

		cout << "n: " << i << " t: " << t << " mi: " << mi << " mp: " << mp << endl;
		cout << " dmi1: " << dmi1 << " dmi2: " << dmi2 << " dmi3: " << dmi3 << " dmi4: " << dmi4 << endl;
		cout << " dmp1: " << dmp1 << " dmp2: " << dmp2 << " dmp3: " << dmp3 << " dmp4: " << dmp4 << endl;

		mi = mi + dmi1 / 6 + dmi2 / 3 + dmi3 / 3 + dmi4 / 6;
		mp = mp + dmp1 / 6 + dmp2 / 3 + dmp3 / 3 + dmp4 / 6;
		t = t + h;

		i++;
	}

	return mi;
}

void quocienteConvergencia(int n) {
	long double y1;
	long double y2;
	long double y3;

	if (n == 1) {
		y1 = euler(H);
		y2 = euler(H / 2);
		y3 = euler(H / 4);
	}

	if (n == 2) {
		y1 = eulerModificado(H);
		y2 = eulerModificado(H / 2);
		y3 = eulerModificado(H / 4);
	}

	if (n == 3) {
		y1 = rungeKutta4(H);
		y2 = rungeKutta4(H / 2);
		y3 = rungeKutta4(H / 4);
	}

	cout << "Erro: " << abs(y3 - y2) << endl;
}
