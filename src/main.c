/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:05:22 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/14 18:17:06 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *stack);
{
	ft_printf("Entry %d: %d", stack->index, stack->value);
}

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
}