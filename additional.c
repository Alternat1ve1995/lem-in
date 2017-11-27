/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:00:19 by vboiko            #+#    #+#             */
/*   Updated: 2017/10/15 14:13:55 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	g_rooms;

void		ft_create_room(t_room *rooms, long int point[], char *name)
{
	static int	i = 0;
	int			k;

	k = -1;
	g_rooms++;
	if (g_rooms > MAXROOMS)
		ft_error();
	while (rooms[++k].n != NULL)
	{
		if (ft_strcmp(rooms[k].n, name) == 0)
			ft_error();
		if (rooms[k].coord_x == point[0] && rooms[k].coord_y == point[1])
			ft_error();
	}
	rooms[i].n = ft_strdup(name);
	rooms[i].coord_x = point[0];
	rooms[i].coord_y = point[1];
	rooms[i].point = point[2];
	rooms[i].link = NULL;
	i++;
	rooms[i].n = NULL;
}

void		ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(-1);
}

short int	ft_if_connection(char *str)
{
	int		i;
	int		space;
	int		def;

	i = -1;
	space = 0;
	def = 0;
	while (str[++i] != '\0')
		if (str[i] == '-')
			def++;
		else if (str[i] == ' ')
			space++;
	if (def == 1 && space == 0)
		return (1);
	return (0);
}

void		ft_if_number(char *str)
{
	int		i;

	if (str[0] == '-')
		i = 0;
	else
		i = -1;
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]) == 0)
			ft_error();
}
