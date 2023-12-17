/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:10 by rmidou            #+#    #+#             */
/*   Updated: 2023/10/17 16:53:48 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

char	*addc(char *str, char c, int *i)
{
	char	*out;
	int		len;

	len = 0;
	if (str != NULL)
		len = ft_strlen(str);
	out = (char *)malloc(sizeof(char) * (len + 2));
	if (out == NULL)
		return (NULL);
	if (str != NULL)
		ft_strlcpy(out, (char *)str, len + 1);
	out[len] = c;
	out[len + 1] = '\0';
	(*i)++;
	return (out);
}

char	*adds(char *str, char *c, int *i)
{
	int		y;
	char	*strr;

	y = 0;
	while (str[y])
		y++;
	strr = (char *)malloc(sizeof(char) * (y + ft_strlen(c) + 1));
	strr[y + ft_strlen(c)] = '\0';
	ft_strlcpy(strr, str, y + 1);
	ft_strlcat(strr, c, (ft_strlen(strr) + ft_strlen(c) + 1));
	(*i) += ft_strlen(c);
	if (str != NULL)
		free(str);
	return (strr);
}

static char	*arg2(char *str, char *input, va_list params, int *i)
{
	char	*strr;

	if (*input == 'i' || *input == 'd')
	{
		strr = ft_itoa(va_arg(params, int));
		str = adds(str, strr, i);
		free (strr);
	}
	else if (*input == 'u')
	{
		strr = ft_itoau(va_arg(params, unsigned int), i);
		str = adds(str, strr, i);
		free (strr);
	}
	else if (*input == 's')
		str = adds(str, va_arg(params, char *), i);
	else if (*input == '%')
		str = addc(str, '%', i);
	else if (*input == 'p')
		str = ft_putptr(va_arg(params, unsigned long long int), str, i);
	return (str);
}

char	*arg(char *str, char *input, va_list params, int *i)
{
	char	*strr;

	if (*input == 'c')
		str = addc(str, va_arg(params, int), i);
	else if (*input == 'x')
	{
		strr = ft_convert_base(va_arg(params, int), "0123456789abcdef");
		str = adds(str, strr, i);
		free (strr);
	}
	else if (*input == 'X')
	{
		strr = ft_convert_base(va_arg(params, int), "0123456789ABCDEF");
		str = adds(str, strr, i);
		free (strr);
	}
	else if (*input == 'p' || *input == 'i' || *input == 'd' || *input == 'u'
		|| *input == '%' || *input == 's')
		str = arg2(str, input, params, i);
	else
	{
		str = addc(str, '%', i);
		str = addc(str, *input, i);
	}
	return (str);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	char	*input;
	va_list	params;
	int		len;

	len = 0;
	str = NULL;
	input = (char *)s;
	va_start(params, s);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			str = arg(str, input, params, &len);
		}
		else
			str = addc(str, *input, &len);
		input++;
	}
	va_end(params);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
