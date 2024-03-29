	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_add_address            ## -- Begin function add_address
	.p2align	4, 0x90
_add_address:                           ## @add_address
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movslq	_add_address.index(%rip), %rcx
	leaq	_add_address.allocations(%rip), %rdx
	movq	%rax, (%rdx,%rcx,8)
	movl	_add_address.index(%rip), %esi
	addl	$1, %esi
	movl	%esi, _add_address.index(%rip)
	movq	%rdx, %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$22, %edi
	callq	_malloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB1_2
## %bb.1:
	movl	$0, -4(%rbp)
	jmp	LBB1_3
LBB1_2:
	movq	-16(%rbp), %rdi
	callq	_add_address
	movl	$1000, %edi             ## imm = 0x3E8
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	_add_address
	movl	$0, -4(%rbp)
LBB1_3:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__end                   ## -- Begin function _end
	.p2align	4, 0x90
__end:                                  ## @_end
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	callq	_system
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_add_address
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdi
	callq	_free
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __GLOBAL_init_65535
___GLOBAL_init_65535:                   ## @__GLOBAL_init_65535
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	__end(%rip), %rax
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	leaq	___dso_handle(%rip), %rdx
	callq	___cxa_atexit
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.zerofill __DATA,__bss,_add_address.allocations,24,4 ## @add_address.allocations
.zerofill __DATA,__bss,_add_address.index,4,2 ## @add_address.index
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"leaks a.out"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	___GLOBAL_init_65535
.subsections_via_symbols
