/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 17:40:45 by hnoguchi         ###   ########.fr       */
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
void	test_operation_push(t_bidrect_circle_list *head_p_stack_a)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;

	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(RED_BACK"\n[TEST] push();"END_BACK);

	printf(GREEN_BACK"\npush_a(); return = [%s]"END_BACK, push_a(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);
	
	printf(GREEN_BACK"\npush_b(); return = [%s]"END_BACK, push_b(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_b(); return = [%s]"END_BACK, push_b(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_b(); return = [%s]"END_BACK, push_b(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_b(); return = [%s]"END_BACK, push_b(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_b(); return = [%s]"END_BACK, push_b(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_a(); return = [%s]"END_BACK, push_a(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_a(); return = [%s]"END_BACK, push_a(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_a(); return = [%s]"END_BACK, push_a(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);
	
	printf(GREEN_BACK"\npush_a(); return = [%s]"END_BACK, push_a(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\npush_a(); return = [%s]"END_BACK, push_a(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	stack_clear(&head_p_stack_a);
	stack_clear(&head_p_stack_b);
}

int	main(int argc, char **argv)
{
	t_bidrect_circle_list	*head_p_stack_a;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	test_operation_push(head_p_stack_a);
	system("leaks -q push_swap");
	return (0);
}
*/
