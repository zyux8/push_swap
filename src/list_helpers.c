/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:08:26 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/24 22:36:26 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(void)
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		ft_exit("Error\n", NULL, NULL, NULL);
	newnode->value = 0;
	newnode->index = -1;
	newnode->next = NULL;
	return (newnode);
}

int	count_nodes(t_node **stack)
{
	int		x;
	t_node	*temp;

	if (!(*stack))
		return (0);
	x = 0;
	temp = *stack;
	while (temp)
	{
		x++;
		temp = temp->next;
	}
	return (x);
}

t_node *find_lowest(t_node *stack_a)
{
	t_node *lowest;
	
	if (!stack_a)
		return (NULL);
	lowest = stack_a;
	while (stack_a)
	{
		if (stack_a->index < lowest->index)
			lowest = stack_a;
		stack_a = stack_a->next;
	}
	return (lowest);
}
