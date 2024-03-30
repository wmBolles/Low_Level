# Ft_write

### Recode the write() funcion from scratch !

Prototype:
```
ssize_t write(int fd, const void *buf, size_t count);
```

### The function should be work on all architectures and os !windows

# Custom Write Function Implementation

This repository contains a basic implementation of a custom `write()` function in C. The `write()` function is commonly used in Unix-like operating systems to write data to a file descriptor.

## Overview

The implementation provided here is a minimal version of the `write()` function, called `ft_write()`. It utilizes low-level system calls to interact with the operating system's file descriptor interface.

## Features

- **Custom Write Function**: The `ft_write()` function replicates the basic functionality of the standard `write()` function.
- **Error Handling**: Checks if the file descriptor is valid before performing the write operation.

## Implementation Details

### Using Assembly (`asm`) and `volatile`

The `asm` keyword is used in C to include assembly instructions directly within C code. In this implementation, `asm` is used to invoke system calls directly, bypassing the standard C library's `write()` function.

The `volatile` keyword is used here to inform the compiler that the assembly block has side effects and should not be optimized out. This is crucial because the assembly block modifies the registers and issues a system call, and these effects must not be optimized away by the compiler.

### System Call Invocation

System calls are low-level interfaces provided by the operating system to interact with the kernel. They enable user-space programs to request services from the kernel, such as reading from or writing to files, creating processes, and managing memory.

In this implementation, the `syscall` instruction is used to invoke system calls directly on x86_64 architecture. Registers are used to pass arguments to the system call, and the return value is typically stored in a register specified by the calling convention.

### Error Handling

The implementation includes basic error handling to check if the file descriptor (`fd`) is valid before performing the write operation. This is achieved using the `fcntl()` function with the `F_GETFL` command, which returns the file status flags for the specified file descriptor. If `fcntl()` returns `-1`, it indicates an error, and `-1` is returned from `ft_write()` to signify the error.

## Limitations

- **Platform Specific**: While this implementation should work on most Unix-like systems, system call numbers and assembly syntax may vary between different platforms.

## Contributions

Contributions to improve error handling, portability, or any other aspect of this implementation are welcome. Feel free to submit pull requests.

# This code is Open Source :)