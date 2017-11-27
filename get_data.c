/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:01:09 by vboiko            #+#    #+#             */
/*   Updated: 2017/10/14 21:05:43 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long int	ft_atoi_l(const char *str)
{
	size_t		i;
	int			negative;
	long int	num;

	i = 0;
	negative = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + (int)str[i++] - 48;
	}
	if (negative == 1)
		return (-num);
	return (num);
}

int			ft_indexof(char c, char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\0' && c != '\0')
		return (-1);
	else
		return (i);
}

ssize_t		ft_update_data(int fd, char **data)
{
	char		*buf;
	char		*tmp;
	ssize_t		rd;

	buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	rd = read(fd, buf, BUFF_SIZE);
	if (*data == NULL && buf[0] == 0)
		ft_error();
	if (rd != 0)
	{
		if (*data == NULL)
			*data = ft_strdup(buf);
		else
		{
			tmp = *data;
			*data = ft_strjoin(*data, buf);
			ft_strannigilation(&tmp);
		}
	}
	ft_strannigilation(&buf);
	return (rd);
}

int			ft_getline(int fd, char **line)
{
	static char		*data = NULL;
	char			*str;
	char			*tmp;
	int				index;
	static ssize_t	rd = 1;

	if (rd == EOF || (data != NULL && data[0] == '\0' && rd == 0))
		return (0);
	while (ft_indexof('\n', data) == -1 && rd != 0)
		rd = ft_update_data(fd, &data);
	if (rd == 0 && data[0] == '\0')
		return (0);
	index = ft_indexof('\n', data);
	if (index == -1 || rd == 0)
		index = ft_indexof('\0', data);
	str = ft_strsub(data, 0, index + 1);
	tmp = data;
	data = ft_strsub(data, index + 1, ft_strlen(data) - index);
	ft_strannigilation(&tmp);
	*line = ft_strdup(str);
	ft_strannigilation(&str);
	return (1);
}
