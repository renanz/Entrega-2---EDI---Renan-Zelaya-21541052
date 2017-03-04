#include "archivoTexto.h"

archivoTexto::archivoTexto(string nombre, string ruta) : archivo(nombre,ruta)
{
    this->contenido = "";
    this->tipo = "Archivo de Texto";
}

void archivoTexto::setContenido(string contenido)
{
    this->contenido = contenido;
}

string archivoTexto::getContenido()
{
    return this->contenido;
}

string archivoTexto::getTipo()
{
    return this->tipo;
}
