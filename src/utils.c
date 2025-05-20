/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:44:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/19 20:48:13 by ohaker           ###   ########.fr       */
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

int	check_double_num(t_node *stack_a)
{
	t_node *tier1;
	t_node *tier2;

	tier1 = stack_a;
	while (tier1)
	{
		tier2 = tier1->next;
		while (tier2)
		{
			// printf("Tier1: %d, Tier2: %d\n", tier1->value, tier2->value);
			if (tier1->value == tier2->value)
				ft_exit("409 Duplicate Number found!\n");
			tier2 = tier2->next;
		}
		tier1 = tier1->next;
	}
	return (0);
}

void	ft_exit(char *exit_msg)
{
	ft_printf(exit_msg);
	exit(0);
}

t_node	*init_first_node(char *value_str, t_node **stack_a)
{
	t_node *new_node;

	new_node = create_node();
	if (!new_node)
		return (NULL);
	new_node->value = ft_atoi(value_str);
	*stack_a = new_node;
	return (new_node);
}
