/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:48:55 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/24 22:48:55 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_unsigned(unsigned int num)
{
	char	*str_num;
	int		i;

	i = 0;
	if (num == 0)
		i += write(1, "0", 1);
	else
	{
		str_num = ft_convert_integer(num);
		i += ft_print_str(str_num);
		free(str_num);
	}
	return (i);
}

char	*ft_convert_integer(unsigned int n)
{
	char	*str;
	size_t	i;

	str = ft_calloc(check_length_int(n) + 1, sizeof(*str));
	i = check_length_int(n);
	while (i > 0)
	{
		str[i - 1] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
