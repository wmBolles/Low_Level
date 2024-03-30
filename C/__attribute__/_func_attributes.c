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

// The ASSEMBLY CODE

.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_Begin                  ## -- Begin function Begin  // Here we have the Begin function which the compiler executes first which is Begin(void);
	.p2align	4, 0x90
_Begin:                                 ## @Begin


## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main // After That We Have The main() Function
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
