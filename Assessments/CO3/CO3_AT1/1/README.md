i) %{
#include <stdio.h>
%}
%token NUMBER
%left '+'
%left '*'
%%
expr : expr '+' expr
     | expr '*' expr
     | NUMBER
     ;
%%
int main()
{
    yyparse();
    return 0;
}
int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}

ii) %{
#include <stdio.h>
%}
%token NUMBER
%left '+'
%left '*'
%%
expr : expr '+' expr   { $$ = $1 + $3; }
     | expr '*' expr   { $$ = $1 * $3; }
     | NUMBER          { $$ = $1; }
     ;
%%
int main()
{
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}

iii) 3 + 4 * 5
= 3 + (4 * 5)
= 3 + 20
= 23

iv) %{
#include <stdio.h>
%}
%token NUMBER
%left '+'
%left '*'
%%
input : expr { printf("Result = %d\n", $1); }
      ;
expr : expr '+' expr   { $$ = $1 + $3; }
     | expr '*' expr   { $$ = $1 * $3; }
     | NUMBER          { $$ = $1; }
     ;
%%
int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}
int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}
