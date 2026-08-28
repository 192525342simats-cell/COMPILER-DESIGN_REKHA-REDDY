%{
#include <stdio.h>
int count=0;
%}

%%
[\(\)\{\}\[\],;]  { count++; }
.|\n              ;
%%

int main()
{
    printf("Enter C program:\n");
    yylex();
    printf("Number of special symbols = %d\n",count);
    return 0;
}

int yywrap()
{
    return 1;
}