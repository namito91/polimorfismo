// Fig. 13.19: EmpleadoPorComision.h
// Clase EmpleadoPorComision derivada de Empleado.
#ifndef COMISION_H
#define COMISION_H
#include "Empleado.h" // definición de la clase Empleado
class EmpleadoPorComision : public Empleado
{
public:
EmpleadoPorComision( const string &, const string &,
const string &, double = 0.0, double = 0.0 );
void setTarifaComision( double ); // establece la tarifa de comisión
double getTarifaComision() const; // devuelve la tarifa de comisión
void setVentasBrutas( double ); // establece el monto de ventas brutas
double getVentasBrutas() const; // devuelve el monto de ventas brutas
// la palabra clave virtual indica la intención de sobrescribir
virtual double ingresos() const; // calcula los ingresos
virtual void imprimir() const; // imprime el objeto EmpleadoPorComision
virtual void bonificacion();
private:
double ventasBrutas; // ventas brutas semanales
double tarifaComision; // porcentaje de comisión
}; // fin de la clase EmpleadoPorComision
#endif // COMISION_H
