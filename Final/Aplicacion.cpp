#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

#include "Registro.h"
#include "Reloj.h"
#include "TarjetaEmpleado.h"
#include "TarjetaProovedor.h"
#include "TarjetaCliente.h"

int main()
{
    Registro registro[20], arregloNuevo[20];
    Tarjeta *listaTarjetas[40];
    Reloj HoraEntrada, HoraSalida, Rentrada(8,0), Rsalida1(21,59), Rsalida2(22,0), HorasEstancia;
    int iCont=0, iR=0, IDAutoEntrada, IDAutoSalida, casilla, ic=0, Salida, Entrada, iPosible, Repetido;
    int IDTarjeta, IDEmp, IDPro, IDCli, iC, Tarifa=10, H;
    string Tienda, Empresa;
    char cOpcion;

    string sNombre;
    const string sNombreArchivo="tarjetas.txt";
    ifstream sArchivoEntrada;
    sArchivoEntrada.open(sNombreArchivo.c_str());
    while(!sArchivoEntrada.eof())//Lectura de archivo para obtener la lista de tarjetas
    {
        sArchivoEntrada>>sNombre;
        if(sNombre[0]=='E')
        {
            sArchivoEntrada>>sNombre;
            IDTarjeta=atoi(sNombre.c_str());
            sArchivoEntrada>>sNombre;
            IDEmp=atoi(sNombre.c_str());
            getline(sArchivoEntrada,sNombre);
            Tienda=sNombre;
            listaTarjetas[iCont]=new TarjetaEmpleado(IDEmp,Tienda,IDTarjeta);
        }
        else if(sNombre[0]=='P')
        {
            sArchivoEntrada>>sNombre;
            IDTarjeta=atoi(sNombre.c_str());
            sArchivoEntrada>>sNombre;
            IDPro=atoi(sNombre.c_str());
            getline(sArchivoEntrada,sNombre);
            Empresa=sNombre;
            listaTarjetas[iCont]=new TarjetaProovedor(IDPro,Empresa,IDTarjeta);
        }
        else if(sNombre[0]=='C')
        {
            sArchivoEntrada>>sNombre;
            IDTarjeta=atoi(sNombre.c_str());
            sArchivoEntrada>>sNombre;
            IDCli=atoi(sNombre.c_str());
            listaTarjetas[iCont]=new TarjetaCliente(IDCli,IDTarjeta);
        }
        iCont++;//Cantidad de tarjetas que hay
    }
    sArchivoEntrada.close();

    do{
        //Despliega menu de opciones al usuario
        cout << "a. Entrada al estacionamiento " << endl;
        cout << "b. Salida del estacionamiento " << endl;
        cout << "c. Consulta del estacionamiento " << endl;
        cout << "d. Consulta de tarjetas " << endl;
        cout << "e. Salir " << endl << endl;
        do{
            cout << "Que opcion quieres hacer?: ";
            cin >> cOpcion;
            cOpcion = tolower(cOpcion);
        }while(cOpcion != 'a' && cOpcion != 'b' && cOpcion != 'c' && cOpcion != 'd' && cOpcion != 'e');
        system("cls");
        switch(cOpcion)
        {
        case 'a'://Opcion para la entrada del estacionamiento
            cout << endl << "\tENTRADA DE ESTACIONAMIENTO " << endl << endl;
            do{
            Entrada=false, Repetido=false;
            cout << "Introduce el ID de la tarjeta del auto " << endl;
            cin >> IDAutoEntrada;
            for(int i=0; i<iCont; i++)//Recorre el arreglo de apuntadores de la lista de tarjetas
            {
                if(listaTarjetas[i]->getidTarj()==IDAutoEntrada)//Verifica que exista en la lista de tarjetas el id que se introdujo
                    Entrada=true;
            }
            if(Entrada==false)
                cout << endl << "No existe un auto con ID " << IDAutoEntrada << endl << endl;
            for(int j=0; j<iR; j++)//Recorre la cantidad de autos estacionados
            {
                if(registro[j].getidTarj()==IDAutoEntrada)//Verifica si ya hay autos estacionados
                {
                    cout << endl << "Este auto ya esta dentro del estacionamiento " << endl << endl;
                    Repetido=true;
                }
            }
            }while((Entrada!=true)or(Repetido!=false));
            cin.ignore();
            //Validar hora de entrada
            do{
            cout << endl << "\tIntroduce los datos de la hora de llegada " << endl << endl;
            cin >> HoraEntrada;
                if(HoraEntrada<Rentrada or HoraEntrada>Rsalida1)//Verifica que no se introduzca una hora fuera del horario
                {
                    cout << endl << "No puedes ingresar a esa hora al estacionamiento " << endl;
                    cout << "HORARIO DE ENTRADA: 8:00-21:59 "<< endl << endl;
                }
            }while(HoraEntrada<Rentrada or HoraEntrada>Rsalida1);
            registro[iR].setidTarj(IDAutoEntrada);
            registro[iR].sethrEntrada(HoraEntrada);
            iR++;//Cantidad de registros (carros estacionados)
            break;

        case 'b'://Opcion para salir del estacionamiento
            cout << endl << "\tSALIDA DE ESTACIONAMIENTO " << endl << endl;
            do{
            Salida=false, H=0;
            cout << "Introduce el ID de la tarjeta del auto " << endl;
            cin >> IDAutoSalida;
            for(int i=0; i<iR; i++)//Recorre la cantidad de registros
                if(IDAutoSalida==registro[i].getidTarj())//Verifica que el auto que quiera salir, esté estacionado ya
                {
                    Salida=true;
                    H=i;
                }

            if(Salida==false)
                cout << endl << "No hay un auto dentro del estacionamiento con ID " << IDAutoSalida << endl << endl;
            }while(Salida!=true);
            cin.ignore();
            //Verifica hora de salida
            do{
            do{
            iPosible=false;
            cin >> HoraSalida;

            if(HoraSalida>=registro[H].gethrEntrada())//Verifica que la hora de salida no sea mayor a la hora de entrada
                    iPosible=true;

                if(iPosible==false)
                    cout << endl << "No puedes ingresar una hora de salida que sea antes de la hora de entrada " << endl << endl;
            }while(iPosible!=true);
                if(HoraSalida<Rentrada or HoraSalida>Rsalida2)//Verifica que la hora de salida esté en el horario posible
                {
                    cout << endl << "No puedes salir a esa hora del estacionamiento " << endl;
                    cout << "HORARIO DE SALIDA: 8:00-22:00 "<< endl << endl;
                }
            }while(HoraSalida<Rentrada or HoraSalida>Rsalida2);

            for(int i=0; i<iR; i++)//Recorre la cantidad de registros (carros estacionados)
            {
                if(IDAutoSalida==registro[i].getidTarj())//Imprime la ficha de salida del auto con el id que introdujiste
                {
                    cout << endl << "\t FICHA DE SALIDA " << endl << endl;
                    cout << endl << "Hora de entrada: " << registro[i].gethrEntrada() << endl;
                    cout << "Hora de salida:  ";
                    HoraSalida.muestra();
                    HorasEstancia=HoraSalida-registro[i].gethrEntrada();
                    cout << "Estuvo en el estacionamiento: " << HorasEstancia.getHora() << " horas con " << HorasEstancia.getMin() << " mns " << endl;
                    for(int j=0; j<iCont; j++)//Recorre la cantidad de tarjetas
                    {
                        if(IDAutoSalida==listaTarjetas[j]->getidTarj())//Verifica que lo que se va a cobrar, sea del tipo de tarjeta correcto
                        {
                            cout << "Las horas cobradas son: " << listaTarjetas[j]->calculaHorasCobrar(registro[i].gethrEntrada(),HoraSalida) << " horas " << endl;
                            cout << "Se tiene que pagar: " << listaTarjetas[j]->calculaPago(registro[i].gethrEntrada(),HoraSalida,Tarifa) << " pesos " << endl << endl;
                        }
                    }
                }
            }
            iC=0;
            for(int j=0; j<iR; j++)//Recorre la cantidad de carros estacionados para cambiar al arreglo nuevo
            {
                if(registro[j].getidTarj()==IDAutoSalida)
                {
                    arregloNuevo[j]=registro[j+1];
                    iC++;
                }
                else
                {
                    if(iC==1)
                        arregloNuevo[j]=registro[j+1];
                    else
                        arregloNuevo[j]=registro[j];
                }
            }
            iR--;
            for(int r=0; r<iR; r++)//Regresa los datos al arreglo original
                registro[r]=arregloNuevo[r];
            break;

        case 'c'://Opcion para ver los carros estacionados
            if(iR==0)
                cout << endl << "No hay carros dentro del estacionamiento " << endl << endl;
            else
            {
                cout << endl << "\t LOS CARROS DENTRO DEL ESTACIONAMIENTO " << endl << endl;
            for(int i=0; i<iR; i++)//Recorre la cantidad de carros estacionados
                for(int f=0; f<iCont; f++)//Recorre la cantidad de tarjetas que hay
                    if(registro[i].getidTarj()==listaTarjetas[f]->getidTarj())//Imprime los datos de los carros estacionados
                    {
                        listaTarjetas[f]->muestraDatos();
                        cout << "Ingresado a las: ";
                        (registro[i].gethrEntrada()).muestra();
                        cout << endl;
                    }
            }
            break;

        case 'd'://Opcion para ver todas las tarjetas
            if(iCont==0)
                cout << endl << "No hay lista de tarjetas en el archivo " << endl << endl;
            else
            {
                cout << endl << "\t LA LISTA DE TARJETAS " << endl << endl;
            for(int i=0; i<iCont; i++)//Recorre todas las tarjetas que hay y las despliega
            {
                listaTarjetas[i]->muestraDatos();
                cout << endl;
            }
            }
            break;

        case 'e':
            break;
        }
    }while(cOpcion!='e');
    return 0;
    system("pause");
}
