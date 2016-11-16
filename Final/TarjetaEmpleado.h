using namespace std;

#ifndef TarjetaEmpleadoo_TarjetaEmpleado_h
#define TarjetaEmpleadoo_TarjetaEmpleado_h

#include "Tarjeta.h"
#include "Reloj.h"

class TarjetaEmpleado: public Tarjeta
{
public:
    TarjetaEmpleado();
    TarjetaEmpleado(int idEmp, string Tienda, int idTarjeta);
    int getidEmp();
    string getTienda();
    void setidEmp(int idEmp);
    void setTienda(string Tienda);
    //Metodos abstractos
    int calculaPago(Reloj HE, Reloj HS, int Tarifa);
    int calculaHorasCobrar(Reloj HE, Reloj HS);
    void muestraDatos();
private:
    int idEmp;
    string Tienda;
};

TarjetaEmpleado::TarjetaEmpleado():Tarjeta()
{
    idEmp=0;
    Tienda="S/T";
    idTarjeta=0;
}

TarjetaEmpleado::TarjetaEmpleado(int idEmp, string Tienda, int idTarjeta)
{
    this->idEmp=idEmp;
    this->Tienda=Tienda;
    this->idTarjeta=idTarjeta;
}

int TarjetaEmpleado::getidEmp()
{
    return idEmp;
}

string TarjetaEmpleado::getTienda()
{
    return Tienda;
}

void TarjetaEmpleado::setidEmp(int idEmp)
{
    this->idEmp=idEmp;
}

void TarjetaEmpleado::setTienda(string Tienda)
{
    this->Tienda=Tienda;
}

int TarjetaEmpleado::calculaPago(Reloj HE, Reloj HS, int Tarifa)
{
    return 0;
}

int TarjetaEmpleado::calculaHorasCobrar(Reloj HE, Reloj HS)
{
    Reloj HoraTotal=HS-HE;
    int Mins=HoraTotal.getMin();
    int Hora=HoraTotal.getHora();

    if(Hora==0 and Mins<15)
        return 0;
    else
    {
        if(Mins>=15)
            return (Hora+1);
        else
            return Hora;
    }
}

void TarjetaEmpleado::muestraDatos()
{
    cout << "EMPLEADO " << endl;
    cout << "ID Tarjeta: " << idTarjeta << endl;
    cout << "ID Empleado: " << idEmp << endl;
    cout << "Tienda: " << Tienda << endl;
}

#endif
