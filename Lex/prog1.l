// Count the number lines, spaces, characters and words in a file

%{
	#include<stdio.h>
	int l=0, s=0, c=0, w=0;
%}
%%
[^ \n\t,.:;'"]+ 	{w++; c+=yyleng;}
[ ] 				{s++;}
[\n] 				{l++;}
. 					{c++;}
%%

int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	yylex();
	printf("Lines : %d\nSpaces : %d\nChar : %d\nWords : %d\n", l, s, c, w);
	return 0;
}

int yywrap(){
	return 1;
}