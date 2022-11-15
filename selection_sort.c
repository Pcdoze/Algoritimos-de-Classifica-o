#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int len;
    int * pos;
} Lista;

typedef Lista * p_lista;

// lista
p_lista criarlista();
int fromarr();
int apagarlista();
int mostrarlista();

// selection sort
int sort();
int proximoindice();

int main ()
{
    int arr[] = {1, 5, 3, 7, 8, 6, 4, 2, 9, 10};

    p_lista lista = criarlista(sizeof(arr)/sizeof(arr[0]));
    fromarr(lista, arr);

    sort(lista);
    mostrarlista(lista);

    apagarlista(lista);
    return 0;
}


p_lista criarlista(int len)
{
    p_lista lista = (p_lista) malloc(len * sizeof(Lista));
    lista->len = len;

    return lista;
}
int fromarr(p_lista lista, int * arr)
{
    lista->pos = (int *) malloc(lista->len * sizeof(int));

    for(int i = 0; i < lista->len; i++)
    {
        lista->pos[i] = arr[i];
    }

    return 1;
}
int apagarlista(p_lista lista)
{
    for(int i = 0; i < lista->len; i++)
    {
        lista->pos[i] = 0;
    }
    lista->len = 0;

    free(lista->pos);
    free(lista);

    return 1;
}
int mostrarlista(p_lista lista)
{
    for(int i = 0; i < lista->len; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", lista->pos[i]);
    }
    printf("\n");

    return 1;
}


int sort(p_lista lista)
{
    printf("\nordenando lista...\n\n1: ");
    mostrarlista(lista);

    proximoindice(0, lista, 1);

    return 1;
}
int proximoindice(int indice, p_lista lista, int mostrar)
{
    if(indice < lista->len)
    {
        int min = indice;

        for(int i = indice; i < lista->len; i++)
        {
            if(lista->pos[i] < lista->pos[min])
                min = i;
        }


        int _temp = lista->pos[indice];

        lista->pos[indice] = lista->pos[min];
        lista->pos[min] = _temp;

        if(mostrar)
        {
            printf("%d: ", indice+2);
            mostrarlista(lista);
        }

        proximoindice(indice+1, lista, mostrar);
    }
    else
    {
        if(mostrar) printf("\nlista ordenada.\n");
    }

    return 1;
}
