#include<stdio.h>
#include<string.h>
#include<locale.h>
#define MAX 1000

typedef struct d
{
	int dia;
	int mes;
	int ano;
}tData;

typedef struct p
{
	char nome[40];
	tData dataCadastro;
	int qtdEstoque;
	float valorUnitario;
} tProd;

int n=0;

//--------------------------> Cadastro de produto.
int cadastrar(tProd p[])
{
	if(n==MAX)
	{
		return 0;
	}
	printf("\n Bem vindo ao assistente de cadastro de Produtos:\n\n");
	
	printf(" Insira os dados conforme solicitados:\n");
 	printf(" Nome do produto: ");
 	fflush(stdin);
	gets(p[n].nome);
//	printf(" Data do cadastro:\n ");
	printf(" Dia: ");
	scanf("%d",&p[n].dataCadastro.dia);
	printf(" Mês: ");
	scanf("%d",&p[n].dataCadastro.mes);
	printf(" Ano: ");
	scanf("%d",&p[n].dataCadastro.ano);
	printf(" Quantidade: ");
	scanf("%d",&p[n].qtdEstoque);
	printf(" Valor Unitário: ");
	scanf("%f",&p[n].valorUnitario);
	n++;
	return 1;
}

//--------------------------> Mostrar todos os produtos cadastrados.
void mostrar(tProd p[])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n Produto nº %d Nome: %s",i,p[i].nome);
		printf("\n Data: %.2d / %.2d / %.2d",p[i].dataCadastro.dia ,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
		printf("\n Quantidade: %d",p[i].qtdEstoque);
		printf("\n Valor Unitário: %.2f\n\n",p[i].valorUnitario);
	}
}

