/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/28 14:28:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	is_duplication_num(int *num_ary, int ary_len)
{
	int	i;

	i = 0;
	while (i < (ary_len - 1))
	{
		if (num_ary[i] == num_ary[i + 1])
		{
			return (true);
		}
		i += 1;
	}
	return (false);
}

void	validation_args(int argc, char **argv)
{
	int	i;
	int	*num_array;

	i = 1;
	while (i < argc)
	{
		if (!is_atoi(argv[i]))
		{
			exit_write_message(Not_int);
		}
		i += 1;
	}
	num_array = create_array_atoi(argc - 1, &argv[1]);
	if (!num_array)
	{
		exit_write_message(Malloc_error);
	}
	quick_sort(num_array, argc - 1);
	if (is_duplication_num(num_array, (argc - 1)))
	{
		free(num_array);
		exit_write_message(Duplicate);
	}
	free(num_array);
}

/*
	check_quick_sort(num_array, argc - 1);
#include <stdio.h>
void	check_quick_sort(int *array, int size)
{
	printf("[BEFORE] :");
	for(int i = 0; i < size; i++) {
		printf(" [%d] ", array[i]);
		if (i != (size - 1))
		{
			printf("->");
		}
	}
	printf("\n");

	quick_sort(array, 0, size - 1);
	
	printf("[AFTER]  :");
	for(int i = 0; i < size; i++) {
		printf(" [%d] ", array[i]);
		if (i != (size - 1))
		{
			printf("->");
		}
	}
	printf("\n");
}
int	main(int argc, char **argv)
{
	validation_args(argc, argv);
	printf(GREEN"[OK]"END); printf(" : validation_args();\n");
	system("leaks -q push_swap");
	return (0);
}
*/
