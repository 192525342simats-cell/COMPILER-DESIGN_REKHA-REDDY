%{
#include <stdio.h>
%}

%%
[0-9]+(\.[0-9]+)?    { printf("%s\n", yytext); }
\"([^\"\\]|\\.)*\"    { printf("%s\n", yytext); }
\'([^\'\\]|\\.)*\'    { printf("%s\n", yytext); }
%%

int main()
{
    yyin = fopen("sample.c", "r");
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}
