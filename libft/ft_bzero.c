/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:25:03 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/16 21:39:57 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
#include <unistd.h>
int main(void)
{
	char str[] = "JUUUUUUUUUUUUUUUUUUUUUUUMP";
	write(1,&str,10);
	ft_bzero(str, 5);
	write(1,&str,10);
}*/