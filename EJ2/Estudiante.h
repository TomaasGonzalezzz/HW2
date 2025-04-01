#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Estudiante {
private:
    std::string nombreCompleto;
    int legajo;
    std::vector<std::pair<std::string, float>> cursosYNotas;

public:
    Estudiante(std::string nombre, int legajo_);

    void agregarCurso(std::string nombreCurso, float nota);
    float calcularPromedio() const;

    std::string getNombre() const;
    int getLegajo() const;

    bool operator<(const Estudiante& otro) const;

    friend std::ostream& operator<<(std::ostream& os, const Estudiante& est);
};

#endif