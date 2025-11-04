/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:09:49 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/04 12:02:51 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_u_int(unsigned int n, int len)
{
	char	c;

	if (n >= 10)
	{
		len = putnbr_u_int(n / 10, len);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

/* #include <stdio.h>

int main (void)
{
	int i;
	i = putnbr_u_int(123456789, 0);
	printf("\n");
	printf("%d", i);
} */
