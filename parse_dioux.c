/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:36:29 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/20 13:56:32 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_int(t_line *line)
{
	line->int_digits = pf_parse_int(ft_itoa(va_arg(line->ap, int)), line);
	line->length += line->int_digits;
}

void		parse_oct(t_line *line)
{
	line->int_digits = ft_putstr(ft_itoa_base(va_arg(line->ap, int), 8), 0);
	line->length += line->int_digits;
}

void		parse_hex(t_line *line, int i)
{
	if (i)
		line->length += ft_putstr(
				ft_itoa_base_lower(va_arg(line->ap, int), 16), 0);
	else
		line->length += ft_putstr(
				ft_itoa_base(va_arg(line->ap, int), 16), 0);
}

void		parse_unsigned(t_line *line)
{
	line->length += ft_putstr(ft_itoa_unsigned(va_arg(line->ap, unsigned int)), 0);
}

void		parse_dioux(t_line *line, const char *p)
{
	if (p[line->pos] == 'd' || p[line->pos] == 'i')
		parse_int(line);
	else if (p[line->pos] == 'o')
		parse_oct(line);
	else if (p[line->pos] == 'u')
		parse_unsigned(line);
	else if (p[line->pos] == 'x')
		parse_hex(line, 1);
	else if (p[line->pos] == 'X')
		parse_hex(line, 0);
}
