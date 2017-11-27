/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:08:43 by vboiko            #+#    #+#             */
/*   Updated: 2017/10/15 14:43:18 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	g_rooms;

void		ft_isline(char *line, t_room *rooms, int *arr)
{
	if (line[0] != '#')
	{
		if (arr[0] == 1)
			ft_parse_line(line, rooms, &arr[0]);
		else if (arr[1] == 2)
			ft_parse_line(line, rooms, &arr[1]);
		else
			ft_parse_line(line, rooms, &arr[2]);
		arr[3] = 0;
	}
}

static void	ft_validate_line(char *line, t_room *rooms)
{
	int			i;
	static int	arr[4] = {0, 0, 0, 0};

	i = 0;
	if (line[i] == '#' && line[i + 1] == '#')
	{
		if (ft_strcmp(line, "##start\n") == 0 && (arr[0] == 1 || arr[1] == 2))
			ft_error();
		if (ft_strcmp(line, "##end\n") == 0 && (arr[0] == 1 || arr[1] == 2))
			ft_error();
		if (ft_strcmp("start\n", line + 2) == 0 && arr[0] == 0)
			arr[0] = 1;
		else if (ft_strcmp("start\n", line + 2) == 0 && arr[0] > 0)
			ft_error();
		if (ft_strcmp("end\n", line + 2) == 0 && arr[1] == 0)
			arr[1] = 2;
		else if (ft_strcmp("end\n", line + 2) == 0 && arr[1] > 0)
			ft_error();
	}
	ft_isline(line, rooms, arr);
}

static void	ft_valid_free(char **line, t_room *rooms, long int *ants)
{
	static int	i = -1;

	if ((*line)[0] == 'L' || (*line)[0] == '\n')
		ft_error();
	if (i == -1)
	{
		while ((*line)[++i] != '\n' && (*line)[i] != '\0')
			if (ft_isdigit((*line)[i]) == 0)
				ft_error();
		*ants = ft_atoi_l(*line);
		if (*ants < 1 || *ants > INT_MAX)
			ft_error();
	}
	else
		ft_validate_line(*line, rooms);
}

void		ft_get_input(char **input, t_room *rooms, long int *ants)
{
	char	*line;
	int		fd;
	int		flag;
	char	*tmp;

	flag = 0;
	fd = 0;
	while (ft_getline(fd, &line) != 0)
	{
		if (line[ft_strlen(line) - 1] != '\n')
		{
			tmp = line;
			line = ft_strjoin(line, "\n\0");
			ft_strannigilation(&tmp);
		}
		if (flag != 0 || line[0] != '#')
		{
			ft_valid_free(&line, rooms, ants);
			flag = 1;
		}
		tmp = *input;
		*input = ft_strjoin(*input, line);
		ft_strannigilation(&tmp);
		ft_strannigilation(&line);
	}
}
