/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_to_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:03:29 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/14 20:03:29 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

void	**deque_to_arr(t_deque *deque)
{
	int				i;
	void			**res;
	t_deque_node	*travel;

	res = ft_malloc((deque->size + 1) * sizeof(void *));
	res[deque->size] = 0;
	i = -1;
	travel = deque->head;
	while (++i < deque->size)
	{
		res[i] = ft_strdup(travel->as_str);
		travel = travel->next;
	}
	return (res);
}