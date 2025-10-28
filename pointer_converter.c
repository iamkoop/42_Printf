/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:01:06 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/28 21:41:42 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	print_pointer(void *ptr)
{
	uintptr_t	nb;
	int len;

	nb = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	len = 2 + print_hex('x', nb, 0);
	print_hex('x', nb, 0);
	return(len);
}
