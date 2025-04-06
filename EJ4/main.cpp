#include <iostream>
#include "cuentas.hpp"

using namespace std;

int main() {
    string nombre;
    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);

    CajaDeAhorro caja(nombre, 0);
    CuentaCorriente corriente(nombre, 0, &caja);

    int opcion;
    do {
        cout << "\n1. Depositar en Caja de Ahorro\n"
             << "2. Depositar en Cuenta Corriente\n"
             << "3. Retirar de Caja de Ahorro\n"
             << "4. Retirar de Cuenta Corriente\n"
             << "5. Mostrar Caja de Ahorro\n"
             << "6. Mostrar Cuenta Corriente\n"
             << "0. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        double monto;
        switch(opcion) {
            case 1:
                cout << "Monto a depositar en Caja de Ahorro: ";
                cin >> monto;
                caja.depositar(monto);
                break;
            case 2:
                cout << "Monto a depositar en Cuenta Corriente: ";
                cin >> monto;
                corriente.depositar(monto);
                break;
            case 3:
                cout << "Monto a retirar de Caja de Ahorro: ";
                cin >> monto;
                caja.retirar(monto);
                break;
            case 4:
                cout << "Monto a retirar de Cuenta Corriente: ";
                cin >> monto;
                corriente.retirar(monto);
                break;
            case 5:
                caja.mostrarInfo();
                break;
            case 6:
                corriente.mostrarInfo();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}
