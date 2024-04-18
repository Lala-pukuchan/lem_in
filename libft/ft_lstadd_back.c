/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:25:16 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 20:03:05 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	node = *lst;
	while (node->next != NULL)
		node = node->next;
	node->next = new;
	new->next = NULL;
}

/*int main(void)
{
	t_list *head;
	t_list *nd1, *nd2, *nd3;
	nd1 = ft_lstnew(ft_strdup("first"));
	head = nd1;
	printf("nd1をaddbackした後、リストにあるノードの数 = %d\n", ft_lstsize(head));
	nd2 = ft_lstnew(ft_strdup("second"));
	ft_lstadd_back(&head, nd2);
	printf("nd2をaddbackした後、リストにあるノードの数 = %d\n", ft_lstsize(head));
	nd3 = ft_lstnew(ft_strdup("third"));
	ft_lstadd_back(&head, nd3);
	printf("nd3をaddbackした後、リストにあるノードの数 = %d\n", ft_lstsize(head));
	printf("nd2->nextが差しているポインタ = %p\n", nd2->next);
	printf("nd3のポインタ                = %p\n", nd3);
	printf("nd3->nextが差しているポインタ = %p\n", nd3->next);
}*/