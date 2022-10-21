/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_write_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:54:25 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/19 17:36:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	exit_write_message(error_num num)
{
	ft_putstr_fd(RED"Error\n", STDERR_FILENO);
	if (num == Malloc_error)
	{
		ft_putstr_fd("Failed malloc."END, STDERR_FILENO);
	}
	else if (num == Not_int)
	{
		ft_putstr_fd("Not int type."END, STDERR_FILENO);
	}
	else if (num == Duplicate)
	{
		ft_putstr_fd("Exist duplication value."END, STDERR_FILENO);
	}
	exit(1);
}
