#include <iostream>
using namespace std;

class Emisor {

    private:
        string nombre,direccion,ciudad,estado,codigoPostal;

    public:
        Emisor( const string &nombre, const string &direccion , const string &ciudad , const string &estado,
        const string &codigoPostal ) : nombre(nombre) , direccion (direccion) , ciudad (ciudad) , estado (estado) , 
        codigoPostal (codigoPostal)
        {
            // cuerpo vacio
        }

        void friend operator<<( ostream& os , Emisor em )
        {
            cout << "datos del emisor" << endl;
            os << "nombre : " << em.nombre << endl;
            os << "direccion : " << em.direccion << endl;
            os << "ciudad : " << em.ciudad << endl;
            os << "estado : " << em.estado << endl;
            os << "codigo postal : " << em.codigoPostal << endl;
            cout << endl;
        } 

};