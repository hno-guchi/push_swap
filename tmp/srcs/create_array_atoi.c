/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/28 12:20:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	*create_array_atoi(int size, char **elements)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
	{
		return (NULL);
	}
	while (i < size)
	{
		array[i] = ft_atoi(elements[i]);
		i += 1;
	}
	return (array);
}
