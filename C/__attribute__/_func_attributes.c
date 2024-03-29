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

#include <stdio.h>

// A function attribute is specified with the keyword __attribute__ followed by the attribute name 
// and any additional arguments the attribute name requires. A function __attribute__ specification is included 
// in the declaration or definition of a function. The syntax takes the following forms:

void Begin(void) __attribute__ ((constructor));

void Begin(void)
{
    printf("Printing in the init function\n");
}

int main(void)
<%

%>

// In This Case When we compile an run this programme WITHOUT CALLING THE BEGIN FUNCTION IN THE MAIN
// the programme must WRITE "Printing in the init function" in the stdout

// How?

// In this function Declaration < void Begin(void) __attribute__ ((constructor)); >
// we call a function predefined in the gcc and cc compiler named init or begin function
// this function has some instructions by default and we add the printf instruction
// such as the concept of constructor in C++, the function will be executed before the main() function
