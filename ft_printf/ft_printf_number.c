/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:38:15 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/24 16:19:45 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int num)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(num);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
