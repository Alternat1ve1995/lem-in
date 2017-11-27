/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 11:19:23 by vboiko            #+#    #+#             */
/*   Updated: 2017/06/13 09:41:47 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			if_were_here(t_way *way, t_room *rooms, t_room c_room)
{
	int		i;

	i = 0;
	while (way->arr[i] != -1)
	{
		if (ft_strcmp(rooms[way->arr[i]].n, c_room.n) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_room		ft_get_start_room(t_room *rooms)
{
	int		i;
	t_room	st_room;

	i = 0;
	st_room.point = 0;
	while (rooms[i].n != NULL)
	{
		if (rooms[i].point == 1)
			st_room = rooms[i];
		i++;
	}
	return (st_room);
}

int			ft_frn(t_room *rooms, t_room c_room)
{
	int		number;

	number = 0;
	while (rooms[number].n != NULL && ft_strcmp(rooms[number].n, c_room.n) != 0)
		number++;
	if (rooms[number].n == NULL)
		return (-1);
	return (number);
}

int			ft_weed_search(t_room *r, t_room c, t_way *way, int step)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	way->arr[step] = ft_frn(r, c);
	if (c.point == 2)
		return (1);
	while (c.link != NULL && c.link[i].n != NULL)
	{
		if (c.link[i].point == 2)
			return (ft_weed_search(r, c.link[i], way, ++step));
		i++;
	}
	while (c.link != NULL && c.link[k].n != NULL)
	{
		if (if_were_here(way, r, r[ft_frn(r, c.link[k])]) == 0)
			if (ft_weed_search(r, r[ft_frn(r, c.link[k])], way, step + 1) == 1)
				return (1);
		k++;
	}
	way->arr[step] = -1;
	return (0);
}

t_way		ft_find_ways(t_way way, t_room *rooms)
{
	t_room	st_room;

	st_room = ft_get_start_room(rooms);
	ft_weed_search(rooms, st_room, &way, 0);
	return (way);
}
