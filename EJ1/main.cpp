#include <iostream>
#include "Horario.h"
using namespace std;

int pedirEntero(string nombre, int min, int max) {
    int valor;
    do {
        cout << nombre << " (" << min << "-" << max << "): ";
        cin >> valor;
        if (valor < min || valor > max)
            cout << "Valor fuera de rango. Intente de nuevo." << endl;
    } while (valor < min || valor > max);
    return valor;
}

string pedirPeriodo() {
    string p;
    do {
        cout << "Ingrese el periodo (a.m. o p.m.): ";
        cin >> p;
        if (p != "a.m." && p != "p.m.")
            cout << "Periodo inválido. Debe ingresar 'a.m.' o 'p.m.'" << endl;
    } while (p != "a.m." && p != "p.m.");
    return p;
}

void modificarHorario(Horario &h) {
    char opcion;
    do {
        cout << "\n¿Desea modificar algún valor?" << endl;
        cout << "(h: hora, m: minuto, s: segundo, p: periodo, n: ninguno): ";
        cin >> opcion;

        switch (opcion) {
            case 'h':
                h.setHora(pedirEntero("Nueva hora", 0, 12));
                h.mostrar();
                break;
            case 'm':
                h.setMinuto(pedirEntero("Nuevo minuto", 0, 59));
                h.mostrar();
                break;
            case 's':
                h.setSegundo(pedirEntero("Nuevo segundo", 0, 59));
                h.mostrar();
                break;
            case 'p':
                h.setPeriodo(pedirPeriodo());
                h.mostrar();
                break;
            case 'n':
                cout << "\nEsta es la hora final:" << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 'n');
}

int main() {
    char seguir = 's';

    while (seguir == 's' || seguir == 'S') {
        cout << "\n--- Crear un nuevo horario ---" << endl;
        cout << "Seleccione el modo de ingreso:" << endl;
        cout << "1) Solo hora" << endl;
        cout << "2) Hora y minutos" << endl;
        cout << "3) Hora, minutos y segundos" << endl;
        cout << "4) Ingreso completo (hora, minuto, segundo, periodo)" << endl;
        cout << "Opción: ";
        int opcion;
        cin >> opcion;

        Horario horario;

        int h, m, s;
        string p;

        switch (opcion) {
            case 1:
                h = pedirEntero("Ingrese la hora", 0, 12);
                horario = Horario(h);
                break;
            case 2:
                h = pedirEntero("Ingrese la hora", 0, 12);
                m = pedirEntero("Ingrese los minutos", 0, 59);
                horario = Horario(h, m);
                break;
            case 3:
                h = pedirEntero("Ingrese la hora", 0, 12);
                m = pedirEntero("Ingrese los minutos", 0, 59);
                s = pedirEntero("Ingrese los segundos", 0, 59);
                horario = Horario(h, m, s);
                break;
            case 4:
                h = pedirEntero("Ingrese la hora", 0, 12);
                m = pedirEntero("Ingrese los minutos", 0, 59);
                s = pedirEntero("Ingrese los segundos", 0, 59);
                p = pedirPeriodo();
                horario = Horario(h, m, s, p);
                break;
            default:
                cout << "Opción inválida. Se creará un horario por defecto." << endl;
                horario = Horario();
        }

        cout << "\nHorario ingresado (formato 12h): ";
        horario.mostrar();

        cout << "Formato 24 horas: ";
        horario.mostrarFormato24();

        modificarHorario(horario);

        horario.mostrar();
        cout << "Formato 24 horas: ";
        horario.mostrarFormato24();

        cout << "\n¿Desea ingresar otro horario? (s/n): ";
        cin >> seguir;
    }

    cout << "\nPrograma finalizado." << endl;
    return 0;
}