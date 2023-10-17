/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:49:01 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/04 14:23:47 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_lenght;
	size_t	src_lenght;

	src_lenght = ft_strlen(src);
	dest_lenght = ft_strlen(dst);
	i = 0;
	j = dest_lenght;
	if (dest_lenght < size -1 && size > 0)
	{
		while (src[i] && dest_lenght + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (dest_lenght >= size)
		dest_lenght = size;
	return (dest_lenght + src_lenght);
}
