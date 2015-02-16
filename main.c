#include<stdio.h>
#include "Listas.h"

int main()
{
    int elem, i;
    Lista lista;
    vacia(&lista);
    printf("%d\n", esVacia(lista));
    i = 1;
    FILE *fr = fopen("elementos.in", "r");
    while(!feof(fr))
    {
        fscanf(fr,"%d", &elem);
        insertar(&lista, elem, i);
        printf("%d ",consultar(lista, i));
        i++;
    }
    printf("\n");
    printf("introducir la posicion del  elemento a eliminar:\n");
    scanf("%d", &i);
    eliminar(&lista, i);
    Nodo *indice;
    indice = lista.primero;
    imprimirLista(lista);
    destruir(&lista);
    imprimirLista(lista);
    return(0);
}
