// Fig. 11.12: Fecha.h
// Definición de la clase Fecha con operadores de incremento sobrecargados.
#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using std::ostream;
class Fecha
{

friend ostream &operator<<( ostream &, const Fecha & );

public:
Fecha( int m = 1, int d = 1, int a = 1900 ); // constructor predeterminado
void setFecha( int, int, int ); // establece mes, día, año
Fecha &operator++(); // operador preincremento
Fecha operator++( int ); // operador postincremento
const Fecha &operator+=( int ); // suma días, modifica el objeto
bool anioBisiesto( int ) const; // ¿está la fecha en un año bisiesto?
bool finDeMes( int , int ) const; // ¿está la fecha en el fin del mes?
int getDia();
int getMes();
bool compararFechas(Fecha);


private:
int mes;
int dia;
int anio;
static const int dias[ ]; // arreglo de días por mes
void ayudaIncremento(); // función utilitaria para incrementar la fecha
}; // fin de la clase Fecha
#endif
