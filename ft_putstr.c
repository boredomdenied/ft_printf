/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:09:22 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/12 05:37:42 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_putstr(char *str)
{
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
