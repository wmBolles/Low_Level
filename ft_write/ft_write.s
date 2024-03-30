	.file	"ft_write.c"
	.text
	.globl	ft_write
	.type	ft_write, @function
ft_write:
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
	movl	$1, %eax
	movl	-20(%rbp), %edi
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdx
#APP
# 48 "ft_write.c" 1
	syscall
# 0 "" 2
#NO_APP
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
.L3:
	leave
	ret
	.size	ft_write, .-ft_write
	.section	.rodata
.LC0:
	.string	"Hello World!"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$12, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	ft_write
	movl	$0, %eax
	popq	%rbp
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
