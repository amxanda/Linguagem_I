#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 100

typedef struct cadastro
{
	int matricula[15];
	char nome[30];
	float nota1;
	float nota2;
	float nota3;
}tcadastro;

int n;

int addaluno(tcadastro c[])
{
	if (n==MAX)
	{
		return 0;
	}
	printf("\t Informe os seguintes dados:");
	printf("\n Matricula: ");
	scanf("%d",&c[n].matricula);
	printf("\n Nome: ");
	fflush(stdin);
	gets(c[n].nome);
	printf("\n Nota 1: ");
	scanf("%d",&c[n].nota1);
	printf("\n Nota 2: ");
	scanf("%d",&c[n].nota2);
	printf("\n Nota 3: ");
	scanf("%d",&c[n].nota3);
	n++;
	return 1;
}

void salvaraluno(tcadastro c[])
{
	int i;
	FILE *arq;
	arq = fopen("cadastro.txt","w");
	fprintf(arq,"%d\n",n);
	for(i=0;i<n;i++)
	{
		fprintf(arq,"Matricula: %d",c[i].matricula);
		fprintf(arq,"Nome: %s",c[i].nome);
		fprintf(arq,"Nota 1: %d",c[i].nota1);
		fprintf(arq,"Nota 2: %d",c[i].nota2);
		fprintf(arq,"Nota 3: %d",c[i].nota3);
	}
	printf(" Dados salvos com sucesso!\n");
	fclose(arq);
}

void carregarcadastro(tcadastro c[])
{
	FILE *arq;
	int i;
	arq=fopen("cadastro.txt","r");
	if(arq==NULL)
	{
		printf(" Arquivo não encontrado!\n");
		return 0;
	}
	fscanf(arq,"%d",&n);
	printf(" Carregar dados");
	for i=0i<n;i++)
	{
		fprintf(arq,"Matricula: %d",c[i].matricula);
		fprintf(arq,"Nome: %s",c[i].nome);
		fprintf(arq,"Nota 1: %d",c[i].nota1);
		fprintf(arq,"Nota 2: %d",c[i].nota2);
		fprintf(arq,"Nota 3: %d",c[i].nota3);
	}
}

void buscaraluno(tcadastro c[], char nomebuscar[30]) //buscar por nome
{
	int i, existe=0;
	char aux[30];
	
	for(i=0;i<n;i++)
	{
		strcpy(aux,c[i].nome);
		
		if(strcmp(strupr(aux),stupr(nomebuscar))==0)
		{
			printf(arq,"Matricula: %d",c[i].matricula);
			printf(arq,"Nome: %s",c[i].nome);
			printf(arq,"Nota 1: %d",c[i].nota1);
			printf(arq,"Nota 2: %d",c[i].nota2);
			printf(arq,"Nota 3: %d",c[i].nota3);
			existe=1;
		}
	}
	if(!existe)
	{
		printf("Aluno(a) não encontrado(a)!");
	}
	
}

void buscarmatricula(tcadastro c[]) //buscar por cadastro
{
	int i, existe=0
	int nmatricula;
	char aux[30];
	
	for(i=0;i<n;i++)
	{
		if(nmatricula==c[i].matricula)
		{
			printf(arq,"Matricula: %d",c[i].matricula);
			printf(arq,"Nome: %s",c[i].nome);
			printf(arq,"Nota 1: %d",c[i].nota1);
			printf(arq,"Nota 2: %d",c[i].nota2);
			printf(arq,"Nota 3: %d",c[i].nota3);
			existe=1;
		}
	}
	if(!existe)
	{
		printf("Matricula não encontrada!");
	}
}

void maiormedia(tcadastro c[])
{
	int i=0;
	float media[i],result,maior;
	
	for(i=0;i>n;i++)
	{
		media[i]=c[i].nota1+c[i].nota2+c[i].nota3/3;
		result=media[i];
		
		if(result>media[i])
		{
			maior=media[i];
		}
	}
	printf(" O aluno com maior média é %s, com %d pontos",c[i].nome,maior);
}

void statusaluno(tcadastro c[])
{
	int i;
	
	for(i=0;i>n;i++)
	{
		if(media[i]>=6])
		{
			printf(" Aluno aprovado!\n"); 
		}
		else
		{
			printf(" Aluno reprovado!\n");
		}
	}
}

int menu()
{
	int op;
	printf(" Bem vindo ao assistente de cadastro de Alunos: ");
	printf(" 1 - Adiciona Aluno\n");
	printf(" 2 - Buscar Aluno\n");
	printf(" 3 - Buscar matricula\n");
	printf(" 4 - Maior Média Geral\n");
	printf(" 5 - Consultar Status do Aluno\n");
	printf(" 6 - Salvar Cadastro\n");
	printf(" 7 - Carregar Cadastro\n");
	printf(" 0 - Sair\n");
	printf(" Digite a opção desejada: ");
	scanf("%d",&op);
	return op;
}

int main()
{
	setlocale(LC_ALL,"");
	
	tcadastro c[MAX];
	char buscar[30];
	int op, m;
	carregaraluno(c);
	
	do
	{
		op=menu();
		switch(op)
		{
			case 1: 
				if(addaluno(c)==1)
				{
					printf(" Aluno cadastrado.");
				}
				else
				{
					printf(" Limite de cadastros atingida.");
				}
			break;
			case 2:
				printf(" Nome do aluno: ");
				fflush(stdin);	
				gets(buscar);			
				buscaraluno(c,buscar);
			break;
			case 3:
				printf(" Matricula: ");			
				buscarmatricula(c,m);
			break;
			case 4:
				printf(" Consultar maior média: ");
				maiormedia(c);
			break;
			case 5:
				printf(" Status de aprovação: ");
				statusaluno(c);
			break;
			case 6:
				printf(" Salvar Cadastro: ");
				salvaraluno(c);
			break;
			case 7:
				printf(" Carregar Cadastro: ");
				carregarcadastro(c);
			break;
			case 0:
				printf(" Saindo...\n");
			break;
			break;
		}
	}
	while(op!=0);
	
	return 0;
}
