#include <iostream>
#include "Ppersona.h"
#include "Libro.h"
#include "Prestamo.h"

using namespace std;

Libro registrarLibro(){
    /*DATOS DEL LIBRO*/
    char titulo[100];
    char nombres[100];
    char apellidos[100];
    char nacionalidad[100];
    int annio;
    int edad;
    char genero[100];
    char editorial[100];
    char isbn[100];
    /*DATOS DEL LIBRO*/

    cout << "Ingrese el titulo del libro"<<endl;
    cin >> titulo;
    cout << "Ingrese le nombre del autor"<<endl;
    cin >> nombres;
    cout << "Ingrese los apellidos del autor"<<endl;
    cin >> apellidos;
    Ppersona autor =Ppersona(nombres,apellidos,edad);
    Libro nuevo = Libro(titulo,autor,annio,genero,editorial,isbn);
    return nuevo;
}

Ppersona registrarUsuario(){
    char nombres[100];
    char apellidos[100];
    int edad;

    cout << "Ingrese su nombre: "<<endl;
    cin >> nombres;
    cout << "Ingrese sus apellidos: "<<endl;
    cin >> apellidos;
    cout << "Ingrese su edad: "<< endl;
    cin >>edad;
    cout << "Registro exitoso"<< endl;

    Ppersona usuario =Ppersona(nombres,apellidos,edad);

    return usuario;
}

Prestamo registrarPrestamo(int libro){
    int usuario;
    char fechaInicial[100];

    cout << "Ingrese el numero de usuario"<<endl;
    cin >> usuario;

    cout << "Ingrese la fecha inicial"<<endl;
    cin >> fechaInicial;

    Prestamo nuevoPrestamo = Prestamo(usuario,libro,fechaInicial);
    return nuevoPrestamo;
}

void mostrarLibros(Libro libros[10],int librosC){

    for (int i = 0; i < librosC; ++i) {
        cout << " Libro: "<< (i) << endl;
        libros[i].toString();
    }
}

void menuLibros(){
    cout << "-------------- MENU -------------"<<endl;
    cout << "      1.- Registrar libro "<<endl;
    cout << "      2.- Editar libro "<<endl;
    cout << "      3.- Eliminar libro "<<endl;
    cout << "      4.- Consultar autor "<<endl;
    cout << "      5.- Detalles de libro "<<endl;
    cout << "---------------------------------"<<endl;
}

void menuUsuarios(){
    cout << "-------------- MENU -------------"<<endl;
    cout << "      1.- Registrar usuario "<<endl;
    cout << "      2.- Editar usuario "<<endl;
    cout << "      3.- Eliminar usuario "<<endl;
    cout << "      4.- Consultar usuario "<<endl;
    cout << "      5.- Menu principal "<<endl;
    cout << "---------------------------------"<<endl;
}

void menuPrestamos(){
    cout << "-------------- MENU -------------"<<endl;
    cout << "    1.- Realizar prestamo "<<endl;
    cout << "    2.- Devolver libro "<<endl;
    cout << "    3.- Consultar prestamo "<<endl;
    cout << "    4.- Regresar "<<endl;
    cout << "---------------------------------"<<endl;
}

void menu(){
    cout << "-------------- MENU -------------"<<endl;
    cout << "     1.- Administrar usuarios "<<endl;
    cout << "     2.- Administrar Libros "<<endl;
    cout << "     3.- Administrar Prestamos "<<endl;
    cout << "     4.- Salir "<<endl;
    cout << "---------------------------------"<<endl;
    cout << "Ingrese la opcion deseada:"<< endl;
}

