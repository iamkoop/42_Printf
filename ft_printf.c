/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:07:04 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/28 23:15:37 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int print_arg_helper(char c,va_list arg)
{
	char *s;
	int n;
	int len;

	if(c == 'd' || c == 'i')
	{
		n = va_arg(arg, int);
		ft_putnbr_fd(n, 1);
		s = ft_itoa(n);
		len = ft_strlen(s);
		free(s);
		return(len);
	}
	else if(c == 's')
	{
		s = va_arg(arg, char *);
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	return(-1);
}

int	print_arg(char *s, va_list arg)
{
	if (s[0] == 'c' || s[0] == '%')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return(1);
	}
	else if (s[0] == 'd' || s[0] == 'i' || s[0] == 's')
		return(print_arg_helper(s[0],arg));
	else if (s[0] == 'p')
		return(print_pointer((va_arg(arg, void *))));
	else if (s[0] == 'u')
		return(putnbr_long((va_arg(arg, unsigned int))));
	else if (s[0] == 'x' || s[0] == 'X')
		return(print_hex(s[0], va_arg(arg, unsigned int), 0));
	return (-1);
}

char	*format_specifier(const char	*c)
{
	int		i;
	char	*set;

	i = 1;
	set = "cspdiuxX%";
	if (c[0] != '%')
		return (NULL);
	while (c[i] && c[i] == ' ')
		i++;
	if (ft_strchr(set, c[i]))
		return (&c[i]);
	return (NULL);
}

int	print_formated(const char *format, va_list arg)
{
	int		i;
	char	*ptr;

	i = 0;
	while (format[i])
	{
		if (format_specifier(&format[i]) == NULL && format[i + 1])
			write(1, &format[i], 1);
		else
			print_arg(format_specifier(&format[i]), arg);
		i++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		count_var;
	int		i;
	va_list	arg;

	va_start(arg, format);
	if (ft_strlen(format) == 0)
		return (0);
	else
		return (print_formated(format, arg));
	va_end(arg);
	return (0);
}

int	main(void)
{
	ft_printf("This is a decimal %d\n", 23);
}
