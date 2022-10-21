/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/20 16:09:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	validation_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_atoi(argv[i]))
		{
			exit_write_message(Not_int);
		}
		i += 1;
	}
}

/*
int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	
	validation_args(argc, argv);
	stack_a = create_stack_a(argc, argv);
	i = 0;
	while (stack_a->next)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	stack_clear(&stack_a);
	// execute_push_swap
	//
	system("leaks -q push_swap");
	return (0);
}
*/
