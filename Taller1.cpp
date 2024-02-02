#include <iostream>
#include "libs/NumberList.h"
#include "libs/NumberMatrix.h"

using namespace std;

void printMenu();

int main() {
    
    printMenu();

    int option = 0;
    NumberList list;
    NumberMatrix matrix;

    do {
        cout << "Ingrese una opción: ";
        cin >> option;

       switch (option)
        {
            case 1:
                cout << "Opción 1" << endl;
                break;
            case 2:
                cout << "Opción 2" << endl;
                break;
            case 3:
                cout << "Opción 3" << endl;
                break;
            case 4:
                cout << "Opción 4" << endl;
                break;
            case 5:
                cout << "Opción 5" << endl;
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        } 

    } while (option != 0);
    
    return 0;
}

void printMenu() {
    cout << "1. Generar números aleatorios" << endl;
    cout << "2. Mostrar números sin repetir" << endl;
    cout << "3. Mostrar números de aparición" << endl;
    cout << "4. Generar matriz con números aleatorios" << endl;
    cout << "5. Mostrar valor mínimo por columna" << endl;
    cout << "0. Salir" << endl;
}
