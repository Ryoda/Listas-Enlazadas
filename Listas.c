#include<stdio.h>
#include<stdlib.h>
#include "Listas.h"

void vacia(Lista *l) //inicializa la lista, valor predeterminado
{
    l->primero = NULL;
    l->longitud = 0;
}

int esVacia(Lista l) //pregunta si la lista esta vacia
{
    return(l.primero == NULL && l.longitud == 0);
}

void insertar(Lista *l, int elem, int pos) //inserta un elemento a la lista en la posicion pos
{
    Nodo *nuevo, *anterior, *siguiente;
    int i;

    if((nuevo = (Nodo *) malloc(sizeof(Nodo))) == NULL)
    {
        printf("Error: malloc termino inesperadamente"); // malloc retorno NULL
    }//Inicializa un nodo

    nuevo->elemento = elem;

    if(pos < 1 || pos > l->longitud + 1)
    {
        printf("Error: Se intento insertar un elemento en una posicion invalida");
    }else
    {
        if(pos == 1)
        {
            nuevo->siguiente = l->primero;
            l->primero = nuevo;
        }else
        {
            anterior = l->primero;
            siguiente = anterior->siguiente;
            for(i = 2; i < pos; i++)
            {
                anterior = siguiente;
                siguiente = siguiente->siguiente;
            }
            anterior->siguiente = nuevo;
            nuevo->siguiente = siguiente;
        }
        l->longitud = l->longitud + 1;
    }
}

void eliminar(Lista *l, int pos) //elimina un elemento de la lista en la posicion pos
{
    Nodo *anterior, *actual, *siguiente;
    int i;
    if(pos < 1 || pos > l->longitud + 1)
    {
        printf("Error: se inteto eliminar un elemento de la lista en una posicion invalida");
    }else
    {
        if(pos == 1)
        {
            actual = l->primero;
            l->primero = actual->siguiente;
            free(actual);
        }else
        {
            actual = l->primero;
            siguiente = actual->siguiente;
            for(i = 2; i < pos; i++)
            {
                anterior = actual;
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
            anterior->siguiente = siguiente;
            free(actual);
        }
       l->longitud = l->longitud - 1;
    }

}

int consultar(Lista l, int pos) //consulta el valor del elemento en una posicion de la lista
{
    Nodo *actual;
    int i, salida;
    if(pos < 1 || pos > l.longitud + 1)
    {
         salida = -1;
    }else
    {
        if(pos == 1)
        {
            actual = l.primero;
        }else
        {
            actual = l.primero;
            for(i = 2; i <= pos; i++)
            {
                actual = actual->siguiente;
            }
        }
        salida = (actual->elemento);
    }
    return(salida);
}

int longitud(Lista l) //retorna la longitud de la lista
{
    return(l.longitud);
}

void destruir(Lista *l) // destruye la lista, liberando todo el espacio reservado en memoria por los nodos
{
    Nodo *actual;

    actual = l->primero;

    while(actual != NULL)
    {
        l->primero = l->primero->siguiente;
        free(actual);
        actual = l->primero;
    }
}
