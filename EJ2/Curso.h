#ifndef CURSO_H
#define CURSO_H

#include <vector>
#include <string>
#include "Estudiante.h"

class Curso {
private:
    std::string nombreCurso;
    std::vector<Estudiante*> estudiantes;
    static const int capacidadMaxima = 20;

public:
    Curso(std::string nombre);
    Curso(const Curso& otro);
    ~Curso();

    std::string getNombre() const;

    bool estaCompleto() const;
    bool estaInscripto(int legajo) const;

    void inscribirEstudiante(std::vector<Curso*>& todosLosCursos);
    void desinscribirEstudiante();
    void buscarEstudiante() const;
    void listarEstudiantes() const;
};

Curso* buscarCurso(std::vector<Curso*>& cursos, const std::string& nombre);

#endif