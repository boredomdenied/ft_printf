/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:27:34 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/13 01:45:10 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int		length(int nbr)
{
	int size;

	if (nbr == 0)
		return (1);
	size = 0;
	if (nbr == -2147483648)
	{
		nbr /= 10;
		size++;
	}
	if (nbr < 0)
	{
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static char		*post_malloc(int neg, int n, char *arr, int size)
{
	if (neg)
		arr[0] = '-';
	if (n == 0)
		arr[size + neg - 1] = '0';
	arr[size + neg] = '\0';
	while (n > 0)
	{
		arr[size + neg - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (arr);
}

char			*ft_itoa(int n)
{
	int		neg;
	int		max;
	int		size;
	char	*arr;
	char	*ret;

	size = 0;
	size = length(n);
	neg = 0;
	max = 0;
	if (n == -2147483648)
	{
		max = 1;
		n = -147483648;
	}
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	arr = (char*)malloc(sizeof(char) * (size + neg + max + 1));
	max ? arr[1] = '2' : 0;
	free(arr);
	ret = post_malloc(neg, n, arr, size);
	return (ret);
}
