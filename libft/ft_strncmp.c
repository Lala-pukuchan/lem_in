/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sho <sho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:36:56 by smizutor          #+#    #+#             */
/*   Updated: 2023/01/25 20:37:10 by sho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2 || !(*str1) || !(*str2))
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*int main(void)
{
	char s1[] = "";
	char s2[] = "abc456";

	printf("orig: %d\n", strncmp(s1, s2, 0));
	printf("orig: %d\n", strncmp(s1, s2, 5));
	printf("ft__: %d\n", ft_strncmp(s1, s2, 0));
	printf("ft__: %d\n", ft_strncmp(s1, s2, 5));
}*/