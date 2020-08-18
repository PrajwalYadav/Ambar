#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void demo() {
    // int exit_code = 0;
    printf("Hello...");
    _Exit(0);
    // exit(0);
}
int
main()
{
    printf("Hello..");

    // int exit_code = 10;
    printf("Hello...");
    demo();
    // _Exit(exit_code);

    printf("Hello");

}
