#include 'nodo.h'



Nodo *nodo_crear(void *info, size_t size) {
    Nodo *new=(Nodo*)malloc(sizeof(Nodo));
    new->info=malloc(size);
    memcpy(new->info, info, size);
    //Direccion de origen; los bytes a reservar para info
    new->sig=NULL;
    new->ant=NULL;
    return new;
}

void nodo_eliminar(Nodo *n) {
    if(n!=NULL) {
        if(n->sig==NULL && n->ant=NULL) {
            free(n);
        }
    }else {
        printf("El nodo no existe\n");
    }
}
bool nodo_actualizar(Nodo *n, void *info, size_t size) {
    n->info = realloc(n->info, size);
    if(n->info ==NULL) return false;
    memcpy(n->info, info, size);
}
