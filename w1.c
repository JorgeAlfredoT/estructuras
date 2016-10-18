#include<stdio.h>
#include<stdlib.h>

struct nodo{
   int val;
   struct nodo *sgte;
};


void imprimir(struct nodo *);
struct nodo *eliminar(struct nodo *, int);
struct nodo *posicionCualquiera(struct nodo *,int ,int);
void concatenar(struct nodo *, struct nodo *);


int main(){
struct nodo *cabeza,*cur;
cabeza = malloc(sizeof(struct nodo));
cabeza->val = 1;
cur = cabeza;
int e=2;
for(; e<=4; e++){
    struct nodo *newNodo;
    newNodo = malloc(sizeof(struct nodo));
    newNodo->val = e;
    cur->sgte = newNodo;
    cur = newNodo;
 }
 cur->sgte = NULL;

imprimir(cabeza);
cabeza=eliminar(cabeza,2);
imprimir(cabeza);
cabeza=posicionCualquiera(cabeza,1,36);
imprimir(cabeza);

struct nodo *cabeza2,*tr;
cabeza2=malloc(sizeof(struct nodo));
cabeza2->val=1;
tr=cabeza2;
int j=2;
for(;j<=3;j++){
   struct nodo *newNodo;
   newNodo=malloc(sizeof(struct nodo));
   newNodo->val=j;
   tr->sgte=newNodo;
   tr=newNodo;
}
tr->sgte=NULL;

concatenar(cabeza,cabeza2);
imprimir(cabeza);


   return 0;
 }


void imprimir(struct nodo *cabeza){
   struct nodo *temp;
   temp=cabeza;
   while(temp != NULL){
      printf("[%d|*--]-->  ",temp->val);
      temp=temp->sgte;
   }
   printf("NULL\n");
}

struct nodo *eliminar(struct nodo *cabeza, int key){
   struct nodo *prev,*cur;
   prev=cabeza;
   cur=cabeza->sgte;
   while(cur != NULL){
      if (cur->val == key){
         prev->sgte=cur->sgte;
         free(cur);
      }
      prev=cur;
      cur=cur->sgte;
   }
   return cabeza;
}


struct nodo *posicionCualquiera(struct nodo *cabeza,int posicion ,int valor){
   struct nodo *prev,*cur,*nuevo;
   nuevo=malloc(sizeof(struct nodo));
   prev=cabeza;
   cur=cabeza->sgte;
   nuevo->val=valor;

   if(posicion==1){
      nuevo->sgte=prev;
      cabeza=nuevo;
      return cabeza;
   }
   int cont=0;
   while(cont != posicion){
      prev=cur;
      cur=cur->sgte;
   }
   prev->sgte=nuevo;
   nuevo->sgte=cur;
   return cabeza;

}


void concatenar (struct nodo *cabeza1, struct nodo *cabeza2){
   struct nodo *cur;
   cur = cabeza1;
   while(cur->sgte != NULL)
      cur =cur->sgte;
   cur->sgte=cabeza2;
}
