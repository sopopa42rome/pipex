/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:49:13 by sopopa            #+#    #+#             */
/*   Updated: 2022/02/20 21:43:47 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned int	i;
	unsigned char	*conv;

	i = 0;
	conv = (unsigned char *)str;
	while (i < len)
	{
		conv[i] = 0;
		i++;
	}
	str = conv;
}
