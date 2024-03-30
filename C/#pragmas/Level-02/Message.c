#include <stdio.h>

#define message(x) _Pragma (#x)

int main() {
    message(message("Hello, this is a message during compilation!"))
    printf("This is the actual program.\n");
    return 0;
}
