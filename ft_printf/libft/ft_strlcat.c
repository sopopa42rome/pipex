/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:27:51 by sopopa            #+#    #+#             */
/*   Updated: 2022/01/27 00:37:37 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *srcs, size_t len_size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_srcs;

	len_dest = ft_strlen(dest);
	len_srcs = ft_strlen(srcs);
	i = len_dest;
	j = 0;
	if (len_dest < len_size - 1 && len_size > 0)
	{
		while (srcs[j] && len_dest + j < len_size - 1)
		{
			dest[i] = srcs[j];
			j++;
			i++;
		}
		dest[i] = 0;
	}
	if (len_dest >= len_size)
		len_dest = len_size;
	return (len_dest + len_srcs);
}
