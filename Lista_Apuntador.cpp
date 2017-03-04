#include "Lista_Apuntador.h"

Lista_Apuntador::Lista_Apuntador()
{
    this->longitud_lista = 0;
    this->Inicio = NULL;
    this->Fin = NULL;
}

void Lista_Apuntador::agregar(archivo * nuevo)
{
    if(longitud_lista==0)
    {
        Inicio=Fin=nuevo;
    }
    else
    {
        Fin->setSig(nuevo);
        nuevo->setAnt(Fin);
        Fin = nuevo;
    }
    longitud_lista+=1;
}

archivo * Lista_Apuntador::obtener(int pos)
{
    archivo * temp = this->Inicio;
    if(!validarPosicion(pos,false))
        return NULL;
    for(int i=0; i<pos; i++)
        temp = temp->getSig();
    return temp;
}

int Lista_Apuntador::buscar(archivo * v)
{
    archivo * temp = this->Inicio;
    for(int i=0; i<getTamano(); i++)
    {
        if(temp!=NULL && temp==v)
            return i;
        temp = temp->getSig();
    }
    return -1;
}

void Lista_Apuntador::eliminar(int pos)
{
    archivo * temp = this->Inicio;
    archivo * eliminarAnt;
    archivo * eliminarSig;
    if(!validarPosicion(pos,false))
        return;
    if(pos==0 && longitud_lista==1)
    {
        Inicio=Fin=NULL;
    }
    else if(pos==0 && longitud_lista>1)
    {
        Inicio = temp->getSig();
        Inicio->setAnt(NULL);
    }
    else if(pos==(longitud_lista-1))
    {
        Fin = Fin->getAnt();
        Fin->setSig(NULL);
    }
    else
    {
        for(int i=0; i<pos; i++)
            temp = temp->getSig();
        eliminarAnt=temp->getAnt();
        eliminarSig=temp->getSig();
        eliminarAnt->setSig(eliminarSig);
        eliminarSig->setAnt(eliminarAnt);
        temp->setAnt(NULL);
        temp->setSig(NULL);
    }
    longitud_lista--;
}

int Lista_Apuntador::getTamano()
{
    return longitud_lista;
}
int Lista_Apuntador::validarPosicion(int pos,bool nPos)
{
    if(pos<0)
        return false;
    if(pos>longitud_lista)
        return false;
    if(pos==longitud_lista && !nPos)
        return false;
    return true;
}
