/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_memory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:34:29 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/12 03:06:55 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_hex(int x)
{
	char *base;

	base = "0123456789abcdef";
	write(1, &base[x / 16], 1);
	write(1, &base[x % 16], 1);
}

void	ft_print_pointer_memory(const void *addr)
{
	size_t				i;
	size_t				j;
	unsigned char const *p;

	i = 0;
	p = addr;
	j = 0;
	while (j < 4)
	{
		ft_print_hex(*(p + i + j));
		j++;
	}
}
