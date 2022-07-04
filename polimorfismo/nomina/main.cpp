// Fig. 13.23: fig13_23.cpp
// Procesamiento de objetos de clases derivadas de Empleado en forma
// individual y polimórfica, mediante el uso de la vinculación dinámica.
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <vector>
using std::vector;
// incluye las definiciones de las clases en la jerarquía de Empleado
#include "Empleado.h"
#include "EmpleadoAsalariado.h"
#include "EmpleadoPorHoras.h"
#include "EmpleadoPorComision.h"
#include "EmpleadoBaseMasComision.h"
#include "Fecha.h"
void virtualViaApuntador( const Empleado * const ); // prototipo
void virtualViaReferencia( const Empleado & ); // prototipo
bool comprobarFecha( Empleado * const , Fecha );

int main()
{

Fecha fechaActual(24,2,1994);

// establece el formato de salida de punto flotante
cout << fixed << setprecision( 2 );
// crea objetos de las clases derivadas
EmpleadoAsalariado empleadoAsalariado(
"John", "Smith", "111-11-1111", 800 );
EmpleadoPorHoras empleadoPorHoras(
"Karen", "Price", "222-22-2222", 16.75, 40 );
EmpleadoPorComision empleadoPorComision(
"Sue", "Jones", "333-33-3333", 10000, .06 );
EmpleadoBaseMasComision empleadoBaseMasComision(
"Bob", "Lewis", "444-44-4444", 5000, .04, 300 );
cout << "Empleados procesados en forma individual, usando vinculacion estatica:\n\n";
// imprime la información de cada empleado y sus ingresos, usando vinculación estática
empleadoAsalariado.imprimir();
cout << "\nobtuvo $" << empleadoAsalariado.ingresos() << "\n\n";
empleadoPorHoras.imprimir();
cout << "\nobtuvo $" << empleadoPorHoras.ingresos() << "\n\n";
empleadoPorComision.imprimir();
cout << "\nobtuvo $" << empleadoPorComision.ingresos() << "\n\n";
empleadoBaseMasComision.imprimir();
cout << "\nobtuvo $" << empleadoBaseMasComision.ingresos()
<< "\n\n";

empleadoAsalariado.setFechaCumpleanios(12,3,1970);
empleadoPorHoras.setFechaCumpleanios(5,9,1964);
empleadoPorComision.setFechaCumpleanios(24,2,1991);
empleadoBaseMasComision.setFechaCumpleanios(16,4,1978);

// crea un vector de cuatro apuntadores de la clase base
vector < Empleado * > empleados( 4 );
// inicializa el vector con objetos Empleado
empleados[0] = &empleadoAsalariado;
empleados[1] = &empleadoPorHoras;
empleados[2] = &empleadoPorComision;
empleados[3] = &empleadoBaseMasComision;

cout << "Empleados procesados en forma polimorfica mediante vinculacion dinamica:\n\n";

// llama a virtualViaApuntador para imprimir la información de cada Empleado
// y a ingresos mediante el uso de la vinculación dinámica
cout << "Llamadas a funciones virtuales realizadas desde apuntadores de la clase base:\n\n";
for ( size_t i = 0; i < empleados.size(); i++ )
virtualViaApuntador( empleados[ i ] );

// llama a virtualViaReferencia para imprimir la información de cada Empleado
// y a ingresos mediante el uso de vinculación dinámica
cout << "Llamadas a funciones virtuales realizadas desde referencias de la clase base:\n\n";
for ( size_t i = 0; i < empleados.size(); i++ )
virtualViaReferencia( *empleados[ i ] ); // observe la desreferencia


for ( size_t i = 0; i < empleados.size(); i++ ){

    if ( comprobarFecha( empleados[i] , fechaActual ) ){
        cout << "bono aprobado" << endl;
    }else
        cout << "no se aprobo el bono por cumpleanios" << endl;
} 



    virtualViaApuntador( empleados[ 2 ] );


    // libera los objetos a los que apuntan los elementos del vector
for ( int j = 0; j < empleados.size(); j++ )
{
   
    
    delete empleados[ j ];
} // fin de for



return 0;
} // fin de main


// llama a las funciones virtuales imprimir e ingresos de Empleado desde un
// apuntador de la clase base mediante la vinculación dinámica
void virtualViaApuntador( const Empleado * const claseBasePtr )
{
claseBasePtr->imprimir();
cout << "\nobtuvo $" << claseBasePtr->ingresos() << "\n\n";
} // fin de la función virtualViaApuntador


// llama a las funciones virtuales imprimir e ingresos de Empleado desde una
// referencia de la clase base mediante la vinculación dinámica
void virtualViaReferencia( const Empleado &claseBaseRef )
{
claseBaseRef.imprimir();
cout << "\nobtuvo $" << claseBaseRef.ingresos() << "\n\n";
} // fin de la función virtualViaReferencia


bool comprobarFecha ( Empleado * const claseBasePtr , Fecha f1 ){

    if ( f1.compararFechas( claseBasePtr->getFechaNacimiento() ) ){

    claseBasePtr->bonificacion();    
    return true;
    }

    return false;

}