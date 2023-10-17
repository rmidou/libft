/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:24:48 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/12 09:06:11 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (src[i] != '\0')
		i++;
	if (size > 0)
	{
		while (src[i2] != '\0' && i2 < size - 1)
		{
			dst[i2] = src[i2];
			i2++;
		}
		dst[i2] = '\0';
	}
	return (i);
}
