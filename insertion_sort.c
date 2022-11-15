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
int adicionar();
int removerindice();
int mostrarlista();

// selection sort
int sort();
int proximovalor();
int retirarmenor();

int main ()
{
    int arr[] = {1, 5, 3, 7, 8, 6, 4, 2, 9, 10};

    p_lista lista = criarlista(sizeof(arr)/sizeof(arr[0]));
    p_lista lista_ordenada = criarlista(0);

    fromarr(lista, arr);

    sort(lista_ordenada, lista);
    mostrarlista(lista);

    apagarlista(lista);
    apagarlista(lista_ordenada);

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
int adicionar(p_lista lista, int valor)
{
    realloc(lista->pos, (lista->len+1) * sizeof(int)); lista->len++;
    lista->pos[lista->len-1] = valor;

    return 1;
}
int removerindice(p_lista lista, int indice)
{
    for(int i = indice; i < lista->len; i++)
    {
        lista->pos[i] = lista->pos[i+1];
    }
    lista->len--;

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


int sort(p_lista lista_ordenada, p_lista lista)
{
    printf("\nordenando lista...\n\nlista 1: ");
    mostrarlista(lista);

    proximovalor(lista_ordenada, lista, 1);

    return 1;
}
int proximovalor(p_lista lista_ordenada, p_lista lista, int mostrar)
{
    if(lista->len > 0)
    {
        adicionar(lista_ordenada, retirarmenor(lista));

        if(mostrar)
        {
            printf("\nlista 1: ");
            mostrarlista(lista);
            printf("lista 2: ");
            mostrarlista(lista_ordenada);
        }

        proximovalor(lista_ordenada, lista, mostrar);
    }

    return 1;
}
int retirarmenor(p_lista lista)
{
    int menor = -1;
    int valor;

    for(int i = 0; i < lista->len; i++)
    {
        if(i == 0)
        {
            menor = 0;
        }

        if(lista->pos[i] < lista->pos[menor])
        {
            menor = i;
        }

    }

    if(menor > -1)
    {
        valor = lista->pos[menor];

        removerindice(lista, menor);

        return valor;
    }

    return 0;
}
