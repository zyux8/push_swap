/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:42:35 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/20 19:39:41 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

	int check_digits(char *str)
	{
		if (!ft_isdigit(ft_atoi(str)))
		{
			ft_printf("422 Non digit detected!\n");
			return (1);
		}
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
			// printf("Tier1: %d, Tier2: %d\n", tier1->value, tier2->value);
			if (tier1->value == tier2->value)
				ft_exit("409 Duplicate Number found!1\n");
			tier2 = tier2->next;
		}
		tier1 = tier1->next;
	}
	return (0);
}

int check_args(t_node *stack_a)
{
	// if (!check_digits(stack_a))
	// {
	// 	ft_printf("422 Non digit detected!\n");
	// 	return (1);
	// }
	if (check_double_num(stack_a))
	{
		ft_printf("409 Duplicate Number found!\n");
		return (1);
	}
	return (0);
}

void	ft_exit(char *exit_msg)
{
	ft_printf(exit_msg);
	exit(0);
}
