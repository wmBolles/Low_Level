	.file	"ft_read.c"
	.text
	.globl	ft_read
	.type	ft_read, @function
ft_read:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	-20(%rbp), %eax
	movl	$3, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	fcntl@PLT
	cmpl	$-1, %eax
	jne	.L2
	movq	$-1, %rax
	jmp	.L3
.L2:
	movl	$0, %eax
	movl	-20(%rbp), %edi
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdx
#APP
# 28 "ft_read.c" 1
	syscall
# 0 "" 2
#NO_APP
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
.L3:
	leave
	ret
	.size	ft_read, .-ft_read
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$288, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-272(%rbp), %rax
	movl	$256, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	ft_read
	movq	%rax, -280(%rbp)
	cmpq	$0, -280(%rbp)
	jns	.L5
	movl	$-1, %eax
	jmp	.L7
.L5:
	leaq	-272(%rbp), %rdx
	movq	-280(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-280(%rbp), %rdx
	leaq	-272(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	ft_write@PLT
	movl	$0, %eax
.L7:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
