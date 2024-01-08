/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:45:20 by chsassi           #+#    #+#             */
/*   Updated: 2023/11/09 16:45:22 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last->next = new;
}

/* void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)(lst->content));
		lst = lst->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list *head = NULL;

	int		n1 = 42;
	t_list	*node1 = malloc(sizeof(t_list));
	node1->content = &n1;
	node1->next = NULL;

	int		n2 = 99;
	t_list	*node2 = malloc(sizeof(t_list));
	node2->content = &n2;
	node2->next = NULL;

	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node1);
	printf("Linked List: ");
	print_list(head);

	while (head)
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
} */