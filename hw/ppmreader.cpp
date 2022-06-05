#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include <fcntl.h>
#include <malloc.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795
#pragma pack(1)
struct ppm_header
{
	char pgmtype1;
	char pgmtype2;
	int pwidth;
	int pheight;
	int pmax;
};
struct ppm_file
{
	struct ppm_header *pheader;
	unsigned char *rdata,*gdata,*bdata;
};
void get_image_data(char *filename,struct ppm_file *image);
void write_image(char *filename,struct ppm_file *image);
void write_image(char *filename,struct ppm_file *image)
{
	FILE *fp;
	int i,max=0;
	fp=fopen(filename,"wb");
	fputc(image->pheader->pgmtype1,fp);
	fputc(image->pheader->pgmtype2,fp);
	fputc('\n',fp);
	fprintf(fp,"%d %d\n",image->pheader->pwidth,image->pheader->pheight);
	fprintf(fp,"%d\n",255/*max*/);
	for(i=0;i<image->pheader->pwidth*image->pheader->pheight;i++)
	{
		fwrite(&image->rdata[i],1,1,fp);
		fwrite(&image->gdata[i],1,1,fp);
		fwrite(&image->bdata[i],1,1,fp);
	}
	fclose(fp);
}
void get_image_data(char *filename, struct ppm_file *image ) 
{
	FILE* fp;
	int i=0;
	char temp[256];
	image->pheader=(struct ppm_header *)malloc(sizeof(struct ppm_header));
	fp = fopen(filename, "rb" );
	if (fp==NULL) 
	{
		printf("File is not opened: %s.\n\n", filename);
		exit(1);
	}
	printf ("The PPM File : %s...\n", filename);
	fscanf (fp, "%s", temp);
	if (strcmp(temp, "P6") == 0) 
	{
		image->pheader->pgmtype1=temp[0];
		image->pheader->pgmtype2=temp[1];
		fscanf (fp, "%s", temp);
		if (temp[0]=='#') 
		{
			while(fgetc(fp)!='\n');
			fscanf (fp, "%d %d\n",&image->pheader->pwidth,&image->pheader->pheight);
			fscanf (fp, "%d\n", &image->pheader->pmax);
		}
		else
		{
			sscanf (temp, "%d", &image->pheader->pwidth);
			fscanf (fp, "%d", &image->pheader->pheight);
			fscanf (fp, "%d", &image->pheader->pmax);
		}
		image->rdata=(unsigned char *)malloc(image->pheader->pheight*image->pheader->pwidth*sizeof(unsigned char));
		image->gdata=(unsigned char *)malloc(image->pheader->pheight*image->pheader->pwidth*sizeof(unsigned char));
		image->bdata=(unsigned char *)malloc(image->pheader->pheight*image->pheader->pwidth*sizeof(unsigned char));
		if (image->rdata==NULL) printf("Memory problem\n");
		for(i=0;i<image->pheader->pwidth*image->pheader->pheight;i++)
		{
			fread(&image->rdata[i],1,1,fp);
			fread(&image->gdata[i],1,1,fp);
			fread(&image->bdata[i],1,1,fp);
		}
	}
	else 
	{
		printf ("\nError! The file is not a PPM file");
		exit(1);
	}
	fclose(fp);
}
int main()
{	
	struct ppm_file picture;
	int i;
	get_image_data("mandrill.ppm",&picture);
	//Information of image
	printf("pgmtype...=%c%c\n",picture.pheader->pgmtype1,picture.pheader->pgmtype2);
	printf("width...=%d\n",picture.pheader->pwidth);
	printf("height...=%d\n",picture.pheader->pheight);
	printf("max gray level...=%d\n",picture.pheader->pmax);
	write_image("pnr.ppm",&picture);
	return 0;
} 
