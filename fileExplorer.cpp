#include "fileExplorer.h"

fileExplorer::fileExplorer()
{
    this->clipboard = NULL;
    this->raiz = new folder("C:","");

}
archivo * fileExplorer::crearArchivo(folder * donde, string nombre, int opc)
{
    string ruta = donde->getRuta() + "\\" + donde->getNombre() + "\\" + nombre;
    if(opc == 0)
    {
        folder * newFolder = new folder(nombre,ruta);
        donde->archivos->agregar(newFolder);
        return newFolder;
    }
    else if(opc == 1)
    {
        archivoTexto * newArchivo = new archivoTexto(nombre,ruta);
        donde->archivos->agregar(newArchivo);
        return newArchivo;
    }
}
Lista_Apuntador fileExplorer::listarArchivos(folder * donde)
{
    Lista_Apuntador newList;

    for(int x = 0; x<donde->archivos->getTamano(); x++)
    {
        archivo * temp = donde->archivos->obtener(x);
        newList.agregar(temp);
    }

    return newList;
}
archivo * fileExplorer::cargarArchivo(string ruta)
{
    return cargarArchivo(ruta, getRaiz());
}
archivo * fileExplorer::cargarArchivo(string ruta, folder * subRaiz)
{
    for(int i = 0; i<subRaiz->archivos->getTamano(); i++){
        archivo * temp = subRaiz->archivos->obtener(i);
        if(temp->getRuta() == ruta)
            return temp;
        else if(temp->getTipo() == "Folder"){
            cargarArchivo(ruta, (folder*)temp);}
    }
    if(subRaiz == raiz)
        return NULL;
}
void fileExplorer::eliminarArchivo(string ruta)
{
    eliminarArchivo(ruta, getRaiz());
}
void fileExplorer::eliminarArchivo(string ruta, folder * subRaiz)
{
    archivo * temp;
    for(int x = 0; x<subRaiz->archivos->getTamano(); x++)
    {
        temp = subRaiz->archivos->obtener(x);
        if(temp->getRuta() == ruta)
        {
            subRaiz->archivos->eliminar(subRaiz->archivos->buscar(temp));
            return;
        }
        else if(temp->getTipo() == "Folder")
        {
            eliminarArchivo(ruta,(folder*)temp);
        }
    }
}
void fileExplorer::copiar(folder * origen, string ar, folder * destino)
{
    for(int x = 0; x<origen->archivos->getTamano(); x++)
    {
        archivo * temp = origen->archivos->obtener(x);
        if(temp->getNombre() == ar){
            clipboard = temp;
            break;
        }
    }
    if(clipboard != NULL)
        destino->archivos->agregar(clipboard);
    clipboard = NULL;
}
void fileExplorer::cortar(folder * origen, string ar, folder * destino)
{
    for(int x = 0; x<origen->archivos->getTamano(); x++)
    {
        archivo * temp = origen->archivos->obtener(x);
        if(temp->getNombre() == ar){
            clipboard = temp;
            break;
        }
    }
    if(clipboard != NULL)
    {
        destino->archivos->agregar(clipboard);
        origen->archivos->eliminar(destino->archivos->buscar(clipboard));
    }
    clipboard = NULL;
}
void fileExplorer::dir()
{
    cout<<getRaiz()->getNombre()<<endl;
    dir(getRaiz(),"");
}
void fileExplorer::dir(folder * subRaiz,string space)
{
    space+="\t";
    for(int x=0; x<subRaiz->archivos->getTamano();x++)
    {
        archivo * temp = subRaiz->archivos->obtener(x);
        cout<<space<<temp->getNombre()<<endl;
        if(temp->getTipo() == "Folder")
        {
            folder * fol = (folder*)temp;
            dir(fol,space);
        }
    }
}
void fileExplorer::seed()
{
    archivo * t3 = crearArchivo(raiz,"archivo3",1);
    archivo * f1 = crearArchivo(raiz,"folder1",0);
    archivo * f2 = crearArchivo(raiz,"folder2",0);
    archivo * t1 = crearArchivo(raiz,"archivo1",1);
    archivo * t2 = crearArchivo(raiz,"archivo2",1);
    archivo * f3 = crearArchivo((folder*)f1,"folder1_1",0);
    archivo * f4 = crearArchivo((folder*)f3,"folder1_1_3",0);

    dir();

    archivo * cargar = cargarArchivo(t3->getRuta());
    cout<<cargar->getNombre()<<cargar->getTipo()<<endl;

    eliminarArchivo(t2->getRuta());

    dir();

    copiar(getRaiz(),t1->getNombre(),(folder*)f4);

    dir();

    cortar((folder*)f4,t1->getNombre(),(folder *)f3);

    dir();
}

folder * fileExplorer::getRaiz()
{
    return this->raiz;
}
