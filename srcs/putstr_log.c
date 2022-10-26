/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 12:13:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	putstr_log(t_list *head_p)
{
	t_list	*list_log;

	list_log = head_p;
	while (list_log)
	{
		// if (list_log->content)
		//{
			// ft_printf("[%s]\n", (char *)list_log->content);
			ft_putstr_fd((char *)list_log->content, 1);
			ft_putstr_fd("\n", 1);
		//}
		list_log = list_log->next;
	}
}

/*
// gcc -g -fsanitize=address putstr_log.c -I../libft/includes -I../includes -L../libft -lft
int	main(void)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	node = ft_lstnew("sa");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("sb");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("ss");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("pa");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("pb");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("ra");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("rb");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("rr");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("rra");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("rrb");
	ft_lstadd_back(&list, node);
	node = ft_lstnew("rrr");
	ft_lstadd_back(&list, node);
	node = ft_lstnew(NULL);
	ft_lstadd_back(&list, node);

	putstr_log(list);
	ft_lstclear(&list, NULL);
	// system("leaks -q a.out");
	return (0);
}
*/
