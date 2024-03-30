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


#pragma GCC diagnostic push	// push a new label
#pragma GCC diagnostic ignored "-Wimplicit-int" // ignored the invalid return main :)

main(void)
<%
    ft_write((2 >> 1), "Hello World!", 0xc);
    return 0b0;
%>

#pragma GCC diagnostic pop	// close the label
