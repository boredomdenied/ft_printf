/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:15:51 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/20 15:59:35 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		pf_parse_int(char *str, t_line *line)
{
	int			i;
	int			j;
	int			k;
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
		i = ft_strlen(str);
		line->int_digits = i;
	//	line->plus == 1 && line->zero == 1 ? i++ : 0;
		j = i;
		if ((line->plus == 1 && *s != '-') || (line->space == 1 && *s != '-'))
			i < line->precision ? 0 : i++;
		if (line->minus != 1)
		{

			k = line->int_digits;
        	while (i < line->width)
        	{
				while (line->width - line->precision > k)
				{
					i++;
					k++;
				}
				line->zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
                i++;
        	}
		}
		if (line->plus == 1 && *s != '-')
		{
			write(1, "+", 1);
//			i++;
		}
		else if(line->space == 1 && *s != '-')
		{
			write(1, " ", 1);
//			i++;
		}
		k = line->int_digits;
		while (line->width - line->precision > k)
		{
			write(1, "0", 1);
			k++;
			i++;
		}	
		write(1, str, j);
	}
	return (i);
}
