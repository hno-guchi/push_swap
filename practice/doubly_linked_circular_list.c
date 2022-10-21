#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list {
	int				num;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	frees_list(t_list **head_p)
{
	t_list	*list_p;

	list_p = head_p[0]->next;
	while (list_p != head_p[0])
	{
		free(list_p);
		list_p = list_p->next;
	}
	free(head_p[0]);
	head_p = NULL;
}

int	main(int argc, char **argv)
{
	int	i = 1;
	t_list	*head;
	t_list	*new_node;

	// 番兵のーど　の作成
	head = (t_list *)malloc(sizeof(t_list));
	head->prev = head;
	head->next = head;

	// listの作成
	while (i < argc)
	{
		new_node = (t_list *)malloc(sizeof(t_list)); // メモリーの確保
		new_node->num = atoi(argv[i]);				 // 値の代入
		new_node->next = head;						 // 新しいノードの次のノードを　　　　　　　番兵ノードにする。
		new_node->prev = head->prev;				 // 新しいノードの前のノードを　　　　　　　番兵ノードの前のノードにする。
		head->prev->next = new_node;				 // 　番兵ノードの前のノードの次のノードを　新しいノードにする。
		head->prev = new_node;						 // 番兵ノードの前のノードを　　　　　　　　新しいノードにする。
		i += 1;
	}

	// 確認
	i = 0;
	t_list	*list_p;

	list_p = head->next;
	while (list_p != head)
	{
		printf(" -> [%2d]", list_p->num);
		list_p = list_p->next;
	}

	// 後処理
	frees_list(&head);
	system("leaks -q a.out");
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int	i = 1;
	t_list	*head;
	t_list	*new_node;

	// 引数のチェック
	if (argc <= 1)
	{
		return (0);
	}
	// 番兵のーど　の作成
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
	{
		return (0);
	}
	head->prev = head;
	head->next = head;
	// listの作成
	while (i < argc)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
		{
			frees_list(&head);
			return (0);
		}
		new_node->num = atoi(argv[i]);
		new_node->next = head;
		new_node->prev = head->prev;
		head->prev->next = new_node;
		head->prev =new_node;
		i += 1;
	}

	// 確認
	i = 0;
	t_list	*list_p;

	list_p = head->next;
	while (list_p != head)
	{
		printf(" -> [%2d]", list_p->num);
		list_p = list_p->next;
	}
	frees_list(&head);
	system("leaks -q a.out");
	return (0);
}
*/
