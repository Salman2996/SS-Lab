%{
	#include<stdio.h>
%}

%token LETTER DIGIT NL UND

%%

stmt : variable NL		{printf("\nValid identifier!"); exit(0);}
	;

variable : LETTER alphanumeric
	;

alphanumeric : LETTER alphanumeric
			  | DIGIT alphanumeric
			  | UND alphanumeric
			  | LETTER
			  | DIGIT
			  | UND
	;

%%

int yyerror(char *msg){
	printf("\nInvalid Expression");
	exit(0);
}

int main(){
	printf("\nEnter variable name: ");
	yyparse();
}