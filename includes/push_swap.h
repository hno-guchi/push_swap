/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/21 17:22:19 by hnoguchi         ###   ########.fr       */
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

typedef enum operationnm {
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
}	t_operation_num;

typedef struct s_operation_log_list {
	t_operation_num				log;
	struct s_operation_log_list	*next;
}	t_operation_log_list;

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
t_bidrect_circle_list	*create_stack_a(int argc, char **argv);
void					stack_clear(t_bidrect_circle_list **head_p);
void					log_list_clear(t_operation_log_list **list);
void					putstr_log(t_operation_log_list *list);
t_operation_log_list	*create_log_node(t_operation_num log);
void					add_back_list_log_node(t_operation_log_list **list,
							t_operation_log_list *new_node);

#endif
