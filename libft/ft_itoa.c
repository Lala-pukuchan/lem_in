/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:25:46 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/07 21:13:43 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit(long long int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_make_box(char *box, long long int n, int digit)
{
	while (n)
	{
		box[digit--] = '0' + (n % 10);
		n = n / 10;
	}
	return (box);
}

char	*ft_itoa(int n)
{
	size_t			digit;
	char			*box;
	long long int	num;

	num = n;
	digit = ft_count_digit(num);
	box = (char *)malloc(sizeof(char) * digit + 1);
	if (box == NULL)
		return (NULL);
	box[digit--] = '\0';
	if (num == 0)
		box[0] = '0';
	if (num < 0)
	{
		num = num * -1;
		box[0] = '-';
	}
	box = ft_make_box(box, num, digit);
	return (box);
}

/*int main(void)
{
	int a = -2147483648;
	int b = 2147483647;
	int c = 0;
	char *ap;
	char *bp;
	char *cp;

	ap = ft_itoa(a);
	bp = ft_itoa(b);
	cp = ft_itoa(c);
	printf("%s\n", ap);
	printf("%s\n", bp);
	printf("%s\n", cp);

	free(ap);
	free(bp);
	free(cp);

	return (0);
}*/