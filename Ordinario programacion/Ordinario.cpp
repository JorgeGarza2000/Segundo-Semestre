/*Este programa es una base de datos de Estados, inserta, actualiza, elimina y busca los estados que estan proporcionados*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;
void menu();
void insertarEstado();
void actualizarEstado(string *, int);
void eliminarEstado(string *, int);
void buscarEstado(string *, int);
void mostrarID(string *,int);

int numEstados,opcion;
int pos;
int i;
string newState;
string *estados;
int ban = 0;

void menu()
{
    cout << "========= MENU =========" << endl;
    cout << "1) Insertar Estado(s) " << endl;
    cout << "2) Actualizar Estado(s) " << endl;
    cout << "3) Eliminar Estado(s) " << endl;
    cout << "4) Buscar Estado" << endl;
    cout << "5) Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        insertarEstado();
        break;
    case 2:
        actualizarEstado(estados, numEstados);
        break;
    case 3:
        eliminarEstado(estados, numEstados);
        break;
    case 4:
        buscarEstado(estados, numEstados);
        break;
    case 5:
        cout << "Gracias por usar mi programa, iiiiii hasta pronto !!!!! " << endl;
    }

    delete[] estados;
}

int main()
{
    cout<<"iiiii Bienvenido !!!!"<<endl;
    cout<<"Autor: Jorge Garza "<<endl;
    menu(); 
    return 0;
}

void insertarEstado()
{
    cout<<"Cuantos Estados quiere agregar:"<<endl;
    cin>>numEstados;
    
    estados = new string[numEstados];

    cout<<"Los estados agregados son: "<<numEstados<<" y son: "<<endl;
    for(i=0;i<numEstados;i++)
    {
        cout<<"Estado en posicion [" << i << "]: ";
        fflush(stdin);
        getline(cin,estados[i]);
        
      
    }
    cout<<endl;
     for (int i = 0; i < numEstados; i++)   
    {
        
       cout << "Estado :[" << i << "] = " << (estados[i]);
        cout << endl;
        cout<<" ID: "; mostrarID(estados,numEstados);
    }
    
    
    menu();
}
void actualizarEstado(string *estados, int numEstados)
{
    cout<<"Dame la posicion del Estado a actualizar: "<<endl;
    cin>>pos;
    if(pos<numEstados)
    {
        cout<<"Dame el nuevo Estado: ["<<pos<<"]"<<endl;
        cin>>newState;
        cout<<"Estado actualizado actualizado"<<endl;
        cout<<" Nuevo ID: "<<&newState<<endl;
        *estados = newState;
        menu();
    }

    
}

void eliminarEstado(string *estados,int numEstados)
{
int eliminarEstado;
cout<<"Dame la posicion del estado a eliminar: "<<endl;
cin>>eliminarEstado;
if(eliminarEstado<numEstados)
{
    estados[eliminarEstado] = "";

    cout<<"Estado eliminado "<<endl;

}
 menu();
}

void buscarEstado(string *estados, int numEstados)
{
    string estado2;
cout<<"Dame el estado que quiere buscar: ";
cin>>estado2;

for(i=0;i<numEstados;i++){
    if(estado2 == estados[i]){
        ban = 1;
        cout<<"El Estado "<< estado2 << " esta en la posicion: "<< "["<< i <<"]";
        cout<<" y su direccion es: "<<&estado2;
        break;
    }else{
        ban = 0;
    }    
}
    if(ban == 0){
        cout<<"El Estado no se encuentra en el arreglo ";
    }
   cout<<endl;
 menu();
}

void mostrarID(string *estados, int numEstados){
    for(i=0;i<1;i++){
        string *estados = &estados[i];
        cout<<estados<<endl;
    }
}