// Exercício 1 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

main()
{	
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	int t,valor,n=0,soma=0,aleatorio,vetor[100];
		
	printf(" Informe o tamanho do vetor: ");
	scanf("%d",&t);
		
	printf("\n 1: Digitar valores do vetor!");
	printf("\n 2: Gerar valores do vetor automaticamente!\n");
	printf("\n Insira o valor desejado: ");
	scanf("%d",&valor);
		
	switch (valor)
	{
		case 1:
			printf("\n Digite os valores para o vetor: \n");
				
			while(n<t)
			{
				printf(" [%d] = ",n);
				scanf("%d",&vetor[n]);
				
				soma=soma+vetor[n];
				
				n++;
			}
		break;
		case 2:
			printf("\n Valores gerados: \n");
			
			while(n<t)
			{
				aleatorio=rand()%10;
				printf(" [%d] = %d \n",n,aleatorio);
				vetor[n]=aleatorio;
				
				soma=soma+vetor[n];
				
				n++;
			}
		break;
		default:
			printf(" Valor invalido!");
		return 0;
	}
	
	printf("\n");
	printf(" A soma dos números do vetor é de %d.\n",soma);
	
	return 0;
}
