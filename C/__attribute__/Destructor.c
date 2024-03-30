//	Created BY Wassim Bolles

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
