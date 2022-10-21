/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:40:24 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/19 10:44:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !lst[0])
	{
		return ;
	}
	while (lst[0])
	{
		next = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = next;
	}
	lst = NULL;
}
