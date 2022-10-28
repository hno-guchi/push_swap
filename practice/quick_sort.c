#include <stdio.h>

void	quick_sort(int list[], int start_left_idx, int start_right_idx)
{
	int	pivot;
	int	temp;
	int	move_left;
	int	start_left;
	int	move_right;
	int	start_right;

	start_left = start_left_idx;
	start_right = start_right_idx;
	if (start_left_idx < start_right_idx)
	{
		pivot = list[(start_left + start_right) / 2];
		// printf("pivot = list[] = [%d]\n", pivot);
		move_left = start_left;
		move_right = start_right;
		// printf("move_left = [%d] | move_right = [%d]\n", move_left, move_right);
		while (1)
		{
			while (list[move_left] < pivot)
			{
				move_left += 1;
			}
			while (pivot < list[move_right])
			{
				move_right -= 1;
			}
			if (move_right <= move_left)
			{
				break ;
			}
			temp = list[move_left];
			list[move_left] = list[move_right];
			list[move_right] = temp;
			// printf("list[move_left] = [%d] | list[move_right] = [%d]\n", list[move_left], list[move_right]);
		}
		quick_sort(list, start_left_idx, move_left - 1);   // left part
		quick_sort(list, move_right + 1, start_right_idx); // right part
	}
}

int	main(void)
{
	static int num_array[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 11};

	quick_sort(num_array, 0, 9);

	for(int i = 0; i < 10; i++) {
		printf(" [%d] ", num_array[i]);
		if (i != 9)
		{
			printf("->");
		}
	}
	printf("\n");

	return (0);
}
