/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_node_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 06:40:40 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 06:40:40 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

void	deque_push_node_left(t_deque *deque, t_deque_node *node)
{
	if (!node)
		return ;
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
