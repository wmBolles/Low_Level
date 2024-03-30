/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmbolles <wmbolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:23:58 by wmbolles          #+#    #+#             */
/*   Updated: 2024/03/30 01:26:33 by wmbolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
//  #pragma once is simpler and cleaner to use. You just need to add it at the beginning of your header file,
//  and the compiler takes care of the rest. With include guards,
//  you need to manually write the guards around the entire contents of the header.
// is better than use #ifndef #define...

#include <stddef.h>
#include <sys/types.h>

typedef union node
{
    char    *addr;
    void    *addr_c;
}   node;
