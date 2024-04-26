/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:46:29 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:36:13 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sig;
	long long int	num;

	i = 0;
	sig = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{	
		sig = sig * (',' - str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sig * num);
}

/*int main(void)
{
	printf("orig: %d\n", atoi("-1"));
	printf("ft__: %d\n", ft_atoi("-1"));
	printf("orig: %d\n", atoi("0"));
	printf("ft__: %d\n", ft_atoi("0"));
	printf("orig: %d\n", atoi("-2147483648"));
	printf("ft__: %d\n", ft_atoi("-2147483648"));
	printf("orig: %d\n", atoi("2147483647"));
	printf("ft__: %d\n", ft_atoi("2147483647"));
	return (0);
}*/
