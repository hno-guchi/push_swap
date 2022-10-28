/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:37:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/28 11:17:45 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	select_pivot(int *array, int begin, int end)
{
	int	pivot;

	pivot = array[(begin + end) / 2];
	return (pivot);
}

void	swap_the_range(int *array, int *to_right, int *to_left)
{
	int	pivot;

	pivot = select_pivot(array, *to_right, *to_left);
	while (1)
	{
		while (array[*to_right] < pivot)
		{
			*to_right += 1;
		}
		while (pivot < array[*to_left])
		{
			*to_left -= 1;
		}
		if (*to_left <= *to_right)
		{
			break ;
		}
		swap(&array[*to_right], &array[*to_left]);
		*to_right += 1;
		*to_left -= 1;
	}
}

void	recursive_quick_sort(int *array, int begin, int end)
{
	int	move_to_right;
	int	move_to_left;

	move_to_right = begin;
	move_to_left = end;
	swap_the_range(array, &move_to_right, &move_to_left);
	if (2 <= (move_to_right - begin))
	{
		recursive_quick_sort(array, begin, move_to_right - 1);
	}
	if (2 <= (end - move_to_left))
	{
		recursive_quick_sort(array, move_to_left + 1, end);
	}
}

void	quick_sort(int *array, int size)
{
	recursive_quick_sort(array, 0, (size - 1));
}

/*
#include <stdio.h>
int	main(void)
{
	static int num_array[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 11};

	printf("[BEFORE] :");
	for(int i = 0; i < 10; i++) {
		printf(" [%d] ", num_array[i]);
		if (i != 9)
		{
			printf("->");
		}
	}
	printf("\n");

	quick_sort(num_array, 10);

	printf("[AFTER]  :");
	for(int i = 0; i < 10; i++) {
		printf(" [%d] ", num_array[i]);
		if (i != 9)
		{
			printf("->");
		}
	}
	printf("\n");
	// system("leaks -q a.out");
	return (0);
}
*/
