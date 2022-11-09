/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/09 11:10:33 by hnoguchi         ###   ########.fr       */
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
	Duplicate,
	Failed_sort
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

typedef enum order {
	Min_mid_max,
	Min_max_mid,
	Max_mid_min,
	Mid_min_max,
	Max_min_mid,
	Mid_max_min
}	t_order;

typedef struct s_bidrect_circle_list {
	int								num;
	int								index;
	struct s_bidrect_circle_list	*prev;
	struct s_bidrect_circle_list	*next;
}	t_bidrect_circle_list;

/*
typedef struct s_stack_info {
	int	stack_size;
	int	median;
	int	maximum;
}	t_stack_info;
*/

typedef struct	s_sort_range_index {
	int	count_sorted;
	int	begin;
	int	end;
	int	a_pivot;
	int	b_pivot;
	int	median;
	int	count_pushed;
	int	cycle;
}	t_sort_range_index;

void					exit_write_message(t_error_num num);
bool					is_atoi(const char *str);
int						*create_array_atoi(int size, char **elements);
void					quick_sort(int *array, int size);
void					validation_args(int argc, char **argv);
t_bidrect_circle_list	*create_node(int num);
t_bidrect_circle_list	*create_sentinel(void);
void					connect_node(t_bidrect_circle_list *head_p,
							t_bidrect_circle_list *new_node);
t_bidrect_circle_list	*create_stack_a(int argc, char **argv);
t_bidrect_circle_list	*prepare_sort(int size, char **elements,
							t_bidrect_circle_list *head_p);
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
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
void					putstr_log(t_list *head_p);
bool					is_ascending_sorted(t_bidrect_circle_list *head_p);
bool					is_descending_sorted(t_bidrect_circle_list *head_p);
t_order					compare_3_values(int first, int second, int third);
t_list					*push_swap_under_7(int n,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
t_list					*sort_n_under_4(int n,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
t_list					*sort_n_under_7(int n,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
t_list					*sort_n_under_4_descending(int n,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
bool					is_swap_a(int sorted, t_bidrect_circle_list *stack);
bool					is_swap_b(int pushed, t_bidrect_circle_list *stack);
t_list					*try_swap(t_sort_range_index *ranges,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
bool					is_rotate_a(int pivot, int index);
bool					is_rotate_b(t_sort_range_index *ranges, int index);
t_list					*try_rotate(t_sort_range_index *ranges,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
bool					is_sort(int sorted, int index);
t_list					*try_sort(t_sort_range_index *ranges,
							t_bidrect_circle_list *stack_a,
							t_bidrect_circle_list *stack_b,
							t_list *head_p_log);
#endif
