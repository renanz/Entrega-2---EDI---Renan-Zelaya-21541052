#include "archivo.h"

archivo::archivo()
{
    //ctor
}
archivo::archivo(string nombre, string ruta)
{
    this->ruta = ruta;
    this->nombre = nombre;
    this->tipo = "";
}

void archivo::setNombre(string nombre)
{
    this->nombre = nombre;
}
void archivo::setRuta(string ruta)
{
    this->ruta = ruta;
}
void archivo::setSig(archivo * a)
{
    this->sig = a;
}
void archivo::setAnt(archivo * a)
{
    this->ant = a;
}

string archivo::getNombre()
{
    return this->nombre;
}
string archivo::getRuta()
{
    return this->ruta;
}
string archivo::getTipo()
{
    return this->tipo;
}
archivo * archivo::getAnt()
{
    return this->ant;
}
archivo * archivo::getSig()
{
    return this->sig;
}

bool archivo::operator==(archivo * ar)
{
    return nombre==ar->nombre;
}
