/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:55:54 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/22 18:03:31 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsub_free(char **s, unsigned int start, unsigned int len)
{
	char	*mem;

	mem = NULL;
	mem = ft_strsub(*s, start, len);
	if (*s)
		free(*s);
	*s = mem;
}
