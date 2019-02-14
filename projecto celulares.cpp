#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nueva_lista_2.h"
#include "nueva_lista.h"
struct lista2{    /* lista que contiene los datos del dueño del telefono */
     char telefono[40];
     char cedula[40];
     char pais[40];
     char operador[40];
     char formato[40];
     char direccion[100];
     char nombre [100];
     lista2*sig;
     lista*prox;
};
lista2 * crear_lista2(char x[40], char a[100] , char b[100] ,char c[40] ,char d[40],char e[40],char f[40]){
    lista2 *p2 = new lista2;   // asigna los datos  correspondientes a cada campo en la lista de celulares
    strcpy(p2->nombre,a);
    strcpy(p2->direccion,b);
    strcpy(p2->telefono,x);
    strcpy(p2->cedula,c); 
    strcpy(p2->pais,d); 
    strcpy(p2->operador,e);
    strcpy(p2->formato,f); 
    p2->prox = NULL;
    p2->sig=NULL;
    return p2;
}
void agregar_cola_lista2(lista2**p2,char x[40] , char a[100] , char b[100] , char c[40] ,char d[40],char e[40],char f[40] ) 
{                              /* agrega por cola los datos del dueño de un telefono */
  lista2* aux=*p2;
  lista2*aux1=*p2;
  if (aux==NULL)
   *p2=crear_lista2( x,a,b,c,d,e,f);
  else
  {                          
       while ((aux->sig) && (strcmp(aux->telefono,x)!=0))
    {
      aux=aux->sig;
    }                         
      if ((aux->sig==NULL) && (strcmp(aux->telefono,x)!=0) )
     {
       lista2* tem= new lista2;
       strcpy(tem->telefono,x);
       strcpy(tem->nombre,a);
       strcpy(tem->direccion,b);
       strcpy(tem->cedula,c);
       strcpy(tem->pais,d);
       strcpy(tem->operador,e);
       strcpy(tem->formato,f);
       tem->prox = NULL;     
       tem->sig=NULL;
       aux->sig=tem;
     }
  } 
}   
void mostrar_lista2 ( lista2 *p2){  /* muestra los datos del dueño de un telefono */
    lista2 * t= p2;
    printf("\n\n");
    if (t==NULL)
       printf("  LA  LISTA ESTA VACIA  \n\n");
    while (t){
        printf( " NUMERO DE CELULAR = ");
        printf(" [%s]",t->telefono);
        printf("\n");
        printf( " NOMBRE COMPLETO = ");
        printf(" [%s]",t->nombre);
        printf("\n");
        printf( " DIRRECCION DE HABITACION  = ");
        printf(" [%s]",t->direccion);
        printf("\n");
        printf( " NUMERO DE CEDULA  = ");
        printf(" [%s]",t->cedula);
        printf("\n");
        printf( " CODIGO DEL PAIS = ");
        printf(" [%s]",t->pais);
        printf("\n");
        printf( " CODIGO DEL OPERADOR = ");
        printf(" [%s]",t->operador);
        printf("\n");
        printf( " CODIGO DEL FORMATO = ");
        printf(" [%s]",t->formato);
        printf("\n");
        t=t->sig;
        printf("\n");
        printf("\n");
    }
}
void eliminar_lista2( lista2 **p2,char x[40]){
    lista2 *aux= *p2;
    if (*p2)
      if (strcmp((*p2)->telefono,x)==0) {
         /* x es el valor cabeza de lista */
          *p2= (*p2)->sig;
       delete aux ; }
      else {
         /* se busca delante de aux para poder enlazar lo que esta antes de x con 
         lo que esta despues de x */
           while ((aux->sig) &&  (strcmp(aux->sig->telefono,x)!=0)) aux= aux->sig;
              if (aux->sig){
                     /* x se encuentra en la lista y no es el primer elemento */
                lista2 *temp= aux->sig;
                aux->sig= aux->sig->sig;
                delete temp;
                printf("\n\n Valor %i ELIMINADO \n\n",x);
              }
            else
              printf("\n\n Valor %i NO ENCONTRADO!!! \n\n",x);
      }
}
int buscar_lista2 (lista2 *p2,char x[40]){ /* busca un numero celular de la lista principal */
        lista2 *aux= p2;
       while ((aux) &&  (strcmp(aux->telefono,x)!=0) ) aux= aux->sig;
          return ( aux!=NULL );
}
void agregar_se_pri(lista2*p2,lista**p,char j[40],char po[20])  /* agrega contactos a un celular */
{
      lista2*aux2=p2;
      lista*aux1=*p;
  if(aux2){  
         while (strcmp(j,aux2->telefono)!=0)  
      {
        aux2=aux2->sig;
      }
     agregar_cola(&(aux2->prox),po);
    }
  else
    printf( " EL NUMERO DE TELEFONO NO EXISTE \n\n");
}
void mostrar_pri_se(lista2*p2, lista*p,char a[40]) /* muestra los contactos de un  numero celular */
{
     lista2*aux2=p2;
     lista*aux=p;
   if (aux2)  
     while (strcmp(a,aux2->telefono)!=0)
     {
            aux2=aux2->sig;
     }
        if (aux2)
            aux=aux2->prox;
        if (aux==NULL)
         printf(" NUMERO EQUIVOCADO \n\n");
        while (aux)
         {
            printf(" [%s]",aux->contacto);
            printf("\n");
            aux=aux->prox;
         }
}
void eliminar_pri_se(lista2**p2, lista**p,char a[40], char b[20])
{
      lista2*aux2=*p2;
      lista*aux=*p;
      while (strcmp(a,aux2->telefono)!=0)
      {
          aux2=aux2->sig;
      }
         eliminar(&(aux2->prox),b);
}
 int buscar_pri_se(lista2*p2,lista*p,char a[40], char b[20]) /* busca un contacto y dice si esta o no*/
{
    lista *aux1= p;
    lista2*aux2=p2;
  if (p2 ){ 
    
    while ((aux2) &&  (strcmp(aux2->telefono,a)!=0) ) aux2= aux2->sig;
        if (aux2->prox){
     
            if (buscar (aux2->prox, b))
              return 1;
           else
            return 0;
        } 
     }
  else
    printf("\n NUMERO EQUIVOCADO \n\n");
 return 0;
}
void agregar_se_ter(lista*p,lista2*p2,lista3**p3,char x[40],char b[20],char yu[40],char so[40]){ /* agrega  numeros telefonicos a un contacto*/
  lista*aux=p;
  lista2*aux2=p2;
  lista3*aux3=*p3;
 if (aux2){

   while (strcmp(x,aux2->telefono)!=0)
      {
        aux2=aux2->sig;
      }
       aux=aux2->prox;
   }
 if (aux){   
  while (strcmp (aux->contacto , b)!=0 ) 
   {
      aux=aux->prox;	
   }
 }
  
   if (aux){
       if  (strcmp (aux->contacto , b)==0 ) {
         agregar_cola_ter(&(aux->continua), so, yu);
       }
   }
   else
     printf("\n NUMERO O CONTACTO EQUIVOCADO \n\n");
}
  void mostrar_se_ter(lista*p,lista2*p2,lista3*p3,char x[40], char b[20] ) /* muestra los numeros telefonicos asociados a un contacto*/
  { lista*aux=p;
    lista2*aux2=p2;
    lista3*aux3=p3;
    
    while( (aux2) && (strcmp(aux2->telefono,x)!=0))
    {
       aux2=aux2->sig;	
    }
      if (aux2)
      aux=aux2->prox;
   while ( (aux) &&  ((strcmp(aux->contacto , b)!=0 ) )     )
    {
       aux=aux->prox;	
    }
    if (aux){
          if  (strcmp (aux->contacto , b)==0 )
               mostrar_ter( aux->continua);
     }
      else
         if (aux==NULL){ 
             printf("\n");
             printf(" ERROR NUMERO O CONTACTO  EQUIVOCADO  \n\n");
         }
  } 
  void elimina_se_ter(lista3**p3,lista2*p2,lista*p,char x[40], char y[20],char z[40]){
    lista*aux=p;
    lista2*aux2=p2;
    lista3*aux3=*p3;
     
    while( (aux2) &&  (strcmp (aux2->telefono,x)!=0 ) )
    {
       aux2=aux2->sig;	
    }
    aux=aux2->prox;
    while ( (aux) &&  ((strcmp (aux->contacto , y)!=0 ) )   )
    {
     aux=aux->prox;	
    }
    if (strcmp (aux->contacto , y)==0 ) 
      elimina_ter(&( aux->continua), z); 
   	
   }
    void  buscar_sospechoso(lista2*p2,char nom[20] ){
     lista2*aux2=p2; /* dado un nombre , ubica la cedula y con esta ubica sus numeros personales */
     lista2*apoyo=p2; 
     lista2*aux21=p2;
     int cont;
     cont=0;
     char ko[40];
     
     char ya[40];
    
     char voy[40];
     
       if (aux2==NULL)
          printf("\n ERROR NOMBRE EQUIVOCADO \n\n" );
     while (aux2){
       if ( strcmp(aux2->nombre,nom)==0){
             printf("\n SU CEDULA ES = ");
           	
                    printf(" [%s]",aux2->cedula);
                    printf("\n");
                    cont++;
             if (cont==1)
               strcpy(voy,aux2->cedula); 
            //   voy=aux2->cedula;
             printf("\n");	
        }
        aux2=aux2->sig;
     }
     if (cont>1){  // caso en que el nombre dado esta asociado a mas de una cedula 
       printf(" DIGA CUAL DE LAS CEDULAS QUE SE MUESTRAN ES LA QUE LE INTERESA \n");
        scanf("%s",voy);
            fflush(stdin);
        printf(" SU O SUS TELEFONOS SON :  ");
         printf("\n");
            while (apoyo){
                	
                 if (strcmp(apoyo->cedula,voy)==0){
                 	 printf("\n");
                    printf(" [%s] ",apoyo->telefono);
                     printf("\n");
                 }	
              apoyo=apoyo->sig;
             }
     }
     else  // caso en el que el nombre dado corresponde a una cedula
        if (cont==1){
         printf(" SU O SUS TELEFONOS SON :  ");
          printf("\n");
            while (apoyo){
                  printf("\n");
                 if (strcmp(apoyo->cedula,voy)==0) {
                     printf(" [%s] ",apoyo->telefono);
                     
                     printf("\n");
                 }	
              apoyo=apoyo->sig;
              printf("\n");
             }
         }
    }
