/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:00:21 by rmidou            #+#    #+#             */
/*   Updated: 2023/12/17 19:57:21 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	display(unsigned int nb, char *str, char *result, int index)
{
	unsigned int	str_length;

	str_length = 0;
	while (str[str_length])
		str_length++;
	if (nb >= str_length)
		display(nb / str_length, str, result, index - 1);
	result[index] = str[nb % str_length];
	return (index);
}

int	get_number_length(unsigned int number, char *base)
{
	unsigned int	length;
	unsigned int	base_length;

	base_length = 0;
	length = 0;
	while (base[base_length])
		base_length++;
	while (number >= base_length)
	{
		++length;
		number /= base_length;
	}
	return (++length);
}

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

char	*ft_convert_base(unsigned int nbr, char *base_to)
{
	char			*result;
	unsigned int	last_index;

	if (!nbr || !base_to)
		return (0);
	result = malloc(sizeof(char) * get_number_length(nbr, base_to));
	last_index = display(nbr, base_to, result,
			get_number_length(nbr, base_to) - 1);
	result[last_index + 1] = '\0';
	return (result);
}

int	ft_hexalen(unsigned long long int n)
{
	int	len;

	len = 0;
	while (n / 16 != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
