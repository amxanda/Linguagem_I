// Exercício 6 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	int t=0,numero,aleatorio,n=0,vetor[t];
	
	printf(" Informe o tamanho do vetor: ");
	scanf("%d",&t);
	
	printf(" Insira um valor a ser procurado no vetor: ");
	scanf("%d",&numero);
	
	while(n<t)
		{
			aleatorio=rand()%10;
			printf(" [%d] = %d \n",n,aleatorio);
			vetor[n]=aleatorio;
				
			n++;
		}
	
	for(n=0;n<t;n++)
	{	
		if(vetor[n]==numero)
		{
			printf("\n O número %d está na posição [%d].",numero,n);
		}
	}

	return 0;
}
