/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:38:15 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/02 19:52:44 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node != NULL)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/*int main(void)
{
	int a = 5;
	int *content = &a;
	t_list *head;
	t_list *last;
	t_list nd4 = {content, NULL};
	t_list nd3 = {content, &nd4};
	t_list nd2 = {content, &nd3};
	t_list nd1 = {content, &nd2};
	head = &nd1;

	last = ft_lstlast(head);
	printf("last = %p\n", last);
	printf("nd4  = %p\n", &nd4);
}*/