/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:38:20 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/20 16:40:25 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_bit(t_node *node, int bit_index)
{
	if (!node)
		return (0);
	return (node->index >> bit_index & 1);
}

int sort_bit(t_node **stack_a, t_node **stack_b, int bit_index)
{
	int x;
	int size;

	x = 0;
	size = count_nodes(stack_a);
	while (x < size)
	{
		if (!check_bit(*stack_a, bit_index))
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		x++;
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
	return (0);
}

int count_bits(t_node *stack)
{
	int bits;
	int max;

	bits = 0;
	max = 8;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int is_sorted(t_node **stack)
{
	int x;
	t_node *temp;

	x = 0;
	temp = *stack;
	while (temp && temp->index == x)
	{
		if (temp->index != x)
			return (0);
		x++;
		temp = temp->next;
	}
	return (0);
}

int radix_sort(t_node **stack_a, t_node **stack_b)
{
	int bit_max;
	int bit_index;

	bit_max = count_bits(*stack_a);
	bit_index = 0;
	while (bit_index < bit_max)
	{
		sort_bit(stack_a, stack_b, bit_index);
		if (is_sorted(stack_a))
			break ;
		bit_index++;
	}
	return (0);
}
