/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hex_Converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:19:35 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/27 22:34:05 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void print_hex_help(int Upper, unsigned int nb)
{
	if(Upper)
		ft_putchar_fd('F' - (15 - nb), 1);
	else
		ft_putchar_fd('f' - (15 - nb), 1);	
}

void print_hex(char c, uintptr_t nb)
{
	int Upper;
	uintptr_t num;

	Upper = 1;
	if(c == 'x')
		Upper = 0;
	if(nb <= 15)
	{
		if(nb < 10)
			ft_putchar_fd('0' + nb, 1);
		else
			print_hex_help(Upper,nb);
		return;
	}
	if(nb >= 16)
		print_hex(c, nb / 16);
	num = (nb % 16);
	if(nb < 10)
		ft_putchar_fd('0' + num, 1);
	else
		print_hex_help(Upper,num);
}

/* int main (void)
{
	print_hex('x', 65535);
} */