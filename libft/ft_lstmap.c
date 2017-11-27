/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:13:03 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/09 21:05:37 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*cr;

	ret = NULL;
	if (lst)
		ret = f(lst);
	if (ret == NULL)
		return (NULL);
	cr = ret;
	while (lst->next != NULL)
	{
		lst = lst->next;
		cr->next = f(lst);
		if (cr->next == NULL)
			return (NULL);
		cr = cr->next;
	}
	return (ret);
}
