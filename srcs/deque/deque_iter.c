/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 07:50:48 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 07:50:48 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

void	deque_iter(t_deque *deque, void (*f)(void *ptr))
{
	t_deque_node	*travel;
	int				i;

	i = -1;
	travel = deque->head;
	while (++i < deque->size)
	{
		f(travel->as_ptr);
		travel = travel->next;
	}
}
