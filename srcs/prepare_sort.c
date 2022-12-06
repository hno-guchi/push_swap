/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:59:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_index_stack_member(t_dcl_list *node, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (node->num == array[i])
		{
			node->index = i;
			break ;
		}
		i += 1;
	}
}

static void	compress(t_dcl_list *head_p, int *array, int array_size)
{
	t_dcl_list	*stack_node;

	stack_node = head_p->next;
	while (stack_node != head_p)
	{
		add_index_stack_member(stack_node, array, array_size);
		stack_node = stack_node->next;
	}
}

t_dcl_list	*prepare_sort(int size, char **elements, t_dcl_list *head_p)
{
	int	*temp_array;

	temp_array = create_array_atoi(size, elements);
	if (!temp_array)
	{
		stack_clear(&head_p);
		exit_write_message(Malloc_error);
	}
	quick_sort(temp_array, size);
	compress(head_p, temp_array, size);
	free(temp_array);
	return (head_p);
}

/*
output_stack_num_index(head_p, temp_array, size);
#include <stdio.h>
void	output_stack_num_index(t_dcl_list *head_p, int *array, int size)
{
	int						i;
	t_dcl_list	*node;
	
	i = 0;
	node = head_p->next;
	printf("\nnum   : ");
	while (node != head_p)
	{
		printf(" [%5d]", node->num);
		if (node->next != head_p)
		{
			printf(" ->");
		}
		node = node->next;

	}
	node = head_p->next;
	printf("\nindex : ");
	while (node != head_p)
	{
		printf(" [%5d]", node->index);
		if (node->next != head_p)
		{
			printf(" ->");
		}
		node = node->next;

	}
	printf("\nsort  : ");
	while (i < size)
	{
		printf(" [%5d]", array[i]);
		if (i != (size - 1))
		{
			printf(" ->");
		}
		i += 1;
	}

	printf("\n------------------\n");
	// printf(" [%d]     | [%d]\n", stack_a->num, stack_b->num);
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
	head_p_stack_a = prepare_sort(argc - 1, &argv[1], head_p_stack_a);
	stack_clear(&head_p_stack_a);
	system("leaks -q push_swap");
	return (0);
}
*/
