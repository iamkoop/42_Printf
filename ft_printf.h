/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:56:05 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/04 12:02:41 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	print_hex(char c, uintptr_t nb, int len);
int	print_pointer(void *ptr);
int	putnbr_u_int(unsigned int n, int len);
int	ft_printf(const char *format, ...);

#endif