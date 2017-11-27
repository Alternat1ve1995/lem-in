/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:56:04 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/22 18:03:53 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strjoin_free(char **s1, char *s2)
{
	char	*mem;

	mem = NULL;
	mem = ft_strjoin(*s1, s2);
	if (*s1)
		free(*s1);
	*s1 = mem;
}
