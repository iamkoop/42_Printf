/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:07:04 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/03 03:33:14 by nilsdruon        ###   ########.fr       */
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
		if(!s)
			s = "(null)";
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	return(-1);
}

int	print_arg(char *s, va_list arg)
{
	if (s[0] == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return(1);
	}
	else if (s[0] == '%')
	{
		write(1,"%",1);
		return(1);
	}
	else if (s[0] == 'd' || s[0] == 'i' || s[0] == 's')
		return(print_arg_helper(s[0],arg));
	else if (s[0] == 'p')
		return(print_pointer((va_arg(arg, void *))));
	else if (s[0] == 'u')
		return(putnbr_u_int((va_arg(arg, unsigned int)),0));
	else if (s[0] == 'x' || s[0] == 'X')
		return(print_hex(s[0], va_arg(arg, unsigned int), 0));
	return (-1);
}

char	*format_specifier(const char	*c, int	*skipped_spaces)
{
	int		i;
	char	*set;

	*skipped_spaces = 1;
	i = 1;
	set = "cspdiuxX%";
	if (c[0] != '%')
		return (NULL);
	while (c[i] && c[i] == ' ')
	{
		(*skipped_spaces)++;
		i++;
	}
	if (ft_strchr(set, c[i]))
	{
		(*skipped_spaces)++;
		return ((char *)&c[i]);
	}
	return (NULL);
}

int	print_formated(const char *format, va_list arg)
{
	int		i;
	int		cnt;
	char	*specifier;
	int	skipped_spaces;

	skipped_spaces = 0;
	i = 0;
	cnt = 0;
	while (format[i])
	{
		specifier = format_specifier(&format[i], &skipped_spaces);
		if (!specifier)
		{
			write(1, &format[i++], 1);
			cnt++;
		}
		else
		{
			if(*specifier == '\0')
				return (-1);
			cnt += print_arg(specifier, arg);
			i += skipped_spaces;
		}
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		count_var;
	int		i;
	va_list	arg;

	va_start(arg, format);
	if (ft_strlen(format) == 0)
		count_var = 0;
	else
		count_var = print_formated(format, arg);
	va_end(arg);
	return (count_var);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ret1, ret2;

	printf("\n--- CHAR TEST ---\n");
	ret1 = ft_printf("Char: [%c]\n", 'A');
	ret2 = printf("Char: [%c]\n", 'A');
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- STRING TEST ---\n");
	ret1 = ft_printf("String: [%s]\n", "Hello, World!");
	ret2 = printf("String: [%s]\n", "Hello, World!");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- POINTER TEST ---\n");
	int x = 42;
	ret1 = ft_printf("Pointer: [%p]\n", &x);
	ret2 = printf("Pointer: [%p]\n", &x);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	ret1 = ft_printf("Null pointer: [%p]\n", (void *)0);
	ret2 = printf("Null pointer: [%p]\n", (void *)0);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- DECIMAL & INTEGER TEST ---\n");
	ret1 = ft_printf("INT_MAX: [%d] INT_MIN: [%i]\n", INT_MAX, INT_MIN);
	ret2 = printf("INT_MAX: [%d] INT_MIN: [%i]\n", INT_MAX, INT_MIN);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- UNSIGNED TEST ---\n");
	ret1 = ft_printf("UINT_MAX: [%u] ZERO: [%u]\n", UINT_MAX, 0);
	ret2 = printf("UINT_MAX: [%u] ZERO: [%u]\n", UINT_MAX, 0);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- HEXADECIMAL TEST ---\n");
	ret1 = ft_printf("Hex lower: [%x] upper: [%X]\n", 305441741, 305441741);
	ret2 = printf("Hex lower: [%x] upper: [%X]\n", 305441741, 305441741);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- PERCENT SIGN TEST ---\n");
	ret1 = ft_printf("100%% sure!\n");
	ret2 = printf("100%% sure!\n");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);



	printf("\n--- DOUBLE SPECIFIERS ---\n");
	ret1 = ft_printf("Mix: [%c][%s][%d][%x]\n", 'X', "Test", -42, 48879);
	ret2 = printf("Mix: [%c][%s][%d][%x]\n", 'X', "Test", -42, 48879);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	/*UNDEFINED BEHAVIOUR - DON'T NEED TO HANDLE
	printf("\n--- NO ARGUMENTS ---\n");
	ret1 = ft_printf("char: %c, int: %d, string: %s\n"); // <- No Arguments!
	ret2 = printf("char: %c, int: %d, string: %s\n");
	printf("Return values: ft: %d og: %d\n", ret1, ret2); //TODO fix segfaoult and test printf
	*/
	printf("\n--- TOO MANY ARGUMENTS ---\n");
	ret1 = ft_printf("only one: %%d = %d\n", 42, 1337, "oops", NULL);
	ret2 = printf("only one: %%d = %d\n", 42, 1337, "oops", NULL);
	printf("Return values: ft: %d og: %d\n", ret1, ret2); //TODO return size -1 // WRONG RETURN HOW MANY IS WRITTEN!!

	char *ptr = NULL;
	printf("\n--- NULL POINTER IN STRING ---\n");
	ret1 = ft_printf("null string: %s\n", ptr);
	ret2 = printf("null string: %s\n", ptr);
	printf("Return values: ft: %d og: %d\n", ret1, ret2);


	printf("\n--- NULL CHAR ---\n");
	ret1 = ft_printf("null char: %c$\n", '\0');
	ret2 = printf("null char: %c$\n", '\0');
	printf("Return values: ft: %d og: %d\n", ret1, ret2);

	printf("\n--- ONLY %% 4 TIMES ---\n");
	ret1 = ft_printf("%%%%%%%%\n");
	ret2 = printf("%%%%%%%%\n");
	printf("Return values: ft: %d og: %d\n", ret1, ret2);

	printf("\n--- STRING ENDS WITH %% ---\n");
	ret1 = ft_printf("invalid: %");
	ret2 = printf("\ninvalid: %");
	printf("\nReturn values: ft: %d og: %d\n", ret1, ret2); //return -1 and don't printf % SOLVED

	printf("\n---CHAINED---\n");
	ret1 = ft_printf("int: %d, hex: %x, char: %c, str: %s, percent: %%\n", 42, 255, 'A', "Hallo");
	ret2 = printf("int: %d, hex: %x, char: %c, str: %s, percent: %%\n", 42, 255, 'A', "Hallo");
	printf("Return values: ft: %d\n", ret1);
	printf("Return values: normal: %d\n", ret2);

	return (0);
}

