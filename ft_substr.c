/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:28:54 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/03 15:31:11 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*malo;
	size_t			j;

	i = 0;
	j = 0;
	while (j < len && s[i])
	{
		if (i >= start)
			j++;
		i++;
	}
	malo = (char *)malloc((j + 1) * sizeof(char));
	if (!malo)
		return (NULL);
	i = 0;
	while (i < j)
	{
		malo[i] = s[i + start];
		i++;
	}
	malo[i] = '\0';
	return (malo);
}
