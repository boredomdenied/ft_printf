/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:35:46 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/13 01:55:06 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_float(va_list ap)
{
	int		i;
	char	buf[20];
	char	*res;

	i = 0;
	ft_ftoa(va_arg(ap, double), buf, 6);
	i = ft_strchri(buf, '.');
	i += 6;
	res = ft_strsub(buf, 0, i);
	write(1, res, i);
	return (i);
}
