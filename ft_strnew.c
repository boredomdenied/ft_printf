/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:27:09 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/12 02:59:22 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*temp;

	temp = (char *)ft_memalloc(sizeof(char) * (size + 1));
	return (temp);
}
