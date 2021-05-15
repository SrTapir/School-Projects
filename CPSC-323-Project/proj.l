%{
	#include <stdlib.h>
	#include <stdio.h>
  #include <string.h>
	#include "y.tab.h"

  extern c;
%}
%option yylineno
%x C_COMMENT
%%
"(*"								{ BEGIN(C_COMMENT); }
<C_COMMENT>"*)"			{ BEGIN(INITIAL); }
<C_COMMENT>. 				{}
"PROGRAM"						{ return PROGRAM; }
"VAR"				  			{ return VAR; }
"INTEGER"						{ return INTEGER; }
"BEGIN"							{ return BEG; }
"PRINT"							{ return PRINT; }
"END."							{ return END; }
'(\\.|[^\\'])*'     {
                      int len = strlen(yytext);
                      yytext[0] = '\"';
                      yytext[len - 1] = '\"';
                      yylval.str = strdup(yytext);
                      return QUOTE;
                    }
[a-f][a-f0-9]*			{ yylval.str = strdup(yytext); return ID; }
[0-9]+							{ yylval.str = strdup(yytext); return NUMBER;}
[ \t\n] 						{}
[-+=:,();\*]				{ return yytext[0]; }

. 									{ECHO; yyerror ("Unexpected character");}

%%

int yywrap()
{
	return 1;
}
