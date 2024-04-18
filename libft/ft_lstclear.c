/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:18:48 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:14:30 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/*void ft_del(void *p)
{	
	free(p);
}

int main(void)
{
	void (* del)(void*);
	del = ft_del;
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
	ft_lstclear(&head, del);
	printf("ft_lstclearした後リストにあるノードの数    = %d\n", ft_lstsize(head));
}*/