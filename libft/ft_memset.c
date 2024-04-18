/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:45:53 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/06 13:01:17 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}

/*int main(void)
{
	char string[] = "0123456789";
	
	size_t i = 3;
	
	ft_memset(&string[2], '*', i);
	printf("%s", string);
	return(0);
}*/