void dos_sospechosos_ter(lista3*p31,lista3*p32,char a[40],char b[40], char c[20], char d[20])  {
  lista3*aux31=p31;  // muestra los telefonos y alias que tienen en comun 
  lista3*aux32=p32; 
  while(aux32){
       while (aux31){
       	
         if (strcmp(aux31->contacto_telefono,aux32->contacto_telefono)==0)  {
             printf(" AMBOS TIENEN REGISTRADO COMO CONTACTO EL SIGUIENTE NUMERO \n");
             printf("[%s]",aux31->contacto_telefono);
             printf("\n");
             printf("\n");
             printf(" EL PRIMER NUMERO : "); 
             printf("[%s]",a);
             printf("\n");
             printf(" CON EL NOMBRE DE : ");
             printf("[%s]",c);
             printf("\n");
             printf("\n");
             printf(" EL SEGUNDO NUMERO : "); 
             printf("[%s]",b);
              printf("\n");
             printf(" CON EL NOMBRE DE : ");
             printf("[%s]",d);
             printf("\n");
          }
         aux31=aux31->continua;
         printf("\n");
       }
      aux31=p31;
      aux32=aux32->continua;
   }
}
void dos_sospechosos(lista*p,lista2*p2,lista3*p3,char al_1[40],char al_2[40]){
  lista*aux=p;     // dados dos numeros de telefonos, busca los contactos que tienen en comun  
  lista*apoyo=p;
  lista*aux_apoyo=p;
  lista2*aux2=p2;
  lista2*apoyo2=p2;
  lista3*aux3=p3;
  lista3*apoyo3=p3;
 
    while( (aux2)&&(strcmp(aux2->telefono,al_1)!=0)){
     aux2=aux2->sig;
     }
     aux=aux2->prox;
     aux_apoyo=aux2->prox;
  
     while ((apoyo2)&&(strcmp(apoyo2->telefono,al_2)!=0)){
       apoyo2=apoyo2->sig;	
     }
     apoyo=apoyo2->prox;
     while (apoyo){
          while (aux){
              dos_sospechosos_ter(aux->continua,apoyo->continua, al_1,al_2,aux->contacto,apoyo->contacto);	
              aux=aux->prox;	
           }
           apoyo=apoyo->prox;
           aux=aux_apoyo;
          
      
      }
}
void listar_datos ( lista2 *p2){
    lista2 * t= p2;  // muestra el numero de telefono del dueño y los datos del dueño 
    printf("\n\n");
    if (t==NULL)
       printf("  LA  LISTA ESTA VACIA  \n\n");
   else{
        printf( " NUMERO DE CELULAR = ");
        printf(" [%s]",t->telefono);
        printf("\n");
        printf( " NOMBRE COMPLETO = ");
        printf(" [%s]",t->nombre);
        printf("\n");
        printf( " DIRRECCION DE HABITACION  = ");
        printf(" [%s]",t->direccion);
        printf("\n");
        printf( " NUMERO DE CEDULA  = ");
        printf(" [%s]",t->cedula);
        printf("\n");
        printf( " CODIGO DEL PAIS = ");
        printf(" [%s]",t->pais);
        printf("\n");
        printf( " CODIGO DEL OPERADOR = ");
        printf(" [%s]",t->operador);
        printf("\n");
        printf( " CODIGO DEL FORMATO = ");
        printf(" [%s]",t->formato);
        printf("\n");
        printf("\n");
        printf("\n");
    }
}
void bus_ali_listar(lista*p,lista2*p2,char a[20]){
   lista*aux=p; // busca en todas las listas de contactos  el alias dado
   lista*poyo=p;
   lista2*aux2=p2;
   while (aux2){
     aux=aux2->prox;
     while (aux){
        if ( strcmp(aux->contacto,a)==0){  // si encuentra el alias 
          listar_datos(aux2);
          printf("\n\n");	
        }
        aux=aux->prox;
     }
     aux2=aux2->sig;
   }	
}
void nueva_busqueda_telefono_ter(lista*p,lista2*p2,lista3*p3,char x[40]){
 lista*aux=p;      // dado un numero busca los numeros de telefono que tienen ese numero como contacto registrado
 lista2*aux2=p2;
 lista3*aux3=p3;
 aux=aux2->prox;
 aux3=aux->continua;
   while (aux2){

      while (aux){
    
          while (aux3){
              	
             if (strcmp(aux3->contacto_telefono,x)==0) {
                  	
                  listar_datos ( aux2);  // si encuentra el numero buscado	
              }
             aux3=aux3->continua;	
         }
           aux=aux->prox;
        if (aux)   
         aux3=aux->continua;
       
      }
      aux2=aux2->sig;
      if (aux2)
      aux=aux2->prox;
      if (aux)
      aux3=aux->continua;
   } 	
}
int existe_contatos(lista2*p2,lista*p,char a[40]){
   lista2*aux2=p2;
   lista*aux=p;
   if (aux2)
    
     while   (strcmp(aux2->telefono,a)!=0){
        aux2=aux2->sig;	
     }
   if (aux2)  
     aux=aux2->prox;
   if (aux)
     return 1;
   else
      return 0; 	
}
int existe_numero_de_contacto(lista3*p3,lista2*p2,lista*p,char a[40],char b[20]){
  lista2*aux2=p2;
  lista3*aux3=p3;
  lista*aux=p;
 
  while (strcmp(aux2->telefono,a)!=0){
    aux2=aux2->sig;	
  }
 if (aux2) 
  aux=aux2->prox;
  while  ( strcmp(aux->contacto,b)!=0){
    aux=aux->prox;	
  }
  if (aux)
   aux3=aux->continua;
  if (aux3)
   return 1;
  else
    return 0; 
}
int existe_contatos_general(lista2*p2,lista*p){
   lista2*aux2=p2;
   lista*aux=p;
  while (aux2){
    aux=aux2->prox;
      if (aux)
        return 1;
    aux2=aux2->sig;    
  }
  return 0; 	
}
int existe_numero_de_contacto_general(lista3*p3,lista2*p2,lista*p){
  lista2*aux2=p2;
  lista3*aux3=p3;
  lista*aux=p;
  while (aux2){
    aux=aux2->prox;
       if (aux)
         while (aux){
           aux3=aux->continua;
              if (aux3)
                 return 1;
           aux=aux->prox;      	
         }
            
    aux2=aux2->sig;   	
  }
  return 0;
  
}
void nuevo_mega_elimina_se(lista**p,lista2**p2,lista3**p3,char x[40], char y[20]){
   lista*aux=*p;
   lista*apoyo=*p;
   lista2*aux2=*p2;
   lista2*apoyo2=*p2;
   lista3*aux3=*p3;
   lista3*apoyo3=*p3;
   
   while  (strcmp(x,aux2->telefono)!=0){
     aux2=aux2->sig;	
   }
  
   aux=aux2->prox;
  
   while  (strcmp (aux->contacto ,y)!=0 ){
      
         aux=aux->prox;
       
    }
    
    aux3=aux->continua;
    while (aux3){
      apoyo3=aux3;
      aux3=aux3->continua;
      elimina_ter( &(aux->continua),apoyo3->contacto_telefono);	
    }
   eliminar( &(aux2->prox),y);
    	
}