int main(){
    Libro libros[10];
    Ppersona usuarios[10];
    Prestamo prestamos[100];
    bool power = true, t = true;
    int op = 0, librosC = 0, no = 0, imc, usuariosC = 0, prestamosC = 0, tB;
    char fechaFinal[100];

    while (power){
        menu();
        cin >> op;

        switch (op) {
            case 1:
                menuUsuarios();
                cout << "Ingrese la opcion deseada:"<< endl;
                cin >> op;
                switch (op) {
                    case 1:

                        usuarios[usuariosC] = registrarUsuario();
                        usuariosC++;

                        break;
                    case 2:
                        cout << "Ingrese el numero de usuario"<<endl;
                        cin >> no;

                        usuarios[no].toString();
                        usuarios[no] = registrarUsuario();
                        break;
                    case 3:
                        cout << "Ingrese el numero de usuario"<<endl;
                        cin >> no;

                        usuarios[no].toString();
                        usuarios[no] = Ppersona();
                        cout << "Usuario eliminado"<<endl;
                        break;
                    case 4:
                        cout << "Ingrese el numero de usuario"<<endl;
                        cin >> no;

                        usuarios[no].toString();

                        for (int i = 0; i < prestamosC; ++i) {
                            if(prestamos[i].getUsuario() == no){

                                //imprime el detalle del libro
                                tB = prestamos[no].getLibro();
                                libros[tB].toString();

                                //imprime el detalle del prestamo
                                prestamos[i].toString();
                            }
                        }
                        break;
                }
                break;
            case 2:
                menuLibros();
                cin >> op;
                switch (op) {
                    case 1:

                        libros[librosC] = registrarLibro();
                        librosC++;
                        no++;

                        break;
                    case 2:
                        cout << "Ingrese el numero del libro"<<endl;
                        cin >> no;

                        libros[no].toString();

                        libros[no] = registrarLibro();

                        break;
                    case 3:
                        cout << "Ingrese el numero de libro"<<endl;
                        cin >> no;

                        libros[no].toString();
                        libros[no] = Libro();
                        cout << "Libro eliminado"<<endl;

                        break;
                    case 4:
                        cout << "Ingrese el numero del libro"<<endl;
                        cin >> no;

                        libros[no].getAutor();

                        break;

                    case 5:
                        cout << "Ingrese el numero de libro"<<endl;
                        cin >> no;

                        libros[no].toString();

                        for (int i = 0; i < prestamosC; ++i) {
                            if(prestamos[i].getLibro() == no){

                                //imprimir los detalles del usario
                                usuarios[prestamos[no].getUsuario()].toString();

                                //imprimir los detalles del prestamo
                                prestamos[i].toString();
                            }
                        }

                        break;
                    default:
                        power = false;
                        break;
                }

                break;
            case 3:
                menuPrestamos();
                cin >> op;

                switch (op) {
                    case 1:
                        mostrarLibros(libros,librosC);

                        cout << "Ingrese el numero de libro"<<endl;
                        cin >> no;

                        t = true;

                        for (int i = 0; i < prestamosC ; ++i) {
                            //si entra al if, el libro esta prestado
                          if(no == prestamos[i].getLibro() && prestamos[i].getEstatus()==1){
                              t = false;
                          }
                        }

                        if(t == true){ //si nunca entro al if, el libro no esta prestado
                            prestamos[prestamosC] = registrarPrestamo(no);
                            prestamosC++;
                        }else{
                            cout << "El libro ya esta prestado"<<endl;
                        }

                        break;
                    case 2:
                        cout << "Ingresa el numero de prestamo"<<endl;
                        cin >> no;

                        usuarios[prestamos[no].getUsuario()].toString();

                        tB = prestamos[no].getLibro();
                        libros[tB].toString();

                        prestamos[no].toString();

                        if(prestamos[no].getEstatus()==1){

                            cout << "Ingresa la fecha de devolucion"<<endl;
                            cin >> fechaFinal;

                            prestamos[no].devolucion(fechaFinal);
                            cout << "Libro devuelto"<<endl;

                        }else{
                            cout << "El prestamo ha sido finalizado anteriormente"<<endl;
                        }

                        break;
                    case 3:
                        cout << "ingresa el numero de prestamo"<<endl;
                        cin >> no;

                        usuarios[prestamos[no].getUsuario()].toString();

                        tB = prestamos[no].getLibro();
                        libros[tB].toString();

                        prestamos[no].toString();
                        break;
                }
                break;
            default:
                power = false;
                break;
        }
    }

    return 0;
}
