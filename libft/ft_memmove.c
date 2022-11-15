/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:25:37 by sopopa            #+#    #+#             */
/*   Updated: 2022/02/13 14:18:54 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *srcs, size_t len)
{
	int	i;

	if (!dest && !srcs && len > 0)
		return (NULL);
	if (dest > srcs)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(srcs + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dest + i) = *(char *)(srcs + i);
			i++;
		}
	}
	return (dest);
}
