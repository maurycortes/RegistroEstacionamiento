using namespace std;

#ifndef TarjetaProovedorr_TarjetaProovedor_h
#define TarjetaProovedorr_TarjetaProovedor_h

#include "Tarjeta.h"
#include "Reloj.h"

class TarjetaProovedor:public Tarjeta
{
public:
    TarjetaProovedor();
    TarjetaProovedor(int idPro, string Empresa, int idTarjeta);
    int getidPro();
    string getEmpresa();
    void setidPro(int idPro);
    void setEmpresa(string Empresa);
    //Metodos abstractos
    int calculaPago(Reloj HE, Reloj HS, int Tarifa);
    int calculaHorasCobrar(Reloj HE, Reloj HS);
    void muestraDatos();
private:
    int idPro;
    string Empresa;
};

TarjetaProovedor::TarjetaProovedor():Tarjeta()
{
    idPro=0;
    Empresa="S/E";
    idTarjeta=0;
}

TarjetaProovedor::TarjetaProovedor(int idPro, string Empresa, int idTarjeta)
{
    this->idPro=idPro;
    this->Empresa=Empresa;
    this->idTarjeta=idTarjeta;
}

int TarjetaProovedor::getidPro()
{
    return idPro;
}

string TarjetaProovedor::getEmpresa()
{
    return Empresa;
}

void TarjetaProovedor::setidPro(int idPro)
{
    this->idPro=idPro;
}

void TarjetaProovedor::setEmpresa(string Empresa)
{
    this->Empresa=Empresa;
}

int TarjetaProovedor::calculaPago(Reloj HE, Reloj HS, int Tarifa)
{
    return calculaHorasCobrar(HE,HS)*Tarifa;
}

int TarjetaProovedor::calculaHorasCobrar(Reloj HE, Reloj HS)
{
    Reloj HoraTotal=HS-HE;
    int Mins=HoraTotal.getMin();
    int Hora=(HoraTotal.getHora()-1);

    if(Hora<=0 and Mins<15)
        return 0;
    else
    {
        if(Mins>=15)
            return (Hora+1);
        else
            return Hora;
    }
}

void TarjetaProovedor::muestraDatos()
{
    cout << "PROOVEDOR " << endl;
    cout << "ID Tarjeta: " << idTarjeta << endl;
    cout << "ID Proovedor: " << idPro << endl;
    cout << "Empresa: " << Empresa << endl;
}

#endif
