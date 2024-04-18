/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:23:59 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/04 13:45:13 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	node = lst;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
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
}*/