#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int list[], int begin, int end)
{
	int	pivot;
	int	move_to_right;
	int	move_to_left;

	if (begin < end)
	{
		pivot = list[(begin + end) / 2];
		move_to_right = begin;
		move_to_left = end;
		while (1)
		{
			while (list[move_to_right] < pivot)
			{
				move_to_right += 1;
			}
			while (pivot < list[move_to_left])
			{
				move_to_left -= 1;
			}
			if (move_to_left <= move_to_right)
			{
				break ;
			}
			swap(&list[move_to_right], &list[move_to_left]);
		}
		quick_sort(list, begin, move_to_right - 1);
		quick_sort(list, move_to_left + 1, end);
	}
}

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

	quick_sort(num_array, 0, 9);

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
