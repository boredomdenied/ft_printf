/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:06:56 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/18 15:53:22 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"


void	parse_flags(t_line *line, const char *p)

{
	line->pos++;
	while (p[line->pos] == '+' || p[line->pos] == '-' || p[line->pos] == '0' || p[line->pos] == '#' || p[line->pos] == ' ')
	{
		if (p[line->pos] == '+')
		{
			line->plus = 1;
		}
		else if (p[line->pos] == '-')
		{
			line->minus = 1;
		}
		else if (p[line->pos] == '0')
		{
			line->zero = 1;
		}
		else if (p[line->pos] == '#')
		{
			line->pound = 1;
		}
		else if (p[line->pos] == ' ')
		{
			line->space = 1;
		}
	//	line->pos++;
	}
//	line->pos++;
}

void	parse_width(t_line *line, const char *p)
{
	int i;
	const char *q;
	char *temp;

	i = 0;
	q = p;
	while (*q >= '0' && *q <= '9')
	{
		q++;
		i++;
	}
	q = p;
	temp = ft_strsub(q, 0, i);
		line->width = ft_atoi(temp);
		line->width_digits = i;
}

void	parse_type(t_line *line, const char *p)
{
	line->pos++;
	if (p[line->pos] == 'd' || p[line->pos] == 'i' || p[line->pos] == 'o'
			|| p[line->pos] == 'u' || p[line->pos] == 'x' || p[line->pos] == 'X')
		parse_dioux(line, p);
	else if (p[line->pos] == 'c' || p[line->pos] == 's' || p[line->pos] == 'p')
		line->length += parse_csp(line->ap, p);
	else if (p[line->pos] == 'f')
		line->length += parse_float(line->ap);
	else if (p[line->pos] == '%')
	{
		ft_putchar('%');
		line->length++;
		line->pos++;
	}
}

void	init_line(t_line *line)
{
	line->pos = 0;
	line->plus = 0;
	line->minus = 0;
	line->pound = 0;
	line->zero = 0;
	line->space = 0;
	line->width = 0;
	line->length = 0;
	line->width_digits = 0;
}

int		ft_printf(const char *str, ...)
{
	int			i;
	t_line		*line;

	line = (t_line*)ft_memalloc(sizeof(t_line));
	init_line(line);
	va_start(line->ap, str);
	while (str[line->pos] != '\0')
	{
		if (str[line->pos] != '%')
		{
			write(1, str, 1);
			line->length++;
			line->pos++;
		}
		else
		{
			parse_flags(line, &str[line->pos]);
//			parse_width(line, p);
//			parse_precision(line, p);
//			parse_length(line, p);
			parse_type(line, &str[line->pos]);
			line->pos++;
		}
	}
	i = line->length;
	free(line);
	return (i);
}
