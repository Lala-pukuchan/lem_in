/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:20:13 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:35:47 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	i;
	size_t	j;
	size_t	cpy_num;

	count_dst = ft_strlen(dst);
	count_src = ft_strlen(src);
	cpy_num = size - count_dst - 1;
	i = count_dst;
	if (size == 0)
		return (count_src);
	if (size < count_dst)
		count_src += size;
	else
		count_src += count_dst;
	j = 0;
	while (i < count_dst + cpy_num && src[j])
	{
		dst[i] = src[i - count_dst];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (count_src);
}

/*int main(void)
{	
	char src1 [] = "kakiku";
	char dst1 [10] = "aiueo";	
	printf("orig:%zu\n", strlcat(dst1, src1, 6));
	printf("orig:%s\n", dst1);

	char src_ft1 [] = "kakiku";
	char dst_ft1 [10] = "aiueo";	
	printf("ft__:%zu\n", ft_strlcat(dst_ft1, src_ft1, 6));
	printf("ft__:%s\n", dst_ft1);
	
	

	char src2 [] = "HelloWorld!";
	char dst2 [101] = "!";	
	printf("orig:%zu\n", strlcat(dst2, src2, 100));
	printf("orig:%s\n", dst2);

	char src_ft2 [] = "HelloWorld!";
	char dst_ft2 [101] = "!";	
	printf("ft__:%zu\n", ft_strlcat(dst_ft2, src_ft2, 100));
	printf("ft__:%s\n", dst_ft2);

	

	char src3 [] = "hello";
	char dst3 [101] = "";	
	printf("orig:%zu\n", strlcat(dst3, src3, 100));
	printf("orig:%s\n", dst3);

	char src_ft3 [] = "hello";
	char dst_ft3 [101] = "";	
	printf("ft__:%zu\n", ft_strlcat(dst_ft3, src_ft3, 100));
	printf("ft__:%s\n", dst_ft3);
	

	char src4 [] = "aiueo";
	char dst4 [101] = "!";	
	printf("orig:%zu\n", strlcat(dst4, src4, 0));
	printf("orig:%s\n", dst4);

	char src_ft4 [] = "aiueo";
	char dst_ft4 [101] = "!";	
	printf("ft__:%zu\n", ft_strlcat(dst_ft4, src_ft4, 0));
	printf("ft__:%s\n", dst_ft4);


	return (0);
}

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}*/
