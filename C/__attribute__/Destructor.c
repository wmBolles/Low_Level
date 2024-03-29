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

void    _End(void) __attribute__ ((destructor));

void    _End(void)
{
    printf("printing in the destructor or the end function");
}

int     main(void)
{
    printf("main\n");   // to check that the destructor must be executed after the main function
    return 0x0000000;
}

// The Same thing here the Destructor or the gcc end function must be executed alone after the main func
// Here is the asm code

                                        ## -- End function
	.globl	_main                   ## -- Begin function main // The main fn
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                       

                                        ## -- End function // The Destructor fn
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"printing in the destructor or the end function" // our printf

L_.str.1:                               ## @.str.1
	.asciz	"main\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	___GLOBAL_init_65535
.subsections_via_symbols
