#include "folder.h"

folder::folder(string nombre, string ruta): archivo(nombre,ruta)
{
    this->tipo = "Folder";
    archivos = new Lista_Apuntador();
}
string folder::getTipo()
{
    return this->tipo;
}
