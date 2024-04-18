/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:41:07 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/04 19:08:26 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*s2;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*char	ft_plus(unsigned int n, char c)
{
	c = c + n;
	return (c);
}

int main(void)
{
	char s[] = "123456";
	char (*f)(unsigned int, char);

	f = ft_plus;
	
	printf("%s\n", ft_strmapi(s, f));
}*/