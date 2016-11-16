using namespace std;

#ifndef Registroo_Registro_h
#define Registroo_Registro_h

#include "Reloj.h"

class Registro
{
public:
    Registro();
    Registro(int idTarj, Reloj hrEntrada);
    int getidTarj();
    Reloj gethrEntrada();
    void setidTarj(int idTarj);
    void sethrEntrada(Reloj hrEntrada);
protected:
    int idTarj;
    Reloj hrEntrada;
};

Registro::Registro()
{
    Reloj r;
    idTarj=0;
    hrEntrada=r;
}

Registro::Registro(int idTarj, Reloj hrEntrada)
{
    this->idTarj=idTarj;
    this->hrEntrada=hrEntrada;
}

int Registro::getidTarj()
{
    return idTarj;
}

Reloj Registro::gethrEntrada()
{
    return hrEntrada;
}

void Registro::setidTarj(int idTarj)
{
    this->idTarj=idTarj;
}

void Registro::sethrEntrada(Reloj hrEntrada)
{
    this->hrEntrada=hrEntrada;
}

#endif
