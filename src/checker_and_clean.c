/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   checker_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:42:35 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/21 20:39:48 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			ft_exit("422 Non digit detected!\n", NULL, NULL, NULL);
		str++;
	}
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		ft_exit("422 Number out of range!\n", NULL, NULL, NULL);
	return (0);
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
			if (tier1->value == tier2->value)
				ft_exit("409 Duplicate Number found!1\n", &stack_a, NULL, NULL);
			tier2 = tier2->next;
		}
		tier1 = tier1->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
    t_node *tmp;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

void	ft_exit(char *exit_msg, t_node **stack_a, t_node **stack_b, char **split)
{
	ft_printf("%s", exit_msg);
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	if (split)
		ft_free_split(split);
	exit(EXIT_FAILURE);
}
