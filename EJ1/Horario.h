#ifndef HORARIO_H
#define HORARIO_H

#include <string>
using namespace std;

class Horario {
private:
    int hora, minuto, segundo;
    string periodo;
    void setHorario(int h, int m, int s, string p);

public:
    Horario();
    Horario(int h);
    Horario(int h, int m);
    Horario(int h, int m, int s);
    Horario(int h, int m, int s, string p);

    void setHora(int h);
    void setMinuto(int m);
    void setSegundo(int s);
    void setPeriodo(string p);

    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;
    string getPeriodo() const;

    void mostrar() const;
    void mostrarFormato24() const;
};

#endif