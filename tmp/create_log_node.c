/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_log_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/25 15:21:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef enum operationnm {
	Swap_a,
	Swap_b,
	Swap_s,
	Push_a,
	Push_b,
	Rotate_a,
	Rotate_b,
	Rotate_r,
	Reverse_rotate_a,
	Reverse_rotate_b,
	Reverse_rotate_r
}	t_operation_num;

typedef struct s_operation_log_list {
	t_operation_num				log;
	struct s_operation_log_list	*next;
}	t_operation_log_list;
*/

t_operation_log_list	*create_log_node(t_operation_num log)
{
	t_operation_log_list	*new_node;

	new_node = (t_operation_log_list *)malloc(sizeof(t_operation_log_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->log = log;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p;
	t_bidrect_circle_list	*stack_a;
	t_operation_log_list	*log;

	i = 0;
	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	log = NULL;
	head_p = create_stack_a(argc, argv);
	add_back_list_log_node(&log, create_log_node(push(head_p, Push_a)));
	stack_a = head_p->next;
	while (stack_a != head_p)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	putstr_log(log);
	log_list_clear(&log);
	stack_clear(&head_p);
	system("leaks -q push_swap");
	return (0);
}
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
*/

/*
// TEST libft ft_lst*.c
// gcc create_log_node.c -L../libft -lft
// gcc -g -fsanitize=address create_log_node.c -L../libft -lft
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include <stdio.h>
int	main(void)
{
	t_list	*log_node;
	t_list	*log_list;
	t_list	*head_p;

	log_list = NULL;
	
	log_node = ft_lstnew("sa");
	head_p = log_node;
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("sb");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("ss");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("pa");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("pb");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("ra");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("rb");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("rr");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("rra");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("rrb");
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew("rrr");
	ft_lstadd_back(&log_list, log_node);

	int	i = 0;
	while (log_list)
	{
		ft_printf("[%2d] : [%s]\n", i, (char *)log_list->content);
		log_list = log_list->next;
		i += 1;
	}
	ft_lstclear(&head_p, NULL);
	// system("leaks -q a.out");
	return (0);
}
*/
