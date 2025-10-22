/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:07:04 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/22 14:54:22 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
//todo : check out printf for the various weird interactions with the % being alone and stuff

static int arg_count (const char * format)
{
	int		i;
	int		cnt;
	char	*conversion_specifier;
	char	*set;

	i = 0;
	cnt = 0;
	set = "cspdiuxX%";
	while (format[i])
	{
		if(format[i] == '%')
			i++;
		while(format[i] == ' ')
			i++;
		if(ft_strchr(set,format[i]) != NULL)
			cnt++;
		i++;
	}
	return (cnt);
}

int ft_printf(const char *format, ...)
{
	int count_var;

	count_var = arg_count(format);
	printf("%zu",ft_strlen(format));
	if(ft_strlen(format) == 0)
		return (0);
	if(arg_count(format) == 0)
	{
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen(format));
	}
	return (0);
}

int main(void)
{
	ft_printf("Hello World");
}
/* int main(void)
{
	int test = 120000;
	printf("%d",test);	
} */