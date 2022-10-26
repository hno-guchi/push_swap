/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 17:04:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define RED "\x1b[31m"
# define RED_BACK "\x1b[41m"
# define GREEN "\x1b[32m"
# define GREEN_BACK "\x1b[42m"
# define END "\x1b[39m"
# define END_BACK "\x1b[49m"

# define SENTINEL 0
# define NODE 1

typedef struct s_list	t_list;

typedef enum enm {
	Malloc_error,
	Not_int,
	Duplicate
}	t_error_num;

typedef enum operation {
	Swap_a,
	Swap_b,
	Swap_s,
	Push_a,
	Push_b,
	Rotate_a,
	Rotate_b,
	Rotate_r,
	Reverse_rotate_a,
	Reverse_rotate_b,
	Reverse_rotate_r
}	t_operation;

typedef struct s_bidrect_circle_list {
	int								num;
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
t_list					*execute_operation(t_operation type,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b);
void					putstr_log(t_list *head_p);
t_bidrect_circle_list	*copy_stack_a(t_bidrect_circle_list *src_head_p);

#endif
