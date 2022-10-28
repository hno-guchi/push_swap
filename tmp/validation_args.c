/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/19 17:58:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	free_exit(int **ary, error_num num)
{
	free(ary[0]);
	exit_write_message(num);
}

static bool	is_duplication_value(int *num_ary, int ary_len)
{
	int	i;
	int	target_num;

	i = 0;
	target_num = num_ary[ary_len];
	while (i < ary_len)
	{
		if (num_ary[i] == target_num)
		{
			return (false);
		}
		i += 1;
	}
	return (true);
}

static void	check_exist_args(int argc)
{
	if (argc == 1)
	{
		exit (1);
	}
}

void	validation_args(int argc, char **argv)
{
	int	i;
	int	*num_ary;

	check_exist_args(argc);
	i = 1;
	num_ary = (int *)malloc(sizeof(int) * (argc - 1));
	if (!num_ary)
	{
		exit_write_message(Malloc_error);
	}
	while (i < argc)
	{
		if (!is_atoi(argv[i]))
		{
			free_exit(&num_ary, Not_int);
		}
		num_ary[i - 1] = ft_atoi(argv[i]);
		if (!is_duplication_value(num_ary, i - 1))
		{
			free_exit(&num_ary, Duplicate);
		}
		i += 1;
	}
	free(num_ary);
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
