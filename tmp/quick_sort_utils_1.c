/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:42 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/27 18:59:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quick_sort.h"

static size_t	calculate_stack_size(int begin, int end)
{
	int	exponents;
	int	power;

	exponents = 1;
	power = 2;
	while (power < (end - begin + 2))
	{
		power = 2 * power;
		exponents += 1;
	}
	return (exponents);
}

t_stack_sort_range	*create_stack(int begin, int end)
{
	size_t				size;
	t_stack_sort_range	*stack;

	size = calculate_stack_size(begin, end);
	stack = (t_stack_sort_range *)malloc(sizeof(t_stack_sort_range));
	if (!stack)
	{
		return (NULL);
	}
	stack->stack_begin_index = (int *)malloc(sizeof(int) * size);
	stack->stack_end_index = (int *)malloc(sizeof(int) * size);
	if (!stack->stack_begin_index || !stack->stack_end_index)
	{
		free(stack);
		return (NULL);
	}
	stack->list_size = size;
	stack->present_index_stack_begin = 0;
	stack->present_index_stack_end = 0;
	return (stack);
}

void	clear_stack(t_stack_sort_range **stack)
{
	free(stack[0]->stack_begin_index);
	free(stack[0]->stack_end_index);
	free(stack[0]);
}
