/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:10:43 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/08 13:07:34 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*object;

	object = (t_list *)malloc(sizeof(t_list));
	if (object == NULL)
		return (NULL);
	if (content == NULL)
	{
		object->content = NULL;
		object->content_size = 0;
	}
	else
	{
		object->content = malloc(content_size);
		if (object->content == NULL)
		{
			free(object);
			return (NULL);
		}
		ft_memcpy(object->content, content, content_size);
		object->content_size = content_size;
	}
	object->next = NULL;
	return (object);
}
