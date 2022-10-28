/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:42 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/28 10:16:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quick_sort.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	execute_sort(int *array, int *move_to_right, int *move_to_left)
{
	int	pivot;

	pivot = array[(*move_to_right + *move_to_left) / 2];
	while (1)
	{
		while (array[*move_to_right] < pivot)
		{
			*move_to_right += 1;
		}
		while (pivot < array[*move_to_left])
		{
			*move_to_left -= 1;
		}
		if (*move_to_left <= *move_to_right)
		{
			return ;
		}
		swap(&array[*move_to_right], &array[*move_to_left]);
		*move_to_right += 1;
		*move_to_left -= 1;
	}
}

static void	execute_sort_until_one_range_ends(int *array
		, int begin_idx, int end_idx, t_stack_sort_range *stack)
{
	int	move_to_right;
	int	move_to_left;

	move_to_right = 0;
	move_to_left = 0;
	while (1)
	{
		if (end_idx <= begin_idx)
		{
			return ;
		}
		move_to_right = begin_idx;
		move_to_left = end_idx;
		execute_sort(array, &move_to_right, &move_to_left);
		if ((move_to_right - begin_idx) < (end_idx - move_to_left))
		{
			add_data_index_stack(stack, move_to_left + 1, end_idx);
			end_idx = move_to_right - 1;
		}
		else
		{
			add_data_index_stack(stack, begin_idx, move_to_right - 1);
			begin_idx = move_to_left + 1;
		}
	}
}

void	quick_sort(int *array, int begin, int end)
{
	t_stack_sort_range	*stack;
	int					begin_idx;
	int					end_idx;

	stack = create_stack(begin, end);
	if (!stack)
	{
		free(array);
		exit_write_message(Duplicate);
	}
	add_data_index_stack(stack, begin, end);
	while (!is_empty_stack(stack))
	{
		begin_idx = get_data_stack_begin_index(stack);
		end_idx = get_data_stack_end_index(stack);
		if (begin_idx == -1 || end_idx == -1)
		{
			free(array);
			clear_stack(&stack);
			exit_write_message(Failed_sort);
		}
		execute_sort_until_one_range_ends(array, begin_idx, end_idx, stack);
	}
	clear_stack(&stack);
}

/*
void	quick_sort(int array[], int begin, int end)
int	main(void)
{
	static int num_array[] = {41, 24, 76, 11, 45, 64, 24, 69, 19, 36};

	printf("[BEFORE] :");
	for(int i = 0; i < 10; i++) {
		printf(" [%d] ", num_array[i]);
		if (i != 9)
		{
			printf("->");
		}
	}
	printf("\n");

	quick_sort(num_array, 0, 9);

	printf("[AFTER]  :");
	for(int i = 0; i < 10; i++) {
		printf(" [%d] ", num_array[i]);
		if (i != 9)
		{
			printf("->");
		}
	}
	printf("\n");
	// system("leaks -q a.out");
	return (0);
}
*/
