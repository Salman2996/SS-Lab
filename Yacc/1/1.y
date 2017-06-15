%{
	#include<stdio.h>
%}

%token ID NUMBER NL
%left '+' '-'
%left '*' '/'

%%

stmt : ID '=' exp NL	{printf("\nValid expression!"); exit(0);}
	;

exp : exp '+' exp
	 | exp '-' exp
	 | exp '*' exp
	 | exp '/' exp
	 | '(' exp ')'
	 | ID
	 | NUMBER
	 ;

%%

int yyerror(char *msg){
	printf("\nInvalid Expression");
	exit(0);
}

int main(){
	printf("\nEnter expression: ");
	yyparse();
}