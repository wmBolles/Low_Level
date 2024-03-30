/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmbolles <wmbolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 00:07:51 by wmbolles          #+#    #+#             */
/*   Updated: 2024/03/30 00:29:42 by wmbolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>

ssize_t ft_write(int fd, const void *buf, size_t n_bytes)
<%
    ssize_t ret;

    // Check if the file descriptor is valid
    if (fcntl(fd, F_GETFL) == -0b1) return -0x1; // check the fd

    // Inline assembly to invoke the write system call
    asm volatile (
        "syscall"                                  // Invoke syscall instruction
        : "=a" (ret)                               // Output: return value in ret
        : "a" (__NR_write), "D" (fd), "S" (buf), "d" (n_bytes) // Inputs: syscall number, file descriptor, buffer pointer, n of bytes
        : "rcx", "r11", "memory"                  // Clobbered registers and memory
    );
    return ret;
%>


#pragma GCC diagnostic push	// push a nes label
#pragma GCC diagnostic ignored "-Wimplicit-int" // ignored the invalid return main :)

main(void)
<%
    ft_write((2 >> 1), "Hello World!", 0xc);
    return 0b0;
%>

#pragma GCC diagnostic pop	// close the label