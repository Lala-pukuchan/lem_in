/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:50:29 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/06 19:31:12 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	n;

	n = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[n] != '\0')
	{
		f(n, &s[n]);
		n++;
	}
}

/*void ft_plus(unsigned int n, char *s)
{
	*s = *s + n;
}

int	main(void)
{
	char s[] = "0000000";
	void (*f)(unsigned int, char *);
	
	f = ft_plus;
	ft_striteri(s, f);
	
	printf("%s", s);
	return (0);
}*/