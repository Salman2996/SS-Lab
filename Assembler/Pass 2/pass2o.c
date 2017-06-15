/*
 * With both object code generation and object program
 * Indexed addressing works
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
  char a[10],ad[10],label[10],opcode[10],operand[10],symbol[10],ch,index[10]; 
  int st,diff,i,address,add,len,actual_len,finaddr,prevaddr,j=0;
  char mnemonic[10][10]={"LDA","STA","LDT","LDCH","STCH"};
  char code[10][10]={"00","14","17","43","34"};
  FILE *fp1,*fp2,*fp3,*fp4;
  
  fp1=fopen("ASSMLIST.DAT","w");
  fp2=fopen("SYMTAB.DAT","r");
  fp3=fopen("OUT.DAT","r");
  fp4=fopen("OBJCODE.DAT","w");
  fscanf(fp3,"%s%s%s",label,opcode,operand);

  while(strcmp(opcode,"END")!=0)
  {
   prevaddr=address;
   fscanf(fp3,"%x%s%s%s%s",&address,label,opcode,operand,index);
  }
  finaddr=address;
  fclose(fp3);
  fp3=fopen("OUT.DAT","r");

  fscanf(fp3,"%s%s%s",label,opcode,operand);
  if(strcmp(opcode,"START")==0)
  {
   fprintf(fp1,"\t%s\t%s\t%s\n",label,opcode,operand);
   fprintf(fp4,"H^%s^00%s^00%x\n",label,operand,(finaddr-(int)strtol(operand,NULL,16)));
   fscanf(fp3,"%x%s%s%s%s",&address,label,opcode,operand,index);
   st=address;
   diff=prevaddr-st;
   fprintf(fp4,"T^00%x^%x",address,diff-0x1000);
  }
  while(strcmp(opcode,"END")!=0)
  {
   if(strcmp(opcode,"BYTE")==0)
   {
    fprintf(fp1,"%x\t%s\t%s\t%s",address,label,opcode,operand);
    len=strlen(operand);
    actual_len=len-3;
    fprintf(fp4,"^");
    for(i=2;i<(actual_len+2);i++)
    {
     //itoa(operand[i],ad,16);
	sprintf(ad,"%x",operand[i]);
     fprintf(fp1,"%s",ad);
     fprintf(fp4,"%s",ad);
    }
    fprintf(fp1,"\t%s\n",index);
   }
   else if(strcmp(opcode,"WORD")==0)
   {
    len=strlen(operand);
    //itoa(atoi(operand),a,10);
	sprintf(a,"%x",atoi(operand));
    fprintf(fp1,"%x\t%s\t%s\t%s\t00000%s\t%s\n",address,label,opcode,operand,a,index);
    fprintf(fp4,"^00000%s",a);
   }
   else if((strcmp(opcode,"RESB")==0)||(strcmp(opcode,"RESW")==0))
    fprintf(fp1,"%x\t%s\t%s\t%s\t%s\n",address,label,opcode,operand,index);
   else
   {
    j=0;
    while(strcmp(opcode,mnemonic[j])!=0)
     j++;
    if(strcmp(operand,"COPY")==0)
     fprintf(fp1,"%x\t%s\t%s\t%s\t%s0000\n",address,label,opcode,operand,code[j]);
    else
    {
     rewind(fp2);
     fscanf(fp2,"%s%x",symbol,&add);
      while(strcmp(operand,symbol)!=0)
       fscanf(fp2,"%s%x",symbol,&add);
     if(strcmp(index,"**")!=0)
     {
     	if(index[0]==',')
     		add+=0x9000-0x1000;
     }
     fprintf(fp1,"%x\t%s\t%s\t%s\t%s\t%s%x\n",address,label,opcode,operand,index,code[j],add);
     fprintf(fp4,"^%s%x",code[j],add);
    }
   }
   fscanf(fp3,"%x%s%s%s%s",&address,label,opcode,operand,index);
  }
  fprintf(fp1,"%x\t%s\t%s\t%s\t%s\n",address,label,opcode,operand,index);
  fprintf(fp4,"\nE^00%x",st);
  printf("\n Intermediate file is converted into object code");
  _fcloseall();

  /*printf("\n\nThe contents of Intermediate file:\n\n\t");
  fp3=fopen("OUT.DAT","r");
  ch=fgetc(fp3);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp3);
  }
  printf("\n\nThe contents of Symbol Table :\n\n");
  fp2=fopen("SYMTAB.DAT","r");
  ch=fgetc(fp2);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp2);
  }*/

  printf("\n\nThe contents of Output file :\n\n");
  fp1=fopen("ASSMLIST.DAT","r");
  ch=fgetc(fp1);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp1);
  }

  printf("\n\nThe contents of Object code file :\n\n");
  fp4=fopen("OBJCODE.DAT","r");
  ch=fgetc(fp4);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp4);
  }
  printf("\n");
  _fcloseall();
}
