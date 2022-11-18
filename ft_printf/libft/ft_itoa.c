/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:47:43 by sopopa            #+#    #+#             */
/*   Updated: 2022/03/17 18:53:39 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_length_int(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_convert_negative(int n)
{
	char			*str;
	size_t			i;
	unsigned int	a;

	i = check_length_int(-n);
	str = ft_calloc(i + 2, sizeof(*str));
	if (!str)
		return (ft_strdup(""));
	a = -n;
	while (i > 0)
	{
		str[i] = ((a % 10) + 48);
		a = a / 10;
		i--;
	}
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	if (n < 0)
	{
		str = ft_convert_negative(n);
	}
	else
	{	
		str = ft_calloc(check_length_int(n) + 1, sizeof(*str));
		if (!str)
			return (ft_strdup(""));
		i = check_length_int(n);
		while (i > 0)
		{
			str[i - 1] = '0' + (n % 10);
			n = n / 10;
			i--;
		}
	}
	return (str);
}
