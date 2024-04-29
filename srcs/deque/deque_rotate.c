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

void	deque_rotate(t_deque *deque, int n)
{
	if (!deque)
		return ;
	if (n > 0)
		while (n--)
			deque->head = deque->head->next;
	else
		while (n++)
			deque->head = deque->head->prev;
}
