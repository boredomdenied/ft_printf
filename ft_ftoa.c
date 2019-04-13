/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:46:29 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/12 02:55:05 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define MAX_PRECISION	(10)

static const double g_rounders[MAX_PRECISION + 1] =
{
	0.5,
	0.05,
	0.005,
	0.0005,
	0.00005,
	0.000005,
	0.0000005,
	0.00000005,
	0.000000005,
	0.0000000005,
	0.00000000005
};

int					set_precision(double f, int precision, char *ptr)
{
	precision > MAX_PRECISION ? precision = MAX_PRECISION : 0;
	if (f < 0)
	{
		f = -f;
		*ptr++ = '-';
	}
	if (precision < 0)
	{
		if (f < 1.0)
			precision = 6;
		else if (f < 10.0)
			precision = 5;
		else if (f < 100.0)
			precision = 4;
		else if (f < 1000.0)
			precision = 3;
		else if (f < 10000.0)
			precision = 2;
		else if (f < 100000.0)
			precision = 1;
		else
			precision = 0;
	}
	precision ? f += g_rounders[precision] : 0;
	return (precision);
}

char				*ft_ftoa(double f, char *buf, int precision)
{
	char *ptr;
	char *p;
	char *p1;
	char c;
	long int_part;

	ptr = buf;
	p = ptr;
	precision = set_precision(f, precision, ptr);
	int_part = f;
	f -= int_part;
	if (!int_part)
		*ptr++ = '0';
	else
	{
		p = ptr;
		while (int_part)
		{
			*p++ = '0' + int_part % 10;
			int_part /= 10;
		}
		p1 = p;
		while (p > ptr)
		{
			c = *--p;
			*p = *ptr;
			*ptr++ = c;
		}
		ptr = p1;
	}
	if (precision)
	{
		*ptr++ = '.';
		while (precision--)
		{
			f *= 10.0;
			c = f;
			*ptr++ = '0' + c;
			f -= c;
		}
	}
	*ptr = 0;
	return (buf);
}
