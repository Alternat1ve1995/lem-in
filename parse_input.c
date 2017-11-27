/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:04:52 by vboiko            #+#    #+#             */
/*   Updated: 2017/10/15 14:50:17 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	g_rooms;

static void	ft_valid_points(char *line, t_room *rooms, int point, long int p[])
{
	char	*valid;
	char	*name;

	name = ft_strsub(line, 0, (size_t)p[0]);
	valid = ft_strsub(line, (unsigned int)(p[0] + 1),
	(size_t)(p[1] - p[0] - 1));
	ft_if_number(valid);
	p[0] = ft_atoi_l(valid);
	ft_strannigilation(&valid);
	valid = ft_strsub(line, (unsigned int)(p[1] + 1),
	(size_t)(p[2] - p[1] - 2));
	ft_if_number(valid);
	p[1] = ft_atoi_l(valid);
	ft_strannigilation(&valid);
	p[2] = point;
	if (p[0] > INT_MAX || p[1] > INT_MAX || p[0] < INT_MIN || p[1] < INT_MIN)
		ft_error();
	ft_create_room(rooms, p, name);
	ft_strannigilation(&name);
}

static void	ft_valid_room(char *line, t_room *rooms, int point)
{
	int			i;
	long int	points[3];

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] == '-')
			ft_error();
		i++;
	}
	if (line[i] == '\0')
		ft_error();
	points[0] = i;
	i++;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		ft_error();
	points[1] = i;
	i++;
	while (line[i] != '\0')
		i++;
	points[2] = i;
	ft_valid_points(line, rooms, point, points);
}

static void	ft_create_connection(char *name1, char *name2, t_room *rooms)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	while (ft_strcmp((rooms)[i].n, name1) != 0 && (rooms)[i].n != NULL)
		i++;
	ft_fix2(rooms, i, k, 0);
	while (ft_strcmp((rooms)[k].n, name2) != 0 && (rooms)[k].n != NULL)
		k++;
	ft_fix2(rooms, i, k, 1);
	if ((rooms)[i].link == NULL)
	{
		(rooms)[i].link = (t_room *)malloc(sizeof(t_room) * MAXROOMS + 2);
		(rooms)[i].link[0] = (rooms)[k];
		(rooms)[i].link[1].n = NULL;
	}
	else
	{
		while ((rooms)[i].link[j].n != NULL)
			j++;
		(rooms)[i].link[j] = (rooms)[k];
	}
}

static void	ft_valid_connection(char *line, t_room *rooms)
{
	int		i;
	char	*name1;
	char	*name2;

	i = 0;
	ft_if_start_end(rooms);
	while (line[i] != '-' && line[i] != '\0')
		i++;
	name1 = ft_strsub(line, 0, (unsigned int)i);
	name2 = ft_strsub(line, (unsigned int)(i + 1), ft_strlen(line) - i - 2);
	i = -1;
	while ((rooms)[++i].n != NULL)
		if (ft_strcmp((rooms)[i].n, name1) == 0)
			break ;
	ft_fix2(rooms, i, 0, 0);
	i = -1;
	while ((rooms)[++i].n != NULL)
		if (ft_strcmp((rooms)[i].n, name2) == 0)
			break ;
	if ((rooms)[i].n == NULL)
		ft_error();
	ft_create_connection(name1, name2, rooms);
	ft_strannigilation(&name1);
	ft_strannigilation(&name2);
}

void		ft_parse_line(char *line, t_room *rooms, int *point)
{
	static int	start = 0;
	static int	end = 0;

	if (ft_if_connection(line) == 0 && (start == 0 || end == 0))
	{
		if (*point == 1 && start == 0)
			ft_valid_room(line, rooms, *point);
		else if (*point == 2 && end == 0)
			ft_valid_room(line, rooms, *point);
		else
			ft_valid_room(line, rooms, 0);
		if (*point == 1)
			start++;
		else if (*point == 2)
			end++;
	}
	else if (ft_if_connection(line) == 0)
		ft_valid_room(line, rooms, 0);
	else
		ft_valid_connection(line, rooms);
	(*point) += 3;
}
