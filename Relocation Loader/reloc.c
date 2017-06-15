#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void convert(char h[12]);
char bitmask[12];
char bit[12]={0};
void main()
{
	char add[6],length[10],input[10],pn[5],ch,relocbit;
	int start,i,address,addr,actualadd,opcode,tlen,temp_address;  //here
	FILE *fp1,*fp2;
	
	printf("\nEnter starting address: ");
	scanf("%x",&start);
	address=start;  //here
	fp1=fopen("RLIN.DAT","r");
	fp2=fopen("RLOUT.DAT","w");
	fscanf(fp1,"%s",input);
	fprintf(fp2,"ADDRESS\tCONTENT\n");
	
	while(strcmp(input,"E")!=0)
	{
		if(strcmp(input,"H")==0)
			fscanf(fp1,"%s%s%s",pn,add,length);
		else if(strcmp(input,"T")==0)
		{
			fscanf(fp1,"%x%x%s",&temp_address,&tlen,bitmask);   //here
			convert(bitmask);
			for(i=0;i<tlen/3;i++)
			{
				fscanf(fp1,"%x%x",&opcode,&addr);
				relocbit=bit[i];
				if(relocbit=='0')
					actualadd=addr;
				else
					actualadd=addr+start;
				fprintf(fp2,"%x\t%x%x\n",address,opcode,actualadd);
				address+=3;
			}
		}
		fscanf(fp1,"%s",input);
	}
	fcloseall();
	
	fp2=fopen("RLOUT.DAT","r");
	ch=fgetc(fp2);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp2);
	}
}

void convert(char h[12])
{
	int i,l;
	l=strlen(h);
	strcpy(bit,"");
	for(i=0;i<l;i++)
	{
		switch(h[i])
		{
			case '0':
				strcat(bit,"0000");
				break;
			case '1':
				strcat(bit,"0001");
				break;
			case '2':
				strcat(bit,"0010");
				break;
			case '3':
				strcat(bit,"0011");
				break;
			case '4':
				strcat(bit,"0100");
				break;
			case '5':
				strcat(bit,"0101");
				break;
			case '6':
				strcat(bit,"0110");
				break;
			case '7':
				strcat(bit,"0111");
				break;
			case '8':
				strcat(bit,"1000");
				break;
			case '9':
				strcat(bit,"1001");
				break;
			case 'A':
				strcat(bit,"1010");
				break;
			case 'B':
				strcat(bit,"1011");
				break;
			case 'C':
				strcat(bit,"1100");
				break;
			case 'D':
				strcat(bit,"1101");
				break;
			case 'E':
				strcat(bit,"1110");
				break;
			case 'F':
				strcat(bit,"1111");
				break;
		}
	}
}
