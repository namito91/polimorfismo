// Fig. 13.13: Empleado.h
// Clase base abstracta Empleado.
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string> // clase string estándar de C++
#include "Fecha.h"
using std::string;

class Empleado
{

public:
Empleado( const string &, const string &, const string & );
virtual ~Empleado(){};
void setPrimerNombre( const string & ); // establece el primer nombre
string getPrimerNombre() const; // devuelve el primer nombre
void setApellidoPaterno( const string & ); // establece el apellido paterno
string getApellidoPaterno() const; // devuelve el apellido paterno
void setNumeroSeguroSocial( const string & ); // establece el NSS
void setFechaCumpleanios(int,int,int);
Fecha getFechaNacimiento();
string getNumeroSeguroSocial() const; // devuelve el NSS
virtual void bonificacion() = 0;
// la función virtual pura hace de Empleado una clase base abstracta
virtual double ingresos() const = 0; // virtual pura
virtual void imprimir() const; // virtual

private:
string primerNombre;
string apellidoPaterno;
string numeroSeguroSocial;
Fecha fechaNacimiento;

}; // fin de la clase Empleado
#endif // EMPLEADO_H
