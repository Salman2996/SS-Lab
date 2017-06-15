%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token A B NL

%%

stmt : as bs NL		
	  | as NL
	  | bs NL
	  | NL				{printf("Valid!"); exit(0);}
	;

as : A as
	| A
	;

bs : B bs
	| B
	;

%%

int main(){
	printf("\nEnter expression: ");
	yyparse();
}

int yyerror(char *s){
	printf("\n%s\n",s);
	return 0;
}