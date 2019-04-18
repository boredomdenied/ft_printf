/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:09:22 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/18 14:36:48 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_putstr(char *str, t_line *line)
{
	int			i;
	const char	*s;

	s = (const char*)str;
	i = 0;
	if (s != NULL)
	{
		if (line->plus == 1)
		{
			write(1, "+", 1);
			i++;
		}
		i = ft_strlen(str);
		write(1, str, i);
	}
	if (line->plus == 1)
		i += 2;
	return (i);
}
