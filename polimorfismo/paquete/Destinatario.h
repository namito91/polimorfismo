#include <iostream>
using namespace std;

class Destinatario {

    private:
        string nombre,direccion,ciudad,estado,codigoPostal;

    public:
        Destinatario ( const string &nombre, const string &direccion , const string &ciudad , const string &estado,
        const string &codigoPostal ) : nombre(nombre) , direccion (direccion) , ciudad (ciudad) , estado (estado) , 
        codigoPostal (codigoPostal)
        {
            // cuerpo vacio
        }

        void friend operator<<( ostream& os , Destinatario de ){

            cout << "datos del destinatario" << endl;
            os << "nombre : " << de.nombre << endl;
            os << "direccion : " << de.direccion << endl;
            os << "ciudad : " << de.ciudad << endl;
            os << "estado : " << de.estado << endl;
            os << "codigo postal : " << de.codigoPostal << endl;
            cout << endl;
        } 

};