/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:28:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/27 19:04:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define RED "\x1b[31m"
# define RED_BACK "\x1b[41m"
# define GREEN "\x1b[32m"
# define GREEN_BACK "\x1b[42m"
# define END "\x1b[39m"
# define END_BACK "\x1b[49m"

typedef struct	s_stack_sort_range {
	int	*stack_begin_index;
	int	*stack_end_index;
	size_t	list_size;
	size_t	present_index_stack_begin;
	size_t	present_index_stack_end;
}	t_stack_sort_range;

t_stack_sort_range	*create_stack(int begin, int end);
void	clear_stack(t_stack_sort_range **stack);
void	add_data_index_stack(t_stack_sort_range *stack, int begin, int end);
bool	is_empty_stack(t_stack_sort_range *stack);
int		get_data_stack_begin_index(t_stack_sort_range *stack);
int		get_data_stack_end_index(t_stack_sort_range *stack);
#endif
