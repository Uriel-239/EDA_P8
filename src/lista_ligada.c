#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"
#include "nodo.h"

DLista* lista_crear() {
    DLista *l = (DLista*) malloc(sizeof(DLista));
    if(l != NULL) {
        l->head = l->tail = NULL;
    }
    return l;
}

bool lista_es_vacia(DLista *l) { 
    return (l == NULL || l->head == NULL); 
}


bool lista_insertar_vacia(DLista *l, void *info, size_t size) {
    if(l == NULL) return false;
    
    nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    l->head = l->tail = nuevo;
    nuevo->sig = nuevo->ant = NULL; 
    return true;
}

bool lista_insertar_inicio(DLista *l, void *info, size_t size) {
    if(!l) return false;
    if(lista_es_vacia(l)) return lista_insertar_vacia(l, info, size);

    nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    nuevo->sig = l->head;
    nuevo->ant = NULL;
    l->head->ant = nuevo;
    l->head = nuevo;
    return true;
}

bool lista_insertar_fin(DLista *l, void *info, size_t size) {
    if(!l) return false;
    if(lista_es_vacia(l)) return lista_insertar_vacia(l, info, size);

    nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    nuevo->ant = l->tail;
    nuevo->sig = NULL;
    l->tail->sig = nuevo;
    l->tail = nuevo;
    return true;
}

bool lista_insertar_x_pos(DLista *l, int pos, void *info, size_t size) {
    if(!l) return false;
    
    int n_nodos = lista_num_nodos(l);

    if(lista_es_vacia(l)) return lista_insertar_vacia(l, info, size);
    if(pos <= 0) return lista_insertar_inicio(l, info, size);
    if(pos >= n_nodos) return lista_insertar_fin(l, info, size);
    nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    nodo *tmp = l->head;
    for(int pos_act = 0; pos_act < pos; pos_act++) {
        tmp = tmp->sig;
    }
    nuevo->ant = tmp->ant;
    nuevo->sig = tmp;
    
    if(tmp->ant != NULL) {
        tmp->ant->sig = nuevo;
    }
    tmp->ant = nuevo;

    return true;
}