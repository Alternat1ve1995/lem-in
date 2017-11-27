/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:31:49 by vboiko            #+#    #+#             */
/*   Updated: 2017/06/13 09:41:54 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_prnt_itoa(t_launch *path, int i)
{
	char	*num1;
	char	*num2;

	num1 = ft_itoa(path[i].ant);
	num2 = ft_itoa(path[i].ant);
	write(1, num1, ft_strlen(num2));
	ft_strannigilation(&num1);
	ft_strannigilation(&num2);
}

static t_launch	*ft_create_path(t_room *rooms, t_way way, int ants)
{
	t_launch	*path;
	int			i;

	i = 0;
	while (way.arr[i] != -1)
		i++;
	path = (t_launch *)malloc(sizeof(t_launch) * i);
	i = 0;
	path[i].point = 1;
	path[i].count = ants;
	path[i].ant = 1;
	while (way.arr[i] != -1)
	{
		path[i].name = ft_strdup(rooms[way.arr[i]].n);
		if (i != 0)
		{
			path[i].point = 0;
			path[i].count = 0;
			path[i].ant = 0;
		}
		i++;
	}
	path[i - 1].point = 2;
	return (path);
}

static void		ft_print_ants(t_launch *path, int len, int ants)
{
	int		i;

	while (path[len - 1].count != ants)
	{
		i = len;
		while (--i > -1)
			if (path[i].count != 0 && path[i].point != 2)
			{
				write(1, "L", 1);
				ft_prnt_itoa(path, i);
				write(1, "-", 1);
				write(1, path[i + 1].name, ft_strlen(path[i + 1].name));
				write(1, " ", 1);
				path[i + 1].count++;
				path[i].count--;
				path[i + 1].ant = path[i].ant;
				if (path[i].point == 1)
					path[i].ant++;
			}
		write(1, "\n", 1);
	}
}

void			ft_launch_ants(t_room *rooms, t_way way, long int ants)
{
	int			i;
	t_launch	*path;

	i = 0;
	path = ft_create_path(rooms, way, ants);
	while (path[i].point != 2)
		i++;
	ft_print_ants(path, i + 1, ants);
	i = -1;
	while (path[++i].point != 2)
		ft_strannigilation(&(path[i].name));
	ft_strannigilation(&(path[i].name));
	free(path);
}
