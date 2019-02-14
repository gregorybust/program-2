/*----------------------------------------------------------------------------
  -      TITULO  : Intercambia dos valores con asm-embebido TURBO-C          -
  -----                                                                  -----
  -      AUTOR   : Alfonso Víctor Caballero Hurtado                          -
  -----                                                                  -----
  -      VERSION : 1.0                                                       -
  ----------------------------------------------------------------------------*/

#include 
/* declaración-prototipo de la función */
void swap (unsigned int *Var1, unsigned int *Var2); 

unsigned int Var1=1;
unsigned int Var2=2;

void swap (unsigned int *Var1, unsigned int *Var2)
{
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     AX, 0
  asm  MOV     SI, WORD PTR [Var1]
  asm  MOV     DI, WORD PTR [Var2]
  asm  MOV     AX, WORD PTR [SI]
  asm  MOV     BX, WORD PTR [DI]
  asm  MOV     WORD PTR [DI], AX
  asm  MOV     WORD PTR [SI], BX
}

int main()
{
  printf("Variable1 %d Variable2 %d\n", Var1, Var2);
  swap(&Var1, &Var2);
  printf("Variable1 %d Variable2 %d", Var1, Var2);
  return (0);
}
