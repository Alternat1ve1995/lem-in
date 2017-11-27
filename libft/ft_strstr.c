/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:09:01 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/06 19:18:12 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *bigstr;
	const char *littlestr;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		bigstr = big;
		littlestr = little;
		while (*littlestr != '\0' && *bigstr == *littlestr)
		{
			bigstr++;
			littlestr++;
		}
		if (*littlestr == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
