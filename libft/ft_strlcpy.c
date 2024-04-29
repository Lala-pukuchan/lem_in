/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:32 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:16:54 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* int main(void)
{
	char src[] = "";
	char dst[] = "0123456789";
	char src_ft[] = "";
	char dst_ft[] = "0123456789";
	
	printf("orig:%lu\n", strlcpy(dst, src, 5));
	printf("orig:%s\n", dst);
	printf("ft__:%lu\n", ft_strlcpy(dst_ft, src_ft, 5));
	printf("ft__:%s\n", dst_ft);

	

	char src2[] = "Hello****World****!";
	char dst2[100] = "0123456789";
	char src_ft2[] = "Hello****World****!";
	char dst_ft2[100] = "0123456789";

	printf("orig:%lu\n", strlcpy(dst2, src2, 12));
	printf("orig:%s\n", dst2);
	printf("ft__:%lu\n", ft_strlcpy(dst_ft2, src_ft2, 12));
	printf("ft__:%s\n", dst_ft2);

	

	char src3[] = "ototo";
	char dst3[100] = "0123456789";
	char src_ft3[] = "ototo";
	char dst_ft3[100] = "0123456789";

	printf("orig:%lu\n", strlcpy(dst3, src3, 2));
	printf("orig:%s\n", dst3);
	printf("ft__:%lu\n", ft_strlcpy(dst_ft3, src_ft3, 2));
	printf("ft__:%s\n", dst_ft3);

	

	char src4[] = "VQrGaEWZBSqs";
	char dst4[200] = "0123456789";
	char src_ft4[] = "VQrGaEWZBSqs";
	char dst_ft4[200] = "0123456789";

	printf("orig:%lu\n", strlcpy(dst4, src4, 55));
	printf("orig:%s\n", dst4);
	printf("ft__:%lu\n", ft_strlcpy(dst_ft4, src_ft4, 55));
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
} */