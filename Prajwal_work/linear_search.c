#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int array[5] = {2,3,4,5,6};

    for(i = 0; i < 5; i++) {
        printf("array = %d\n", array[i]);
    }
    printf("enter no to search: ");
    scanf("%d", &n);
    for(i = 0; i < 5; i++) {
        if(array[i] == n) {
            printf("found\n");
            break;
        }
        // else {
        //     printf("Not found\n");
        // }
        // i++;
    }
    printf("Not found\n");
    printf("Exit\n");

return 0;
}
