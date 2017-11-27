/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_connections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 11:07:14 by vboiko            #+#    #+#             */
/*   Updated: 2017/06/13 09:42:10 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_add_connection(t_room **rooms, t_room c_room, int n)
{
	int		i;

	i = 0;
	while ((*rooms)[n].link[i].n != NULL)
		i++;
	(*rooms)[n].link[i] = c_room;
}

int			ft_find_link_number(char *str, t_room *rooms)
{
	int		i;

	i = 0;
	while (rooms[i].n != NULL)
	{
		if (ft_strcmp(str, rooms[i].n) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_if_connection_exists(t_room **rooms, t_room c_room, int n)
{
	int		i;

	i = 0;
	if ((*rooms)[n].link == NULL)
		(*rooms)[n].link = (t_room *)malloc(sizeof(t_room) * MAXROOMS * 2);
	while ((*rooms)[n].link[i].n != NULL)
	{
		if (ft_strcmp((*rooms)[n].link[i].n, c_room.n) == 0)
			return (1);
		i++;
	}
	return (0);
}

void		ft_check_rooms_connections(t_room c_room, t_room **rooms)
{
	int		i;
	int		n;

	i = 0;
	while (c_room.link[i].n != NULL)
	{
		n = ft_find_link_number(c_room.link[i].n, *rooms);
		if (n == -1)
			ft_error();
		if (ft_if_connection_exists(rooms, c_room, n) == 0)
			ft_add_connection(rooms, c_room, n);
		i++;
	}
}

void		ft_select_connections(t_room *rooms)
{
	int		i;

	i = 0;
	while (rooms[i].n != NULL)
	{
		if (rooms[i].link == NULL)
			rooms[i].link = (t_room *)malloc(sizeof(t_room) * MAXROOMS * 2);
		ft_check_rooms_connections(rooms[i], &rooms);
		i++;
	}
}
