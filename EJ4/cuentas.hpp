#ifndef CUENTAS_HPP
#define CUENTAS_HPP

#include <string>

class CuentaBanco {
protected:
    double balance;
    std::string titularCuenta;

public:
    CuentaBanco(std::string titular, double saldoInicial = 0);
    void depositar(double monto);
    double getBalance() const;
    void setBalance(double nuevoBalance);
    virtual void retirar(double monto) = 0;
    virtual void mostrarInfo() = 0;
    virtual ~CuentaBanco() {}
};

class CajaDeAhorro : public CuentaBanco {
private:
    int contadorMostrarInfo;

public:
    CajaDeAhorro(std::string titular, double saldoInicial = 0);
    void retirar(double monto) override;
    void mostrarInfo() override;
};

class CuentaCorriente : public CuentaBanco {
private:
    CajaDeAhorro* cajaAhorro;

public:
    CuentaCorriente(std::string titular, double saldoInicial, CajaDeAhorro* caja);
    void retirar(double monto) override;
    void mostrarInfo() override;
};

#endif
