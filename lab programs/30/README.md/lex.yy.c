### lex.yy.c

```c
#include <stdio.h>
#include <ctype.h>

int yylex(void);
int yywrap(void);

char str[200];
int i, consonants = 0;

int main()
{
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    yylex();

    printf("Number of consonants = %d\n", consonants);

    return 0;
}

int yylex(void)
{
    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);

        if (ch >= 'a' && ch <= 'z')
        {
            if (ch != 'a' && ch != 'e' &&
                ch != 'i' && ch != 'o' &&
                ch != 'u')
            {
                consonants++;
            }
        }
    }

    return 0;
}

int yywrap()
{
    return 1;
}
```
