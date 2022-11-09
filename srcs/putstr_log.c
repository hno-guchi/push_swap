/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/09 19:42:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include "ft_printf.h"

/*
void	putstr_log(t_list *head_p)
{
	t_list	*list_log;

	if (head_p == NULL)
	{
		return ;
	}
	list_log = head_p;
	while (list_log)
	{
		if (list_log->content)
		{
			ft_printf("%s\n", (char *)list_log->content);
		}
		list_log = list_log->next;
	}
}
*/

void	putstr_log(t_list *head_p)
{
	int		count;
	t_list	*list_log;

	if (head_p == NULL)
	{
		return ;
	}
	count = 0;
	list_log = head_p;
	while (list_log)
	{
		if (list_log->content)
		{
			count += 1;
		}
		if (list_log->next != NULL)
		{
			if (!ft_strncmp((char *)list_log->content, "sa", 2) && !ft_strncmp((char *)list_log->next->content, "sb", 2))
			{
				ft_printf(RED"%3s "END, (char *)list_log->content);
				list_log = list_log->next;
				count += 1;
				ft_printf(RED"%3s "END, (char *)list_log->content);
			}
			else if (!ft_strncmp((char *)list_log->content, "sb", 2) && !ft_strncmp((char *)list_log->next->content, "sa", 2))
			{
				ft_printf(RED"%3s "END, (char *)list_log->content);
				list_log = list_log->next;
				count += 1;
				ft_printf(RED"%3s "END, (char *)list_log->content);
			}
			else if (!ft_strncmp((char *)list_log->content, "ra", 2) && !ft_strncmp((char *)list_log->next->content, "rb", 2))
			{
				ft_printf(RED"%3s "END, (char *)list_log->content);
				list_log = list_log->next;
				count += 1;
				ft_printf(RED"%3s "END, (char *)list_log->content);
			}
			else if (!ft_strncmp((char *)list_log->content, "rb", 2) && !ft_strncmp((char *)list_log->next->content, "ra", 2))
			{
				ft_printf(RED"%3s "END, (char *)list_log->content);
				list_log = list_log->next;
				count += 1;
				ft_printf(RED"%3s "END, (char *)list_log->content);
			}
			else if (!ft_strncmp((char *)list_log->content, "rra", 3) && !ft_strncmp((char *)list_log->next->content, "rrb", 3))
			{
				ft_printf(RED"%3s "END, (char *)list_log->content);
				list_log = list_log->next;
				count += 1;
				ft_printf(RED"%3s "END, (char *)list_log->content);
			}
			else if (!ft_strncmp((char *)list_log->content, "rrb", 3) && !ft_strncmp((char *)list_log->next->content, "rra", 3))
			{
				ft_printf(RED"%3s "END, (char *)list_log->content);
				list_log = list_log->next;
				count += 1;
				ft_printf(RED"%3s "END, (char *)list_log->content);
			}
			else
			{
				ft_printf("%3s ", (char *)list_log->content);
			}
		}
		else
		{
			ft_printf("%3s ", (char *)list_log->content);
		}
		if (!(count % 10))
		{
			ft_printf("\n");
		}
		list_log = list_log->next;
	}
	ft_putstr_fd("\n-----------------------------------------------\n", 1);
	ft_printf("Total : [%d]\n", count);
}

/*
// gcc -g -fsanitize=address 
// putstr_log.c -I../libft/includes -I../includes -L../libft -lft
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
