%{
//#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror (const char *s);
void print_header();
void addString(char *s);
void printType();
void checkID(char *s);

extern int yylineno;

char str[15][10];
int numStrings = 0;


struct Compile
{
	FILE *output_file;
} c;

%}
%union {char *str; int num;}
%start line

%token PRINT VAR BEG PROGRAM END
%token<str> INTEGER ID NUMBER QUOTE
%type<str> pname dec_list stat_list stat print output dec type
%type<str> term expr factor assign
%left '-' '+'
%left '*' '/'

%%

line : PROGRAM pname';'{ print_header(); } var dec_list';' { fprintf(c.output_file, ";\n"); } BEG stat_list END { printf("Start Completed\n"); }
    |                   { yyerror("PROGRAM is expected."); exit(1); }
    ;

pname: ID						    { $$ = $1; }
    |                   { yyerror("Program name <pname> is expected."); exit(1); }
		;

var: VAR
    |                   { yyerror("VAR is expected."); exit(1); }

dec_list: dec ':' type	{ printType(); }
		| dec type          { yyerror(": is missing"); }
		;

dec: ID',' dec 				  { addString($1); }
		| ID dec            { yyerror(", is missing"); }
		| ID                { $$ = $1; addString($1); }
		;

stat_list: stat';' stat_list	{ $$ = $1; }
		| stat';'               { $$ = $1; }
		| stat                  { yyerror("; is missing"); }
		;

stat: print             { $$ = $1; fprintf(c.output_file, ";\n"); }
		| assign            { $$ = $1; fprintf(c.output_file, ";\n"); }
		;

print: PRINT'(' output ')'	{ $$ = $3; }
		| PRINT output ')'			{ yyerror("( is missing"); }
		| PRINT '(' output			{ yyerror(") is missing"); }
		;

output: QUOTE',' ID     {  checkID($3); fprintf(c.output_file, "cout << %s << %s << endl", $1, $3);}
    | ID                {  fprintf(c.output_file, "cout << %s << endl", $1);  }
		;

assign: ID '=' expr			{ fprintf(c.output_file, "%s = %s", $1, $3);  checkID($1); }
		| ID expr           { yyerror("= is missing"); }
		;

expr: term					    { $$ = $1; }
		| expr '+' term			{ $$ = $1;  strcat($$, " + "); strcat($$, $3);}
		| expr '-' term			{  $$ = $1; strcat($$, " - "); strcat($$, $3);}
		;

term: term '*' factor		{ $$ = $1;  strcat($$, " * "); strcat($$, $3);}
		| term '/' factor		{ $$ = $1;  strcat($$, " / "); strcat($$, $3);}
		| factor            { $$ = $1;}
		;

factor: ID						  { $$ = $1; checkID($1); }
		| NUMBER            { $$ = $1; }
		| '(' expr ')'			{ $$ = $2; }
		| expr ')'          { yyerror("( is missing"); }
		| '(' expr          { yyerror(") is missing"); }
		;

type: INTEGER					  { $$ = $1; }
		;

%%

int main(int argc, char *argv[])
{
	  c.output_file = fopen("abc13.cpp", "w");

    if (c.output_file == NULL)
    {
        printf("Error!\n");
        return 1;
    }

	yyparse();
  fprintf(c.output_file, "%s\n", "return 0;");
  fprintf(c.output_file, "%s\n", "}");
	fclose(c.output_file);
	return 0;
}

void print_header()
{
	fprintf(c.output_file, "%s\n", "#include <iostream>");
	fprintf(c.output_file, "%s\n", "using namespace std;");
	fprintf(c.output_file, "%s\n", "int main() {");
}

void addString(char *s)
{
	if (numStrings > 14)
	{
		printf("Too many variables, must be under 15\n");
		return;
	}

	strcpy(str[numStrings], s);
	numStrings += 1;
}

void checkID(char *s)
{
    int i;
    int stringflag = 1;

    for (i = 0; i < numStrings; i++)
    {
        if (strcmp(str[i], s) == 0)
        {
            stringflag = 0;
        }
    }

    if (stringflag == 1)
    {
        yyerror("UNKNOWN IDENTIFIER");
    }
}

void printType()
{
	int i;

	fprintf(c.output_file, "int ");

	for (i = 0; i < numStrings - 1; i++ )
	{
		fprintf(c.output_file, "%s, ", str[i]);
	}

	fprintf(c.output_file, "%s", str[numStrings - 1]);
}

void yyerror (const char *s)
{
	printf("%s on line %d\n", s, yylineno);
}
