/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 08:37:44 by vboiko            #+#    #+#             */
/*   Updated: 2017/10/14 21:44:52 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define MAXROOMS 100000
# define BUFF_SIZE 1

# include "libft/libft.h"
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "limits.h"
# include "fcntl.h"

int					g_rooms;

typedef struct		s_room
{
	char			*n;
	long int		coord_x;
	long int		coord_y;
	long int		point;
	struct s_room	*link;
}					t_room;

typedef struct		s_way
{
	int				*arr;
}					t_way;

typedef struct		s_launch
{
	char			*name;
	int				ant;
	int				point;
	int				count;
}					t_launch;

void				ft_get_input(char **input, t_room *rooms, long int *ants);
void				ft_create_room(t_room *rooms, long int point[], char *name);
void				ft_parse_line(char *line, t_room *rooms, int *point);
short int			ft_if_connection(char *str);
void				ft_if_number(char *str);
void				ft_select_connections(t_room *rooms);
void				ft_error();
void				ft_fix2(t_room *rooms, int i, int k, int fix);
void				ft_launch_ants(t_room *rooms, t_way way, long int ants);
int					ft_getline(int fd, char **line);
void				ft_strannigilation(char **str);
void				ft_if_start_end(t_room *rooms);
long int			ft_atoi_l(const char *str);
t_way				ft_find_ways(t_way way, t_room *rooms);

#endif
