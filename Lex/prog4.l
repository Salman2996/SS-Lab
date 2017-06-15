// Find all the identifiers in a file

%{
	#include<stdio.h>
	int c=0;
%}

%%

("int")|("float")|("printf")|("scanf") 		{printf("%s is not an identifier\n",yytext);}
[a-zA-Z][a-zA-Z0-9_]* 						{c++; printf("%s is an identifier\n",yytext);}
.+ 											{printf("%s is not an identifier\n",yytext);}
\n 											;
%%

int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	yylex();
	printf("Number of identifiers : %d\n", c);
	return 0;
}
