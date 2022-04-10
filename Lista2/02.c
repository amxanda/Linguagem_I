// Exercício 2 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main()
{
	setlocale(LC_ALL,"");
	
	int t,n=0,vetorA[t],maior,menor;
	
	printf(" Informe o tamanho do vetor: ");
	scanf("%d",&t);
	
	printf("\n Digite o valor desejado: \n");
	
	while(n<t)
	{
		printf(" [%d] = ",n);
		scanf(" %d",&vetorA[n]);
		
		menor=vetorA[n];
		maior=vetorA[n];
		
		n++;
	}
	
	for(n=0;n<t;n++)
	{
		if(vetorA[n]<menor)
		{
			menor=vetorA[n];
		}
		else
		if(vetorA[n]>maior)
		{
			maior=vetorA[n];
		}	
	}
	
	printf("\n O menor e o maior número do vetor são respectivamente: %d, %d.\n",menor,maior);
	
	return 0;
}

