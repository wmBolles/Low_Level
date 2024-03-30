	.file	"ft_write.c"
	.text
	.globl	ft_write         		// Define global symbol ft_write
	.type	ft_write, @function	// Mark ft_write as a function

ft_write:                      		// Start of ft_write function
	endbr64                 		// Ensure compatibility with 64-bit mode
	pushq	%rbp              		// Save base pointer
	movq	%rsp, %rbp        		// Set base pointer

	subq	$48, %rsp         		// Allocate space for local variables

	movl	%edi, -20(%rbp)  		// Store first function argument (file descriptor) at -20(%rbp)
	movq	%rsi, -32(%rbp)  		// Store second function argument (buffer pointer) at -32(%rbp)
	movq	%rdx, -40(%rbp)  		// Store third function argument (buffer size) at -40(%rbp)

	movl	-20(%rbp), %eax   		// Load file descriptor into %eax
	movl	$3, %esi          		// Set flag for fcntl (F_GETFL)
	movl	%eax, %edi        		// Set file descriptor for fcntl
	movl	$0, %eax          		// Clear %eax
	call	fcntl@PLT         		// Call fcntl to retrieve file status flags

	cmpl	$-1, %eax         		// Compare result of fcntl with -1
	jne	.L2                 		// If not equal to -1, jump to .L2

	movq	$-1, %rax         		// Set return value to -1
	jmp	.L3                 		// Jump to .L3

.L2:                          		// Start of .L2 block
	movl	$1, %eax          		// Set return value to 1
	movl	-20(%rbp), %edi   		// Load file descriptor into %edi
	movq	-32(%rbp), %rsi   		// Load buffer pointer into %rsi
	movq	-40(%rbp), %rdx   		// Load buffer size into %rdx

	// Inline assembly syscall to perform write system call
	syscall                  		// Perform system call

	movq	%rax, -8(%rbp)    		// Store return value of syscall
	movq	-8(%rbp), %rax    		// Load return value into %rax

.L3:                          		// Start of .L3 block
	leave                  		// Restore stack frame
	ret                    		// Return from function

	.size	ft_write, .-ft_write	// Define size of ft_write function

	.section	.rodata          	// Start of read-only data section
.LC0:                         		// Define label .LC0
	.string	"Hello World!"   		// Define string "Hello World!"
	.text                      		// Return to text section

	.globl	main              		// Define global symbol main
	.type	main, @function    		// Mark main as a function

main:                          		// Start of main function
	endbr64                 		// Ensure compatibility with 64-bit mode
	pushq	%rbp              		// Save base pointer
	movq	%rsp, %rbp        		// Set base pointer

	movl	$12, %edx         		// Load buffer size (12) into %edx
	leaq	.LC0(%rip), %rax  		// Load address of string into %rax
	movq	%rax, %rsi        		// Move address of string to second argument
	movl	$1, %edi          		// Move file descriptor (stdout) to first argument
	call	ft_write          		// Call ft_write function

	movl	$0, %eax          		// Load return value (0) into %eax
	popq	%rbp              		// Restore base pointer
	ret                    		// Return from main function

	.size	main, .-main        		// Define size of main function

	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"	// Compiler version information

	.section	.note.GNU-stack,"",@progbits	// Stack note section

	.section	.note.gnu.property,"a"	// GNU property note section
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

// This assembly code is for x86-64 architecture, commonly known as AMD64.
// It is compatible with 64-bit processors from AMD and Intel.
