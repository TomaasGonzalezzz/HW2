
#include <iostream>
#include "Numero.h"

int main() {
    Entero e1(5), e2(3);
    Real r1(3.5), r2(2.5);
    Complejo c1(1.0, 2.0), c2(3.0, 4.0);

    // Operaciones con enteros
    std::cout << "Suma de Enteros: " << e1.suma(e2)->toString() << std::endl;

    // Operaciones con reales
    std::cout << "Suma de Reales: " << r1.suma(r2)->toString() << std::endl;

    // Operaciones con complejos
    std::cout << "Suma de Complejos: " << c1.suma(c2)->toString() << std::endl;

    return 0;
}
