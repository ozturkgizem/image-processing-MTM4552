#include <stdio.h>
#include <stdlib.h>
int main()
{
	int array1[8],array2[8],i;
	FILE *fp;
	fp=fopen("block.bin","rb");
	if(fp==NULL)
	{
		printf("The file is not found");
		exit(1);
	}
	//first way
	for(i=0;i<8;i++)
	   fread(&array1[i],sizeof(int),1,fp);
	printf("The elements of array1 read from the block.bin:\n");
	for(i=0;i<8;i++) printf("%4d",array1[i]);
	//second way
	fread(array2,sizeof(int),8,fp);//the file is read as block
	printf("\nThe elements of array2 read from the block.bin:\n");
	for(i=0;i<8;i++) printf("%4d",array2[i]);
	return 0;
}
