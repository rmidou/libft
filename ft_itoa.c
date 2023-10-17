/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:42:46 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/04 18:32:37 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	addc(char *str, char c)
{
	while (*str)
		str++;
	str[0] = c;
	str[1] = '\0';
}

static void	filling(char *str, int n)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		addc(str, '-');
		nb *= -1;
	}
	if (nb >= 10)
		filling(str, nb / 10);
	addc(str, '0' + (nb % 10));
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(13 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	filling(str, n);
	return (str);
}
