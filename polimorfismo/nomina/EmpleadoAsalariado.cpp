// Fig. 13.16: EmpleadoAsalariado.cpp
// Definiciones de las funciones miembro de la clase EmpleadoAsalariado.
#include <iostream>
using std::cout;
#include "EmpleadoAsalariado.h" // definición de la clase EmpleadoAsalariado
using namespace std;

// constructor
EmpleadoAsalariado::EmpleadoAsalariado( const string &nombre,
const string &apellido, const string &nss, double salario )
: Empleado( nombre, apellido, nss )
{
setSalarioSemanal( salario );
} // fin del constructor de EmpleadoAsalariado
// establece el salario
void EmpleadoAsalariado::setSalarioSemanal( double salario )
{
salarioSemanal = ( salario < 0.0 ) ? 0.0 : salario;
} // fin de la función setSalarioSemanal
// devuelve el salario
double EmpleadoAsalariado::getSalarioSemanal() const
{
return salarioSemanal;
} // fin de la función getSalarioSemanal
// calcula los ingresos;
// sobrescribe a la función virtual pura ingresos en Empleado
double EmpleadoAsalariado::ingresos() const
{
return getSalarioSemanal();
} // fin de la función ingresos
// imprime la información del EmpleadoAsalariado
void EmpleadoAsalariado::imprimir() const
{
cout << "empleado asalariado: ";
Empleado::imprimir(); // reutiliza la función imprimir de la clase base abstracta
cout << "\nsalario semanal: " << getSalarioSemanal();
} // fin de la función imprimir

void EmpleadoAsalariado::bonificacion(){

    cout << "se obtuvo un bono por cumpleanios" << endl;
    salarioSemanal += 100.00;
    
}