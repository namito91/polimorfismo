#include <iostream>
#include <vector>
#include "Destinatario.h"
#include "Emisor.h"
using namespace std;


class Paquete {

    private:
        Emisor em;
        Destinatario des;
        double pesoPaquete , precioOnza;

    public:

        Paquete( const string &nombre, const string &direccion , const string &ciudad , const string &estado,
            const string &codigoPostal , const string &nombreD , const string &direccionD , const string &ciudadD , 
            const string &estadoD , const string &codigoPostalD, 
            const double &pesoPaquete , const double &pesoOnza )       
            : 
            em ( nombre,direccion, ciudad ,estado ,codigoPostal ) ,
            des ( nombreD,direccionD, ciudadD ,estadoD ,codigoPostalD )   
            {       
                setPesoPaquete ( pesoPaquete );
                setPrecioOnza ( pesoOnza );
            }    


        void setPesoPaquete ( double peso ){

            if ( peso > 0 ) pesoPaquete = peso;
            else {
                cout << "valor incorrecto" << endl;
                pesoPaquete = 0;
            } 
        }

        void setPrecioOnza ( double precio ){

            if ( precio > 0 ) precioOnza = precio;
            else {
                cout << "valor incorrecto" << endl;
                precioOnza = 0;
            } 
        }

        double getPrecioOnza(){
            return this->precioOnza;
        }

        double getPesoPaquete (){
            return this->pesoPaquete;
        }

        virtual double calcularCostoEnvio(){
           
            return getPrecioOnza () * getPesoPaquete ();
        }

        Emisor getEmisor () 
        {
            return em;
        }

        Destinatario& getDestinatario ()
        {
            return des;
        }
};  


class PaqueteDosDias : public Paquete {

    private:
        double cuotaFija;

    public:
        PaqueteDosDias ( const string &nombre, const string &direccion , const string &ciudad , const string &estado,
            const string &codigoPostal , const string &nombreD , const string &direccionD , const string &ciudadD , 
            const string &estadoD , const string &codigoPostalD,  const double &pesoPaquete , const double &precioOnza , 
            const double &cuota )       
            : 
            Paquete ( nombre,direccion, ciudad ,estado ,codigoPostal , nombreD ,direccionD, ciudadD ,estadoD ,codigoPostalD  
            ,pesoPaquete ,precioOnza )

        {
            setCuotaFija ( cuota );
        }    

        void setCuotaFija ( double cuota )
        {
            this->cuotaFija = cuota;        
        }

        double getCuotaFija ()
        {
            return this->cuotaFija;
        }

        double calcularCostoEnvio()
        {
            cout << "costo envio de paquete dos dias " << endl;
            return  Paquete::calcularCostoEnvio() + getCuotaFija();
        }

};


class PaqueteNocturno : public Paquete {

    private:
        double cuotaAdicionalOnza;

    public:

        PaqueteNocturno ( const string &nombre, const string &direccion , const string &ciudad , const string &estado,
            const string &codigoPostal ,const string &nombreD , const string &direccionD , const string &ciudadD , 
            const string &estadoD , const string &codigoPostalD,const double &pesoPaquete , const double &precioOnza , 
            const double &cuota ,const int &cuotaAdicional )       
            : 
            Paquete ( nombre,direccion, ciudad ,estado ,codigoPostal ,
                    nombreD,direccionD, ciudadD ,estadoD ,codigoPostalD , pesoPaquete ,precioOnza )
            {
                setCuotaAdicional ( cuotaAdicional );
            }


        void setCuotaAdicional ( double cuota )
        {
            this->cuotaAdicionalOnza = ( cuota < 0.0 ) ? 0.0 : (cuota * Paquete:: getPesoPaquete());
        }

        double calcularCostoEnvio () 
        {
            cout << "costo envio de paquete nocturno " << endl;
            return Paquete :: calcularCostoEnvio () + cuotaAdicionalOnza; 
        }


};


int main(int argc, char const *argv[])
{

    PaqueteDosDias pqDD ( "pepe" , "abc 123" , " rosario " , "sta fe" , "2000" ,
    "pepa" , "ghj 456" , " caballito " , "bs as" , "1000",
     20.1 , 1.32 , 300 );
    PaqueteNocturno pqN ( "pepa" , "ghj 456" , " caballito " , "bs as" , "1000" ,
    "pepe" , "abc 123" , " rosario " , "sta fe" , "2000" ,
     20.1 , 1.32 , 300.3 , 1.2 );
    vector <Paquete *> vect (2);
    vect[0] = &pqDD;
    vect[1] = &pqN;

   // mostrarDatosEm( vect[0] );
    double costoTotal = 0;
    
    for (size_t i = 0; i < vect.size() ; i++)
    {
        /* code */
        cout << vect[i]->getEmisor(); 
        cout << vect[i]->getDestinatario();
        costoTotal += vect[i]->calcularCostoEnvio();    
    }
    
    cout << "costo total : " << costoTotal << endl;
    
    return 0;
}

