/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:05:22 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/29 02:05:22 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

void	deque_swap(t_deque *deque)
{
	t_deque_node	*tail;

	if (!deque || deque->size <= 1)
		return ;
	if (deque->size == 2)
		return (deque_rotate(deque, 1));
	tail = deque->head->prev;
	deque_pop_left(deque);
	deque->head = deque->head->next;
	deque_push_node_right(deque, tail);
}
