# include <stdio.h>
# include <string.h>
# include <stdlib.h>
struct deftab
{
	char lab[10], opc[10], oper[10];
}d[10];
void main()
{
	char label[10],opcode[10],operand[10],macroname[10];
	int i,lines,flag=0;
	FILE *f1,*f2,*f3;
	f1=fopen("macin.dat","r");
	f2=fopen("macout.dat","w");
	f3=fopen("deftab.dat","w");
	fscanf(f1,"%s%s%s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		if(strcmp(opcode,"MACRO")==0)
		{
			strcpy(macroname,label);
			fscanf(f1,"%s%s%s",label,opcode,operand);
			lines=0;
			while(strcmp(opcode,"MEND")!=0)
			{
				fprintf(f3,"%s\t%s\t%s\n",label,opcode,operand);
				strcpy(d[lines].lab,label);
				strcpy(d[lines].opc,opcode);
				strcpy(d[lines].oper,operand);
				fscanf(f1,"%s%s%s",label,opcode,operand);
				lines++;
			}
		}
		else if(strcmp(opcode,macroname)==0)
		{
			if(strcmp(label,"**")!=0)
				flag=1;
			for(i=0;i<lines;i++){
				if(flag==1){
					fprintf(f2,"%s\t%s\t%s\n",label,d[i].opc,d[i].oper);
					flag=0;
				}
				else
					fprintf(f2,"%s\t%s\t%s\n",d[i].lab,d[i].opc,d[i].oper);
			}
		}
		else
			fprintf(f2,"%s\t%s\t%s\n",label,opcode,operand);
		fscanf(f1,"%s%s%s",label,opcode,operand);
	}
	fprintf(f2,"%s\t%s\t%s\n",label,opcode,operand);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	f2=fopen("macout.dat","r");
	f3=fopen("deftab.dat","r");
	printf("\nThe expanded program is as follows:\n");
	char ch=fgetc(f2);
	while(ch!=EOF)
 	{
		printf("%c",ch);
		ch=fgetc(f2);
 	}
 	printf("\nThe definition table is as follows:\n");
 	ch=fgetc(f3);
	while(ch!=EOF)
 	{
		printf("%c",ch);
		ch=fgetc(f3);
 	}
}