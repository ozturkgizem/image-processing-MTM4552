//A small program for writing to binary files
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	int x=123456;
	double f=1.899;
	fp=fopen("data.bin","wb");//data.bin is opened in writing mode as binary file 
    fwrite(&x,sizeof(int),1,fp);
	fwrite(&f,sizeof(double),1,fp);
	fclose(fp);	
}
