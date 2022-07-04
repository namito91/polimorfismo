// Fig. 13.20: EmpleadoPorComision.cpp
// Definiciones de las funciones miembro de la clase EmpleadoPorComision.
#include <iostream>
using std::cout;
#include "EmpleadoPorComision.h" // definición de la clase EmpleadoPorComision
using namespace std;

// constructor
EmpleadoPorComision::EmpleadoPorComision( const string &nombre,
const string &apellido, const string &nss, double ventas, double tarifa )
: Empleado( nombre, apellido, nss )
{
setVentasBrutas( ventas );
setTarifaComision( tarifa );
} // fin del constructor de EmpleadoPorComision
// establece la tarifa de comisión
void EmpleadoPorComision::setTarifaComision( double tarifa )
{
tarifaComision = ( ( tarifa > 0.0 && tarifa < 1.0 ) ? tarifa : 0.0 );
} // fin de la función setTarifaComision
// devuelve la tarifa de comisión
double EmpleadoPorComision::getTarifaComision() const
{
return tarifaComision;
} // fin de la función getTarifaComision
// establece el monto de ventas brutas
void EmpleadoPorComision::setVentasBrutas( double ventas )
{
ventasBrutas = ( ( ventas < 0.0 ) ? 0.0 : ventas );
} // fin de la función setVentasBrutas
// devuelve el monto de ventas brutas
double EmpleadoPorComision::getVentasBrutas() const
{
return ventasBrutas;
} // fin de la función getVentasBrutas
// calcula los ingresos;
// sobrescribe la función virtual pura ingresos en Empleado
double EmpleadoPorComision::ingresos() const
{
return getTarifaComision() * getVentasBrutas();
} // fin de la función ingresos
// imprime la información del EmpleadoPorComision
void EmpleadoPorComision::imprimir() const
{
cout << "empleado por comision: ";
Empleado::imprimir(); // reutilización de código
cout << "\nventas brutas: " << getVentasBrutas()
<< "; tarifa de comision: " << getTarifaComision();
} // fin de la función imprimir

void EmpleadoPorComision::bonificacion() {

    cout << "se obtuvo un bono por cumpleanios" << endl;
    ventasBrutas += 100;
}

