/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:55:05 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/12 09:01:51 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	len(char const *s1, char const *set)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (in(s1[i], set))
		i++;
	count = i;
	i = ft_strlen(s1) - 1;
	while (in(s1[i], set))
	{
		i--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mallo;
	int		count;
	int		i2;
	int		i;

	i = 0;
	i2 = 0;
	count = len(s1, set);
	if (!s1 || !set)
		return (NULL);
	mallo = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!mallo)
		return (NULL);
	while (in(s1[i], set))
		i++;
	while ((size_t)i2 < ft_strlen(s1) - count)
	{
		mallo[i2] = s1[i];
		i2++;
		i++;
	}
	mallo[i2] = '\0';
	return (mallo);
}
