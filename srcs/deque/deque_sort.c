/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:36:46 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/29 02:36:46 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

void	deque_sort(t_deque *deque, int (cmp)(void *ptr1, void *ptr2))
{
	int	i;
	int	flag;

	if (!deque || deque->size <= 1)
		return ;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = -1;
		while (++i < deque->size - 1)
		{
			if (cmp(deque->head, deque->head->next))
			{
				deque_swap(deque);
				flag = 1;
			}
			deque_rotate(deque, 1);
		}
		deque_rotate(deque, 1);
	}
}
