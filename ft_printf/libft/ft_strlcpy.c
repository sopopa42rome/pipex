/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:39:45 by sopopa            #+#    #+#             */
/*   Updated: 2022/01/26 21:03:57 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *srcs, size_t len_s)
{
	size_t	i;

	i = 0;
	if (len_s > 0)
	{
		while (srcs[i] != '\0' && i < (len_s - 1))
		{
			dest[i] = srcs[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (srcs[i] != '\0')
	i++;
	return (i);
}
