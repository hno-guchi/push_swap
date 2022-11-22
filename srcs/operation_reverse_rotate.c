/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/22 11:39:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	reverse_rotate(t_dcl_list *head_p)
{
	t_dcl_list	*last_node;
	t_dcl_list	*last_prev_node;

	if (head_p == head_p->next || head_p == head_p->next->next)
	{
		return (false);
	}
	last_node = head_p->prev;
	last_prev_node = head_p->prev->prev;
	connect_node(head_p, last_node);
	last_prev_node->next = head_p;
	head_p->prev = last_prev_node;
	return (true);
}

char	*reverse_rotate_a(t_dcl_list *stack_a)
{
	if (!stack_a)
	{
		return (NULL);
	}
	if (!reverse_rotate(stack_a))
	{
		return (NULL);
	}
	return ("rra");
}

char	*reverse_rotate_b(t_dcl_list *stack_b)
{
	if (!stack_b)
	{
		return (NULL);
	}
	if (!reverse_rotate(stack_b))
	{
		return (NULL);
	}
	return ("rrb");
}

char	*reverse_rotate_r(t_dcl_list *stack_a,
		t_dcl_list *stack_b)
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
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return ("rrr");
}

/*
void	test_operation_reverse_rotate(t_dcl_list *head_p_stack_a)
{
	t_dcl_list	*stack_a;
	t_dcl_list	*head_p_stack_b;
	t_dcl_list	*stack_b;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;

	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(RED_BACK"\n[TEST] reverse_rotate();"END_BACK);

	printf(GREEN_BACK"\nreverse_rotate_a(); return = [%s]"END_BACK
	, reverse_rotate_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);
	
	printf(GREEN_BACK"\nreverse_rotate_b(); return = [%s]"END_BACK
	, reverse_rotate_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_r(); return = [%s]"END_BACK
	, reverse_rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_b(); return = [%s]"END_BACK
	, reverse_rotate_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_r(); return = [%s]"END_BACK
	, reverse_rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_b(); return = [%s]"END_BACK
	, reverse_rotate_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_r(); return = [%s]"END_BACK
	, reverse_rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_a(); return = [%s]"END_BACK
	, reverse_rotate_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_r(); return = [%s]"END_BACK
	, reverse_rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_a(); return = [%s]"END_BACK
	, reverse_rotate_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nreverse_rotate_r(); return = [%s]"END_BACK
			, reverse_rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	stack_clear(&head_p_stack_a);
	stack_clear(&head_p_stack_b);
}

int	main(int argc, char **argv)
{
	t_dcl_list	*head_p_stack_a;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	test_operation_reverse_rotate(head_p_stack_a);
	system("leaks -q push_swap");
	return (0);
}
*/
