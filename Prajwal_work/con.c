#include <stdio.h>
#include <ctype.h>


int main(){
    char word[] = "prajwal";
    char chr;
    int i = 0;

    while(word[i]){
        chr = word[i];
        printf("%c", toupper(chr));
        i++;
    }
    printf("\n");
    return 0;
}
