/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:08:26 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/17 18:18:48 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *create_node(void)
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	newnode->value = 0;
	newnode->index = -1;
	newnode->next = NULL;
	return (newnode);
}

void	add_node_back(t_node **stack, t_node *newnode)
{
	t_node *temp;

	if (*stack)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = newnode;
	}
	else
		*stack = newnode;
}

void	add_node_front(t_node **stack, t_node *newnode)
{
	if (!newnode)
		return ;
	newnode->next = *stack;
	*stack = newnode;
}

int	count_nodes(t_node **stack)
{
	int x;
	t_node *temp;

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
