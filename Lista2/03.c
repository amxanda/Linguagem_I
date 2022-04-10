// Exercício 3 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	int n=0,t,valor,vetor[t],aleatorio,impar=0;
	
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
				
				if(vetor[n] % 2!=0)
				{
					impar++;
				}		
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
				
				if(vetor[n] % 2!=0)
				{
					impar++;
				}
				n++;
			}
		break;
		default:
			printf(" Valor invalido!");
		return 0;
	}
	
	printf("\n No vetor, existem %d números impares.\n",impar);
	printf("\n O vetor é: \n");
	
	for(n=0;n<t;n++)
	{
		printf(" [%d] = %d \n",n,vetor[n]);
	}
	
	return 0;
}
