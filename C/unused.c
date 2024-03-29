// The MIT License (MIT)
//
// Copyright (c) 2024 WASSIM BOLLES
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

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
