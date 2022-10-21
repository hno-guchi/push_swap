#include <stdio.h>

int	main(void)
{
	int	i = 0;
	int	j = 0;
	int	target = 0;
	int	list[10] = {100, 210, 85, 23, 1, 8, 8000, 1123, 3332, 1};
	int	ranking[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// 大きさを比較する
	while (i < 10)
	{
		// 大きさを調べる値をlist[]から取り出す。
		target = list[i];
		while (j < 10)
		{
			// targetの方が大きい場合、targetに対応するranking[]の値をインクリメントする。
			if (list[j] < target)
			{
				ranking[i] += 1;
			}
			j += 1;
		}
		j = 0;
		i += 1;
	}

	i = 0;
	printf("ranking[]; | list[];\n");
	while (i < 10)
	{
		printf("       [%d] | [%4d] \n", ranking[i], list[i]);
		i += 1;
	}

	int	rank = 0;
	i = 0;
	printf("\n\n");
	printf("---- Out put (Compress) ----\n");
	printf("ranking[]; | list[];\n");
	while (rank < 10)
	{
		while (i < 10)
		{
			if (rank == ranking[i])
			{
				printf("       [%d] | [%4d] \n", ranking[i], list[i]);
			}
			i += 1;
		}
		i = 0;
		rank += 1;
	}
	return (0);
}
