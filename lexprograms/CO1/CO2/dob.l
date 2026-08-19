%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

(0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[0-2])\/[0-9]{4} {
    printf("Valid Date of Birth: %s\n", yytext);
}

(0[1-9]|[12][0-9]|3[01])-[0-9]{2}-[0-9]{4} {
    printf("Invalid Date of Birth: %s (Check day, month, or year format)\n", yytext);
}

[ \t\n]+ {
    /* Ignore whitespace and newlines */
}

. {
    /* Ignore any other character */
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Date of Birth (DD/MM/YYYY or DD-MM-YYYY):\n");
    yylex();
    return 0;
}