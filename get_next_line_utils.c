/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:40:17 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/24 17:40:17 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_len(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (((char *)list->content)[i])
		{
			if (((char *)list->content)[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	free_list(t_list **list, t_list *clear_node, char *buf)
{
	t_list	*temp;

	if (!*list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (((char *)clear_node->content)[0])
		*list = clear_node;
	else
	{
		free(buf);
		free(clear_node);
	}
}

void	clear_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clear_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	clear_node = malloc(sizeof(t_list));
	if (!buf || !clear_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (((char *)last_node->content)[i] && ((char *)last_node->content)[i] != '\n')
		i++;
	while (((char *)last_node->content)[i] && ((char *)last_node->content)[++i])
		buf[j++] = ((char *)last_node->content)[i];
	buf[j] = '\0';
	clear_node->content = buf;
	clear_node->next = NULL;
	free_list(list, clear_node, buf);
}

void	str_copy(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (((char *)list->content)[i])
		{
			if (((char *)list->content)[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = ((char *)list->content)[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}
