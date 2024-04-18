/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sho <sho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:59:16 by smizutor          #+#    #+#             */
/*   Updated: 2022/06/23 17:40:17 by sho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, count * size);
	return (mem);
}

/*int main(void)
{
	int *a;
	int *b;
	int *c;
	
	a = (int *)malloc(sizeof(int) * 4);
	b = (int *)calloc(4, sizeof(int));
	c = (int *)ft_calloc(4, sizeof(int));
	
	printf("malloc:    %p\n", &a[2]);
	printf("calloc:    %p\n", &b[1]);
	printf("ft_calloc: %p\n", c);

	free(a);
	free(b);
	free(c);
	return (0);
}*/