// Fig. 13.15: EmpleadoAsalariado.h
// Clase EmpleadoAsalariado derivada de Empleado.
#ifndef ASALARIADO_H
#define ASALARIADO_H
#include "Empleado.h" // definición de la clase Empleado

class EmpleadoAsalariado : public Empleado
{
public:
EmpleadoAsalariado( const string &, const string &,
const string &, double = 0.0 );
void setSalarioSemanal( double ); // establece el salario semanal
double getSalarioSemanal() const; // devuelve el salario semanal
// la palabra clave virtual indica el intento de sobrescribir
virtual double ingresos() const; // calcula los ingresos
virtual void imprimir() const; // imprime el objeto EmpleadoAsalariado
virtual void bonificacion();
private:
double salarioSemanal; // salario por semana
}; // fin de la clase EmpleadoAsalariado
#endif // ASALARIADO_H
