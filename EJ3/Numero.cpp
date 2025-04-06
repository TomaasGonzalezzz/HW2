
#include "Numero.h"
#include <iostream>
#include <string>

Entero::Entero(int valor) : valor(valor) {};

Numero* Entero::suma(const Numero& otro) {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(this->valor + e.valor);
}

Numero* Entero::resta(const Numero& otro) {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(this->valor - e.valor);
}

Numero* Entero::multiplicacion(const Numero& otro) {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(this->valor * e.valor);
}

std::string Entero::toString() const {
    return std::to_string(valor);
}

Real::Real(double valor) : valor(valor) {};

Numero* Real::suma(const Numero& otro) {
    const Real& e = dynamic_cast<const Real&>(otro);
    return new Real(this->valor + e.valor);
}

Numero* Real::resta(const Numero& otro) {
    const Real& e = dynamic_cast<const Real&>(otro);
    return new Real(this->valor - e.valor);
}

Numero* Real::multiplicacion(const Numero& otro) {
    const Real& e = dynamic_cast<const Real&>(otro);
    return new Real(this->valor * e.valor);
}

std::string Real::toString() const {
    return std::to_string(valor);
}

Complejo::Complejo(double real, double imaginario) : real(real), imaginario(imaginario) {};

Numero* Complejo::suma(const Numero& otro) {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(this->real + c.real, this->imaginario + c.imaginario);
}

Numero* Complejo::resta(const Numero& otro) {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(this->real - c.real, this->imaginario - c.imaginario);
}

Numero* Complejo::multiplicacion(const Numero& otro) {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    double parteReal = this->real * c.real - this->imaginario * c.imaginario;
    double parteImaginaria = this->real * c.imaginario + this->imaginario * c.real;
    return new Complejo(parteReal, parteImaginaria);
}

std::string Complejo::toString() const {
    return std::to_string(real) + " + " + std::to_string(imaginario) + "i";
}