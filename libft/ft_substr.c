/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 07:12:24 by sopopa            #+#    #+#             */
/*   Updated: 2022/03/15 15:28:43 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;

	if (!string)
		return (NULL);
	if (start >= ft_strlen(string))
		start = ft_strlen(string);
	if ((start + len) >= ft_strlen(string))
		len = ft_strlen(string) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (index != len)
	{
		ptr[index] = *(string + start + index);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
