#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H
#include "folder.h"
#include "archivoTexto.h"
#include <typeinfo>
#include <QtGlobal>
#include <QString>

using namespace std;

class fileExplorer
{
    public:
        fileExplorer();
        enum opcs {FOLDER, TXT};
        archivo * crearArchivo(folder * donde, string nombre, int opc);
        Lista_Apuntador listarArchivos(folder * donde);
        archivo * cargarArchivo(string ruta);
        void eliminarArchivo(string ruta);
        void copiar(folder * origen, string ar, folder * destino);
        void cortar(folder * origen, string ar, folder * destino);
        void dir();
        void dir(folder * subRaiz,string space);
        void seed();

        folder * getRaiz();

    protected:

    private:
        archivo * cargarArchivo(string ruta, folder * subRaiz);
        void eliminarArchivo(string ruta, folder * subRaiz);
        archivo * clipboard;
        folder * raiz;
};

#endif // FILEEXPLORER_H
