// Exercício 5 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	
	int vvt=0,numero=0,n,aleatorio,vetor[vvt];
	float soma=0;
	
	printf(" Digite o tamanho do vetor: ");
	
	do
	{
		scanf("%d",&vvt);
		if(vvt>50)
		{
			printf("\n Valor máximo de 50 bases.");
			printf(" Digite o vetor do vetor: ");
		}	
	}
	
	while(vvt>50);
	
	printf("\n");
	printf(" Para digitar os valores clique 1 e para gerar o vetor clique 2: ");
	
	do{
		if(numero == 0)
		{
			scanf("%d",&numero);
		}
		else if(numero != 1 && numero != 2)
		{
			printf("\n");
			printf(" Opção Invalida!\n");
			printf(" Tente novamente...\n\n");
			printf(" Para digitar os valores clique 1 e para gerar o vetor clique 2: ");
			scanf("%d",&numero);
		}
	}
	
	while(numero != 1 && numero != 2);
	
	if(numero == 1)
	{
		printf("\n");
		printf(" Digite os valores do vetor:\n");
		
		for(n=0;n<vvt;n++)
		{
			printf(" %d: ",n);
			scanf("%c",&vetor[n]);
			vetor[n] = toupper(vetor[n]);
		}
	}
	else if(numero == 2)
	{
		printf("\n");
		printf(" Os valores gerados são:\n");
		
		for(n=0;n<vvt;n++)
		{
			aleatorio = rand() % 4;
			switch(aleatorio)
			{
				case 0:
					vetor[n] = 'A';
					printf(" %d: %c\n",n,'A');
					break;
				case 1:
					vetor[n] = 'T';
					printf(" %d: %c\n",n,'T');
					break;
				case 2:
					vetor[n] = 'C';
					printf(" %d: %c\n",n,'C');
					break;
				case 3:
					vetor[n] = 'G';
					printf(" %d: %c\n",n,'G');
					break;
			}
		}
	}
	
	printf("\n");
	printf(" Os valores do vetor são:\n");
	
	for(n=0;n<vvt;n++)
	{
		printf(" %c",vetor[n]);
		printf("\n");
	}
	
	printf("\n");
	printf(" O vetor complementar do DNA é:");
	
	for(n=0;n<vvt;n++)
	{
		switch(vetor[n])
		{
			case 'A':
				vetor[n] = 'T';		
				break;
			case 'T':
				vetor[n] = 'A';
				break;
			case 'C':
				vetor[n] = 'G';
				break;
			case 'G':
				vetor[n] = 'C';
				break;
		}
		printf(" %c",vetor[n]);			
	}	
    return 0;
}
