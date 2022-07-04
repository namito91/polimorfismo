// Fig. 13.21: EmpleadoBaseMasComision.h
// Clase EmpleadoBaseMasComision derivada de Empleado.
#ifndef BASEMAS_H
#define BASEMAS_H
#include "EmpleadoPorComision.h" // definición de la clase EmpleadoPorComision
class EmpleadoBaseMasComision : public EmpleadoPorComision
{
public:
EmpleadoBaseMasComision( const string &, const string &,
const string &, double = 0.0, double = 0.0, double = 0.0 );
void setSalarioBase( double ); // establece el salario base
double getSalarioBase() const; // devuelve el salario base
// la palabra clave virtual indica el intento de sobrescribir
virtual double ingresos() const; // calcula los ingresos
virtual void imprimir() const; // imprime el objeto EmpleadoBaseMasComision
virtual void bonificacion();
private:
double salarioBase; // salario base por semana
}; // fin de la clase EmpleadoBaseMasComision
#endif // BASEMAS_H
