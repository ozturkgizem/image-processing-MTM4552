#include <stdio.h>
#include <stdlib.h>
int main()
{
	int array[]={1,2,3,4,5,6,-8,-10},i;
	int n=sizeof(array)/sizeof(array[0]);
	FILE *fp;
	fp=fopen("block.bin","wb");
	//first way
	for(i=0;i<n;i++)
	     fwrite(&array[i],sizeof(int),1,fp);
	//second way
	fwrite(array,sizeof(int),n,fp);//writing the files as block
	fclose(fp);
	return 0;
}
