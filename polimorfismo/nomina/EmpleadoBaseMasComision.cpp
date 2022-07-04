// Fig. 13.22: EmpleadoBaseMasComision.cpp
// Definiciones de las funciones miembro de EmpleadoBaseMasComision.
#include <iostream>
using std::cout;
// definición de la clase EmpleadoBaseMasComision
#include "EmpleadoBaseMasComision.h"
using namespace std;

// constructor
EmpleadoBaseMasComision::EmpleadoBaseMasComision(
const string &nombre, const string &apellido, const string &nss,
double ventas, double tarifa, double salario )
: EmpleadoPorComision( nombre, apellido, nss, ventas, tarifa )
{
setSalarioBase( salario ); // valida y almacena el salario base

} // fin del constructor de EmpleadoBaseMasComision
// establece el salario base
void EmpleadoBaseMasComision::setSalarioBase( double salario )
{
salarioBase = ( ( salario < 0.0 ) ? 0.0 : salario );
} // fin de la función setSalarioBase
// devuelve el salario base
double EmpleadoBaseMasComision::getSalarioBase() const
{
return salarioBase;
} // fin de la función getSalarioBase
// calcula los ingresos;
// sobrescribe la función virtual pura ingresos en Empleado
double EmpleadoBaseMasComision::ingresos() const
{
return getSalarioBase() + EmpleadoPorComision::ingresos();
} // fin de la función ingresos
// imprime la información del EmpleadoBaseMasComision
void EmpleadoBaseMasComision::imprimir() const
{
cout << "con salario base ";
EmpleadoPorComision::imprimir(); // reutilización de código
cout << "; salario base: " << getSalarioBase();
} // fin de la función imprimir

void EmpleadoBaseMasComision::bonificacion(){

    cout << "se obtuvo un bono por cumpleanios" << endl;
    salarioBase += 100;

}