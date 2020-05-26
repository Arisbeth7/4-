#ifndef PPERSONA_H
#define PPERSONA_H


class Ppersona
{
    public:
        Ppersona();
        Ppersona(char [],char [],int);
        void toString();

    private:
        char nombres[100];
        char apellidos[100];
        int edad;
};

#endif // PPERSONA_H
