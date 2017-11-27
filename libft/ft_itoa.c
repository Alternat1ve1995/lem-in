/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:58:35 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/08 14:45:56 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_mem(int neg, size_t len, long int nb, int n)
{
	char	*fin;

	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	if (neg == 0)
		fin = ft_strnew(len);
	else
	{
		fin = ft_strnew(len + 1);
		len = len + 1;
	}
	if (fin == NULL)
		return (NULL);
	nb = (long int)n;
	if (neg == 1)
		nb = nb * (-1);
	while (len > 0)
	{
		fin[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (fin);
}

char		*ft_itoa(int n)
{
	size_t			len;
	long int		nb;
	int				neg;
	char			*str;

	len = 1;
	neg = 0;
	nb = (long int)n;
	if (n < 0)
	{
		nb = nb * (-1);
		neg = 1;
	}
	str = ft_itoa_mem(neg, len, nb, n);
	if (str == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	return (str);
}
