#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int filas = 10;
const int columnas = 20;

int jugador1, jugador2;
int meta1, meta2;
char opcion;


int obstaculo1, obstaculo2;
int obstaculo3, obstaculo4;
int obstaculo5, obstaculo6;
int obstaculo7, obstaculo8;

bool esObstaculo(int i, int j) {
    return ( (i == obstaculo1 && j == obstaculo2) ||
             (i == obstaculo3 && j == obstaculo4) ||
             (i == obstaculo5 && j == obstaculo6) ||
             (i == obstaculo7 && j == obstaculo8) );
}

void generarObstaculos() {
    
    obstaculo1 = rand() % (filas - 2) + 1;
    obstaculo2 = rand() % (columnas - 2) + 1;

    obstaculo3 = rand() % (filas - 2) + 1;
    obstaculo4 = rand() % (columnas - 2) + 1;

    obstaculo5 = rand() % (filas - 2) + 1;
    obstaculo6 = rand() % (columnas - 2) + 1;

    obstaculo7 = rand() % (filas - 2) + 1;
    obstaculo8 = rand() % (columnas - 2) + 1;

   
    if ((obstaculo1 == jugador1 && obstaculo2 == jugador2) || (obstaculo1 == meta1 && obstaculo2 == meta2)) generarObstaculos();
    if ((obstaculo3 == jugador1 && obstaculo4 == jugador2) || (obstaculo3 == meta1 && obstaculo4 == meta2)) generarObstaculos();
    if ((obstaculo5 == jugador1 && obstaculo6 == jugador2) || (obstaculo5== meta1 && obstaculo6 == meta2)) generarObstaculos();
    if ((obstaculo7 == jugador1 && obstaculo8 == jugador2) || (obstaculo7 == meta1 && obstaculo8 == meta2)) generarObstaculos();
}

void mostrarlaberinto() {
    system("cls");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1) {
                cout << "#"; 
            } else if (i == jugador1 && j == jugador2) {
                cout << "p"; 
            } else if (i == meta1 && j == meta2) {
                cout << "m"; 
            } else if (esObstaculo(i,j)) {
                cout << "#"; 
            } else {
                cout << " "; 
            }
        }
        cout << endl;
    }
}

bool moverjugador(char direccion) {
    int nuevo1 = jugador1;
    int nuevo2 = jugador2;

    if (direccion == 'w') nuevo1--;
    else if (direccion == 's') nuevo1++;
    else if (direccion == 'a') nuevo2--;
    else if (direccion == 'd') nuevo2++;

    
    if (nuevo1 <= 0 || nuevo1 >= filas - 1 || nuevo2 <= 0 || nuevo2 >= columnas - 1) {
        cout << "Has perdido. Chocaste con un borde" << endl;
        return false;
    }

    
    if (esObstaculo(nuevo1, nuevo2)) {
        cout << "Has perdido. Chocaste con un obstaculo" << endl;
        return false;
    }

    
    if (nuevo1 == meta1 && nuevo2 == meta2) {
        cout << "Has ganado. Llegaste a la meta" << endl;
        return false;
    }

    jugador1 = nuevo1;
    jugador2 = nuevo2;
    return true;
}

int main() {
    srand(time(0)); 

    do {
        jugador1 = 1;
        jugador2 = 1;
        meta1 = filas - 2;
        meta2 = columnas - 2;

        generarObstaculos(); 

        bool jugando = true;
        while (jugando) {
            mostrarlaberinto();
            char tecla = _getch();
            jugando = moverjugador(tecla);
        }

        cout << "Deseas jugar de nuevo? (ingresa c para continuar,  sino cualquier otra para salir): ";
        cin >> opcion;

    } while (opcion == 'c' || opcion == 'C');

    return 0;
}
