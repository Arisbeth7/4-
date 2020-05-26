#ifndef LIBRO_H
#define LIBRO_H
#include "Ppersona.h"


class Libro
{
    public:
        Libro();
        Libro(char [],Ppersona,int,char [],char [],char []);
        void update(char [], Ppersona, int, char[],char [],char []);
        void getAutor();
        void toString();

    private:
        char titulo[100];
        Ppersona autor;
        int annio;
        char genero[100];
        char editorial[100];
        char isbn[100];
};

#endif // LIBRO_H
