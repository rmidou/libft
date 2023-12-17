/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:16:19 by rmidou            #+#    #+#             */
/*   Updated: 2023/12/17 19:57:39 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putptr_two(unsigned long long int n, int j)
{
	int		len;
	char	*res;

	len = ft_hexalen(n);
	res = (char *)ft_calloc(sizeof(char), (len + 2));
	if (!res)
		return (0);
	while (n != 0)
	{
		res[len--] = "0123456789abcdef"[n % 16];
		n = n / 16;
		j++;
	}
	return (res);
}

char	*ft_putptr(unsigned long long int n, char *str, int *i)
{
	if (!n)
		return (adds(str, "(nil)", i));
	return (adds (adds(str, "0x", i), ft_putptr_two(n, 2), i));
}

static void	iaddc(char *str, char c, int *i)
{
	while (*str)
		str++;
	str[0] = c;
	str[1] = '\0';
	i++;
}

static void	filling(char *str, unsigned int n, int *i)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb >= 10)
		filling(str, nb / 10, i);
	iaddc(str, ('0' + (nb % 10)), i);
}

char	*ft_itoau(unsigned int n, int *i)
{
	char	*str;

	str = (char *)malloc(15 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	filling(str, n, i);
	return (str);
}
