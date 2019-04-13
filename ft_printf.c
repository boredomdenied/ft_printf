/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:06:56 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/13 16:17:28 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"


void	parse_flags(t_line *line, const char *p)
{
	if (*p == '+')
	{
		line->plus = 1;
		p++;
	}
	else if (*p == '-')
	{
		line->minus = 1;
		p++;
	}
	else if (*p == '0')
	{
		line->zero = 1;
		p++;
	}
	else if (*p == '#')
	{
		line->pound = 1;
		p++;
	}
	else if	(*p == ' ')
	{
		line->space = 1;
		p++;
	}
}

void	parse_type(t_line *line, const char *p)
{
	if (*p == 'd' || *p == 'i' || *p == 'o'
			|| *p == 'u' || *p == 'x' || *p == 'X')
		parse_dioux(line, p);
	else if (*p == 'c' || *p == 's' || *p == 'p')
		line->length += parse_csp(line->ap, p);
	else if (*p == 'f')
		line->length += parse_float(line->ap);
	else if (*p == '%')
	{
		ft_putchar('%');
		line->length++;
		p++;
	}
}

int		ft_printf(const char *str, ...)
{
	int			i;
	const char	*p;
	t_line		*line;

	line = (t_line*)ft_memalloc(sizeof(t_line));
	va_start(line->ap, str);
	p = str;
	while (*p != '\0')
	{
		if (*p != '%')
		{
			write(1, p, 1);
			line->length++;
		}
		else
		{
			p++;
			parse_flags(line, p);
			parse_type(line, p);
			p++;
		}
		p++;
	}
	i = line->length;
	free(line);
	return (i);
}
