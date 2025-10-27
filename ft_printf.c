/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:07:04 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/27 22:34:36 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
//todo : check out printf for the various weird 
//			interactions with the % being alone and stuff

void print_arg(char *s, va_list arg)
{
	if(s[0] == 'c')
		ft_putchar_fd(va_arg(arg, char), 1);
	else if(s[0] == 's')
		ft_putchar_fd(va_arg(arg, char), 1);
	else if(s[0] == 'p')
		(va_arg(arg, void *), 1);
	else if(s[0] == 'd' || s[0] == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if(s[0] == 'u')
		ft_putnbr_fd(va_arg(arg, long), 1);
	else if(s[0] == 'x' || s[0] == 'X')
		print_hex(s[0],va_arg(arg, unsigned int));
	else if(s[0] == '%')
		ft_putchar_fd(va_arg(arg, char), 1);
}

char	*format_specifier(char	*c)
{
	int	i;
	char *set;
	
	i = 1;
	set = "cspdiuxX%";
	if(c[0] != '%')
		return (NULL);
	while (c[i] && c[i] == ' ')
		i++;
	if(ft_strchr(set, c[i]))
		return (&c[i]);
	return (NULL);
}

int	print_formated(const char *format, va_list arg)
{
	int	i;
	char *ptr;

	i = 0;
	while(format[i])
	{
		if(format_specifier(&format[i]) == NULL && format[i + 1])
			write(1,&format[i], 1);
		else
			print_arg(format_specifier(&format[i]), arg);
		i++;
	}
	return (1);
}

/* static int	arg_count(const char *format)
{
	int		i;
	int		cnt;
	char	*conversion_specifier;
	char	*set;
	int		found_percent_sign;

	i = 0;
	cnt = 0;
	found_percent_sign = 0;
	set = "cspdiuxX%";
	while (format[i])
	{
		found_percent_sign = 0;
		if (format[i] == '%')
		{
			found_percent_sign = 1;
			i++;
		}
		while (format[i] == ' ')
			i++;
		if (ft_strchr(set, format[i]) != NULL && found_percent_sign)
			cnt++;
		i++;
	}
	return (cnt);
} */

int	ft_printf(const char *format, ...)
{
	int		count_var;
	int		i;
	va_list	arg;

	va_start(arg, format);
	count_var = arg_count(format);
	if (ft_strlen(format) == 0)
		return (0);
	if (arg_count(format) == 0)
	{
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen(format));
	}
	else
		return (print_formated(format, arg));
	va_end(arg);
	return (0);
}

int	main(void)
{
	ft_printf("Hello %s World");
}
