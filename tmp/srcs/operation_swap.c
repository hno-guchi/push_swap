/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 17:41:39 by hnoguchi         ###   ########.fr       */
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
void	test_operation_swap(t_bidrect_circle_list *head_p_stack_a)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;

	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(RED_BACK"\n[TEST] swap();"END_BACK);

	printf(GREEN_BACK"\nswap_a(); return = [%s]"END_BACK, swap_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);
	
	printf(GREEN_BACK"\nswap_b(); return = [%s]"END_BACK, swap_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_s(); return = [%s]"END_BACK, swap_s(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_b(); return = [%s]"END_BACK, swap_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_s(); return = [%s]"END_BACK, swap_s(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_b(); return = [%s]"END_BACK, swap_b(stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_s(); return = [%s]"END_BACK, swap_s(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_a(); return = [%s]"END_BACK, swap_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_s(); return = [%s]"END_BACK, swap_s(stack_a, stack_b));
	printf("\n"); output_stack(stack_a, stack_b);

	(void)push_b(stack_a, stack_b);
	printf(RED_BACK"\n[BEFORE]"END_BACK); printf("\n");
	output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_a(); return = [%s]"END_BACK, swap_a(stack_a));
	printf("\n"); output_stack(stack_a, stack_b);

	printf(GREEN_BACK"\nswap_s(); return = [%s]"END_BACK, swap_s(stack_a, stack_b));
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
	test_operation_swap(head_p_stack_a);
	system("leaks -q push_swap");
	return (0);
}
*/
