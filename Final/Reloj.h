#include <iomanip>
#include <fstream>
using namespace std;

#ifndef Relojj_Reloj_h
#define Relojj_Reloj_h

class Reloj
{
	public:
		Reloj();
		Reloj(int h);
		Reloj(int h, int m);
		void setHora(int h);
		void setMin(int m);
		int getHora();
		int getMin();
		void muestra();

		Reloj operator-(Reloj r);
		bool operator>(Reloj r);
		bool operator<(Reloj r);
		bool operator>=(Reloj r);
		bool operator<=(Reloj r);
		friend ostream& operator<<(ostream &os, const Reloj &r);
		friend istream& operator>>(istream &is, Reloj &r);
	private:
		int hora;
		int minu;
};

Reloj::Reloj()
{
    hora=0;
    minu=0;
}

Reloj::Reloj(int h)
{
    hora=h;
    minu=0;
}

Reloj::Reloj(int h, int m)
{
    hora=h;
    minu=m;
}

void Reloj::setHora(int h)
{
    hora = h;
}

void Reloj::setMin(int m)
{
    minu = m;
}

int Reloj::getHora()
{
    return hora;
}

int Reloj::getMin()
{
    return minu;
}

void Reloj::muestra()
{
    if(hora<10)
    {
        if(minu<10)
            cout << "0" << hora << ":" << "0" << minu << endl;
        else
            cout << "0" << hora << ":" << minu << endl;
    }
    else
    {
        if(minu<10)
            cout << hora << ":" << "0" << minu << endl;
        else
            cout << hora << ":" << minu << endl;
    }

}

Reloj Reloj::operator-(Reloj r)
{
    int iMinutos, iHoras, iMinTot;

    iMinutos=r.getMin();
    iHoras=r.getHora();
    iMinTot=(iHoras*60)+iMinutos;
    iMinutos = minu;
    iHoras = hora;

    for(int i=0; i < iMinTot; i++)
    {
        if(iMinutos==0)
        {
            if(iHoras>=1)
            {
                iHoras-=1;
                iMinutos=59;
            }
            else
            {
                iHoras=23;
                iMinutos=59;
            }
        }
        else
            iMinutos-=1;
    }
    Reloj NuevoRej(iHoras,iMinutos);
    return NuevoRej;
}

bool Reloj::operator>(Reloj r)
{
    if(hora>(r.getHora()))
        return true;
    else if(hora==(r.getHora()))
    {
        if(minu>(r.getMin()))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Reloj::operator<(Reloj r)
{
    if(hora<(r.getHora()))
        return true;
    else if(hora==(r.getHora()))
    {
        if(minu<(r.getMin()))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Reloj::operator>=(Reloj r)
{
    if(hora>(r.getHora()))
        return true;
    else if(hora==(r.getHora()))
    {
        if(minu>=(r.getMin()))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Reloj::operator<=(Reloj r)
{
    if(hora<(r.getHora()))
        return true;
    else if(hora==(r.getHora()))
    {
        if(minu<=(r.getMin()))
            return true;
        else
            return false;
    }
    else
        return false;
}

ostream& operator<<(ostream &os, const Reloj &r)
{
    os<<setfill('0')<<setw(2)<<r.hora<<":"<<setfill('0')<<setw(2)<<r.minu;
    return os;
}

istream& operator>>(istream &is, Reloj &r)
{
    cout << "Teclea la hora " << endl;
    is >> r.hora;
    do{
    cout << "Teclea los minutos " << endl;
    is >> r.minu;
    }while(r.minu<0 or r.minu>59);
    is.ignore();
    return is;
}

#endif // Proyecto
