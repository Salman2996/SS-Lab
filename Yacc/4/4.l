%{
	#include "y.tab.h"
	extern int yylval;
%}

%%

[ ]						;
[a-zA-Z][a-zA-Z0-9_]*	{yylval=strdup(yytext); return ID;}
[0-9]+					{yylval=atoi(yytext); return NUMBER;}
\n 						{return NL;}
.						{return yytext[0];}

%%

int yywrap(){
	return 1;
}