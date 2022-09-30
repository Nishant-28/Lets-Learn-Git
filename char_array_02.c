#include <stdio.h>
#include <string.h>

int main()
{
    char c1[6] = "Hello";
    char *c2;
    c2=c1;
    printf("%c\n",c2[1]);
    c2[0] = 'A';
    // c2[i] is *(c2+i)
    return 0;
} 