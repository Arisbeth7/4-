#ifndef PRESTAMO_H
#define PRESTAMO_H


class Prestamo
{
    public:
        Prestamo();
        Prestamo(int,int,char []);
        void devolucion(char []);
        int getUsuario();
        int getLibro();
        int getEstatus();
        void toString();

    private:
        int usuario;
        int libro;
        char fechaInicial[100];
        char fechaFinal[100];
        int estatus;
};

#endif // PRESTAMO_H
