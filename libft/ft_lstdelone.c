/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:33:09 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:17:21 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void ft_del(void *p)
{
	free(p);
}*/

/*int main(void)
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
	ft_lstdelone(nd3, del);
	printf("--deloneを使い、nd3を解放--\n");
	printf("まだnd2がNULLを示せていないので、これ以降にlstsizeを測ろうとするとセグフォ\n");
}*/