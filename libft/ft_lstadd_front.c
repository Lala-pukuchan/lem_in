/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:27 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 20:04:00 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main(void)
{
	t_list *head = NULL;
	t_list *nd1, *nd2, *nd3;
	nd1 = ft_lstnew(ft_strdup("first"));
	ft_lstadd_front(&head, nd1);
	printf("nd1をaddfrontした後、リストにあるノードの数 = %d\n", ft_lstsize(head));
	nd2 = ft_lstnew(ft_strdup("second"));
	ft_lstadd_front(&head, nd2);
	printf("nd2をaddfrontした後、リストにあるノードの数 = %d\n", ft_lstsize(head));
	nd3 = ft_lstnew(ft_strdup("third"));
	ft_lstadd_front(&head, nd3);
	printf("nd3をaddfrontした後、リストにあるノードの数 = %d\n", ft_lstsize(head));
	printf("nd1->nextが差しているポインタ = %p\n", nd1->next);
	printf("nd3->nextのポインタ         = %p\n", nd3->next);
	printf("nd2のポインタ               = %p\n", nd2);
}*/