void mega_elimina(lista**p,lista2**p2,lista3**p3,char x[40]){
   lista*aux=*p;
   lista*apoyo=*p;
   lista2*aux2=*p2;
   lista2*apoyo2=*p2;
   lista3*aux3=*p3;
   lista3*apoyo3=*p3;
    
   while (strcmp(x,aux2->telefono)!=0) {
     aux2=aux2->sig;	
   }
   aux=aux2->prox;
   while (aux){
     aux3=aux->continua;
     
        while (aux3){
            apoyo3=aux3;
            aux3=aux3->continua;	
            elimina_ter(&(aux->continua),apoyo3->contacto_telefono); 
            
        }
         apoyo=aux;
         aux=aux->prox;
        eliminar( &(aux2->prox),apoyo->contacto);
    }
    eliminar_lista2(&(*p2),x);
    	
}
 int buscar_se_ter(lista*p,lista2*p2,lista3*p3,char x[40], char b[20],char c[40]) /* muestra los numeros telefonicos asociados a un contacto*/
  { lista*aux=p;
    lista2*aux2=p2;
    lista3*aux3=p3;
    
    while( (aux2) && (strcmp(aux2->telefono,x)!=0))
    {
       aux2=aux2->sig;	
    }
      if (aux2)
      aux=aux2->prox;
   while ( (aux) &&  ((strcmp(aux->contacto , b)!=0 ) )     )
    {
       aux=aux->prox;	
    }
    
          if  (strcmp (aux->contacto , b)==0 ){
          
               if  (buscar_ter (aux->continua,c));
                     return 1;
               
         }
     
    return 0;
  } 
