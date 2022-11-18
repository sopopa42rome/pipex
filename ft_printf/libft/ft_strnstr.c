/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:49:57 by sopopa            #+#    #+#             */
/*   Updated: 2022/03/17 17:07:04 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = -1;
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	if ((int)len == -1)
		len = ft_strlen(haystack);
	while (haystack[++i] != '\0' && i < (int)len)
	{
		j = -1;
		while (i + (++j) < (int)len && needle[j] == haystack[i + j])
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
	}
	return (NULL);
}
