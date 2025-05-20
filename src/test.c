void	pull_node_front(t_node **stack, int index)
{
	t_node	*prev;
	t_node	*curr;

	prev = NULL;
	curr = *stack;
	if (!stack || !*stack || index <= 0)
		return ;
	for (int i = 0; curr && i < index; i++)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!curr || !prev)
		return ;
	prev->next = curr->next;
	curr->next = *stack;
	*stack = curr;
}

void	sorting_test(t_node **stack)
{
	t_node	*sorted;
	t_node	*tmp;
	t_node	*next;

	sorted = NULL;
	int min_index, min_pos, i;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		min_index = tmp->index;
		min_pos = 0;
		i = 0;
		// Find the position of the node with the lowest index
		while (tmp)
		{
			if (tmp->index < min_index)
			{
				min_index = tmp->index;
				min_pos = i;
			}
			tmp = tmp->next;
			i++;
		}
		// Pull the node with the smallest index to the front
		pull_node_front(stack, min_pos);
		// Detach the front node and add it to the sorted list
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = sorted;
		sorted = tmp;
	}
	// Reverse the sorted list to correct the order (since we built it backwards)
	tmp = NULL;
	while (sorted)
	{
		next = sorted->next;
		sorted->next = tmp;
		tmp = sorted;
		sorted = next;
	}
	*stack = tmp;
}