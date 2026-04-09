#ifndef _LISTA_SIMPLE_H_
#define _LISTA_SIMPLE_H_
#include "nodo.h"

typedef struct DLista DLista;

struct DLista{
    nodo*head;
    nodo*tail;
}

DLista* Listacrear();
bool liista_es_vacia(DLista *l);

bool lista_insertar_vacia(DLista *l, void *info, size_t size);
bool lista_insertar_inicio(DLista *l, void *info, size_t size);
bool lista_insertar_fin(DLista *l, void *info, size_t size);
bool lista_insertar_x_pos(DLista *l, void *info, size_t size);

#endif
 