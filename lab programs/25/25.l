%{
#include <stdio.h>
%}

%%

[A-Z]+      { printf("Capital Word: %s\n", yytext); }
[ \t\n]+    ;
.           ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a sentence:\n");
    yylex();
    return 0;
}
