#ifndef NUMERO_H
#define NUMERO_H

#include <string>

class Numero {
public:
    virtual Numero* suma(const Numero& otro) = 0;
    virtual Numero* resta(const Numero& otro) = 0;
    virtual Numero* multiplicacion(const Numero& otro) = 0;
    virtual std::string toString() const = 0;
    virtual ~Numero() {}
};

class Entero : public Numero {
    private:
        int valor;
    public:
        Entero(int valor);
        Numero* suma(const Numero& otro) override;
        Numero* resta(const Numero& otro) override;
        Numero* multiplicacion(const Numero& otro) override;
        std::string toString() const override;
};

class Real : public Numero {
    private:
        double valor;
    public:
        Real(double valor);
        Numero* suma(const Numero& otro) override;
        Numero* resta(const Numero& otro) override;
        Numero* multiplicacion(const Numero& otro) override;
        std::string toString() const override;
};

class Complejo : public Numero {
    private:
        double real;
        double imaginario;
    public:
        Complejo(double real, double imaginario);
        Numero* suma(const Numero& otro) override;
        Numero* resta(const Numero& otro) override;
        Numero* multiplicacion(const Numero& otro) override;
        std::string toString() const override;
};

#endif
