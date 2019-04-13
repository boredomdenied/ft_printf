/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 06:42:30 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/13 01:46:34 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
	while (((unsigned char*)s)[i] != ((unsigned char)c)
			&& ((unsigned char*)s)[i] != '\0')
		i++;
	if (((unsigned char*)s)[i] == ((unsigned char)c))
		return (i + 1);
	return (0);
}
