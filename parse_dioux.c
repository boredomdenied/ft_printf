/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:36:29 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/13 16:19:50 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_int(t_line *line)
{
	if (line->plus != 1)
		write(1, "+", 1);
	line->length += ft_putstr(ft_itoa(va_arg(line->ap, int)));
}

void		parse_oct(t_line *line)
{
	line->length += ft_putstr(ft_itoa_base(va_arg(line->ap, int), 8));
}

void		parse_hex(t_line *line, int i)
{
	if (i)
		line->length += ft_putstr(
				ft_itoa_base_lower(va_arg(line->ap, int), 16));
	else
		line->length += ft_putstr(
				ft_itoa_base(va_arg(line->ap, int), 16));
}

void		parse_unsigned(t_line *line)
{
	line->length += ft_putstr(ft_itoa_unsigned(va_arg(line->ap, unsigned int)));
}

void		parse_dioux(t_line *line, const char *p)
{
	if (*p == 'd' || *p == 'i')
		parse_int(line);
	else if (*p == 'o')
		parse_oct(line);
	else if (*p == 'u')
		parse_unsigned(line);
	else if (*p == 'x')
		parse_hex(line, 1);
	else if (*p == 'X')
		parse_hex(line, 0);
}
