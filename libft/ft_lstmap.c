/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:53:49 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 20:09:43 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
		return (NULL);
	new_lst = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*void *ft_f(void *content)
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
	return(content);
}

void ft_del(void *p)
{	
	free(p);
}

int main(void)
{
	void *(* f)(void*);
	void (*del)(void *);
	f = ft_f;
	del = ft_del;
	t_list *head;
	t_list *new_list = NULL;
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
	
	new_list = ft_lstmap(head, f, del);
	while (new_list != NULL)
	{
		printf("new_node->contentの中身      = %s\n", (char*)new_list->content);
		new_list = new_list->next;
	}
}*/