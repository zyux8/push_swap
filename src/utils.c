/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:44:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/20 19:42:47 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	assign_index(t_node **stack)
{
	int		x;
	int		max;
	t_node	*temp;
	t_node	*lowest_node;

	x = 0;
	if (!(*stack))
		return (0);
	temp = *stack;
	max = count_nodes(&temp);
	while (x < max)
	{
		temp = *stack;
		lowest_node = NULL;
		while (temp)
		{
			if (temp->index == -1 && (!lowest_node
					|| temp->value < lowest_node->value))
				lowest_node = temp;
			temp = temp->next;
		}
		if (lowest_node)
			lowest_node->index = x++;
	}
	return (max);
}

t_node	*init_first_node(char *value_str, t_node **stack_a)
{
	t_node *new_node;

	if (!check_digits(value_str))
		return (NULL);
	new_node = create_node();
	if (!new_node)
		return (NULL);
	new_node->value = ft_atoi(value_str);
	*stack_a = new_node;
	return (new_node);
}
