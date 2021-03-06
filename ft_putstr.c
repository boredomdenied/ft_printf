/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:09:22 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/10 16:58:18 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *str, t_line *line)
{
	if (line)
		 ;
	int			i;
	const char	*s;

	s = (const char*)str;
	i = 0;
	if (s != NULL)
	{
		i = ft_strlen(str);
		write(1, str, i);
	}
	return (i);
}
