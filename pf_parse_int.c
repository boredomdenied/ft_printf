/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:09:22 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/20 11:49:46 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		pf_parse_int(char *str, t_line *line)
{
	int			i;
	int			j;
	const char	*s;

	s = (const char*)str;
	i = 0;
	if (s != NULL)
	{
	//	line->zero == 1 && *s == '-' ? str++ : 0;
		if (line->minus == 1)
		{
			i = ft_strlen(str);
			while (i < line->width)
        	{
                	line->zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
                	i++;
        	}
		}
		if (line->plus == 1 && *s != '-')
		{
			write(1, "+", 1);
			i++;
		}
		else if(line->space == 1 && *s != '-')
		{
			write(1, " ", 1);
			i++;
		}
		i = ft_strlen(str);
	//	line->plus == 1 && line->zero == 1 ? i++ : 0;
		j = i;
		if (line->minus != 1)
		{
        	while (i < line->width)
        	{
                	line->zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
                	i++;
        	}
		}
		write(1, str, j);
	}
	if ((line->plus == 1 && *s != '-') || (line->space == 1 && *s != '-'))
		i++;
	return (i);
}
