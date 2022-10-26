/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 17:48:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate(t_bidrect_circle_list *head_p)
{
	t_bidrect_circle_list	*first_node;
	t_bidrect_circle_list	*second_node;

	if (head_p == head_p->next || head_p == head_p->next->next)
	{
		return (false);
	}
	first_node = head_p->next;
	second_node = head_p->next->next;
	head_p->prev->next = first_node;
	first_node->prev = head_p->prev;
	first_node->next = head_p;
	head_p->prev = first_node;
	second_node->prev = head_p;
	head_p->next = second_node;
	return (true);
}

char	*rotate_a(t_bidrect_circle_list *stack_a)
{
	if (!stack_a)
	{
		return (NULL);
	}
	if (!rotate(stack_a))
	{
		return (NULL);
	}
	return ("ra");
}

char	*rotate_b(t_bidrect_circle_list *stack_b)
{
	if (!stack_b)
	{
		return (NULL);
	}
	if (!rotate(stack_b))
	{
		return (NULL);
	}
	return ("rb");
}

char	*rotate_r(t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b)
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
	rotate(stack_a);
	rotate(stack_b);
	return ("rr");
}

/*
void	test_operation_rotate(t_bidrect_circle_list *head_p_stack_a)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;

	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(RED_BACK"\n[TEST] rotate();"END_BACK);

	printf(GREEN_BACK"\nrotate_a(); return = [%s]"END_BACK, rotate_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);
	
	printf(GREEN_BACK"\nrotate_b(); return = [%s]"END_BACK, rotate_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_r(); return = [%s]"END_BACK, rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_b(); return = [%s]"END_BACK, rotate_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_r(); return = [%s]"END_BACK, rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_b(); return = [%s]"END_BACK, rotate_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_r(); return = [%s]"END_BACK, rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_a(); return = [%s]"END_BACK, rotate_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_r(); return = [%s]"END_BACK, rotate_r(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_a(); return = [%s]"END_BACK, rotate_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nrotate_r(); return = [%s]"END_BACK, rotate_r(stack_a, stack_b));
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
	test_operation_rotate(head_p_stack_a);
	system("leaks -q push_swap");
	return (0);
}
*/
