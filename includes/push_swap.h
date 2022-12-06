/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 10:49:33 by hnoguchi         ###   ########.fr       */
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
# define HEAD_SORTED 0
# define SORT_MINIMAM_SIZE 4
# define ARRAY_SIZE 100

typedef struct s_list	t_list;

typedef enum enm {
	Malloc_error,
	Not_int,
	Duplicate,
	Failed_sort
}	t_error_num;

typedef enum operation {
	Not,
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
	Bad_order,
	Min_mid_max,
	Min_max_mid,
	Mid_min_max,
	Mid_max_min,
	Max_min_mid,
	Max_mid_min
}	t_order;

typedef struct s_dcl_list {
	int					num;
	int					index;
	struct s_dcl_list	*prev;
	struct s_dcl_list	*next;
}	t_dcl_list;

typedef struct	s_sort_info {
	int			size;
	int			sorted;
	int			limits[ARRAY_SIZE];
	int			limit;
	int			limits_idx;
	int			section_size;
	int			a_pivot;
	int			b_pivot;
	int			stack_b_size;
}	t_sort_info;

void		exit_write_message(t_error_num num);
bool		is_atoi(const char *str);
int			*create_array_atoi(int size, char **elements);
void		quick_sort(int *array, int size);
void		validation_args(int argc, char **argv);
t_dcl_list	*create_node(int num);
t_dcl_list	*create_sentinel(void);
void		connect_node(t_dcl_list *head_p, t_dcl_list *new_node);
t_dcl_list	*create_stack_a(int argc, char **argv);
t_dcl_list	*prepare_sort(int size, char **elements, t_dcl_list *head_p);
void		stack_clear(t_dcl_list **head_p);
int			stack_len(t_dcl_list *head_p);
char		*swap_a(t_dcl_list *stack_a);
char		*swap_b(t_dcl_list *stack_b);
char		*swap_s(t_dcl_list *stack_a, t_dcl_list *stack_b);
char		*push_a(t_dcl_list *stack_a, t_dcl_list *stack_b);
char		*push_b(t_dcl_list *stack_a, t_dcl_list *stack_b);
char		*rotate_a(t_dcl_list *stack_a);
char		*rotate_b(t_dcl_list *stack_b);
char		*rotate_r(t_dcl_list *stack_a, t_dcl_list *stack_b);
char		*reverse_rotate_a(t_dcl_list *stack_a);
char		*reverse_rotate_b(t_dcl_list *stack_b);
char		*reverse_rotate_r(t_dcl_list *stack_a, t_dcl_list *stack_b);
t_list		*execute_operation(t_operation type, t_dcl_list *stack_a,
			t_dcl_list *stack_b, t_list *log);
void		putstr_log(t_list *head_p);
bool		is_ascending_sorted(t_dcl_list *head_p);
bool		is_descending_sorted(t_dcl_list *head_p, int begin);
t_order		compare_3_values(int first, int second, int third);
t_list		*sort_n_under_4(int n, t_dcl_list *stack_a, t_dcl_list *stack_b,
				t_list *log);
t_list		*sort_n_under_7(int n, t_dcl_list *stack_a, t_dcl_list *stack_b,
				t_list *log);
t_list		*sort_n_under_4_descending(int n, t_dcl_list *stack_a, t_dcl_list *stack_b,
				t_list *log);
int			calculate_median(int size);
int			calculate_section_size(t_sort_info *info, t_dcl_list *stack);
void		initialize_array(int array_size, int *array);
void		initialize_sort_info_first_half(t_sort_info *info, int stack_size);
void		initialize_sort_info_second_half(t_sort_info *info);
void		set_sort_info_next_section(t_sort_info *info, t_dcl_list *stack);
t_list		*split_first_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*split_second_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*push_swap_stack_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*push_swap_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_min_max_mid(t_sort_info *info, t_dcl_list *stack_a,t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_mid_min_max(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_mid_max_min(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_max_min_mid(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_max_mid_min(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*sort_section_size_under_4(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
bool		is_under_b_pivot(t_sort_info *info, t_dcl_list *node);
bool		is_swap_a(t_sort_info *info, t_dcl_list *node);
bool		is_swap_b(t_sort_info *info, t_dcl_list *node);
bool		is_sort_stack_b_prev(t_sort_info *info, t_dcl_list *prev_node);
bool		is_sort_stack_b_next(t_sort_info *info, t_dcl_list *prev_node);
bool		is_complete_sort_section(t_sort_info *info, t_dcl_list *stack);
t_list		*try_swap(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_swap_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_until_possible(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list		*try_sort_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
// debug_output
void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);

#endif
