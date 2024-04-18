/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:02:39 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 20:08:24 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void ft_f(void *content)
{
	size_t i;
	char *c_content;
	c_content = content;
	i = 0;
	while (c_content[i])
	{
		c_content[i] = c_content[i] + 1;
		i++;
	}
}

int main(void)
{
	void (* f)(void*);
	f = ft_f;
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
	ft_lstiter(head, f);
	printf("ft_lstiter後のnd1->contentの中身       = %s\n", (char*)nd1->content);
	printf("ft_lstiter後のnd2->contentの中身       = %s\n", (char*)nd2->content);
	printf("ft_lstiter後のnd3->contentの中身       = %s\n", (char*)nd3->content);
}*/