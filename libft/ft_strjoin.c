/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:19:40 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/09 15:38:35 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*concatenated;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	concatenated = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (concatenated == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		concatenated[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
		concatenated[j++] = s2[i++];
	concatenated[j] = '\0';
	return (concatenated);
}
