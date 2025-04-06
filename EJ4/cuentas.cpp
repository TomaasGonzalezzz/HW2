#include <iostream>
#include "cuentas.hpp"

using namespace std;

CuentaBanco::CuentaBanco(string titular, double saldoInicial)
    : titularCuenta(titular), balance(saldoInicial) {}

void CuentaBanco::depositar(double monto) {
    if (monto > 0) {
        balance += monto;
    }
}

double CuentaBanco::getBalance() const {
    return balance;
}

void CuentaBanco::setBalance(double nuevoBalance) {
    balance = nuevoBalance;
}

CajaDeAhorro::CajaDeAhorro(string titular, double saldoInicial)
    : CuentaBanco(titular, saldoInicial), contadorMostrarInfo(0) {}

void CajaDeAhorro::retirar(double monto) {
    if (monto <= balance) {
        balance -= monto;
        cout << "Retiro exitoso.\n";
    } else {
        cout << "Fondos insuficientes.\n";
    }
}

void CajaDeAhorro::mostrarInfo() {
    contadorMostrarInfo++;
    cout << "Titular: " << titularCuenta << endl;
    cout << "Tipo: Caja de Ahorro\n";
    cout << "Balance: $" << balance << endl;

    if (contadorMostrarInfo > 2) {
        balance -= 20;
        cout << "Se descontaron $20 por exceso de consultas.\n";
    }
}

CuentaCorriente::CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* caja)
    : CuentaBanco(titular, saldoInicial), cajaAhorro(caja) {}

void CuentaCorriente::retirar(double monto) {
    if (monto <= balance) {
        // Si cuenta corriente sola alcanza, se retira directamente
        balance -= monto;
        cout << "Retiro exitoso desde Cuenta Corriente.\n";
    } else {
        double totalDisponible = balance + cajaAhorro->getBalance();
        if (monto > totalDisponible) {
            // Si no alcanza entre ambas cuentas, no se realiza el retiro
            cout << "Fondos insuficientes en ambas cuentas.\n";
        } else {
            // Se usa lo que hay en cuenta corriente y el resto en caja de ahorro
            double restante = monto - balance;
            balance = 0;
            double nuevoSaldoCaja = cajaAhorro->getBalance() - restante;
            cajaAhorro->setBalance(nuevoSaldoCaja);
            cout << "Retiro combinado desde Cuenta Corriente y Caja de Ahorro.\n";
        }
    }
}

void CuentaCorriente::mostrarInfo() {
    cout << "Titular: " << titularCuenta << endl;
    cout << "Tipo: Cuenta Corriente\n";
    cout << "Balance: $" << balance << endl;
}
