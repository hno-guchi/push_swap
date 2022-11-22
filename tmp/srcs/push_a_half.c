/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_half.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/16 16:01:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a,
			t_bidrect_circle_list *head_p_stack_b);
void	print_ranges_info(t_sort_range_index *ranges, char stack);
t_list	*try_push_a(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
bool	is_empty_stack_b(t_bidrect_circle_list *stack_b);

/*
t_operation	search_under_a_pivot(int pivot, t_bidrect_circle_list *stack)
{
	t_bidrect_circle_list	*head;
	t_bidrect_circle_list	*tail;

	head = stack->next;
	tail = stack->prev;
	while (head != tail)
	{
		if (head->index < pivot && pivot <= tail->index)
		{
			return (Rotate_a);
		}
		else if (tail->index < pivot && pivot <= head->index)
		{
			return (Reverse_rotate_a);
		}
		else if (head->index < pivot && tail->index < pivot)
		{
			if (head->index < tail->index)
			{
				return (Rotate_a);
			}
			else
			{
				return (Reverse_rotate_a);
			}
		}
		head = head->next;
		tail = tail->prev;
	}
	return (Not);
}

int	count_execute_operation(t_operation operation, int pivot, t_bidrect_circle_list *stack)
{
	int	count;
	t_bidrect_circle_list *node;

	count = 0;
	node = NULL;
	if (operation == Rotate_a)
	{
		node = stack->next;
		while (pivot <= node->index)
		{
			count += 1;
			node = node->next;
		}
	}
	else if (operation == Reverse_rotate_a)
	{
		count = 1;
		node = stack->prev;
		while (pivot <= node->index)
		{
			count += 1;
			node = node->prev;
		}
	}
	return (count);
}

t_list	*try_rotate_under_a_pivot(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_operation	flag;
	int			count;

	flag = search_under_a_pivot(ranges->a_pivot, stack_a);
	count = count_execute_operation(flag, ranges->a_pivot, stack_a);
	if (flag == Rotate_a)
	{
		while (count)
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			count -= 1;
		}
	}
	else if (flag == Reverse_rotate_a)
	{
		while (count)
		{
			head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			count -= 1;
		}
	}
	return (head_p_log);
}
*/
static t_list	*try_swap2(t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_operation	operation;
	t_operation	a;
	t_operation	b;

	operation = Not;
	a = Not;
	b = Not;
	if ((stack_a->next->index - stack_a->next->next->index) == 1)
	// if (stack_a->next->next->index < stack_a->next->index)
	{
		a = Swap_a;
	}
	if ((stack_b->next->index - stack_b->next->next->index) == -1)
	// if (stack_b->next->index < stack_b->next->next->index)
	{
		b = Swap_b;
	}
	if (a == Swap_a && b == Swap_b)
	{
		operation = Swap_s;
	}
	else if (a == Swap_a && b != Swap_b)
	{
		operation = a;
	}
	else if (a != Swap_a && b == Swap_b)
	{
		operation = b;
	}
	head_p_log = execute_operation(operation, stack_a, stack_b, head_p_log);
	return (head_p_log);
}

bool	is_exist_sort_index_until_n_th(int n, t_sort_range_index *ranges, t_bidrect_circle_list *stack)
{
	int	i;
	t_bidrect_circle_list *head;
	t_bidrect_circle_list *tail;

	i = 0;
	head = stack->next;
	tail = stack->prev;
	if (head == stack || tail == stack || head == tail)
	// if ((ranges->count_pushed - ranges->end) < 2)
	{
		return (false);
	}
	if ((ranges->count_pushed - ranges->end) < n)
	{
		n = ranges->count_pushed - ranges->end;
	}
	while (i < n && head != tail)
	{
		if (head->index == ranges->count_sorted || tail->index == ranges->count_sorted)
		{
			return (true);
		}
		i += 1;
		head = head->next;
		tail = tail->prev;
	}
	return (false);
}

static int	stack_len2(t_bidrect_circle_list *stack)
{
	int						len;
	t_bidrect_circle_list	*node;

	len = 0;
	node = stack->next;
	if (node == stack)
	{
		return (0);
	}
	while (node != stack)
	{
		len += 1;
		node = node->next;
	}
	return (len);
}

static t_list	*try_sort2(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int	stack_size;

	stack_size = stack_len2(stack_b);
	if (5 < stack_size)
	{
		if (stack_b->prev->prev->index == ranges->count_sorted)
		{
			// if (stack_a->prev->index == (ranges->count_sorted + 1))
			// {
			// 	head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
			// }
			// else
			// {
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			// }
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			ranges->count_sorted += 1;
		}
	}
	if (3 < stack_size)
	{
		if (stack_b->prev->prev->index == ranges->count_sorted)
		{
			// if (stack_a->prev->index == (ranges->count_sorted + 1))
			// {
			// 	head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
			// }
			// else
			// {
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			// }
	 		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			ranges->count_sorted += 1;
		}
	}
	if (2 < stack_size)
	{
		if (stack_b->prev->index == ranges->count_sorted)
		{
			// if (stack_a->prev->index == (ranges->count_sorted + 1))
			// {
			// 	head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
			// }
			// else
			// {
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			// }
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			ranges->count_sorted += 1;
		}
	}
	if (1 < stack_size)
	{
		if (stack_b->next->next->index == ranges->count_sorted)
		{
			if (stack_b->next->index == (ranges->count_sorted + 1))
			{
	 			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
				ranges->count_pushed += 1;
			}
			else
			{
				head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			}
			if (stack_a->prev->index == (ranges->count_sorted + 1))
			{
				head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			}
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			ranges->count_sorted += 1;
		}
	}
	if (0 < stack_size)
	{
		if (stack_b->next->index == ranges->count_sorted)
		{
			if (stack_a->prev->index == (ranges->count_sorted + 1))
			{
				head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			}
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			ranges->count_sorted += 1;
		}
	}
	if (stack_a->next->next->index == ranges->count_sorted)
	{
 		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		if (stack_a->prev->index == (ranges->count_sorted + 1))
		{
			head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
 			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		ranges->count_sorted += 1;
	}
	if (stack_a->next->index == ranges->count_sorted)
	{
		if (stack_a->prev->index == (ranges->count_sorted + 1))
		{
			head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
 			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		ranges->count_sorted += 1;
	}
	return (head_p_log);
}

static t_list	*try_prepare_sort2(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int	stack_size;

	stack_size = stack_len2(stack_b);
	if (5 < stack_size)
	{
		if (stack_b->prev->prev->index == (ranges->count_sorted + 1))
		{
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	/*
	if (3 < stack_size)
	{
		if (stack_b->prev->prev->index == (ranges->count_sorted + 1))
		{
	 		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			ranges->count_sorted += 1;
		}
	}
	*/
	if (2 < stack_size)
	{
		if (stack_b->prev->index == (ranges->count_sorted + 1))
		{
	 		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	if (1 < stack_size)
	{
		if (stack_b->next->next->index == (ranges->count_sorted + 1))
		{
			/*
			if (stack_b->next->index == (ranges->count_sorted + 1))
			{
	 			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
				ranges->count_pushed += 1;
			}
			else
			{
				head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			}
			*/
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	if (0 < stack_size)
	{
		if (stack_b->next->index == (ranges->count_sorted + 1))
		{
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	if (stack_a->next->next->index == (ranges->count_sorted + 1) && stack_a->next->index != ranges->count_sorted)
	{
 		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	if (stack_a->next->index == (ranges->count_sorted + 1))
	{
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}
/*
static t_list	*try(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_operation	operation;
	t_operation	a;
	t_operation	b;

	operation = Not;
	a = Not;
	b = Not;
	if (ranges->a_pivot <= stack_a->next->index)
	{
		a = Rotate_a;
	}
	if (1 < ranges->count_pushed && stack_b->next->index < ranges->b_pivot)
	{
		b = Rotate_b;
	}
	if (a == Rotate_a && b == Rotate_b)
	{
		operation = Rotate_r;
	}
	else if (a == Rotate_a && b != Rotate_b)
	{
		operation = a;
	}
	else if (a != Rotate_a && b == Rotate_b)
	{
		operation = b;
	}
	head_p_log = execute_operation(operation, stack_a, stack_b, head_p_log);
	return (head_p_log);
}
*/

t_list	*push_a_half(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int	cycle = 0;

	while (1)
	{
		if (is_finish(ranges->count_pushed, ranges->end) || is_empty_stack_b(stack_b))
		{
			break;
		}
		// print_ranges_info(ranges, 'b');
		// output_stack(stack_a, stack_b);
		head_p_log = try_prepare_sort2(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_sort2(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_swap2(stack_a, stack_b, head_p_log);
		if (!is_under_b_pivot(ranges->b_pivot, stack_b->next->index))
		{
		 	head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		 	ranges->count_pushed += 1;
		}
		else
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);
		cycle += 1;
		if (cycle == 1000)
		{
			exit(1);
			// return (head_p_log);
		}
	}
	return (head_p_log);
}

/*
t_list	*push_a_half(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int	cycle = 0;

	while (1)
	{
		// if ((ranges->count_pushed == ranges->end) || is_empty_stack_b(stack_b))
		if (is_finish(ranges->count_pushed, ranges->end) || is_empty_stack_b(stack_b))
		{
			break;
		}
		// print_ranges_info(ranges, 'b');
		// output_stack(stack_a, stack_b);
		if (3 < stack_len(stack_b) && !is_under_b_pivot(ranges->b_pivot, stack_b->prev->index))
		{
			head_p_log = try_reverse_rotate_b(ranges, stack_a, stack_b, head_p_log);
		}
		if (is_head_less_than_second(stack_b))
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
		head_p_log = try_swap(ranges, stack_a, stack_b, head_p_log);
		if (!is_under_b_pivot(ranges->b_pivot, stack_b->next->index) || !is_under_b_pivot(ranges->b_pivot, stack_b->prev->index))
		{
			head_p_log = try_reverse_rotate_b(ranges, stack_a, stack_b, head_p_log);
			head_p_log = try_push_a(ranges, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
		}
		else
		{
			if (is_sort(ranges->count_sorted, stack_a))
			{
				head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
				ranges->count_sorted += 1;
			}
			else
			{
				head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			}
		}
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);
		cycle += 1;
		if (cycle == 1000)
		{
			exit(1);
			// return (head_p_log);
		}
	}
	return (head_p_log);
}
*/
