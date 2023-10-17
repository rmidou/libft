/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:28:40 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/03 18:08:17 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*mallo;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	mallo = (char *)malloc((i1 + i2 + 1) * sizeof(char));
	if (!mallo)
		return (NULL);
	ft_strlcpy(mallo, (char *)s1, i1 + 1);
	ft_strlcat(mallo, s2, i1 + i2 + 1);
	mallo[i1 + i2] = '\0';
	return (mallo);
}
