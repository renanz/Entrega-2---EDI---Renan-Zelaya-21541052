#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>

using namespace std;

class archivo
{
    public:
        archivo();
        archivo(string nombre, string ruta);

        void setNombre(string nombre);
        void setRuta(string ruta);
        void setSig(archivo * a);
        void setAnt(archivo * a);

        string getNombre();
        string getRuta();
        string getTipo();
        archivo * getSig();
        archivo * getAnt();

        bool operator==(archivo * ar);
    protected:
        string tipo;
    private:
        string nombre;
        string ruta;
        archivo * sig;
        archivo * ant;
};

#endif // ARCHIVO_H
