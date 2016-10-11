#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int val;
    struct nodo *siguiente;
};

void agregar(struct nodo *, int);
void imprimir(struct nodo *);
void eliminar(struct nodo *, int);

int main()
{   
    struct nodo *cabeza = malloc(sizeof(struct nodo));
    cabeza->val = 1;
    struct nodo *cur = cabeza;   
	int i; 
    for(i = 2; i<=4; i++){      
        struct nodo *newNodo = malloc(sizeof(struct nodo));
        newNodo-> val = i;
        cur-> siguiente = newNodo;
        cur = newNodo;
    }
    cur-> siguiente = NULL;
    
    imprimir(cabeza);    
    agregar(cur,5);
    imprimir(cabeza);
    eliminar(cabeza,3);
    imprimir(cabeza);
    
    return 0;
}

void agregar(struct nodo *cur, int n)
{
    struct nodo *newNodo = malloc(sizeof(struct nodo));
    newNodo-> val = n;
    newNodo-> siguiente = NULL;
    cur->siguiente = newNodo;  
}

void imprimir(struct nodo *cabeza)
{
    struct nodo *cur = cabeza;
	while(cur != NULL){
        printf("%d   ", cur->val);
		cur = cur -> siguiente;
	}
    printf("\n");
}


void eliminar(struct nodo *cabeza, int key)
{
    struct nodo *prev = cabeza;
    struct nodo *cur = cabeza->siguiente;
    while(cur != NULL){
		if (cur->val == key){
			prev->siguiente = cur-> siguiente;
			free(cur);
			break;
		}
		prev = cur;
		cur = cur -> siguiente;

    }

}

