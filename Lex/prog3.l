// Check for a valid expression

%{
	#include<stdio.h>
	int stack=0, valid=1, opd=0, opt=0;
%}

%%

"(" 						{stack++;} 
")" 						{stack--; 
							 if(stack < 0) 
								valid = 0;
							}
[a-zA-Z][a-zA-Z0-9]* 		{opd++;printf("%s is an operand\n", yytext);}
[+\-*/] 					{opt++;printf("%s is an operator\n", yytext);} 
[\n] 						;

%%

int main(){
	printf("\nEnter the expression: ");
	yylex();
	if(stack==0 && valid && opd-opt==1){
		printf("Valid\n");
	}
	else{
		printf("Invalid");
	}
	return 0;
}

int yywrap(){
	return 1;
}