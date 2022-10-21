/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:12:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/20 16:09:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define END "\x1b[39m"

# define SENTINEL 0
# define NODE 1

typedef enum	enm {
	Malloc_error,
	Not_int,
	Duplicate
}	error_num;

typedef struct	s_bidrect_circle_list {
	int								num;
	int								role;
	int								index;
	struct s_bidrect_circle_list	*prev;
	struct s_bidrect_circle_list	*next;
}	t_bidrect_circle_list;

/*
typedef struct	s_stack {
	int				*num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;
*/

void					exit_write_message(error_num num);
bool					is_atoi(const char *str);
void					validation_args(int argc, char **argv);
t_bidrect_circle_list	*create_node(int num, int role);
t_bidrect_circle_list	*search_sentinel(t_bidrect_circle_list *node);
t_bidrect_circle_list	*create_stack_a(int argc, char **argv);
void					add_node_stack_back(t_bidrect_circle_list **stack, t_bidrect_circle_list *new);
void					stack_clear(t_bidrect_circle_list **stack);

# endif
