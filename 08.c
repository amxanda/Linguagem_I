// Exerc�cio 8 - Lista 2

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main()
{	
	setlocale(LC_ALL,"");
	
	int t,x,n=0,vetorA[t],vetorB[t];
		
	printf(" Informe o tamanho do vetor: ");
	scanf("%d",&t);
	
	while(n<t)
	{
		printf(" [%d] = ",n);
		scanf("%d",&vetorA[n]);
		
		n++;
	}
	
	printf("\n Digite um n�mero para a multiplica��o: ");
	scanf("%d",&x);
	
	printf("\n O vetor B �: \n");
	
	n=0;
	
	while(n<t)
	{
		vetorB[n]=vetorA[n]*x;
		printf(" [%d] = %d \n",n,vetorB[n]);
		
		n++;
	}

	return 0;
}
