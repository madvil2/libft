/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 07:49:35 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 07:49:35 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

t_deque_node	*deque_pop_right(t_deque *deque)
{
	t_deque_node	*prev;
	t_deque_node	*head;
	t_deque_node	*next;

	head = deque->head;
	if (!head)
		return (NULL);
	prev = head->prev;
	next = head->next;
	if (head == head->next)
		deque->head = NULL;
	else
	{
		deque->head = next;
		next->prev = prev;
		prev->next = next;
	}
	head->next = NULL;
	head->prev = NULL;
	deque->size -= 1;
	return (head);
}
