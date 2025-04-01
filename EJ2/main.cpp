#include <iostream>
#include <limits>
#include "Curso.h"
#include "EstudiantesGlobal.h"

int main() {
    std::vector<Curso*> cursos;
    int opcion;

    do {
        std::cout << "\n--- GESTOR DE CURSOS ---\n";
        std::cout << "1. Crear nuevo curso\n";
        std::cout << "2. Eliminar curso\n";
        std::cout << "3. Listar cursos existentes\n";
        std::cout << "4. Copiar un curso\n";
        std::cout << "5. Agregar estudiante a un curso\n";
        std::cout << "6. Quitar estudiante de un curso\n";
        std::cout << "7. Ver cursos y promedio de un estudiante por legajo\n";
        std::cout << "8. Ver si un curso está completo\n";
        std::cout << "9. Listar estudiantes de un curso\n";
        std::cout << "10. Salir\nOpción: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada inválida. Ingrese un número entre 1 y 10: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore();

        std::string nombre;
        Curso* curso;
        Estudiante* estudianteEncontrado = nullptr;
        
        switch (opcion) {
            case 1:
                std::cout << "Nombre del curso: ";
                std::getline(std::cin, nombre);
                cursos.push_back(new Curso(nombre));
                break;
            case 2:
                std::cout << "Nombre del curso a eliminar: ";
                std::getline(std::cin, nombre);
                for (auto it = cursos.begin(); it != cursos.end(); ++it) {
                    if ((*it)->getNombre() == nombre) {
                        delete *it;
                        cursos.erase(it);
                        std::cout << "Curso eliminado.\n";
                        break;
                    }
                }
                break;
            case 3:
                if (cursos.empty()) std::cout << "No hay cursos creados.\n";
                else for (auto c : cursos) std::cout << c->getNombre() << std::endl;
                break;
            case 4:
                std::cout << "Nombre del curso a copiar: ";
                std::getline(std::cin, nombre);
                curso = buscarCurso(cursos, nombre);
                if (curso) cursos.push_back(new Curso(*curso));
                else std::cout << "Curso no encontrado.\n";
                break;
            case 5:
                std::cout << "Curso destino: ";
                std::getline(std::cin, nombre);
                curso = buscarCurso(cursos, nombre);
                if (curso) curso->inscribirEstudiante(cursos);
                else std::cout << "Curso no encontrado.\n";
                break;
            case 6:
                std::cout << "Curso: ";
                std::getline(std::cin, nombre);
                curso = buscarCurso(cursos, nombre);
                if (curso) curso->desinscribirEstudiante();
                else std::cout << "Curso no encontrado.\n";
                break;
            case 7:
                int legajoBuscar;
                std::cout << "Ingrese el legajo del estudiante para ver sus cursos: ";
                while (!(std::cin >> legajoBuscar)) {
                    std::cout << "Entrada inválida. Ingrese un número entero para el legajo: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(); // Limpiar el buffer
            
                // Buscar al estudiante por legajo
                for (auto est : estudiantesGlobal) {
                    if (est->getLegajo() == legajoBuscar) {
                        estudianteEncontrado = est;
                        break;
                    }
                }
            
                if (estudianteEncontrado) {
                    estudianteEncontrado->listarCursos(); // Mostrar los cursos y el promedio
                } else {
                    std::cout << "Estudiante con legajo " << legajoBuscar << " no encontrado.\n";
                }
                break;
            case 8:
                std::cout << "Curso: ";
                std::getline(std::cin, nombre);
                curso = buscarCurso(cursos, nombre);
                if (curso)
                    std::cout << (curso->estaCompleto() ? "Curso completo.\n" : "Curso con vacantes.\n");
                else std::cout << "Curso no encontrado.\n";
                break;
            case 9:
                std::cout << "Curso: ";
                std::getline(std::cin, nombre);
                curso = buscarCurso(cursos, nombre);
                if (curso) curso->listarEstudiantes();
                else std::cout << "Curso no encontrado.\n";
                break;
            case 10:
                for (auto c : cursos) delete c;
                cursos.clear();
                std::cout << "Programa finalizado.\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 10);

    return 0;
}