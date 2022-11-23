/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/23 20:45:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a,
			t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);

t_list	*push_swap_over_6(int n, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_sort_info	info;

	initialize_sort_info(&info, n);
	log = split_first_half(&info, stack_a, stack_b, log);
	// while(info->sorted != info->size)
	// {
		// log = push_swap_stack_b(&info, stack_a, stack_b, log);
		// log = push_swap_stack_a(&info, stack_a, stack_b, log);
	// }
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
	output_stack(stack_a, stack_b);
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
	system("leaks -q push_swap");
	return (0);
}

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b)
{
	// int	size_a;
	// int	i;
	// int	size_b;
	t_dcl_list	*stack_a;
	t_dcl_list	*stack_b;

	// size_a = stack_len(stack_a);
	// size_b = stack_len(stack_b);
	// i = 0;
	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a    |  stack_b\n");
	printf("------------------------------------------------------");
	printf("------------------------------------------------------\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
		{
			printf("         |   [%3d]\n", stack_b->index);
		}
		else if (stack_b == head_p_stack_b)
		{
			printf(" [%3d]   |\n", stack_a->index);
		}
		else
		{
			printf(" [%3d]   |   [%3d]\n", stack_a->index, stack_b->index);
		}
		if (stack_a != head_p_stack_a)
		{
			stack_a = stack_a->next;
		}
		if (stack_b != head_p_stack_b)
		{
			stack_b = stack_b->next;
		}
	}
	printf("------------------------------------------------------");
	printf("------------------------------------------------------\n");
}

void	print_sort_info(t_sort_info *info, char stack)
{
	// int	i = 0;

	// printf("Cycle [%d] : stack [%c] info\n", info->cycle, stack);
	printf("stack [%c] info\n", stack);
	printf("-----------------------------------\n");
	printf("info->size          : [%d]\n", info->size);
	printf("info->sorted        : [%d]\n", info->sorted);
	printf("info->pushed       : [%d]\n", info->pushed);
	// printf("info->position_ary  : [%d]\n", info->position_ary);
	// printf("info->begin_idxes[] : ");
	// while (i < info->position_ary)
	// {
	// 	printf("[%d]", info->begin_idxes[i]);
	// 	i += 1;
	// 	if (i < info->position_ary)
	// 	{
	// 		printf("-> ");
	// 	}
	// }
	// printf("\n");
	// printf("info->end_idxes[]   : ");
	// i = 0;
	// while (i < info->position_ary)
	// {
	// 	printf("[%d]", info->end_idxes[i]);
	// 	i += 1;
	// 	if (i < info->position_ary)
	// 	{
	// 		printf("-> ");
	// 	}
	// }
	// printf("\n");
	printf("info->a_pivot      : [%d]\n", info->a_pivot);
	printf("info->a_size       : [%d]\n", info->a_size);
	printf("info->b_pivot      : [%d]\n", info->b_pivot);
	printf("info->b_size       : [%d]\n", info->b_size);
	printf("info->median       : [%d]\n", info->median);
	printf("-----------------------------------\n");
}

