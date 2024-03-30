// The MIT License (MIT)
// Copyright (c) 2024 WASSIM BOLLES JOKE ;)
#include <stdio.h>

// We have a macro in C programming named __attribute__
// The __attribute__ macro in C is a powerful feature provided by GCC and some other compilers
// that allows developers to provide additional information or hints to the compiler about certain aspects of functions,
// variables, or types. This macro can be particularly useful for controlling optimization.

// First Example:

int main(void)
{
    int var;    // We have an unused variable here.
    return 0;
}

// When we compile the code using the following flags: "-Wall -Wextra -Werror",
// we will get some errors due to this unused variable.
// So, we need to fix this issue using the attribute macro in C.

int main(void)
{
    int __attribute__((unused)) var; // In this case, we will not have any warnings or errors during the compiling of the code.
    return 0;
}

// This solution is smarter and better than casting the variable such as (void)var;
