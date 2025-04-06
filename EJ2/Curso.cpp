#include "Curso.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include "EstudiantesGlobal.h"

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

    // Buscar si el estudiante ya existe en la lista global
    Estudiante* estudianteExistente = nullptr;
    for (auto est : estudiantesGlobal) {
        if (est->getLegajo() == legajo && est->getNombre() == nombre) {
            estudianteExistente = est;
            break;
        }
    }

    // Si no existe, crear uno nuevo y añadirlo a la lista global
    if (!estudianteExistente) {
        estudianteExistente = new Estudiante(nombre, legajo);
        estudiantesGlobal.push_back(estudianteExistente);  
    }

    // Agregar el curso y la nota al estudiante existente
    float nota;
    std::cout << "Ingrese la nota del estudiante para el curso \"" << nombreCurso << "\": ";
    while (!(std::cin >> nota) || nota < 0 || nota > 10) {
        std::cout << "Nota inválida. Ingrese un número entre 0 y 10: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    estudianteExistente->agregarCurso(nombreCurso, nota);
    estudiantes.push_back(estudianteExistente); 
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
            Estudiante* est = *it;

            // 1. Eliminar del curso actual
            estudiantes.erase(it);

            // 2. Eliminar el curso actual del vector cursosYNotas del estudiante
            for (auto itCurso = est->cursosYNotas.begin(); itCurso != est->cursosYNotas.end(); ++itCurso) {
                if (itCurso->first == nombreCurso) {
                    est->cursosYNotas.erase(itCurso);
                    break;
                }
            }

            std::cout << "Estudiante desinscripto del curso.\n";
            return;
        }
    }

    std::cout << "Estudiante no encontrado en este curso.\n";
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