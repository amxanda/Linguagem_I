//feito na monitoria

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct {
	
char nome[40];
float pot, horas;
	
}teletrodomestico;
int quant=0;

//******************************
 
 void inserireletrodomestico(teletrodomestico e[]){
if(quant==MAX){
printf("\n Sistema cheio, impossivel cadastrar novo eletrodomestico!");
}
printf("\n ***** CADASTRO DE ELETRODOMESTICO *****");
printf("\n Nome do eletrodomestico: ");
fflush(stdin);
gets(e[quant].nome);
printf("\n Potencia: ");
scanf("%f",&e[quant].pot);
printf("\n Tempo médio diario em atividade (por horas): ");
scanf("%f",&e[quant].horas);

quant++;


 }
 //*******************************
 
 void mostrarEletro(teletrodomestico e[]){
int i;
for( i=0;i<quant; i++){
printf("\n** eletrodomestico %d**",i+1);
printf("\n Nome do eletrodomestico: %s ", e[i].nome);
printf("\n Potencia: %.2f KW ",e[i].pot);
printf("\n Tempo médio diario em atividade (por horas): %.2f hrs ",e[i].horas);
}
 }
 
 //*********************************
 
void BuscarEletrodomestico(teletrodomestico e[], char BuscarN[]){
int i;
char nome[40];
int existe=0;
for (i=0; i<quant; i++){
	strcpy(nome, e[i].nome);
if(strcpm(strupr(nome), strupr(BuscarN))==0){
printf("\n *** Eletrodomestico %d ***",i+1);
printf("\n Nome: %s",e[i].nome);
printf("\n Potencia: %.2f KW ",e[i].pot);
printf("\n Tempo médio diario em atividade (por horas): %.2f hrs ",e[i].horas);

existe=1;
break;

}
}
if(!existe)
printf("\n não foi possivel encontrar o eletrodomestico!");

} 

//******************************
void BuscarMaior(teletrodomestico e[], float valor){
int i;
int existe=0;
int cont=0;
for (i=0; i<quant; i++){
if(valor <e[i].pot){
printf("\n *** Eletrodomestico %d ***",i+1);
printf("\n Nome: %s",e[i].nome);
printf("\n Potencia: %.2f KW ",e[i].pot);
printf("\n Tempo médio diario em atividade (por horas): %.2f hrs ",e[i].horas);
 existe=1;
 cont++;
 

}
}
if(existe==0){
printf("\n Nao existe superior a tal valor!");
}
}

//*************************************
void consumo(teletrodomestico e[]){
int i;
float total=0;
float totalM, cm, cd;
for(i=0;i<quant;i++){
total+=e[i].pot;
total=total;
totalM= total*30;
}
printf("\n Consumo diario em Kw: %.2f",total);
printf("\n Consumo mensal em Kw: %.2f",totalM);

}


//***********************************
void salvarArquivo(teletrodomestico e[]){
FILE*arq;
arq=fopen("Eletrodomesticos.txt","wb");
fwrite(&e[0],sizeof(teletrodomestico),quant,arq);
printf("\n Salvo com sucesso!");
fclose(arq);
}

//*************************************

void carregarArquivo (teletrodomestico e[]){
FILE*arq;
arq=fopen("Eletrodomesticos.txt","rb");
if(arq==NULL){
printf("\n Arquivo não encontrado");
return;
}
while(fread(&e[quant],sizeof(teletrodomestico),1,arq) >0)
quant++;
fclose(arq);
}

//******************************************
int menu()
{
int op;
printf("\n ***** CADASTRO DE ELETRONICOS *****");
printf("\n 1- Cadastrar eletrodomestico\n");
printf("\n 2- Mostrar eletrodomestico cadastrado\n");
printf("\n 3- Buscar eletrodomestico pelo nome\n");
printf("\n 4- Consumo\n");
printf("\n 0- Sair\n");
scanf("%d",&op);
return op;
}

//************************************************

int main()
{
int op;
teletrodomestico e[MAX];
char BuscarpNome[40];
float valor, total;

do{

op* menu();
switch(op){
	
	 case 1:inserireletrodomestico (e);
break;  

     case 2:mostrarEletro (e);
     	
break;
	
	 case 3: printf("\nDigite o nome do eletrodomestico para a busca:");
	         fflush(stdin);
	         gets(BuscarpNome);
	         BuscarEletrodomestico(e,BuscarpNome );
	         
	 
break;
	
	 case 4:consumo(e);
	 	
break;

     case 5: printf(" \n Buscar por eletrodomestico que consuma mais que um valor x:");
	         printf("\nDigite o valor da busca:");
			 scanf("%f",&valor);
			 BuscarMaior(e,valor);
			 
break;

    case 6: carregarArquivo (e);
    printf("\n Os dados foram carregados!");
    
break;

   case 7: salvarArquivo(e);
   
break;

   case 0: printf("\n sair!");
   
break;
			 	 	
}
getch();
system("cls");
}
while(op!=0);
return 0;
}