int main(){
      FILE*nuevo_celular;
      FILE*nuevo_contactos;
      FILE*nuevo_numero_telefono;	
     char n[40];	
      int op=-1;
      lista *p = NULL;  // apuntador a la lista de contactos
      lista2*p2=NULL; // apuntaador a la lista de telefonos
      lista3*p3=NULL; // apuntador a lista de numeros telefonicos asociados a un contacto
   char a1[60];
   strcpy(a1,"0");
   char a2[60];
   strcpy(a2,"0");
   char a3[60];
   strcpy(a3,"0");
   char a4[60];
   strcpy(a4,"0");
   char a5[60];
   strcpy(a5,"0");
   char a6[60];
   strcpy(a6,"0");
   char a7[60];
   strcpy(a7,"0");
   nuevo_celular= fopen( "nuevo_dispositivo.txt", "r" ); 
   if (nuevo_celular!=NULL){
     while (feof(nuevo_celular)==0){
          fscanf(nuevo_celular,"%s\n",a1);
          fscanf(nuevo_celular,"%[^\n]\n",a2);
          fscanf(nuevo_celular,"%[^\n]\n",a3);
          fscanf(nuevo_celular,"%s\n",a4);
          fscanf(nuevo_celular,"%s\n",a5);
          fscanf(nuevo_celular,"%s\n",a6);
          fscanf(nuevo_celular,"%s\n",a7);
            if (strcmp(a2,"0")!=0)            // ESTO EN CASO DE QUE EL ARCHIVO EXISTA PERO ESTA VACIO
            agregar_cola_lista2(&(p2),a1,a2,a3,a4,a5,a6,a7);
    }
     fclose(nuevo_celular);
    }
     char b1[60];	 
     strcpy(b1,"0");
     char b2[60];
     strcpy(b2,"0");
     nuevo_contactos=fopen("nuevo_alias.txt","r");
     if (nuevo_contactos!=NULL){
     while (feof(nuevo_contactos)==0){
        fscanf(nuevo_contactos,"%s\n",b1);
        fscanf(nuevo_contactos,"%[^\n]\n",b2);
         if (strcmp(b1,"0")!=0)    // ESTO EN CASO DE QUE EL ARCHIVO EXISTA PERO ESTA VACIO
           agregar_se_pri(p2,&p,b1,b2);
          }
      fclose(nuevo_contactos);
     }
      char c1[60];
      strcpy(c1,"0");
      char c2[60];
      strcpy(c2,"0");
      char c3[60];
      strcpy(c3,"0");
      char c4[60];
      strcpy(c4,"0");
      nuevo_numero_telefono=fopen("nuevo_telefono_ali.txt","r");
      if (nuevo_numero_telefono!=NULL){
      while (feof(nuevo_numero_telefono)==0){
          fscanf(nuevo_numero_telefono,"%s\n",c1);
          fscanf(nuevo_numero_telefono,"%[^\n]",c2);
          fscanf(nuevo_numero_telefono,"%s\n",c3);
          fscanf(nuevo_numero_telefono,"%s\n",c4);
        if (strcmp(c2,"0")!=0)     // ESTO EN CASO DE QUE EL ARCHIVO EXISTA PERO ESTA VACIO
            agregar_se_ter(p,p2,&p3,c1,c2,c3,c4); 
         }
          fclose(nuevo_numero_telefono); 
       }
       while (1==1) {
         system("cls");
          printf( "\n\n        Menu Principal \n\n   1. AGREGAR UN DATOS DEL CELULAR \n\n");
         printf( "   2. MOSTRAR DATOS DEL CELULAR \n\n");
         printf( "   3. ELIMINAR DATOS DE UNA  PERSONA DE LA LISTA DE CELULARES  \n \n");
         printf( "   4. BUSCAR UN CELULAR  \n\n");
         printf( "   5. AGREGAR UN CONTACTO A UN CELULAR \n\n");
         printf( "   6. MOSTRAR CONTACTOS DE UN CELULAR  \n\n");
         printf( "   7. ELIMINAR UN CONTACTO DE UN CELULAR   \n\n");
         printf( "   8. VER SI SE ENCUENTRA UN CONTACTO EN UN CELULAR   \n\n");
         printf( "   9. AGREGAR UN NUMERO CELULAR A UN CONTACTO  \n\n");
         printf( "   10. VER LA LISTA DE LOS NUMEROS TELEFONICOS ASOCIADOS A UN CONTACTO \n\n");
         printf( "   11. ELIMINAR UN NUMERO TELEFONICO DE LA LISTA DE LOS CONTACTOS\n\n");
         printf( "   11.1  VER SI ENCUENTRA EL NUMERO TELEFONICO DE UN CONTACTO \n\n");
         printf("          CONSULTAS PEDIDAS EN EL PROYECTO:  \n\n");     
         printf( "   12. UBICAR LA CEDULA Y  TELEFONOS PERSONALES DE UN SOSPECHOSO , POR NOMBRE \n\n");
         printf( "   13. LISTAR CONTACTOS CON CADA UNO DE SUS TELEFONOS \n\n");
         printf( "   14. LISTAR LOS NUMEROS DE TELEFONO Y DATOS DEL TITULAR  \n\n");
         printf( "   15. BUSCAR CONTACTOS (TELEFONOS Y ALIAS) QUE TIENEN EN COMUN DOS SOPECHOSOS \n\n ");
         printf( "   16. DADADO UN ALIAS LISTAR (NUMEROS TELEFONICOS, DATOS DEL DUEÑO) DONDE ESTE \n\n"); 
         printf( "    0. Salir\n\n Marque opcion => ");
        scanf( "%i", &op);
        system("cls");
        switch (op){
           case 1:
                 nuevo_celular= fopen( "nuevo_dispositivo.txt", "a" ); 
                 
                 printf( "\n\n    1. Agregar datos del celular  \n\n");
                 char lu[40];
                 printf(" NUMERO DE CELULAR  = ");
                 scanf("%s",lu);
			     fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",lu);
                 char ba[100];
                 printf( " NOMBRE COMPLETO = ");
                 scanf("%[^\n]",ba);
                 fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",ba);
                 char ca[100];
                 printf( " DIRECCION DE HABITACION  = ");
                 scanf("%[^\n]",ca);
                 fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",ca);
                 char a[40];
                 
                 printf( " CEDULA DE IDENTIDAD = ");
                 scanf("%s",a);
                 fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",a);
                 char b[40];
                 
                 printf( " CODIGO DEL PAIS = " );
                 scanf("%s",b);
                 fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",b);
                 char c[40];
                 
                 printf( " CODIGO DEL OPERADOR = " );
                 scanf("%s",c);
                 fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",c);
                 char d[40];
                 printf( " CODIGO DEL FORMATO =");     
                 scanf("%s",d);
                 fflush(stdin);
                 fprintf(nuevo_celular,"%s\n",d);
                 agregar_cola_lista2(&p2,lu,ba,ca,a,b,c,d);
                 fclose(nuevo_celular);
                 printf("\n\n  Valor agregado\n\n");
           break;
           case 2: printf( "\n\n     LISTA DE CELULARES :  \n\n");mostrar_lista2(p2);
            break;
             case 3:
                 if (p2){
                          printf(" \n NUMERO CELULAR  = ");
                          scanf("%s",n);
                          fflush(stdin);
                           
                              
                              mega_elimina(&p,&p2,&p3,n);
                         
                                 
                  }
                  else
                    printf("\n LA LISTA DE CELUARES ESTA VACIA \n\n");
            break;
            case 4: printf( "\n\n    3. Buscar valor en lista\n\n");
                 if (p2){
                       printf(" Valor a BUSCAR = ");
                       scanf("%s",n);
                       fflush(stdin);
                       if (buscar_lista2(p2,n))
                            printf("\nEl NUMERO CELULAR  %s SI SE ENCUENTRA EN LA LISTA \n\n",n);
                       else
                            printf("\nEl NUMERO CELULAR %s NO ESTA EN LA LISTA DE CELULARES\n\n",n);
                  }
                  else
                     printf(" LA LISTA DE CELULARES ESTA VACIA \n\n");
           break;  
             case 5:
                 if (p2){	
                     printf ( " \n\n  NUMERO DE CELULAR =  ");
                     scanf("%s",n); 
                     fflush(stdin);
                     printf("\n");
                  
                          if (buscar_lista2(p2,n)){
							          char po[20];
                                      fflush(stdin);	 
                                      printf(" NOMBRE DE CONTACTO QUE DESEA AGREGAR   = ");
                                      scanf("%[^\n]",po);
                                      fflush(stdin);
                                      FILE*nuevo_contactos;
                                      nuevo_contactos= fopen( "nuevo_alias.txt", "a" );
                                      fprintf(nuevo_contactos,"%s\n",n);
                                      fprintf(nuevo_contactos,"%s\n",po);
                                      fclose(nuevo_contactos);
                                      agregar_se_pri(p2,&p,n,po);  
                               
                                       
                          }
                          else    
                             printf("\n EL NUMERO NO SE ENCUENTRA EN LA LISTA   \n\n");
                   }
                   else
                     printf("\n LA LISTA DE NUMEROS TELEFONICOS ESTA VACIA   \n\n");       
            break; 
            case 6: 
            if (p2){
                    printf("\n DIGA EL NUMERO CELULAR  =  ");
                    scanf("%s",n);
                    fflush(stdin);
                    printf("\n");
                    
                          if (buscar_lista2(p2,n)){
                                if  (existe_contatos(p2,p,n))
                                   mostrar_pri_se(p2, p,n);
                                else
                                    printf(" NO EXIXTEN CONTACTOS ASOCIADOS A ESTE NUMERO \n\n");     
                     
                          }            
                         else
                        printf("\n  EL NUMERO NO SE ENCUENTRA EN LA LISTA \n\n");      
            }
            else
               printf("\n LA LISTA DE NUMEROS TELEFONICOS ESTA VACIA \n\n");
           break;  
           case 7: 
              if(p2){
                  printf ("\n  NUMERO CELULAR = ");
                  char j[40];
                
                  scanf("%s",j);
                  fflush(stdin);
                if (buscar_lista2(p2,n)){	
                       printf (" CONTACTO= ");
                       char y[20];
                       scanf("%s",y);
                       fflush(stdin);
                       if (existe_contatos(p2,p,n)){
                               if (buscar_pri_se(p2,p,j,y)){
                                   // eliminar_pri_se(&p2, &p,n, y);
                                    nuevo_mega_elimina_se(&p,&p2,&p3,j,y);
                               }
                               else
                                  printf("\n EL CONTACTO DADO NO SE ENCUENTRA EN LA LISTA \n\n");
                       }
                       else
                          printf("\n NO EXISTEN CONTACTOS ASOCIADOS A EL NUMERO DADO \n\n");    
                  }
                  else
                    printf("\n EL NUMERO NO SE ENCUENTRA EN LA LISTA  \n\n");
               }
               else
                  printf("\n ERROR NO EXINTEN NUMEROS DE TELEFONOS EN LA LISTA  \n\n");
           break;
           case 8: 
           if (p2){
                  printf ("\n NUMERO CELULAR = ");
                  char x[40];
                 
                  scanf("%s",x);
                  fflush(stdin);
                  if (buscar_lista2(p2,x)){
                      printf ("\n CONTACTO = ");
                      char e[20];
                      scanf("%s",e);
                      fflush(stdin);
                      if (buscar_pri_se(p2,p,x,e))
                           printf("\nEl %s SI se encuentra en la lista\n\n",e);
                      else 
                          printf("\nEl %s NO  se encuentra en la lista\n\n",e);    
                  }
                  else
                     printf("\n EL NUMERO NO SE ENCUENTRA EN LA LISTA \n\n");
           }
           else
              printf("\n  ERROR  NO EXISTE LA LISTA DE NUMEROS TELEFONICOS   \n\n");
          break;
          case 9:
            if (p2){	
                 char xo[40];
                 
                 printf("\n");
                  printf(" DIGA EL NUMERO DE TELEFONO DE LA LISTA PRINCIPAL = ");
                    scanf("%s",xo);
                   fflush(stdin);
                   printf("\n");
                  if (buscar_lista2(p2,xo)){
                      if ( existe_contatos(p2,p,xo)){	
                         
                            printf(" DIGA EL NOMBRE DEL CONTACTO =  ");
                            char eo[20];
                            scanf("%[^\n]",eo);
                           fflush(stdin);
                            printf("\n");
                          if (buscar_pri_se(p2,p,xo,eo)){ 
                                        char yu[40]; 
                                        char so[20];
                                        printf(" DIGA EL NUMERO DE TELEFONO QUE DESEA AGREGAR AL CONTACTO =  ");
                                        scanf("%s",yu);
                                        fflush(stdin);
                                        printf("\n");
                                        printf(" DIGA COMO DESEA CLAIFICAR EL TELEFONO =  ");
                                        scanf("%[^\n]",so); 
                                        fflush(stdin);
                                        printf("\n");
                                        FILE*nuevo_numero_telefono;
                                        nuevo_numero_telefono= fopen( "nuevo_telefono_ali.txt", "a" ); 
                                        fprintf(nuevo_numero_telefono,"%s\n",xo);
                                        fprintf(nuevo_numero_telefono,"%s\n",eo);
                                        fprintf(nuevo_numero_telefono,"%s\n",yu);
                                        fprintf(nuevo_numero_telefono,"%s\n",so);
                                        fclose( nuevo_numero_telefono);
                                       agregar_se_ter(p,p2,&p3, xo, eo,yu,so); 
							}
                         else
                           printf("\n EL CONTACTO DADO NO SE ENCUENTRA EN LA LISTA\n\n");    
                      }
                      else
                        printf("\n NO EXISTEN CONTACTOS ASOCIADOS AL EL NUMERO DADO \n\n");
                  }
                  else
                    printf("\n EL NUMERO NO SE ENCUENTRA EN LA LISTA \n\n");
           }
           else
             printf("\n  ERROR  NO EXISTE LA LISTA DE NUMEROS TELEFONICOS   \n\n");
          break;
          case 10:
            if (p2){	
                 char mio[40];
                 	
                 printf("\n");	
                 printf(" DIGA EL NUMERO DE TELEFONO DE LA LISTA PRINCIPAL = ");
                 scanf("%s",mio);
                 fflush(stdin);
                 char ll[20];
                  if (buscar_lista2(p2,mio)){
                    if (existe_contatos(p2,p,mio)){  	
                       printf(" DIGA EL NOMBRE DEL CONTACTO =  ");
                       scanf("%[^\n]",ll);  
                       fflush(stdin);
                      if (buscar_pri_se(p2,p,mio,ll))  {
                            if (existe_numero_de_contacto(p3,p2,p,mio,ll))
                                 mostrar_se_ter(p,p2,p3, mio, ll );
                            else
                               printf("\n  NO EXISTEN NUMEROS TELEFONICOS ASOCIADOS A ESE CONTACTO \n\n"); 
                      }
                      else
                        printf("\n EL CONTACTO NO SE ENCUENTRA EN LA LISTA \n\n");  
                     }
                     else
                       printf("\n NO EXISTEN CONTACTOS ASOCIADOS A ESTE NUMERO \n\n");  
                  }
                 else
                   printf("\n EL NUMERO DADDO NO SE ENCUENTRA EN LA LISTA \n\n");  
               
            }
            else
              printf("\n ERROR LA LISTA DE NUMEROS TELEFONICOS NO EXITE  \n\n");
          break; 
          case 11:
            if (p2){ 	
                 char abc[40];
                
                 char zxy[20]; 
                 char aeio[40];
                 
                 printf("\n");
                 printf(" DIGA EL NUMERO DE TELEFONO DE LA LISTA PRINCIPAL =  ") ; 
                 scanf("%s",abc); 
                 fflush(stdin);
                 if (buscar_lista2(p2,abc)){
                    if (existe_contatos(p2,p,abc)){ 	
                          printf("\n");
                          printf(" DIGA EL NOMBRE DEL CONTACTO = ");
                          scanf("%s",zxy);
                          fflush(stdin);
                          printf("\n");
                          if(existe_numero_de_contacto(p3,p2,p,abc,zxy)) {
                              if (buscar_pri_se(p2,p,abc,zxy)){     	
                                  printf(" DIGA EL NUMERO DE TELEFONO =  ") ;
                                  scanf("%s",aeio);
                                  fflush(stdin);
                                 
                                        elimina_se_ter(&p3,p2,p,abc,zxy,aeio);
                                 
                                         
                              }
                              else
                                printf("\n EL CONTACTO NO SE ENCUENTRA EN LA LISTA \n\n");   
                          }
                          else
                              printf("\n NO EXISTEN NUMEROS TELEFONICOS ASOCIADOS A ESE CONTACTO \n\n");     
                    }
                    else
                      printf("\n NO EXISTEN CONTACTOS ASOCIADOS A ESE NUMERO \n\n");
                  }
                   else
                      printf("\n EL NUMERO DADO NO SE ENCUENTRA EN LA LISTA \n\n");
            
            }
            else
              printf("\n ERROR LA LISTA NUMEROS DE TELEFONICOS NO EXITE \n\n");
         break;
         case 12:
           if (p2){ 	
                char rt[20];
                printf("\n");
                fflush(stdin);
                printf( "DIGA EL NONMBRE DEL SOSPECHOSO = ");
                scanf("%[^\n]", rt);
                fflush(stdin);
                buscar_sospechoso(p2, rt); 
           }
           else
             printf("\n ERROR NO EXITE LA LISTA DE CELULARES \n\n");   
        break; 
        case 13:
          if (p2){ 	
              int salir;
              salir=0;
              char aus[20];	
              printf("\n DIGA EL NUMERO CELULAR  =  ");
              scanf("%s",n);
              fflush(stdin);
              printf("\n");
              if (buscar_lista2(p2,n)){
                        if (existe_contatos(p2,p,n)  ) {	
                                  mostrar_pri_se(p2, p,n);
                                  while (salir==0){  
                                             printf("\n ESCRIBA EL CONTACTO QUE DESEA VER SUS NUMEROS = ");	
                                             scanf("%[^\n]",aus);
                                             fflush(stdin);
                                    if (buscar_pri_se(p2,p,n,aus)) {    
                                           if ( existe_numero_de_contacto(p3,p2,p,n,aus)){
                                                  mostrar_se_ter(p,p2,p3, n, aus );
                                                  printf(" PRECIONE ( 1) PARA SALIR O ( 0) PARA VER TELEFENOS DE OTRO CONTACTO  =  ");
                                                  scanf("%i",&salir);
                                                 printf("\n");
                                                 fflush(stdin);
                                          }
                                          else{
                                             printf(" \n ERROR NO EXITEN NUMEROS ASOCIADADOS A ESE CONTACTO \n\n");
                                          salir=1;
                                          }
                                     } 
                                   else{
                                    printf(" \n CONTACTO EQUIVOCADO  \n\n");  
                                    salir=1;
                                   }	  
										  
                                  }
                        }
                       else
                            printf("ERROR NO EXISTEN CONTACTOS ASOCIADOS A ESTE NUMERO \n\n");
             }
            else
                printf("\n NUMERO EQUIVOCADO \n\n");
          } 
          else
             printf("\n ERROR NO EXISTE LA LISTA DE CELULARES \n\n");
		         
        break;   
        case 14:
          if (p2) { 	
              char gb[40];
              printf ( "\n DIGA EL NUMERO DE TELEFONO DEL CONTACTO: ");
              scanf("%s",gb);
              fflush(stdin);
              if(existe_contatos_general(p2,p)){
                   if ( existe_numero_de_contacto_general(p3,p2,p))
                         nueva_busqueda_telefono_ter(p,p2,p3,gb);
                   else
                      printf( "\n ERROR NO EXISTEN NUMEROS TELEFONICOS ASOCIADOS A NINGUN CONTACTO \n\n");      
              }
              else
               printf("\n ERROR NO EXISTEN CONTACTOS \n\n");
		                
          }
          else
              printf(" \n ERROR NO EXISTEN NUMEROS TELEFONICOS EN LA LISTA PRINCIPAL \n\n"); 
       
        break;
        case 15:
           if (p2){ 	
              char ali_1[40];
              char ali_2[40];
              printf("\n");	
              printf(" INGRESE EL PRIMER NUMERO TELEFONICO = ");
              scanf("%s",ali_1);
              fflush(stdin);
              printf("\n");
              if (buscar_lista2(p2,ali_1)) {
                           printf(" INGRESE EL SEGUNDO NUMERO TELEFONICO = ");
                           scanf("%s",ali_2); 
                           fflush(stdin);
                           printf("\n");
                            if (buscar_lista2(p2,ali_2)) {
                                  if(existe_contatos_general(p2,p)) {
                                         if ( existe_numero_de_contacto_general(p3,p2,p))
                                              dos_sospechosos(p,p2,p3,ali_1,ali_2);
                                        else
                                             printf(" \n ERROR NO EXISTEN NINGUN NUMERO ASOCIADO A ALGUN CONTACTO \n\n");      
                                  }
                                  else
                                       printf(" \n ERROR NO EXISTE NINGUN CONTACTO \n\n");
                             } 
                            else
                                printf(" \n EL NUMERO NO SE ENCUENTRA EN LA LISTA  \n\n");           
                                       
              } 
              else
                printf(" \n EL NUMERO NO SE ENCUENTRA EN LA LISTA  \n\n");
			                    
           }
           else
           printf(" \n ERROR NO EXISTE NINGUN NUMERO EN LA LISTA PRINCIPAL \n\n");
        break; 
        case 16: 
           if( p2) {
                char porfavor[60];
                printf("\n");
                fflush(stdin);
                printf(" DIGA EL ALIAS = ");
                scanf("%[^\n]",porfavor);
                fflush(stdin);
                if (existe_contatos_general(p2,p))
                    bus_ali_listar(p,p2,porfavor);
                else
                    printf("\n ERROR NO EXISTE NINGUN CONTACTO \n\n");     
           }
           else
               printf("\n ERROR NO EXISTE NINGUN NUMERO CELULAR DE A LISTA PRINCIPAL \n\n");  
        break;
        default:
           printf("Opcion NO Valida ... intente de nuevo");
         break;
        }
           if (!(op)) break;
           system("pause");
           system("cls");
       }
}
