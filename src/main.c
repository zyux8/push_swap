/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:05:22 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/24 20:39:39 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *stack)
{
	if (!stack)
	{
		ft_printf("404 Stack not found\n");
		return ;
	}
	while (stack)
	{
		ft_printf("Entry %d: %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}

void	read_string(char *str, t_node **stack_a)
{
	int		x;
	char	**split;
	t_node	*temp;
	t_node	*new;

	x = 0;
	split = ft_split(str, ' ');
	if (!split)
		ft_exit("Error\n", stack_a, NULL, split);
	temp = init_first_node(split[x++], stack_a);
	if (!temp)
		ft_exit("Error\n", stack_a, NULL, NULL);
	while (split[x])
	{
		if (check_digits(split[x]) == -1)
			ft_exit("Error\n", stack_a, NULL, split);
		new = create_node();
		if (!new)
			ft_exit("Error\n", stack_a, NULL, NULL);
		new->value = ft_atoi(split[x++]);
		temp->next = new;
		temp = temp->next;
	}
	ft_free_split(split);
}

void	read_args(char **args, t_node **stack_a)
{
	int		x;
	t_node	*temp;
	t_node	*new_node;

	x = 1;
	temp = init_first_node(args[x++], stack_a);
	if (!temp)
		ft_exit("Error\n", stack_a, NULL, NULL);
	while (args[x])
	{
		if (check_digits(args[x]) == -1)
			ft_exit("Error\n", stack_a, NULL, NULL);
		new_node = create_node();
		if (!new_node)
			ft_exit("Error\n", stack_a, NULL, NULL);
		new_node->value = ft_atoi(args[x++]);
		temp->next = new_node;
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		read_string(argv[1], &stack_a);
	else
		read_args(argv, &stack_a);
	check_double_num(stack_a);
	assign_index(&stack_a);
	// ft_printf("Stack 1:\n");
	// print_stack(stack_a);
	if (!is_sorted(&stack_a))
		radix_sort(&stack_a, &stack_b);
	// ft_printf("Stack 2:\n");
	// print_stack(stack_a);
	return (0);
}
