/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:34:49 by vboiko            #+#    #+#             */
/*   Updated: 2017/06/21 16:45:38 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	g_rooms;

void	ft_strannigilation(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		(*str)[i] = '\0';
		i++;
	}
	free(*str);
}

void	ft_if_start_end(t_room *rooms)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (rooms[i].n != NULL)
	{
		if (rooms[i].point == 1)
			start++;
		if (rooms[i].point == 2)
			end++;
		i++;
	}
	if (start != 1 || end != 1)
		ft_error();
}

int		ft_is_way_exists(t_way w, t_room *r)
{
	int		i;

	i = 0;
	while (i < MAXROOMS + 2 && r[w.arr[i]].n != NULL && r[w.arr[i]].point != 2)
		i++;
	if (r[w.arr[i]].point == 2)
		return (1);
	else
		return (0);
}

int		main(void)
{
	char		*input;
	t_room		*rooms;
	t_way		way;
	long int	ants;

	g_rooms = 0;
	ants = -1;
	input = (char *)malloc(sizeof(char));
	way.arr = (int *)malloc(sizeof(int) * MAXROOMS * 2);
	rooms = (t_room *)malloc(sizeof(t_room) * MAXROOMS * 2);
	while (++ants < MAXROOMS * 2)
		way.arr[ants] = -1;
	ft_get_input(&input, rooms, &ants);
	ft_if_start_end(rooms);
	if (g_rooms > MAXROOMS)
		ft_error();
	ft_select_connections(rooms);
	way = ft_find_ways(way, rooms);
	if (ft_is_way_exists(way, rooms) != 1)
		ft_error();
	write(1, input, ft_strlen(input));
	write(1, "\n", 1);
	ft_launch_ants(rooms, way, ants);
}
