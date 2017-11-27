/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_norme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:52:59 by vboiko            #+#    #+#             */
/*   Updated: 2017/10/14 21:32:22 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	g_rooms;

void		ft_fix2(t_room *rooms, int i, int k, int fix)
{
	if (fix == 0)
	{
		if ((rooms)[i].n == NULL)
			ft_error();
		i++;
	}
	else if (fix == 1)
	{
		if ((rooms)[k].n == NULL)
			ft_error();
	}
	else
	{
		if ((rooms)[i].n == NULL)
			ft_error();
	}
}
