#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
/* Libreria de Listas enlazadas en C */
typedef struct NodoLista
{
    int elemento;
    struct NodoLista *siguiente;
}Nodo;

typedef struct
{
    Nodo *primero;
    int longitud;
}Lista;

void vacia(Lista *l); //crea una lista vacia
int esVacia(Lista l); //pregunta si la lista esta vacia
void insertar(Lista *l, int elem, int pos); // inserta un elemento en una posicion de la lista
void eliminar(Lista *l, int pos); //elimina un elemento en la posicion de la lista
int consultar(Lista l, int pos); // consulta un elemento en la posicion de la lista
int longitud(Lista l); // retorna la longitud de la lista
void destruir(Lista *l); // destruye la lista, liberando todo el espacio reservado para los nodos
void imprimirLista(Lista l);

#endif // LISTAS_H_INCLUDED
