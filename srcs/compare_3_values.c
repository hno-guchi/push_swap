/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_3_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/02 11:12:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_order	compare_3_values(int first, int second, int third)
{
	if ((first < second) && (third < second) && (first < third))
	{
		return (Min_max_mid);
	}
	else if ((second < first) && (third < first) && (third < second))
	{
		return (Max_mid_min);
	}
	else if ((second < first) && (second < third) && (first < third))
	{
		return (Mid_min_max);
	}
	else if ((second < first) && (third < first) && (second < third))
	{
		return (Max_min_mid);
	}
	else if ((first < second) && (third < second) && (third < first))
	{
		return (Mid_max_min);
	}
	return (Min_mid_max);
}
