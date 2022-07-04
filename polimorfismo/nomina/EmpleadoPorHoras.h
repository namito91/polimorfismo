// Fig. 13.17: EmpleadoPorHoras.h
// Definición de la clase EmpleadoPorHoras.
#ifndef PORHORAS_H
#define PORHORAS_H
#include "Empleado.h" // definición de la clase Empleado
class EmpleadoPorHoras : public Empleado
{
public:
EmpleadoPorHoras( const string &, const string &,
const string &, double = 0.0, double = 0.0 );
void setSueldo( double ); // establece el sueldo por hora
double getSueldo() const; // devuelve el sueldo por hora
void setHoras( double ); // establece las horas trabajadas
double getHoras() const; // devuelve las horas trabajadas
// la palabra clave virtual indica el intento de sobrescribir
virtual double ingresos() const; // calcula los ingresos
virtual void imprimir() const; // imprime el objeto EmpleadoPorHoras
virtual void bonificacion();
private:
double sueldo; // sueldo por hora
double horas; // horas trabajadas por semana
}; // fin de la clase EmpleadoPorHoras
#endif // PORHORAS_H
