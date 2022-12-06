/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_all_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:43:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*try_all_push_a(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	while (!is_empty_stack_b(stack_b))
	{
		log = execute_operation(Push_a, stack_a, stack_b, log);
	}
	return (log);
}
