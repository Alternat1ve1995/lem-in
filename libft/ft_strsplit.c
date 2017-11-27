/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:01:13 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/09 13:33:45 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char delim)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == delim && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			break ;
		count++;
		while (str[i] != delim && str[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *str, char delim, size_t i)
{
	while (str[i] != delim && str[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[k] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] == '\0')
			break ;
		str[i] = ft_strsub(s, k, ft_word_len(s, c, k) - k);
		k = ft_word_len(s, c, k);
		i++;
	}
	str[i] = 0;
	return (str);
}
