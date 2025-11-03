/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:56:05 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/03 02:16:39 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	print_hex(char c, uintptr_t nb, int len);
int	print_pointer(void *ptr);
int	putnbr_u_int(unsigned int n, int len);
