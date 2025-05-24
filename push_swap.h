/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:03:43 by ohaker            #+#    #+#             */
/*   Updated: 2025/05/24 19:23:24 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// main.c Main structure of the program
void				print_stack(t_node *stack);
void				read_string(char *str, t_node **stack_a);
int					main(int argc, char **argv);

// swap_ops.c All functions for swapping
void				swap_a(t_node **stack_a);
void				swap_b(t_node **stack_b);
void				swap_ab(t_node **stack_a, t_node **stack_b);

// push_ops.c All functions for pushing
void				push_a(t_node **stack_a, t_node **stack_b);
void				push_b(t_node **stack_a, t_node **stack_b);

// rotate_ops.c All functions for rotating
void				rotate_a(t_node **stack_a);
void				rotate_b(t_node **stack_b);
void				rotate_ab(t_node **stack_a, t_node **stack_b);

// rev_rotate_ops.c All functions for reverse rotating
void				rev_rotate_a(t_node **stack_a);
void				rev_rotate_b(t_node **stack_b);
void				rev_rotate_ab(t_node **stack_a, t_node **stack_b);

// list_helpers.c Functions to work with the List
t_node				*create_node(void);
int					count_nodes(t_node **stack);
t_node				*find_biggest(t_node *stack_a);

// utils.c Helping functions for general stuff
int					assign_index(t_node **stack);
t_node				*init_first_node(char *value_str, t_node **stack_a);

// radix.c Radix sorting functions
int					is_sorted(t_node **stack);
int					check_bit(t_node *node, int bit_index);
int					radix_sort(t_node **stack_a, t_node **stack_b);

// checker_and_clean.c Checks conditions of the arguments and also exits clean
int					check_digits(char *str);
int					check_double_num(t_node *stack_a);
void				ft_exit(char *exit_msg, t_node **stack_a, t_node **stack_b,
						char **split);

//sort_3-5.c Functions to sort 3 and 5 numbers
void				sort_two(t_node **stack_a);
void				sort_three(t_node **stack_a);
void				sort_five(t_node **stack_a, t_node **stack_b);

#endif // PUSH_SWAP_H
