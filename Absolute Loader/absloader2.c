/*
 * Without xx's
 * Learn this one
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
 char ch,label[10],input[10];
 int address,length,start,l;
 FILE *fp1,*fp2;

 fp1=fopen("input_1.dat","r");
 fp2=fopen("out.dat","w");

 fscanf(fp1,"%s",input);

 while(strcmp(input,"E")!=0)
 {
	if(strcmp(input,"H")==0)
	{	
		fscanf(fp1,"%s%x%x%s",label,&start,&length,input);
	}
 	else if(strcmp(input,"T")==0)
	{	
		fscanf(fp1,"%x%x%s",&address,&length,input);
		fprintf(fp2,"%x\t%c%c\n",address,input[0],input[1]);
		fprintf(fp2,"%x\t%c%c\n",(address+1),input[2],input[3]);
		fprintf(fp2,"%x\t%c%c\n",(address+2),input[4],input[5]);
		address+=3;
		fscanf(fp1,"%s",input);
	}
	else
	{
		l=strlen(input);
		if(l==6)
		{
	 	fprintf(fp2,"%x\t%c%c\n",address,input[0],input[1]);
		fprintf(fp2,"%x\t%c%c\n",(address+1),input[2],input[3]);
		fprintf(fp2,"%x\t%c%c\n",(address+2),input[4],input[5]);
		address+=3;
		}
		else if(l==4)
		{
	 	fprintf(fp2,"%x\t%c%c\n",address,input[0],input[1]);
		fprintf(fp2,"%x\t%c%c\n",(address+1),input[2],input[3]);
		address+=2;
		}
		else if(l==2)
		{
	 	fprintf(fp2,"%x\t%c%c\n",address,input[0],input[1]);
		//fprintf(fp2,"%x\t%c%c\n",(address+1),input[2],input[3]);
		address+=1;
		}
		fscanf(fp1,"%s",input);
	}
 }


_fcloseall();

fp2=fopen("out.dat","r");
ch=fgetc(fp2);
while(ch!=EOF)
{
	printf("%c",ch);
	ch=fgetc(fp2);
}
}
