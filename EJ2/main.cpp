#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Estudiante {
private:
    string nombreCompleto;
    int legajo;
    vector<pair<string, float>> cursosYNotas;

public:
    Estudiante(string nombre, int legajo_) : nombreCompleto(nombre), legajo(legajo_) {}

    void agregarCurso(string nombreCurso, float nota) {
        cursosYNotas.push_back({nombreCurso, nota});
    }

    float calcularPromedio() const {
        if (cursosYNotas.empty()) return 0.0f;
        float suma = 0;
        for (auto& c : cursosYNotas)
            suma += c.second;
        return suma / cursosYNotas.size();
    }

    string getNombre() const { return nombreCompleto; }
    int getLegajo() const { return legajo; }

    // Para ordenar alfabéticamente
    bool operator<(const Estudiante& otro) const {
        return nombreCompleto < otro.nombreCompleto;
    }

    // Para imprimir por pantalla
    friend ostream& operator<<(ostream& os, const Estudiante& est) {
        os << "Nombre: " << est.nombreCompleto
           << ", Legajo: " << est.legajo
           << ", Promedio: " << fixed << setprecision(2) << est.calcularPromedio();
        return os;
    }
};

class Curso {
private:
    vector<Estudiante*> estudiantes;
    static const int capacidadMaxima = 20;

public:
    ~Curso() {
        // Liberar memoria
        for (auto est : estudiantes) {
            delete est;
        }
    }

    bool estaCompleto() const {
        return estudiantes.size() >= capacidadMaxima;
    }

    void inscribirEstudiante() {
        if (estaCompleto()) {
            cout << "El curso está completo. No se puede inscribir más estudiantes." << endl;
            return;
        }

        string nombre;
        int legajo;
        cout << "Ingrese nombre completo: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese legajo: ";
        cin >> legajo;

        if (estaInscripto(legajo)) {
            cout << "Ya hay un estudiante con ese legajo." << endl;
            return;
        }

        Estudiante* nuevo = new Estudiante(nombre, legajo);

        int cantCursos;
        cout << "¿Cuántos cursos desea cargar? ";
        cin >> cantCursos;
        for (int i = 0; i < cantCursos; ++i) {
            string curso;
            float nota;
            cout << "Curso " << i + 1 << ": ";
            cin.ignore();
            getline(cin, curso);
            cout << "Nota final: ";
            cin >> nota;
            nuevo->agregarCurso(curso, nota);
        }

        estudiantes.push_back(nuevo);
        cout << "Estudiante inscripto correctamente." << endl;
    }

    void desinscribirEstudiante() {
        int legajo;
        cout << "Ingrese legajo del estudiante a eliminar: ";
        cin >> legajo;

        for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
            if ((*it)->getLegajo() == legajo) {
                delete *it;
                estudiantes.erase(it);
                cout << "Estudiante eliminado del curso." << endl;
                return;
            }
        }
        cout << "Estudiante no encontrado." << endl;
    }

    bool estaInscripto(int legajo) const {
        for (auto est : estudiantes)
            if (est->getLegajo() == legajo)
                return true;
        return false;
    }

    void buscarEstudiante() const {
        int legajo;
        cout << "Ingrese legajo a buscar: ";
        cin >> legajo;
        for (auto est : estudiantes) {
            if (est->getLegajo() == legajo) {
                cout << *est << endl;
                return;
            }
        }
        cout << "No se encontró el estudiante." << endl;
    }

    void listarEstudiantes() const {
        if (estudiantes.empty()) {
            cout << "No hay estudiantes inscriptos." << endl;
            return;
        }

        vector<Estudiante*> copia = estudiantes;
        sort(copia.begin(), copia.end(), [](Estudiante* a, Estudiante* b) {
            return *a < *b;
        });

        cout << "--- Lista de estudiantes (orden alfabético) ---" << endl;
        for (auto est : copia) {
            cout << *est << endl;
        }
    }
};

void mostrarMenu() {
    cout << "\n--- MENU ---" << endl;
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Buscar estudiante por legajo" << endl;
    cout << "4. Ver si el curso está completo" << endl;
    cout << "5. Listar estudiantes ordenados alfabéticamente" << endl;
    cout << "0. Salir" << endl;
    cout << "Opción: ";
}

int main() {
    Curso curso;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: curso.inscribirEstudiante(); break;
            case 2: curso.desinscribirEstudiante(); break;
            case 3: curso.buscarEstudiante(); break;
            case 4:
                cout << (curso.estaCompleto() ? "El curso está completo." : "Aún hay cupos disponibles.") << endl;
                break;
            case 5: curso.listarEstudiantes(); break;
            case 0: cout << "Fin del programa." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
