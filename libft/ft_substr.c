/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sho <sho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:32:51 by smizutor          #+#    #+#             */
/*   Updated: 2022/06/21 15:46:02 by sho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < (unsigned int)ft_strlen(s))
	{
		s2[i] = s[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*int main(void)
{
	char s[] = "abeshin";
	char *p;
	char *p2;
	char *p3;
	p = strchr(s, '\0');
	p2 = ft_substr(s, 8, 6);
	p3 = strchr(p2, '\0');
	
	printf("ft__:%s\n", ft_substr(s, 3, 6));
	printf("ポイ:%p\n", p);
	printf("ポイ:%p\n", p3);
	
	return (0);
}*/