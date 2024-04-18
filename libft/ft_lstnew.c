/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:41:09 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 20:10:50 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nd;

	nd = (t_list *)malloc(sizeof(*nd));
	if (!nd)
		return (NULL);
	nd ->content = content;
	nd ->next = NULL;
	return (nd);
}

/*int main(void)
{
	t_list *head;
	t_list *new;

	new = ft_lstnew(strdup("new"));
	head = new;
	printf("現在のノード数 = %d\n", ft_lstsize(head));
	printf("newのcontentの中身 = %s\n", (char*)new->content);
}*/