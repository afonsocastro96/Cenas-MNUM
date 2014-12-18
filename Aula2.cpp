#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	int cd; // No de casas decimais
	long double initial = exp(1); // Valor inicial do investimento

	cout << "Insira o numero de C.D: "; cin >> cd;
	cout << endl << endl;
	cout << " Ano        Valor" << endl;

	for (size_t i=1;i <= 25; i++)
	{
		if (i < 10)
		cout << setprecision(cd) << " " << i << "  " << initial << endl;
		else cout << setprecision(cd) << " " << i << " " << initial << endl;
		initial = initial * i - 1;
	}

	return 0;
}
