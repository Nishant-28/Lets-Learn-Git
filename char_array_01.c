#include <stdio.h>
#include <string.h>

int main(){
    char C[]="John";
    // char C[5] = {'J','O','H','N','\0'};
    // C[0] = 'J';
    // C[1] = 'o';
    // C[2] = 'h';
    // C[3] = 'n';
    // C[4] = '\0';
    printf("%s\n",C);
    printf("Size of bytes = %ld\n", sizeof(C));
    int len = strlen(C);
    printf("Length = %d\n", len);
    return 0;
}