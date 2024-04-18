/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:15:09 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/04 17:22:03 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str2 > str1)
	{
		while (i++ < len)
			str2[len - i] = str1[len - i];
	}
	else
	{
		while (len-- > 0)
			*(str2++) = *(str1++);
	}
	return (dst);
}

/*int main(void)
{
	char src[] = "12345";
	//char dst[] = "";

	char src2[] = "12345";
	//char dst2[] = "0123456789";
	
	ft_memmove(src, src + 2, 3);
	memmove(src2, src2 + 2, 3);
	printf("orig:%s\n", src2);
	printf("ft__:%s\n", src);
	return (0);
}*/