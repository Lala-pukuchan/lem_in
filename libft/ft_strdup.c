/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:40:21 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:14:13 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	count_s;
	char	*s2;
	size_t	i;

	count_s = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * count_s + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < count_s)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*int main(void)
{
	char s[] = "ueda shinya";
	char *s2;
	
	s2 = ft_strdup(s);

	printf("orig: %p %p %s\n",s, strdup(s), strdup(s));
	printf("ft__: %p %p %s\n",s, ft_strdup(s), ft_strdup(s));

	free(s2);
}*/