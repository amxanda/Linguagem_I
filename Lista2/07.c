// Exercício 7 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main()
{	
	setlocale(LC_ALL,"");
	
	int t,valor,n=0,aleatorio,vetor1[t],vetor2[t],vetor3[t];
		
	printf(" Informe o tamanho do vetor: ");
	scanf("%d",&t);
		
	printf("\n 1: Digitar valores do vetor!");
	printf("\n 2: Gerar valores do vetor automaticamente!\n");
	printf("\n Insira o valor desejado: ");
	scanf("%d",&valor);
	
	switch (valor)
	{
		case 1:
			printf("\n Digite os valores para o vetor 1: \n");
				
			for(n=0;n<t;n++)
			{
				printf(" [%d] = ",n);
				scanf("%d",&vetor1[n]);
			}
			
			printf("\n Digite os valores para o vetor 2: \n");
				
			for(n=0;n<t;n++)
			{
				printf(" [%d] = ",n);
				scanf("%d",&vetor2[n]);
			}
		break;
		case 2:
			printf("\n Valores gerados para vetor 1: \n");
			
			for(n=0;n<t;n++)
			{
				aleatorio=rand()%10;
				printf(" [%d] = %d \n",n,aleatorio);
				vetor1[n]=aleatorio;
			}
			
			printf("\n Valores gerados para vetor 2: \n");
			
			for(n=0;n<t;n++)
			{
				aleatorio=rand()%10;
				printf(" [%d] = %d \n",n,aleatorio);
				vetor2[n]=aleatorio;
			}
		break;
		default:
			printf(" Valor invalido!");
		return 0;
	}
	
	printf("\n Resultado da multiplicação dos vetores: \n");
	
	for(n=0;n<t;n++)
	{
		vetor3[n]=vetor1[n]*vetor2[n];
		printf(" [%d] = %d \n",n,vetor3[n]);
	}

	return 0;
}
