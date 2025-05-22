/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:40:33 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/14 17:33:12 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*previous;

	if (!*stack || !(*stack)->next)
		return ;
	previous = *stack;
	while (previous->next)
	{
		last = previous;
		previous = previous->next;
	}
	last->next = NULL;
	previous->next = *stack;
	*stack = previous;
}

void	rev_rotate_a(t_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
