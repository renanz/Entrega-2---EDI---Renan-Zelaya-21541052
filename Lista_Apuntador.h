#ifndef LISTA_APUNTADOR_H
#define LISTA_APUNTADOR_H
#include "archivo.h"
#include <iostream>

using namespace std;

class Lista_Apuntador
{
    public:
        Lista_Apuntador();
        void agregar(archivo * nuevo);
        archivo * obtener(int pos);
        int buscar(archivo * v);
        void eliminar(int pos);
        int getTamano();

    protected:

    private:
        int validarPosicion(int pos, bool nPos);
        int longitud_lista;
        archivo * Inicio;
        archivo * Fin;
};

#endif // LISTA_APUNTADOR_H
