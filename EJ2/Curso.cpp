#include "Curso.h"
#include <iostream>
#include <limits>
#include <algorithm>

Curso::Curso(std::string nombre) : nombreCurso(nombre) {}

Curso::Curso(const Curso& otro)
    : nombreCurso(otro.nombreCurso + " (copia)"), estudiantes(otro.estudiantes) {}

Curso::~Curso() {
    for (auto est : estudiantes) {
        delete est;
    }
}

std::string Curso::getNombre() const { return nombreCurso; }

bool Curso::estaCompleto() const {
    return estudiantes.size() >= capacidadMaxima;
}

bool Curso::estaInscripto(int legajo) const {
    for (auto est : estudiantes)
        if (est->getLegajo() == legajo)
            return true;
    return false;
}

void Curso::inscribirEstudiante(std::vector<Curso*>& todosLosCursos) {
    if (estaCompleto()) {
        std::cout << "El curso está completo.\n";
        return;
    }

    std::string nombre;
    int legajo;

    std::cout << "Ingrese nombre completo del estudiante: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese legajo del estudiante: ";
    while (!(std::cin >> legajo)) {
        std::cout << "Entrada inválida. Ingrese un número entero para el legajo: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    for (auto curso : todosLosCursos) {
        if (curso->estaInscripto(legajo)) {
            std::cout << "Ya existe un estudiante con ese legajo en otro curso.\n";
            return;
        }
    }

    Estudiante* nuevo = new Estudiante(nombre, legajo);

    float nota;
    std::cout << "Ingrese la nota del estudiante para el curso \"" << nombreCurso << "\": ";
    while (!(std::cin >> nota) || nota < 0 || nota > 10) {
        std::cout << "Nota inválida. Ingrese un número entre 0 y 10: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    nuevo->agregarCurso(nombreCurso, nota);
    estudiantes.push_back(nuevo);
    std::cout << "Estudiante inscripto.\n";
}

void Curso::desinscribirEstudiante() {
    int legajo;
    std::cout << "Ingrese legajo a eliminar: ";
    while (!(std::cin >> legajo)) {
        std::cout << "Entrada inválida. Ingrese un número válido: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if ((*it)->getLegajo() == legajo) {
            delete *it;
            estudiantes.erase(it);
            std::cout << "Estudiante eliminado.\n";
            return;
        }
    }
    std::cout << "Estudiante no encontrado.\n";
}

void Curso::buscarEstudiante() const {
    int legajo;
    std::cout << "Ingrese legajo a buscar: ";
    while (!(std::cin >> legajo)) {
        std::cout << "Entrada inválida. Ingrese un número válido: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();
    for (auto est : estudiantes) {
        if (est->getLegajo() == legajo) {
            std::cout << *est << std::endl;
            return;
        }
    }
    std::cout << "No se encontró el estudiante.\n";
}

void Curso::listarEstudiantes() const {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes inscriptos.\n";
        return;
    }
    std::vector<Estudiante*> copia = estudiantes;
    std::sort(copia.begin(), copia.end(), [](Estudiante* a, Estudiante* b) {
        return *a < *b;
    });
    for (auto est : copia) {
        std::cout << *est << std::endl;
    }
}

Curso* buscarCurso(std::vector<Curso*>& cursos, const std::string& nombre) {
    for (auto c : cursos) {
        if (c->getNombre() == nombre)
            return c;
    }
    return nullptr;
}