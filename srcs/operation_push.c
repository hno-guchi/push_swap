/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/25 19:58:26 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_bidrect_circle_list *from_stack
		, t_bidrect_circle_list *to_stack)
{
	t_bidrect_circle_list	*from_stack_node;
	t_bidrect_circle_list	*from_stack_next_node;

	if (from_stack->next == from_stack)
	{
		return (false);
	}
	from_stack_node = from_stack->next;
	from_stack_next_node = from_stack->next->next;
	connect_node(to_stack, from_stack_node);
	from_stack_next_node->prev = from_stack;
	from_stack->next = from_stack_next_node;
	return (true);
}

char	*push_a(t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (!stack_a || !stack_b)
	{
		return (NULL);
	}
	if (!push(stack_b, stack_a))
	{
		return (NULL);
	}
	return ("pa");
}

char	*push_b(t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (!stack_a || !stack_b)
	{
		return (NULL);
	}
	if (!push(stack_a, stack_b))
	{
		return (NULL);
	}
	return ("pb");
}

/*
int	main(int argc, char **argv)
{
	t_bidrect_circle_list	*head_p_stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*stack_b;

	t_list					*log_node;
	t_list					*log_list;
	t_list					*log_head_p;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_stack_b = create_sentinel();
	stack_a = head_p_stack_a;
	stack_b = head_p_stack_b;
	log_list = NULL;

	log_node = ft_lstnew(swap_a(stack_a));
	log_head_p = log_node;
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(swap_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(swap_s(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a | stack_b\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
		{
			printf("         | [%d]\n", stack_b->num);
		}
		else if (stack_b == head_p_stack_b)
		{
			printf(" [%d]     |\n", stack_a->num);
		}
		else
		{
			printf(" [%d]     | [%d]\n", stack_a->num, stack_b->num);
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
	printf("------------------\n");
	printf(" [%d]     | [%d]\n", stack_a->num, stack_b->num);
	
	stack_clear(&head_p_stack_a);
	stack_clear(&head_p_stack_b);
	while (log_list)
	{
		// if (log_list->content)
		//{
			ft_printf("[%s]\n", (char *)log_list->content);
		//}
		log_list = log_list->next;
	}
	ft_lstclear(&log_head_p, NULL);
	system("leaks -q push_swap");
	return (0);
}
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
*/
