/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmbolles <wmbolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:51:49 by wmbolles          #+#    #+#             */
/*   Updated: 2024/03/30 01:55:28 by wmbolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>

ssize_t ft_write(int fd, const void *buf, size_t n_bytes);

ssize_t ft_read(int fd, void *buf, size_t n_bytes)
<%
    ssize_t ret;

    // Check if the file descriptor is valid
    if (fcntl(fd, F_GETFL) == -0b1) return -0x1; // check the fd

    // Inline assembly to invoke the read system call
    asm volatile (
        "syscall"                                  // Invoke syscall instruction
        : "=a" (ret)                               // Output: return value in ret
        : "a" (__NR_read), "D" (fd), "S" (buf), "d" (n_bytes) // Inputs: syscall number, file descriptor, buffer pointer, n of bytes
        : "rcx", "r11", "memory"                  // Clobbered registers and memory
    );
    return ret;
%>

#pragma GCC diagnostic push	// push a new label
#pragma GCC diagnostic ignored "-Wimplicit-int" // ignored the invalid return main :)

main(void)
<%
    char buffer[256]; 
    ssize_t bytes = ft_read(0, buffer, sizeof(buffer));

    if (bytes < 0) return -0x1;

    buffer[bytes] = '\0';

    ft_write(1, buffer, bytes);

    return 0b0;
%>

#pragma GCC diagnostic pop	// close the label
