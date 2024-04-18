/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:45:11 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/04 17:16:21 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char a[] = "abcdefghijklmn";
	char b[] = "abc\0defghijklmn";

	printf("orig: %s\n", (unsigned char *)memchr(a, 'd', 5));
	printf("ft__: %s\n", (unsigned char *)ft_memchr(a, 'd', 5));
	printf("orig: %s\n", (unsigned char *)memchr(b, 'e', 8));
	printf("ft__: %s\n", (unsigned char *)ft_memchr(b, 'e', 8));
}*/