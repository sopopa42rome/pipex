/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:32:31 by sopopa            #+#    #+#             */
/*   Updated: 2022/02/06 23:46:55 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *srcs, size_t len)
{
	unsigned int	i;
	char			*conv_d;
	char			*conv_s;

	i = 0;
	conv_s = (char *)srcs;
	conv_d = (char *)dest;
	while (i < len)
	{
		conv_d[i] = conv_s[i];
		i++;
	}
	return (dest);
}
