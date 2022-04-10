#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

typedef struct biblioteca
{
	int codigo;
	char titulo[50];
	char autor[50];
	int ano;
	int prateleira;
}tbiblioteca;

int total=0;

int addlivros(tbiblioteca b[]) //bd Biblioteca
{
	if(total==MAX) //espa�o total da biblioteca
	{
		return 0;
	}

		printf("\t Cadastro de livros \n");
		printf(" Código: \n");
		scanf("%d",&b[total].codigo);
		printf(" Título: ");
		fflush(stdin);
		gets(b[total].titulo);
		printf(" Autor: ");
		fflush(stdin);
		fflush(stdin);
		gets(b[total].autor);
		printf(" Ano: ");
		scanf("%d",&b[total].ano);
		printf(" Prateleira: ");
		scanf("%d",&b[total].prateleira);
		total++;
		return 1;
}

void exibirbiblioteca(tbiblioteca b[]) //exibir livros cadastrados
{
	int i;
	
	printf(" Cadastrar livros\n\n");
	for(i=0;i<total;i++)
	{
		printf(" Livro %d\n",i+1);
		printf(" Código: %d\n",b[i].codigo);
		printf(" Título: %s\n",b[i].titulo);
		printf(" Autor: %s\n",b[i].autor);
		printf(" Ano: %d\n",b[i].ano);
		printf(" Prateleira: %s\n",b[i].prateleira);
		printf("- - - - - - - - - - - - - - -\n");
	}
}

void buscarlivro(tbiblioteca b[], char nomebusca[50]) //pesquisar dados
{
	int i,existe=0;
	char aux[50];
	
	for(i=0;i<total;i++)
	{
		//aux=b[i].titulo;
		strcpy(aux,b[i].titulo); 
	}
	for(i=0;i<total;i++)
	{
		if(strupr(aux),strupr(nomebusca)==0)
		{
			printf(" Livro %d\n",i+1);
			printf(" Código: %d\n",b[i].codigo);
			printf(" Título: %s\n",b[i].titulo);
			printf(" Autor: %s\n",b[i].autor);
			printf(" Ano: %d\n",b[i].ano);
			printf(" Prateleira: %s\n",b[i].prateleira);
			printf("- - - - - - - - - - - - - - -\n");
			existe=1;
		}	
	}
	if(!existe)
	{
		printf("Banda não encontrada!");
	}
}

void salvarbiblioteca(tbiblioteca b[]) //salvar dados
{
	int i;
	FILE *projeto;
	
	projeto=fopen("projeto-biblioteca.txt","w"); // w = write
	fprintf(projeto,"%d\n",&total)
	for(i=0;i<total;i++)
	{
		fprintf(projeto,"%d\n",b[i].codigo);
		fprintf(projeto,"%s\n",b[i].titulo);
		fprintf(projeto,"%s\n",b[i].autor);
		fprintf(projeto,"%d\n",b[i].ano);
		fprintf(projeto,"%d\n",b[i].prateleira);
	}
	printf(" Dados salvos com sucesso!");
	fclose(projeto);
}

void carregarbiblioteca(tbiblioteca b[]) //carregar dados
{
	int i;
	FILE *projeto;
	
	projeto=fopen("projeto-biblioteca.txt","r"); // r = read
	if(projeto==NULL)
	{
		printf(" Arquivo não encontrado.\n");
		return;
	}
	fscanf(projeto,"%d\n",&total);
	printf("Carregando dados");
	for(i=0;i<total;i++)
	{
		fprintf(projeto,"%d\n",b[i].codigo);
		fprintf(projeto,"%s\n",b[i].titulo);
		fprintf(projeto,"%s\n",b[i].autor);
		fprintf(projeto,"%d\n",b[i].ano);
		fprintf(projeto,"%d\n",b[i].prateleira);
		printf(".");
		//_sleep(1000);
	}
	fclose(projeto);
	system("cls");
}

void removerlivro(tbiblioteca b[], char nomebusca[50]) //remover dados
{
	int i,existe=0;
	char aux[50];
	
	for(i=0;i<total;i++)
	{
		strcpy(aux,b[i].titulo);
	}
	if(strupr(aux),strupr(nomebusca)==0)
	{
		b[i]=b[total-1];
		total--;
		existe=1;
	}	
	
	if(!existe)
	{
		printf("Banda não encontrada!");
	}
	else
	{
		printf("Banda removida com sucesso!");
	}
		
}

int menu() //menu para programa
{
	int n;
	
	printf("\t Bem vindo ao assistente da biblioteca.\n");
	printf(" 1: Adicionar Livro.\n");
	printf(" 2: Exibir Livros Cadastrados.\n");
	printf(" 3: Procurar Livro.\n");
	printf(" 4: Remover Livro,\n");
	printf(" 0: Sair.\n\n");
	printf(" Selecione a opção desejada: ");
	scanf(" %d",&n);
	
	return n;
}

int main() //programa principal
{
	setlocale(LC_ALL,"");
	
	tbiblioteca b[MAX];
	int n;
	char nome[50];
	carregarbiblioteca(b);
	
	do
	{
		n = menu();
		
		switch(n)
		{
			case 1: 
				if(addlivros(b)==1)
				{
					printf(" Banda Adicionada com sucesso!\n");				
				}
				else
				{
					printf(" Limite de Livros cadastrados atingida!\n");
				}
			break;
			case 2: 
				exibirbiblioteca(b);
			break;
			case 3:
				printf(" Digite o nome do livro no qual deseja procurar: ");
				fflush(stdin);
				gets(nome);
				buscarlivro(b,nome);
			break;
			case 4:
				printf(" Digite o nome do livro no qual deseja remover: ");
				fflush(stdin);
				gets(nome);
				removerlivro(b,nome);
			break;
			case 0:
				salvarbiblioteca(b);
				printf(" Saindo do programa!\n");
			break;
			default:
				printf(" Opção inválida!\n");
		} //fim switch
		//getch(); //esperar digitar tecla
		system("cls");
	}
	while(n !=0);
	
	return 0;
}
