//A small program for reading data from the file
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	int x;
	double f;
	fp=fopen("data.bin","rb");
	fread(&x,sizeof(int),1,fp);
	fread(&f,sizeof(double),1,fp);
	printf("x value read from the file:%d",x);
	printf("\nf value read from the file:%f",f);
	fclose(fp);
}
