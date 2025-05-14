/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:03:43 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/14 18:00:47 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
#define PUSH_SWAP_H)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

typedef struct s_node
{
	int value;
	int index;
	struct s_node *next;
} t_node;

void	print_stack(t_node *stack);;

//swap_ops.c All functions for swapping
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ab(t_node **stack_a, t_node **stack_b);

//push_ops.c All functions for pushing
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);

//rotate_ops.c All functions for rotating
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_ab(t_node **stack_a, t_node **stack_b);

//rev_rotate_ops.c All functions for reverse rotating
void	rev_rotate_a(t_node **stack_a);
void	rev_rotate_b(t_node **stack_b);
void	rev_rotate_ab(t_node **stack_a, t_node **stack_b);

#endif // PUSH_SWAP_H)
