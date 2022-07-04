// Fig. 13.18: EmpleadoPorHoras.cpp
// Definiciones de las funciones miembro de EmpleadoPorHoras.
#include <iostream>
using std::cout;
#include "EmpleadoPorHoras.h" // definición de la clase EmpleadoPorHoras
using namespace std;

// constructor
EmpleadoPorHoras::EmpleadoPorHoras( const string &nombre, const string &apellido,
const string &nss, double sueldoHora, double horasTrabajadas )
: Empleado( nombre, apellido, nss )
{
setSueldo( sueldoHora ); // valida el sueldo por hora
setHoras( horasTrabajadas ); // valida las horas trabajadas
} // fin del constructor de EmpleadoPorHoras
// establece el sueldo
void EmpleadoPorHoras::setSueldo( double sueldoHora )
{
sueldo = ( sueldoHora < 0.0 ? 0.0 : sueldoHora );
} // fin de la función setSueldo
// devuelve el sueldo
double EmpleadoPorHoras::getSueldo() const
{
return sueldo;
} // fin de la función getSueldo
// establece las horas trabajadas
void EmpleadoPorHoras::setHoras( double horasTrabajadas )
{
horas = ( ( ( horasTrabajadas >= 0.0 ) && ( horasTrabajadas <= 168.0 ) ) ?
horasTrabajadas : 0.0 );
} // fin de la función setHoras
// devuelve las horas trabajadas
double EmpleadoPorHoras::getHoras() const
{
return horas;
} // fin de la función getHoras

// calcula los ingresos;
// sobrescribe la función virtual pura ingresos en Empleado
double EmpleadoPorHoras::ingresos() const
{
if ( getHoras() <= 40 ) // no hay tiempo extra
return getSueldo() * getHoras();
else
return 40 * getSueldo() + ( ( getHoras() - 40 ) * getSueldo() * 1.5 );
} // fin de la función ingresos

// imprime la información del EmpleadoPorHoras
void EmpleadoPorHoras::imprimir() const
{
cout << "empleado por horas: ";
Empleado::imprimir(); // code reuse
cout << "\nsueldo por hora: " << getSueldo() <<
"; horas trabajadas: " << getHoras();
} // fin de la función imprimir

void EmpleadoPorHoras :: bonificacion (){

    cout << "se obtuvo un bono por cumpleanios" << endl;
    sueldo += 100.00;
}