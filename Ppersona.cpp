#include <iostream>
#include "Ppersona.h"
#include <cstring>

using namespace std;


Ppersona::Ppersona(){

}
Ppersona::Ppersona(char nombres[100], char apellidos[100], int edad) {

    strcpy(this->nombres,nombres);
    strcpy(this->apellidos,apellidos);
    this ->edad=edad;

}


void Ppersona::toString() {

    cout << "---- Informacion ----"<<endl;
    cout << "Nombre: "<< this->nombres << endl;
    cout << "Apellidos: "<< this->apellidos << endl;
    cout << endl<<endl;
}

