/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/25 19:45:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define END "\x1b[39m"

# define SENTINEL 0
# define NODE 1

typedef enum enm {
	Malloc_error,
	Not_int,
	Duplicate
}	t_error_num;

typedef struct s_bidrect_circle_list {
	int								num;
	// int								role;
	int								index;
	struct s_bidrect_circle_list	*prev;
	struct s_bidrect_circle_list	*next;
}	t_bidrect_circle_list;

void					exit_write_message(t_error_num num);
bool					is_atoi(const char *str);
void					validation_args(int argc, char **argv);
t_bidrect_circle_list	*create_node(int num);
t_bidrect_circle_list	*create_sentinel(void);
void					connect_node(t_bidrect_circle_list *head_p,
							t_bidrect_circle_list *new_node);
t_bidrect_circle_list	*create_stack_a(int argc, char **argv);
void					stack_clear(t_bidrect_circle_list **head_p);
char					*swap_a(t_bidrect_circle_list *stack_a);
char					*swap_b(t_bidrect_circle_list *stack_b);
char					*swap_s(t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b);
char					*push_a(t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b);
char					*push_b(t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b);
char					*rotate_a(t_bidrect_circle_list *stack_a);
char					*rotate_b(t_bidrect_circle_list *stack_b);
char					*rotate_r(t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b);
char					*reverse_rotate_a(t_bidrect_circle_list *stack_a);
char					*reverse_rotate_b(t_bidrect_circle_list *stack_b);
char					*reverse_rotate_r(t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b);

#endif
