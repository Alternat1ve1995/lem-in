/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revsort_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:22:17 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/14 17:22:24 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revsort_char(char *str)
{
	int		change;
	int		i;

	i = 0;
	change = 1;
	while (change == 1)
	{
		while (str[++i] != '\0')
			if (str[i] > str[i - 1])
			{
				ft_swap_char(&str[i - 1], &str[i]);
				i = 0;
			}
			else
				change = 0;
	}
}
