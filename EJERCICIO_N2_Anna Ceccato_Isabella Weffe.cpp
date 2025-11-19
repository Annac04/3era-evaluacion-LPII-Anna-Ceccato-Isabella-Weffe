#include <iostream>
using namespace std;

int main () {
	
	int  filashojas, filastronco;
	char opcion;
	
	do{
		cout << "ingrese el numero de filas para las hojas" << endl;
		cin >> filashojas;
		cout << "ingrese el numero de filas para el tronco" << endl;
		cin >> filastronco;
		
		for (int i = 1; i <= filashojas; i++) {
			for (int j = 1; j <= filashojas - i; j++) {
				cout << " ";
			}
			for (int j = 1; j <= 2 * i - 1; j++) {
				cout << "*";
			}
			cout << endl;
		}
		
		for (int i = 1; i <= filastronco; i++) {
			for (int j = 1; j <= filashojas - 1; j++) {
				cout << " ";
			}
			cout << "*" << endl;
		}
		
		cout << "ingrese la letra i para continuar, sino cualquier otra para salir" << endl;
			cin >> opcion;
	} while (opcion == 'i' || opcion == 'I');
	
	return 0;
}

