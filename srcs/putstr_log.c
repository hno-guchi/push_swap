/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/21 16:56:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	putstr_reverse_rotate(operation_num log)
{
	if (log == Reverse_rotate_a)
	{
		ft_putstr_fd("rra\n", 1);
	}
	else if (log == Reverse_rotate_b)
	{
		ft_putstr_fd("rrb\n", 1);
	}
	else if (log == Reverse_rotate_r)
	{
		ft_putstr_fd("rrr\n", 1);
	}
}

static void	putstr_rotate(operation_num log)
{
	if (log == Rotate_a)
	{
		ft_putstr_fd("ra\n", 1);
	}
	else if (log == Rotate_b)
	{
		ft_putstr_fd("rb\n", 1);
	}
	else if (log == Rotate_r)
	{
		ft_putstr_fd("rr\n", 1);
	}
}

static void	putstr_push(operation_num log)
{
	if (log == Push_a)
	{
		ft_putstr_fd("pa\n", 1);
	}
	else if (log == Push_b)
	{
		ft_putstr_fd("pb\n", 1);
	}
}

static void	putstr_swap(operation_num log)
{
	if (log == Swap_a)
	{
		ft_putstr_fd("sa\n", 1);
	}
	else if (log == Swap_b)
	{
		ft_putstr_fd("sb\n", 1);
	}
	else if (log == Swap_s)
	{
		ft_putstr_fd("ss\n", 1);
	}
}

void	putstr_log(t_operation_log_list *list)
{
	while (list != NULL)
	{
		if (list->log == Swap_a || list->log == Swap_b || list->log == Swap_s)
		{
			putstr_swap(list->log);
		}
		else if (list->log == Push_a || list->log == Push_b)
		{
			putstr_push(list->log);
		}
		else if (list->log == Rotate_a || list->log == Rotate_b
			|| list->log == Rotate_r)
		{
			putstr_rotate(list->log);
		}
		else if (list->log == Reverse_rotate_a || list->log == Reverse_rotate_b
			|| list->log == Reverse_rotate_r)
		{
			putstr_reverse_rotate(list->log);
		}
		list = list->next;
	}
}

/*
int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p;
	t_bidrect_circle_list	*stack_a;
	t_operation_log_list	*log;

	i = 0;
	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	log = NULL;
	head_p = create_stack_a(argc, argv);
	add_back_list_log_node(&log, create_log_node(push(head_p, Push_a)));
	stack_a = head_p->next;
	while (stack_a != head_p)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	putstr_log(log);
	log_list_clear(&log);
	stack_clear(&head_p);
	system("leaks -q push_swap");
	return (0);
}
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
*/
