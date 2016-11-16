using namespace std;

#ifndef Tarjetaa_Tarjeta_h
#define Tarjetaa_Tarjeta_h

#include "Reloj.h"
#include "Registro.h"

class Tarjeta:public Registro
{
public:
    Tarjeta();
    int getidTarj();
    virtual int calculaPago(Reloj HE, Reloj HS, int Tarifa) = 0;
    virtual int calculaHorasCobrar(Reloj HE, Reloj HS) = 0;
    virtual void muestraDatos() = 0;
protected:
    int idTarjeta;
};

Tarjeta::Tarjeta()
{
    idTarjeta=0;
}

int Tarjeta::getidTarj()
{
    return idTarjeta;
}

#endif // Proyecto
