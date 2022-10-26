/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 16:05:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_list	*execute_reverse_rotate(t_operation type, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (type == Reverse_rotate_a)
	{
		return (ft_lstnew(reverse_rotate_a(stack_a)));
	}
	else if (type == Reverse_rotate_b)
	{
		return (ft_lstnew(reverse_rotate_b(stack_b)));
	}
	else if (type == Reverse_rotate_r)
	{
		return (ft_lstnew(reverse_rotate_r(stack_a, stack_b)));
	}
	return (NULL);
}

static t_list	*execute_rotate(t_operation type, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (type == Rotate_a)
	{
		return (ft_lstnew(rotate_a(stack_a)));
	}
	else if (type == Rotate_b)
	{
		return (ft_lstnew(rotate_b(stack_b)));
	}
	else if (type == Rotate_r)
	{
		return (ft_lstnew(rotate_r(stack_a, stack_b)));
	}
	return (NULL);
}

static t_list	*execute_push(t_operation type, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (type == Push_a)
	{
		return (ft_lstnew(push_a(stack_a, stack_b)));
	}
	else if (type == Push_b)
	{
		return (ft_lstnew(push_b(stack_a, stack_b)));
	}
	return (NULL);
}

static t_list	*execute_swap(t_operation type, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (type == Swap_a)
	{
		return (ft_lstnew(swap_a(stack_a)));
	}
	else if (type == Swap_b)
	{
		return (ft_lstnew(swap_b(stack_b)));
	}
	else if (type == Swap_s)
	{
		return (ft_lstnew(swap_s(stack_a, stack_b)));
	}
	return (NULL);
}

t_list	*execute_operation(t_operation type, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b)
{
	if (type == Swap_a || type == Swap_b || type == Swap_s)
	{
		return (execute_swap(type, stack_a, stack_b));
	}
	else if (type == Push_a || type == Push_b)
	{
		return (execute_push(type, stack_a, stack_b));
	}
	else if (type == Rotate_a || type == Rotate_b || type == Rotate_r)
	{
		return (execute_rotate(type, stack_a, stack_b));
	}
	else if (type == Reverse_rotate_a || type == Reverse_rotate_b || type == Reverse_rotate_r)
	{
		return (execute_reverse_rotate(type, stack_a, stack_b));
	}
	return (NULL);
}

/*
int	main(int argc, char **argv)
{
	t_bidrect_circle_list	*head_p_stack_a;
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;
	t_list					*head_p_log;
	t_list					*node_log;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_stack_b = create_sentinel();
	stack_a = head_p_stack_a;
	stack_b = head_p_stack_b;
	head_p_log = NULL;
	
	node_log = execute_operation(Swap_a, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Push_b, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Push_b, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Swap_b, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Swap_s, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Rotate_a, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Rotate_b, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Rotate_r, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Reverse_rotate_a, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Reverse_rotate_b, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Reverse_rotate_r, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);
	node_log = execute_operation(Push_a, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, node_log);

	putstr_log(head_p_log);
	stack_clear(&head_p_stack_a);
	stack_clear(&head_p_stack_b);
	ft_lstclear(&head_p_log, NULL);
	system("leaks -q push_swap");
	return (0);
}
*/