//--------------------------> Pesquisar produto.
void pesquisar(tProd p[],char pesquisa[40])
{
 	int i,x=0;
 	char aux[40];
 	
	for(i=0;i<n;i++)
	{
		strcpy(aux,p[i].nome);
		if(strcmp(strupr(aux),strupr(pesquisa))==0)
		{
 			printf("\n Produto nº %d Nome: %s",i,p[i].nome);
 			printf("\n Data: %d / %d / %d",p[i].dataCadastro.dia ,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
 			printf("\n Quantidade: %d",p[i].qtdEstoque);
 			printf("\n Valor Unitário: %.2f\n\n",p[i].valorUnitario);
 			x=1;
		}
	}
	if(!x)
	{
		printf("\n Este produto não está na sua lista!");
	}
}

//--------------------------> Realizar venda.
void vender(tProd p[], char pesquisa[40])
{
	int i=0,x=0,valor,estoque;
	char aux[40];
	
	for(i=0;i<n;i++)
	{
		strcpy(aux,p[i].nome);
		if(strcmp(strupr(aux),strupr(pesquisa))==0)
		{
			printf(" Digite quantas unidades deseja vender: ");
			scanf("%d",&valor);
		}
		estoque=p[i].qtdEstoque-valor;
		p[i].qtdEstoque=estoque;
				
		x=1;
	}
	if(!x)
	{
		printf(" Este produto não foi encontrado para alteração!");
	}
	printf("\n O produto agora possui %d unidades no estoque.\n",estoque);
}

//--------------------------> Add ao estoque.
void adicionar(tProd p[], char pesquisa[])
{
	int i=0,x=0,estoque,valor;
	char aux[40];
	
	for(i=0;i<n;i++)
	{
		strcpy(aux,p[i].nome);
		if(strcmp(strupr(aux),strupr(pesquisa))==0)
		{
 			printf(" Digite quantos produtos deseja adicionar ao estoque: ");
 			scanf("%d",&valor);
		}
		estoque=p[i].qtdEstoque+valor;
		p[i].qtdEstoque=estoque;
				
		x=1;
	}
	if(!x)
	{
		printf(" Este produto não foi encontrado para alteração!");
	}
	printf("\n O produto agora possui %d unidades no estoque.\n",estoque);
}

//--------------------------> Pesquisar ano.
void pesquisarAno(tProd p[])
{
	int i=0,x=0,ano;
	
	printf(" Digite o ano: ");
	scanf("%d",&ano);
	
	for(i=0;i<n;i++)
	{
		if(ano <= p[i].dataCadastro.ano)
		{
 			printf("\n Produto nº %d Nome: %s",i,p[i].nome);
 			printf("\n Data: %d / %d / %d",p[i].dataCadastro.dia ,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
 			printf("\n Quantidade: %d",p[i].qtdEstoque);
 			printf("\n Valor Unitário: %.2f\n\n",p[i].valorUnitario);
 			x=1;
		}
		if(!x)
		{
			printf(" Não existem produtos desses ano!");
		}
	}
}

//--------------------------> Valor total do estoque.
void valortotal(tProd p[])
{
	int i=0;
	float total=0;
	
	for(i=0;i<n;i++)
	{
		total=total+(p[i].valorUnitario*p[i].qtdEstoque);
	}
	printf("\n O valor total de todos os produtos do estoque é, R$%.2f",total);
	
}

void caroebarato (tProd p[])
{
	int i=0,x=0;
	float caro=0,barato=0;
	
	for(i=0;i>n;i++)
	{
		if(caro<p[i].valorUnitario)
		{
			caro=p[i].valorUnitario;
		}
		else 
		if(p[i].valorUnitario>caro)
		{
			barato=p[i].valorUnitario;
		}
	}
	printf(" O produto mais caro é o %s, que custa %.2d.\n",p[i].nome,caro);
	printf(" O produto mais barato é o %s, que custa %.2d.\n",p[i].nome,barato);
	x=1;
}

//--------------------------> Menu
int menu()
{
	int op;
	
	printf("\n ------------Sistema de Cadastro de produtos------------\n\n");
	printf("\t 1. Cadastrar.\n");
	printf("\t 2. Mostrar. \n");
	printf("\t 3. Pesquisar.\n");
	printf("\t 4. Realizar uma venda.\n");
	printf("\t 5. Adicionar item ao estoque.\n");
	printf("\t 6. Buscar produto por ano.\n");
	printf("\t 7. Valor total do estoque.\n");
	printf("\t 8. Produto mais caro.\n");
	printf("\t 9. Produto mais barato.\n");
	printf("\t 0. Sair.\n\n");
	printf(" -------------------------------------------------------");
	printf("\n\n Digite a opção desejada: ");

	scanf("%d",&op);

	return op;
}

//--------------------------> Programa principal
int main()
{
	setlocale(LC_ALL,"");
	
	tData d[MAX];
	tProd p[MAX];
	char pesquisa[40];
	int op;
	
	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				if(cadastrar(p)==1)
				{
					printf("\n Produto cadastrado com sucesso!\n");
					printf("\n Toque em qualquer tecla para continuar...\n");
				}
				else
				{
					printf("\n Limite de produtos atingido!");
				}	
			break;
			case 2:
				mostrar(p);
			break;
			case 3:
				printf("\n Digite o nome da do produto que deseja pesquisar: ");
				fflush(stdin);
				gets(pesquisa);
				pesquisar(p,pesquisa);
				printf(" Toque em qualquer tecla para continuar...\n");
			break;
			case 4:
				printf("\n Digite o nome da do produto que deseja vender: ");
				fflush(stdin);
				gets(pesquisa);
				vender(p,pesquisa);
				printf("\n Toque em qualquer tecla para continuar...\n");
			break;
			case 5:
				printf("\n Digite o nome da do produto que deseja adicionar: ");
				fflush(stdin);
				gets(pesquisa);
				adicionar(p,pesquisa);
				printf("\n Toque em qualquer tecla para continuar...\n");
			break;
			case 6:				
				pesquisarAno(p);
				printf(" Toque em qualquer tecla para continuar...\n");
			break;
			case 7:
				valortotal(p);		
				printf("\n Toque em qualquer tecla para continuar...\n");
			break;
			case 8:
				caroebarato(p);
				printf("\n Toque em qualquer tecla para continuar...\n");
			break;
			case 9:
					//
				printf("\n Toque em qualquer tecla para continuar...\n");
			break;
			case 0:
				printf("\n Programa encerrado.");
				printf("\n Toque em qualquer tecla para fechar...\n");
				return 0;
			break;
			default:
				printf("\n Opção invalida!");
		}
		getch();
		system("cls");
	}
	while(op!=0);
	return 0;	
}
