// Fig. 13.14: Empleado.cpp
// Definiciones de las funciones miembro de la clase base abstracta Empleado.
// Nota: no se proporcionan definiciones para las funciones virtuales puras.
#include <iostream>
using std::cout;
using namespace std;
#include "Empleado.h" // definición de la clase Empleado
// constructor
Empleado::Empleado( const string &nombre, const string &apellido,
const string &nss )
: primerNombre( nombre ), apellidoPaterno( apellido ), numeroSeguroSocial( nss )
{
// cuerpo vacío
} // fin del constructor de Empleado
// establece el primer nombre
void Empleado::setPrimerNombre( const string &nombre )
{
primerNombre = nombre;
} // fin de la función setPrimerNombre
// devuelve el primer nombre
string Empleado::getPrimerNombre() const
{
return primerNombre;
} // fin de la función getPrimerNombre
// establece el apellido paterno
void Empleado::setApellidoPaterno( const string &apellido )
{
apellidoPaterno = apellido;
} // fin de la función setApellidoPaterno
// devuelve el apellido paterno
string Empleado::getApellidoPaterno() const
{
return apellidoPaterno;
} // fin de la función getApellidoPaterno
// establece el número de seguro social
void Empleado::setNumeroSeguroSocial( const string &nss )
{
numeroSeguroSocial = nss; // debe validar
} // fin de la función setNumeroSeguroSocial

// devuelve el número de seguro social
string Empleado::getNumeroSeguroSocial() const
{
return numeroSeguroSocial;
} // fin de la función getNumeroSeguroSocial

void Empleado::setFechaCumpleanios(int dd , int mm, int anio){

    fechaNacimiento.setFecha(dd,mm,anio);

}

// imprime la información del Empleado (virtual, pero no virtual pura)
void Empleado::imprimir() const
{
cout << getPrimerNombre() << ' ' << getApellidoPaterno()
<< "\nnumero de seguro social: " << getNumeroSeguroSocial();
} // fin de la función imprimir


Fecha Empleado::getFechaNacimiento(){

    return fechaNacimiento;
}