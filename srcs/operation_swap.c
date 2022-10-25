/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/25 19:59:36 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_bidrect_circle_list *head_p)
{
	t_bidrect_circle_list	*first_node;
	t_bidrect_circle_list	*second_node;

	if (head_p == head_p->next || head_p == head_p->next->next)
	{
		return (false);
	}
	first_node = head_p->next;
	second_node = head_p->next->next;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = head_p;
	head_p->next = second_node;
	return (true);
}

char	*swap_a(t_bidrect_circle_list *stack_a)
{
	if (!stack_a)
	{
		return (NULL);
	}
	if (!swap(stack_a))
	{
		return (NULL);
	}
	return ("sa");
}

char	*swap_b(t_bidrect_circle_list *stack_b)
{
	if (!stack_b)
	{
		return (NULL);
	}
	if (!swap(stack_b))
	{
		return (NULL);
	}
	return ("sb");
}

char	*swap_s(t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (!stack_a || !stack_b)
	{
		return (NULL);
	}
	if (stack_a == stack_a->next || stack_a == stack_a->next->next)
	{
		return (NULL);
	}
	if (stack_b == stack_b->next || stack_b == stack_b->next->next)
	{
		return (NULL);
	}
	swap(stack_a);
	swap(stack_b);
	return ("ss");
}

/*
int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p_stack_a;
	t_bidrect_circle_list	*stack_a;

	t_list					*log_node;
	t_list					*log_list;
	t_list					*log_head_p;

	i = 0;
	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	stack_a = head_p_stack_a;

	log_list = NULL;
	log_node = ft_lstnew(swap_a(stack_a));
	log_head_p = log_node;
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew(swap_b(stack_a));
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew(swap_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	stack_a = head_p_stack_a->next;
	while (stack_a != head_p_stack_a)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	while (log_list)
	{
		ft_printf("[%s]\n", (char *)log_list->content);
		log_list = log_list->next;
	}
	ft_lstclear(&log_head_p, NULL);
	stack_clear(&head_p_stack_a);
	system("leaks -q push_swap");
	return (0);
}
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
*/
