/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 08:30:07 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/12 03:07:19 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#define ABS(x) x < 0 ? -(x) : (x)

void	calc_lower(int n, int b, char *res, int *p)
{
	char *str;

	str = "0123456789abcdef";
	if (n >= b || n <= -b)
		calc_lower(n / b, b, res, p);
	res[(*p)++] = str[ABS(n % b)];
}

char	*ft_itoa_base_lower(int value, int base)
{
	int		p;
	char	*res;
	char	*ret;

	p = 0;
	if (((base < 2 || base > 16) || !(res = (char*)malloc(sizeof(char) * 35))))
		return (NULL);
	if (value < 0 && base == 10)
		res[p++] = '-';
	calc_lower(value, base, res, &p);
	res[p] = '\0';
	ret = res;
	free(res);
	return (ret);
}
