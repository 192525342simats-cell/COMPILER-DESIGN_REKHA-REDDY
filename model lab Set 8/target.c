#include <stdio.h>
#include <string.h>

int main()
{
    char op[10],a[10],b[10],c[10];

    printf("Enter TAC (example: t1 = b + c):\n");
    scanf("%s = %s %s %s",a,b,op,c);

    printf("\nTarget Code:\n");
    printf("MOV R0, %s\n",b);

    if(strcmp(op,"+")==0)
        printf("ADD R0, %s\n",c);
    else if(strcmp(op,"-")==0)
        printf("SUB R0, %s\n",c);
    else if(strcmp(op,"*")==0)
        printf("MUL R0, %s\n",c);
    else if(strcmp(op,"/")==0)
        printf("DIV R0, %s\n",c);

    printf("MOV %s, R0\n",a);

    return 0;
}