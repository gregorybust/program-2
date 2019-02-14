struct lista { /* lista que contiene los contactos de un numero de telefon */
   char contacto[20];
   lista *prox ;
   lista3*continua;
};

lista * crear( char  x[20]){
    lista *p = new lista;
    strcpy(p->contacto,x);
    p->prox = NULL;
    p->continua=NULL;
    return p;
}



void agregar( lista **p, char x[20]) {
       /* Agrega x a la lista p por cabeza */
    lista *aux = crear(x);
    aux->prox= *p;
    *p= aux;
	
}
void agregar_cola(lista**p, char x[20] )
{
  lista* aux=*p;
  if (aux==NULL)
     *p=crear(x);
  else
  {
     
    while ((aux->prox) && (strcmp(aux->contacto,x)!=0))
    {
   
       aux=aux->prox;
    }
      if ((aux->prox==NULL) && (strcmp(aux->contacto,x)!=0))
     {
       lista* tem= new lista;
      
       strcpy(tem->contacto,x);
       tem->prox=NULL;
       tem->continua=NULL;
       aux->prox=tem;
     }
   
  } 
}       

void mostrar ( lista *p){
    lista * t= p;
    printf("\n\n");
    while (t){
       printf(" [%s]",t->contacto);
       t=t->prox;
     }
     printf(" NULL\n\n");
}

int buscar (lista *p, char x[20]){
   lista *aux= p;
    int milagro;
    milagro=1;  
   while (      (aux)  ){
    if (strcmp (aux->contacto , x)==0){
      aux=NULL;
      milagro=0;
    }
    else	
     aux= aux->prox;	
   }
  
   if (milagro==0)
     return 1;
    else
      return 0;  
       
}

void eliminar( lista **p, char x[20]){
   lista *aux= *p;
    if (*p)
       
        if  ( strcmp( (*p)->contacto,x )==0) {
           *p= (*p)->prox;
          delete aux ;
        }
       else {
         while ((aux->prox) &&   (strcmp (aux->prox->contacto , x)!=0 )  ) aux= aux->prox;
           if (aux->prox){
               lista *temp= aux->prox;
               aux->prox= aux->prox->prox;
               delete temp;
               printf("\n\n Valor %s ELIMINADO \n\n",x);
            }
           else
             printf("\n\n Valor %s NO ENCONTRADO!!! \n\n",x);
       }
} 

