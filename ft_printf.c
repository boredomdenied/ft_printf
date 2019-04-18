/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:06:56 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/18 15:16:27 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"


void	parse_flags(t_line *line, const char **p)

{
	while (**p == '+' || **p == '-' || **p == '0' || **p == '#' || **p == ' ')
	{
		if (**p == '+')
		{
			line->plus = 1;
		}
		else if (**p == '-')
		{
			line->minus = 1;
		}
		else if (**p == '0')
		{
			line->zero = 1;
		}
		else if (**p == '#')
		{
			line->pound = 1;
		}
		else if (**p == ' ')
		{
			line->space = 1;
		}
		p++;
	}
//	p++;
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

void	parse_type(t_line *line, const char **p)
{
//	p++;
	if (**p == 'd' || **p == 'i' || **p == 'o'
			|| **p == 'u' || **p == 'x' || **p == 'X')
		parse_dioux(line, *p);
	else if (**p == 'c' || **p == 's' || **p == 'p')
		line->length += parse_csp(line->ap, *p);
	else if (**p == 'f')
		line->length += parse_float(line->ap);
	else if (**p == '%')
	{
		ft_putchar('%');
		line->length++;
		p++;
	}
}

void	init_line(t_line *line)
{
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
	while (*str != '\0')
	{
		if (*str != '%')
		{
			write(1, str, 1);
			line->length++;
			str++;
		}
		else
		{
			str++;

			parse_flags(line, &str);
//			parse_width(line, p);
//			parse_precision(line, p);
//			parse_length(line, p);
			parse_type(line, &str);
			str++;
		}
	}
	i = line->length;
	free(line);
	return (i);
}
