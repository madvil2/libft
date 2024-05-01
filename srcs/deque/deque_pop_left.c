/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 07:24:41 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 07:24:41 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

t_deque_node	*deque_pop_left(t_deque *deque)
{
	t_deque_node	*head;
	t_deque_node	*prev;
	t_deque_node	*prev_prev;

	head = deque->head;
	if (!head)
		return (NULL);
	prev = deque->head->prev;
	prev_prev = prev->prev;
	if (head == head->next)
		deque->head = NULL;
	else
	{
		deque->head->prev = prev_prev;
		prev_prev->next = deque->head;
	}
	prev->next = NULL;
	prev->prev = NULL;
	deque->size -= 1;
	return (prev);
}
