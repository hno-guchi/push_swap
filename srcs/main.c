/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/20 16:14:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*stack_a;

	i = 0;
	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	stack_a = create_stack_a(argc, argv);
	while (stack_a->role != SENTINEL)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	stack_a = stack_a->next;
	// execute_push_swap();
	stack_clear(&stack_a);
	system("leaks -q push_swap");
	return (0);
}
/*
	i = 0;
*/
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
// validation_args(int argc, char **argv);
// create_stack_a
	// validation
	// atoi
	// add_back
	// search_max
