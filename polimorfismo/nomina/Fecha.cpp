// Fig. 11.13: Fecha.cpp
// Definiciones de las funciones miembro y funciones friend de la clase Fecha.
#include <iostream>
#include "Fecha.h"

// inicializa miembro estático en alcance de archivo; una copia a nivel de clase
const int Fecha::dias[ ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// constructor de Fecha
Fecha::Fecha( int m, int d, int a )
{
setFecha( m, d, a );
} // fin del constructor de Fecha

// establece mes, día y año
void Fecha::setFecha( int mm, int dd, int aa )
{
mes = ( mm >= 1 && mm <= 12 ) ? mm : 1;
anio = ( aa >= 1900 && aa <= 2100 ) ? aa : 1900;

( dd > 31 || dd < 0 ) ? 1 : dd;

// prueba si es año bisiesto
if ( mes == 2 && anioBisiesto( anio ) )
dia = ( dd >= 1 && dd <= 29 ) ? dd : 1;
else
dia = ( dd >= 1 && dd <= dias[ mes ] ) ? dd : 1;
} // fin de la función setFecha

// operador preincremento sobrecargado
Fecha &Fecha::operator++()
{
ayudaIncremento(); // incrementa la fecha
return *this; // devuelve referencia para crear un lvalue
} // fin de la función operator++

// operador postincremento sobrecargado; observe que el parámetro
// entero de muestra no tiene un nombre de parámetro
Fecha Fecha::operator++( int )
{
Fecha temp = *this; // contiene el estado actual del objeto
ayudaIncremento();
// devuelve objeto temporal almacenado y sin incrementar
return temp; // devuelve un valor; no devuelve una referencia
} // fin de la función operator++

// suma el número especificado de días a la fecha
const Fecha &Fecha::operator+=( int diasAdicionales )
{
for ( int i = 0; i < diasAdicionales; i++ )
ayudaIncremento();
return *this; // permite la asignación en cascada
} // fin de la función operator+=

// si el año es bisiesto, devuelve true; en caso contrario, devuelve false
bool Fecha::anioBisiesto( int anioPrueba ) const
{
if ( anioPrueba % 400 == 0 ||
( anioPrueba % 100 != 0 && anioPrueba % 4 == 0 ) )
return true; // un año bisiesto
else
return false; // no es un año bisiesto
} // fin de la función anioBisiesto


// determina si el día es el último del mes
bool Fecha::finDeMes( int diaPrueba , int anioPrueba ) const
{

if ( anioBisiesto( anioPrueba ) )
return diaPrueba == 29; // último día de Feb. en año bisiesto
else 
    return diaPrueba == dias[ mes ];

} // fin de la función finDeMes


// función para ayudar a incrementar la fecha
void Fecha::ayudaIncremento()
{
// dia no es fin de mes
if ( !finDeMes( dia , anio ) )
dia++; // incrementa dia
else
if ( mes < 12 ) // día es fin de mes y mes < 12
{
mes++; // incrementa mes
dia = 1; // primer día del nuevo mes
} // fin de if
else // último día de anio
{
anio++; // incrementa anio
mes = 1; // primer mes del nuevo anio
dia = 1; // primer día del nuevo mes
} // fin de else
} // fin de la función ayudaIncremento

// operador de salida sobrecargado
ostream &operator<<( ostream &salida, const Fecha &d )
{
static char *nombreMes[ 13 ] = { "", "Enero", "Febrero",
"Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto",
"Septiembre", "Octubre", "Noviembre", "Diciembre" };
salida << nombreMes[ d.mes ] << ' ' << d.dia << ", " << d.anio;
return salida; // permite la asignación en cascada
} // fin de la función operator<<

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

bool Fecha::compararFechas( Fecha f2 ){

    if ( this->getDia() == f2.getDia() && this->getMes() == f2.getMes() )
        return true;

    return false;    
}