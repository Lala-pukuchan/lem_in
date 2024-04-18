/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:35:05 by smizutor          #+#    #+#             */
/*   Updated: 2022/01/23 15:43:36 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*int main(void)
{
	char s[] = "abcdefghi'\0jklmnabcd";
	char *p1;
	char *p2;

	p1 = strrchr(s, 'h');
	p2 = ft_strrchr(s, 'h');

	
	printf("orig:%s\n", p1);
	printf("ft__:%s\n", p2);
}*/