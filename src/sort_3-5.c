/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3-5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:05:29 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/23 21:39:33 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two(t_node **stack_a)
{
	int temp;

	temp = (*stack_a)->next->index;
	if ((*stack_a)->index > temp)
		swap_a(stack_a);
}

void sort_three(t_node **stack_a)
{
	int a;
	int b;
	int c;

	if (is_sorted(stack_a))
		return;
	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(stack_a);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
	int size;

	size = count_nodes(stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index < 2)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
	
}
