#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
 int PIDP;
 char nomeP [40];
 struct Node *proxP;
};
struct Node2{
 int PIDN;
 char nomeN [40];
 struct Node2 *proxN;
};
typedef struct Node node;
typedef struct Node2 node2;

int tamP, tamN;
int menu(void);
void opcao(node *FP, node2 *FN, int op);

void IP(node *FP);
int VP(node *FP);
node *AP();
void insereP(node *FP);
node *retiraP(node *FP);
void exibeP(node *FP);
void liberaP(node *FP);

void iniciaN(node2 *FN);
int vaziaN(node2 *FN);
node2 *alocaN();
void insereN(node2 *FN);
node2 *retiraN(node2 *FN);
void exibeN(node2 *FN);
void liberaN(node2 *FN);
int main(void)
{
 node *FP = (node *) malloc(sizeof(node));
 node2 *FN = (node2 *) malloc(sizeof(node2));
 if(!FP || !FN){
  printf("Sem memoria\n");
  exit(1);
 }else{
 IP(FP);
 iniciaN(FN);
 int opt;	
 do{
  opt=menu();
  opcao(FP, FN, opt);
 }while(opt);

 free(FP);
 return 0;
 }
}
int menu(void)
{
 int opt;

 printf("Escolha a opcao\n");
 printf("\n0: Sair\n");
 printf("1: Zerar\n");
 printf("2: Exibir\n");
 printf("3: Adicionar Elemento\n");
 printf("4: Retirar Elemento\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
 
}

void opcao(node *FP, node2 *FN,  int op)
{
 int PouN, RetirarPouN;
 node *tmpP;
 node2 *tmpN;
 switch(op){
  case 0:
   liberaP(FP);
   liberaN(FN);
   break;

  case 1:

   	liberaP(FP);
   	IP(FP);
   	liberaN(FN);
   	iniciaN(FN);
   	 break;

  case 2:
   printf("\nFila Preferencial\n ");
   exibeP(FP);
   printf("\nFila Normal\n ");
   exibeN(FN);
   break;
  case 3:
   printf("\nColoque 9 para FP ou 10 para FN:\t");
   scanf("%i", &PouN);
   
   if(PouN == 9){
   	insereP(FP);
   }else{
   	insereN(FN);
   }
   break;
   case 4:
   	printf("Para retirar a FP digite 7, Para retirar da FN digite 8:\t");
   	scanf("%i", &RetirarPouN);
   	
   	if(RetirarPouN){
	   tmpP= retiraP(FP);
   	   if(tmpP != NULL){
		  printf("\nRetirado o PID:%i\t nome:", tmpP->PIDP, tmpP->nomeP);
          liberaP(tmpP);
	   }
   }else{
   	tmpN= retiraN(FN);
   	   if(tmpN != NULL){
		  printf("\nRetirado o PID:%i\t nome:", tmpN->PIDN,tmpN->nomeN);
		  liberaN(tmpN);
   }
}
   break;
  default:
   printf("CARACTERE ERRADO\n\n");
 }
}
void IP(node *FP)
{
 FP->proxP = NULL;
 tamP=0;
}

int VP(node *FP)
{
 if(FP->proxP == NULL)
  return 1;
 else
  return 0;
}

node *AP()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria !\n");
  exit(1);
 }else{
  printf("\nPID: "); scanf("%d", &novo->PIDP);
  printf("Nome: "); scanf("%s", &novo->nomeP);
  system("cls");

  
  return novo;
 }
}

void insereP(node *FP)
{
 node *novo=AP();
 novo->proxP = NULL;

 if(VP(FP))
  FP->proxP=novo;
 else{
  node *tmpP = FP->proxP;

  while(tmpP->proxP != NULL)
   tmpP = tmpP->proxP;
   tmpP->proxP = novo;
 }
 tamP++;
}
node *retiraP(node *FP)
{
 if(FP->proxP == NULL){
  printf("Fila sem nada\n");
  return NULL;
 }else{
  node *tmpP = FP->proxP;
  FP->proxP = tmpP->proxP;
  tamP--;
  return tmpP;
 }
}
void exibeP(node *FP)
{
 if(VP(FP)){
  printf("Fila vazia!\n\n");
  return ;
 }
 node *tmpP;
 tmpP = FP->proxP;
 while( tmpP != NULL){
  printf("Pid:%d\tNome:%s\n", tmpP->PIDP, tmpP->nomeP);
  tmpP = tmpP->proxP;
 }
}
void liberaP (node *FP){
 if(!VP(FP)){
  node *proxNodeP, *atualP;
  atualP = FP->proxP;
  while(atualP != NULL){
   proxNodeP = atualP->proxP;
   free(atualP);
   atualP = proxNodeP;
  }
 }
}
void iniciaN(node2 *FN)
{
 FN->proxN = NULL;
 tamN=0;
}
int vaziaN(node2 *FN)
{
 if(FN->proxN == NULL)
  return 1;
 else
  return 0;
}
node2 *alocaN()
{
 node2 *novoN=(node2 *) malloc(sizeof(node2));
 if(!novoN){
  printf("Sem memoria!\n");
  exit(1);
 }else{
  printf("\nPID: "); scanf("%d", &novoN->PIDN);
  printf("Nome: "); scanf("%s", &novoN->nomeN);
  system("cls");
  return novoN;
 }
}
void insereN(node2 *FN)
{
 node2 *novoN=alocaN();
 novoN->proxN = NULL;

 if(vaziaN(FN))
  FN->proxN=novoN;
 else{
  node2 *tmpN = FN->proxN;
  while(tmpN->proxN != NULL)
   tmpN = tmpN->proxN;
   tmpN->proxN = novoN;
 }
 tamN++;
}
node2 *retiraN(node2 *FN)
{
 if(FN->proxN == NULL){
  printf("Fila esta vazia\n");
  return NULL;
 }else{
  node2 *tmpN = FN->proxN;
  FN->proxN = tmpN->proxN;
  tamN--;
  return tmpN;
 }
}
void exibeN(node2 *FN)
{
 if(vaziaN(FN)){
  printf("Fila vazia!\n\n");
  return ;
 }
 node2 *tmpN;
 tmpN = FN->proxN;
 while( tmpN != NULL){
  printf("Pid:%d\tNome:%s\n", tmpN->PIDN, tmpN->nomeN);
  tmpN = tmpN->proxN;
 }
}
void liberaN(node2 *FN){
 if(!vaziaN(FN)){
  node2 *proxNodeN, *atualN;
  atualN = FN->proxN;
  while(atualN != NULL){
   proxNodeN = atualN->proxN;
   free(atualN);
   atualN = proxNodeN;
  }
 }
}
