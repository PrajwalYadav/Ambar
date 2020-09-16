#include <stdio.h>

void add(int a, int b) {
    int c = a + b;
    printf("%d\n", c);
}

int main() {
    printf("Hello World..\n");
    add(2,3);
    return 0;
}