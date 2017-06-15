// Count the number comments in a file 

%{
	#include<stdio.h>
	int c=0;
%}

%%

"/*"[^("*/")]+"*/" 	{c++;}
\/\/ 				{c++;}

%%

int main(int argc, char *argv[]){
	yyin = fopen(argv[1],"r");
	yylex();
	printf("%d\n", c);
	return 0;
}