/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:14:14 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/12 02:40:35 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(*list) * content_size);
	if (list)
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			list->next = NULL;
		}
		else
		{
			if (!(list->content = malloc(content_size)))
				return (NULL);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
			list->next = NULL;
		}
		return (list);
	}
	return (NULL);
}
