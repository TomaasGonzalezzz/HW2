#include "Horario.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Horario::setHorario(int h, int m, int s, string p) {
    if (h < 0 || h > 12 || m < 0 || m > 59 || s < 0 || s > 59 || (p != "a.m." && p != "p.m.")) {
        cout << "Error: valores fuera de rango." << endl;
        return;
    }
    hora = h;
    minuto = m;
    segundo = s;
    periodo = p;
}

Horario::Horario() {
    setHorario(0, 0, 0, "a.m.");
}

Horario::Horario(int h) {
    setHorario(h, 0, 0, "a.m.");
}

Horario::Horario(int h, int m) {
    setHorario(h, m, 0, "a.m.");
}

Horario::Horario(int h, int m, int s) {
    setHorario(h, m, s, "a.m.");
}

Horario::Horario(int h, int m, int s, string p) {
    setHorario(h, m, s, p);
}

void Horario::setHora(int h) {
    if (h >= 0 && h <= 12) hora = h;
    else cout << "Hora inválida." << endl;
}

void Horario::setMinuto(int m) {
    if (m >= 0 && m <= 59) minuto = m;
    else cout << "Minuto inválido." << endl;
}

void Horario::setSegundo(int s) {
    if (s >= 0 && s <= 59) segundo = s;
    else cout << "Segundo inválido." << endl;
}

void Horario::setPeriodo(string p) {
    if (p == "a.m." || p == "p.m.") periodo = p;
    else cout << "Periodo inválido." << endl;
}

int Horario::getHora() const { return hora; }
int Horario::getMinuto() const { return minuto; }
int Horario::getSegundo() const { return segundo; }
string Horario::getPeriodo() const { return periodo; }

void Horario::mostrar() const {
    cout << setfill('0') << setw(2) << hora << "h, "
         << setw(2) << minuto << "m, "
         << setw(2) << segundo << "s "
         << periodo << endl;
}

void Horario::mostrarFormato24() const {
    int h24 = hora;
    if (periodo == "p.m." && hora != 12) h24 += 12;
    if (periodo == "a.m." && hora == 12) h24 = 0;

    cout << setfill('0') << setw(2) << h24 << ":"
         << setw(2) << minuto << ":"
         << setw(2) << segundo << endl;
}