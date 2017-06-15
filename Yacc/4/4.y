%{
	#include<stdio.h>
%}

%token ID NUMBER NL
%left '+' '-'
%left '*' '/'

%%

stmt : ID '=' exp NL	{printf("\nValue: %s = %d\n",$1,$3); exit(0);}
	;

exp : exp '+' exp 	{$$=$1+$3;}
	 | exp '-' exp 	{$$=$1-$3;}
	 | exp '*' exp  {$$=$1*$3;}
	 | exp '/' exp  {if($3==0){
	 					printf("\nCannot divide by 0!");
	 					exit(0);
	 				 }
	 				 $$=$1/$3;
	 				}
	 | '(' exp ')'	{$$=$2;}
	 | ID 			{$$=$1;}
	 | NUMBER 		{$$=$1;}
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