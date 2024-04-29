/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:39:33 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/29 03:39:33 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	dumpster_push(t_deque *deque, void *ptr)
{
	t_deque_node	*node;

	node = malloc(sizeof(t_deque_node));
	if (!node)
		return ;
	node->next = node;
	node->prev = node;
	node->as_ptr = ptr;
	if (!deque->head)
	{
		deque->head = node;
		deque->head->next = deque->head;
		deque->head->prev = deque->head;
	}
	else
	{
		deque->head->prev->next = node;
		node->prev = deque->head->prev;
		node->next = deque->head;
		deque->head->prev = node;
	}
	deque->size++;
}

static t_deque	**get_dumpster(int flag)
{
	static t_deque	*perm;
	static t_deque	*temp;

	if (!perm && flag == PERM)
	{
		perm = malloc(sizeof(t_deque));
		perm->head = NULL;
		perm->size = 0;
	}
	if (!temp && flag == TEMP)
	{
		temp = malloc(sizeof(t_deque));
		temp->head = NULL;
		temp->size = 0;
	}
	if (flag == PERM)
		return (&perm);
	return (&temp);
}

void	gc_free(int flag)
{
	int				i;
	t_deque_node	*travel;
	t_deque_node	*next;
	t_deque			**deque;

	deque = get_dumpster(flag);
	travel = (*deque)->head;
	i = -1;
	while (++i < (*deque)->size)
	{
		if (i != (*deque)->size - 1)
			next = travel->next;
		free(travel->as_ptr);
		free(travel);
		travel = next;
	}
	free(*deque);
	*deque = NULL;
}

void	ft_malloc(size_t size, int flag)
{
	void			*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_printf("malloc error");
		exit(0);
	}
	dumpster_push(*get_dumpster(flag), ptr);
}
