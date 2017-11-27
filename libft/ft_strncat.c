/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:39:58 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/06 19:18:59 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	char		*str1;

	i = 0;
	j = 0;
	str1 = s1;
	while (str1[i] != '\0')
		i++;
	while (s2[j] != '\0' && n > 0)
	{
		str1[i] = s2[j];
		i++;
		j++;
		n--;
	}
	str1[i] = '\0';
	return (str1);
}
