#include 'lista_ligada.h'
#include 'nodo.h'

DLista* lista_crear(){
    DLista * l = (DLista*) malloc (sizeof(DLista));
    if(l != NULL){
        l -> head = l -> tail = NULL;
    }
    return l;
}



int esVacia(DLista* l) { return (l == NULL || l->head == NULL); }

static Nodo* crearNodo(void* dato, size_t size) {
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    n->dato = malloc(size);
    memcpy(n->dato, dato, size);
    n->siguiente = NULL;
    return n;
}




bool lista_insertar_vacia(DLista *l, void * info, size_t size){
    if(l == NULL){
        return false;
    }
    Nodo *n = nodo_crear(info, size);
    l -> head = l -> tail = n;
    return true;
}

bool lista_insertar_inicio(DLista *l, void * info, size_t size){
    if(l == NULL){
        return false;
    }
    Nodo *n = nodo_crear(info, size);
    nuevo -> sig = l -> head;
    l -> head -> ant = nuevo;
    l -> head = nuevo; 
    return true;
}

bool lista_insertar_fin(DLista *l, void * info, size_t size){
    if(l == NULL){
        return false;
    }
    Nodo *n = nodo_crear(info, size);
    nuevo -> sig = l -> tail;
    l -> tail -> sig = nuevo;
    l -> tail = nuevo; 
    return true;
}

bool lista_insertar_fin(DLista *l, int pos * info, size_t size){
    if(!l) return false;
    if(DLista_es_vacia(l))return lista_insertar_vacia(l, info, size);
}

