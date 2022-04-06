#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateRandom(int array[],int n)
{
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++)
	   array[i]=rand()%100;
    return;
}
int main()
{
	int array[120],n=120,i,j,w=10,h=12;
	generateRandom(array,n);
	for(i=0;i<n;i++) printf("%4d",array[i]);
	//How I can print all the values in matrix form
	printf("\n\n\n\n\n");
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		    printf("%4d",array[i*w+j]);
		printf("\n");
	}
	return 0;
}
