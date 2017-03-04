#ifndef FOLDER_H
#define FOLDER_H
#include "archivo.h"
#include "Lista_Apuntador.h"

class folder : public archivo
{
    public:
        folder(string nombre, string ruta);

        Lista_Apuntador * archivos;

        string getTipo();

    protected:

    private:
};

#endif // FOLDER_H
