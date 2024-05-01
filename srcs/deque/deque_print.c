/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:53:50 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/01 06:53:50 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

void	deque_print(t_deque *deque)
{
	int				i;
	t_deque_node	*travel;

	i = -1;
	travel = deque->head;
	while (++i < deque->size)
	{
		ft_printf("%d: %s\n", i, travel->as_ptr);
		travel = travel->next;
	}
}
