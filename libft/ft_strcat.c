/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:41:53 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/06 19:21:10 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str1;

	i = 0;
	j = 0;
	str1 = s1;
	while (str1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		str1[i] = s2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return (str1);
}
