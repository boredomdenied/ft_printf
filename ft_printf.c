/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:06:56 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/20 14:11:46 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"


void	parse_flags(t_line *line, const char *p)

{
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
		line->pos++;
	}
}

void	parse_width(t_line *line, const char *p)
{
	char *temp;

	while (p[line->pos] >= '0' && p[line->pos] <= '9')
	{
		line->pos++;
		line->width_digits++;
	}
	line->pos -= line->width_digits;
	temp = ft_strsub(p, line->pos, line->width_digits);
		line->width = ft_atoi(temp);
		free(temp);
	line->pos += line->width_digits;
}

void	parse_precision(t_line *line, const char *p)
{
	char *temp;

	if (p[line->pos] == '.')
		line->pos++;
	while (p[line->pos] >= '0' && p[line->pos] <= '9')
	{
		line->pos++;
		line->precision_digits++;
	}
	line->pos -= line->precision_digits;
	temp = ft_strsub(p, line->pos, line->precision_digits);
		line->precision = ft_atoi(temp);
		free(temp);
	line->pos += line->precision_digits;
}

void	parse_type(t_line *line, const char *p)
{
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
	line->precision = -1;
	line->int_digits = 0;
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
			write(1, &str[line->pos], 1);
			line->length++;
			line->pos++;
		}
		else
		{
			line->pos++;
			parse_flags(line, str);
			parse_width(line, str);
			parse_precision(line, str);
//			parse_length(line, p);
			parse_type(line, str);
			line->pos++;
		}
	}
	i = line->length;
	free(line);
	return (i);
}
