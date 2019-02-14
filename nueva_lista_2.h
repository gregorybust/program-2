struct lista3{  /* lista que contiene los numeros de telefono asociados a un contacto */
  char contacto_telefono[40];
  char clasificasion[20];
  lista3*continua;
 	
};
int buscar_ter (lista3 *p3, char x[40]){
        lista3 *aux= p3;
       
        while ((aux)&&(strcmp(aux->contacto_telefono,x)!=0) ) aux= aux->continua;
        return ( aux!=NULL );
}  


void mostrar_ter( lista3 *p3){
    lista3 * t= p3;
    printf("\n\n");
    
    while (t){
       printf(" [%s]",t->contacto_telefono);
       printf("\n");
       printf(" [%s]",t->clasificasion );
        printf("\n");
        printf("\n");
       t=t->continua;
     }
    
   
     
}
lista3 * crear_ter( char  x[20],char y[40]){
   
    lista3 *p3 = new lista3;
    strcpy(p3->clasificasion,x);
    strcpy( p3->contacto_telefono,y);
   
    p3->continua = NULL;
  
    return p3;
}
void agregar_cola_ter(lista3**p3,char x[20],char y[40] )
{ 
  lista3* aux=*p3;
  if (aux==NULL){
     *p3=crear_ter(x,y);
     
  }
  else
  {   
            
             
           while ((aux->continua) &&   (strcmp(aux->contacto_telefono,y)!=0))
          { 
               
              aux=aux->continua;
          }
              
      
          if ((aux->continua==NULL) &&  (strcmp(aux->contacto_telefono,y)!=0))
          {
             lista3* tem= new lista3;
      
            strcpy(tem->clasificasion,x);
            strcpy(tem->contacto_telefono,y);
           
            tem->continua=NULL;
            aux->continua=tem;   
          }
    
      
  }

}   
void elimina_ter( lista3 **p3,char x[40]){
   lista3 *aux= *p3;
    if (*p3)
        
        if (strcmp((*p3)->contacto_telefono,x)==0)  {
           *p3= (*p3)->continua;
          delete aux ;
        }
       else {
       	
         while ((aux->continua) && (strcmp(aux->continua->contacto_telefono,x)!=0) ) aux= aux->continua;
           if (aux->continua){
               lista3 *temp= aux->continua;
               aux->continua= aux->continua->continua;
               delete temp;
               printf("\n\n Valor %s ELIMINADO \n\n",x);
            }
           else
             printf("\n\n Valor %s NO ENCONTRADO!!! \n\n",x);
       }
}  





