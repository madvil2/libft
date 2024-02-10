/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:40:02 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/10 21:46:13 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

static int	is_newline(t_list *list)
{
	int	i;


	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (((char *)list->content)[i] && i < BUFFER_SIZE)
		{
			if (((char *)list->content)[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

static void	save_list(t_list **list, int fd)
{
	long	read_char;
	char	*buf;

	while (!is_newline(*list))
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return ;
		read_char = read(fd, buf, BUFFER_SIZE);
		if (!read_char)
		{
			free(buf);
			return ;
		}
		buf[read_char] = '\0';
		join_list(list, buf);
	}
}

static char	*make_line(t_list *list)
{
	int		len;
	char	*str;

	if (!list)
		return (NULL);
	len = line_len(list);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_copy(list, str);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	t_list			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		while (list)
		{
			tmp = list->next;
			free(list->content);
			free(list);
			list = tmp;
		}
		list = NULL;
		return (NULL);
	}
	save_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = make_line(list);
	clear_list(&list);
	return (next_line);
}
