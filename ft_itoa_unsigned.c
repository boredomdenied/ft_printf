/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 07:43:27 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/13 01:50:11 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int		length(unsigned int nbr)
{
	unsigned int size;

	if (nbr == 0)
		return (1);
	size = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static char		*post_malloc(unsigned int n, char *arr, unsigned int size)
{
	if (n == 0)
		arr[size - 1] = '0';
	arr[size] = '\0';
	while (n > 0)
	{
		arr[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (arr);
}

char			*ft_itoa_unsigned(unsigned int n)
{
	unsigned int		size;
	char				*arr;
	char				*ret;

	size = 0;
	size = length(n);
	if (!(arr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret = post_malloc(n, arr, size);
	free(arr);
	return (ret);
}
