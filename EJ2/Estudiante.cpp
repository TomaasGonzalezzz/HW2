#include "Estudiante.h"

Estudiante::Estudiante(std::string nombre, int legajo_)
    : nombreCompleto(nombre), legajo(legajo_) {}

void Estudiante::agregarCurso(std::string nombreCurso, float nota) {
    cursosYNotas.push_back({nombreCurso, nota});
}

void Estudiante::listarCursos() const {
    if (cursosYNotas.empty()) {
        std::cout << "El estudiante no está inscrito en ningún curso.\n";
        return;
    }

    std::cout << "Cursos de " << nombreCompleto << " (Legajo: " << legajo << "):\n";
    for (const auto& curso : cursosYNotas) {
        std::cout << "Curso: " << curso.first << ", Nota: " << curso.second << std::endl;
    }

    // Mostrar el promedio
    std::cout << "Promedio general: " << calcularPromedio() << std::endl;
}

float Estudiante::calcularPromedio() const {
    if (cursosYNotas.empty()) return 0.0f;
    float suma = 0;
    for (auto& c : cursosYNotas)
        suma += c.second;
    return suma / cursosYNotas.size();
}

std::string Estudiante::getNombre() const { return nombreCompleto; }
int Estudiante::getLegajo() const { return legajo; }

bool Estudiante::operator<(const Estudiante& otro) const {
    return nombreCompleto < otro.nombreCompleto;
}

std::ostream& operator<<(std::ostream& os, const Estudiante& est) {
    os << "Nombre: " << est.nombreCompleto
       << ", Legajo: " << est.legajo
       << ", Promedio: " << std::fixed << std::setprecision(2) << est.calcularPromedio();
    return os;
}