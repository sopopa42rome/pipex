/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:59:21 by sopopa            #+#    #+#             */
/*   Updated: 2022/03/10 21:20:09 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static size_t	get_length_word(const char *s, int pos, char c)
{
	size_t	len;

	len = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (len);
		len++;
		pos++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	row;
	size_t	i;
	int		index;

	if (!s)
		return (NULL);
	table = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!table)
		return (NULL);
	row = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			index = i;
			table[row++] = ft_substr(s, index, get_length_word(s, index, c));
			i += get_length_word(s, index, c);
		}
		else
			i++;
	}
	table[row] = NULL;
	return (table);
}
