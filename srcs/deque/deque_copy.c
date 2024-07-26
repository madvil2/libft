#include "../../includes/deque.h"

t_deque	*deque_copy(t_deque *deque)
{
	t_deque_node	*travel;
	int				i;
	t_deque			*res;
	t_deque_node	*new_node;

	res = deque_init();
	i = -1;
	travel = deque->head;
	while (++i < deque->size)
	{
		new_node = deque_node_init(ft_strdup(travel->as_str));
		deque_push_node_right(res, new_node);
		travel = travel->next;
	}
	return (res);
}
