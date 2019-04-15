/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:07:49 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/14 10:18:11 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_char(int length, va_list ap)
{
	length = ft_putchar((char)va_arg(ap, char*));
	return (length);
}

int		parse_string(int length, va_list ap)
{
	length = ft_putstr(va_arg(ap, char*), 0);
	return (length);
}

int		parse_pointer(int length, va_list ap)
{
	length = 2;
	ft_print_pointer_memory(va_arg(ap, void*));
	return (length);
}

int		parse_csp(va_list ap, const char *p)
{
	int length;

	length = 0;
	if (*p == 'c')
		length = parse_char(length, ap);
	else if (*p == 's')
		length = parse_string(length, ap);
	else if (*p == 'p')
		length = parse_pointer(length, ap);
	return (length);
}
