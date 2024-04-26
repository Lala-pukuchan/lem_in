/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:13:34 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/06 13:00:45 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}

/*int main(void)
{
	char s1[] = "abcdefg\0ijklmn";
	char s2[] = "abcdefgh234567";

	printf("orig: %d\n", memcmp(s1, s2, 10));
	printf("ft__: %d\n", ft_memcmp(s1, s2, 10));

	return (0);
}*/