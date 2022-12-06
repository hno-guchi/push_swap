/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 09:33:09 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

t_list	*push_swap_under_7(int n, t_dcl_list *stack_a, t_dcl_list *stack_b
		, t_list *log)
{
	if (n < 4)
	{
		log = sort_n_under_4(n, stack_a, stack_b, log);
	}
	else
	{
		log = sort_n_under_7(n, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*push_swap_over_6(int n, t_dcl_list *stack_a, t_dcl_list *stack_b
		, t_list *log)
{
	t_sort_info	info;

	initialize_sort_info_first_half(&info, n);
	log = split_first_half(&info, stack_a, stack_b, log);
	while (info.sorted != info.size)
	{
		if (info.a_pivot <= info.sorted)
		{
			initialize_sort_info_second_half(&info);
			log = split_second_half(&info, stack_a, stack_b, log);
			info.a_pivot = info.size;
		}
		while (info.sorted < info.a_pivot)
		{
			log = push_swap_stack_b(&info, stack_a, stack_b, log);
			log = try_sort_until_possible(&info, stack_a, stack_b, log);
			if (is_complete_sort_section(&info, stack_a))
			{
				set_sort_info_next_section(&info, stack_a);
			}
			log = push_swap_stack_a(&info, stack_a, stack_b, log);
		}
	}
	return (log);
}

t_list	*push_swap(int stack_size, t_dcl_list *stack_a, t_list *log)
{
	t_dcl_list	*stack_b;

	stack_b = create_sentinel();
	if (is_ascending_sorted(stack_a) || stack_size == 1)
	{
		stack_clear(&stack_b);
		return (NULL);
	}
	if (stack_size < 7)
	{
		log = push_swap_under_7(stack_size, stack_a, stack_b, log);
	}
	else
	{
		log = push_swap_over_6(stack_size, stack_a, stack_b, log);
	}
	stack_clear(&stack_b);
	return (log);
}

int	main(int argc, char **argv)
{
	t_dcl_list	*head_p_stack_a;
	t_list		*head_p_log;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_log = NULL;
	head_p_stack_a = prepare_sort(argc - 1, &argv[1], head_p_stack_a);
	head_p_log = push_swap(argc - 1, head_p_stack_a, head_p_log);
	putstr_log(head_p_log);
	stack_clear(&head_p_stack_a);
	ft_lstclear(&head_p_log, NULL);
	// system("leaks -q push_swap");
	return (0);
}
