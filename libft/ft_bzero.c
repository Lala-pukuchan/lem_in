/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:36:35 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/06 12:45:10 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int main(void)
{
	char string[] = "0123456789";
	void *s = string;
	
	ft_bzero(s, 3);	
	for (int i = 0; i < 10; i++)
	{
		printf("%c", string[i]);
	}
	
	return (0);
}*/