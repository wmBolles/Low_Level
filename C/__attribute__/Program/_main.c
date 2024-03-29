// The MIT License (MIT)

// Copyright (c) 2024 WASSIM BOLLES

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

// Warning : Run This Code in Unix Os(MacOS)
// Segfault in linux cuz there is a big changes in the attribute concept in linux

#include <stdio.h>
#include <stdlib.h>

void    _end(void) __attribute__ ((destructor));
void    **add_address(void *addr)<%
    static void *allocations[3];
    static int index;
    allocations[index] = addr;
    index += (2 >> 1);
    return (allocations);
%>

int     main(void)
{
    char*  allocation = malloc(0X16);
    if (!allocation)    return 0b0;

    add_address(allocation);
    allocation = malloc(1000);
    add_address(allocation);
    return (0b0);
}

void    _end(void)
{
    system("leaks a.out");
    void    **addr = add_address(NULL);
    free(addr[0]);
}
