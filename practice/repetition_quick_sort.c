#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_stack_sort_range {
	int	*stack_begin_index;
	int	*stack_end_index;
	size_t	list_size;
	size_t	present_index_stack_begin;
	size_t	present_index_stack_end;
}	t_stack_sort_range;

t_stack_sort_range	*create_stack(size_t size)
{
	t_stack_sort_range	*stack;

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

void	add_data_index_stack(t_stack_sort_range *stack, int begin, int end)
{
	if (stack->list_size <= stack->present_index_stack_begin
			|| stack->list_size <= stack->present_index_stack_end)
	{
		return ;
	}
	stack->stack_begin_index[stack->present_index_stack_begin] = begin;
	stack->stack_end_index[stack->present_index_stack_end] = end;
	stack->present_index_stack_begin += 1;
	stack->present_index_stack_end += 1;
}

bool	is_empty_stack(t_stack_sort_range *stack)
{
	if (stack->present_index_stack_begin <= 0
			&& stack->present_index_stack_end <= 0)
	{
		return (true);
	}
	return (false);
}

int	get_data_stack_begin_index(t_stack_sort_range *stack)
{
	if (is_empty_stack(stack))
	{
		return (-1);
	}
	stack->present_index_stack_begin -= 1;
	return (stack->stack_begin_index[stack->present_index_stack_begin]);
}

int	get_data_stack_end_index(t_stack_sort_range *stack)
{
	if (is_empty_stack(stack))
	{
		return (-1);
	}
	stack->present_index_stack_end -= 1;
	return (stack->stack_end_index[stack->present_index_stack_end]);
}

size_t	calculate_stack_size(int begin, int end)
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	execute_sort(int list[], int *move_to_right, int *move_to_left)
{
	int	pivot;

	pivot = list[(*move_to_right + *move_to_left) / 2];
	while (1)
	{
		while (list[*move_to_right] < pivot)
		{
			*move_to_right += 1;
		}
		while (pivot < list[*move_to_left])
		{
			*move_to_left -= 1;
		}
		if (*move_to_left <= *move_to_right)
		{
			return ;
		}
		swap(&list[*move_to_right], &list[*move_to_left]);
		*move_to_right += 1;
		*move_to_left -= 1;
	}
}

void	execute_sort_until_one_range_ends(int list[], int begin_idx, int end_idx, t_stack_sort_range *stack)
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
		execute_sort(list, &move_to_right, &move_to_left);
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

void	quick_sort(int list[], int begin, int end)
{
	t_stack_sort_range	*stack;
	size_t				stack_size;
	int					begin_idx;
	int					end_idx;

	stack_size = calculate_stack_size(begin, end);
	stack = create_stack(stack_size);
	if (!stack)
	{
		return ;
	}
	add_data_index_stack(stack, begin, end);
	while (!is_empty_stack(stack))
	{
		begin_idx = get_data_stack_begin_index(stack);
		end_idx = get_data_stack_end_index(stack);
		execute_sort_until_one_range_ends(list, begin_idx, end_idx, stack);
	}
	clear_stack(&stack);
}

int	main(void)
{
	static int num_array[] = {41, 24, 76, 11, 45, 64, 24, 69, 19, 11};

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
