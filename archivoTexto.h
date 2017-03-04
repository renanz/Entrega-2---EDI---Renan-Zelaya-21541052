#ifndef ARCHIVOTEXTO_H
#define ARCHIVOTEXTO_H
#include "archivo.h"

class archivoTexto : public archivo
{
    public:
        archivoTexto(string nombre, string ruta);

        void setContenido(string contenido);
        string getContenido();
        string getTipo();
    protected:

    private:
        string contenido;
};

#endif // ARCHIVOTEXTO_H
