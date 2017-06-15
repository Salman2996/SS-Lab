#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
 char label[10],opcode[10],operand[10],ch;
 char mnemonic[10][10]={"START","LDA","LDCH","STA","STCH","LDT","END"};
 int locctr,start,j=0;
 FILE *fp1,*fp2,*fp3;
 
 fp1=fopen("INPUT.DAT","r");
 fp2=fopen("SYMTAB.DAT","w");
 fp3=fopen("OUT.DAT","w");

 fscanf(fp1,"%s%s%s",label,opcode,operand);
 
 if(strcmp(opcode,"START")==0)
 {
	start=(int) strtol(operand,NULL,16);
	locctr=start;
	fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
	fscanf(fp1,"%s%s%s",label,opcode,operand);
 }
 else
 locctr=0;

 while(strcmp(opcode,"END")!=0)
 {
	j=0;
	fprintf(fp3,"%x",locctr);
	if(strcmp(label,"**")!=0)
	fprintf(fp2,"%s\t%x\n",label,locctr);

	while(strcmp(mnemonic[j],"END")!=0)
	{
	 if(strcmp(opcode,mnemonic[j])==0)
	 {
		locctr+=3;
		break;
	 }
	 j++;
	}

	if(strcmp(opcode,"WORD")==0)
	locctr+=3;
	else if(strcmp(opcode,"RESW")==0)
	locctr+=(3*(atoi(operand)));
	else if(strcmp(opcode,"RESB")==0)
	locctr+=(atoi(operand));
	else if(strcmp(opcode,"BYTE")==0)
	locctr++;
	
	fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
	fscanf(fp1,"%s%s%s",label,opcode,operand);
 }

 fprintf(fp3,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
 _fcloseall();

 printf("\nOutput table:\n");
 fp3=fopen("OUT.DAT","r");
 ch=fgetc(fp3);
 while(ch!=EOF)
 {
	printf("%c",ch);
	ch=fgetc(fp3);
 }
 printf("\nSymbol table:\n");
 fp2=fopen("SYMTAB.DAT","r");
 ch=fgetc(fp2);
 while(ch!=EOF)
 {
	printf("%c",ch);
	ch=fgetc(fp2);
 }
}
