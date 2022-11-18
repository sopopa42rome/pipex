/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:28:28 by sopopa            #+#    #+#             */
/*   Updated: 2022/03/12 23:05:54 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*pinned;

	i = 0;
	pinned = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			pinned = ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == c)
	{
		pinned = ((char *)(str + i));
	}
	return (pinned);
}
