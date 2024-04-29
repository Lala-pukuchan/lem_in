/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool_atol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sho <sho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:38:56 by sho               #+#    #+#             */
/*   Updated: 2023/02/17 15:46:01 by sho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_overflow(int sig, char str, long long int num)
{
	if (sig == 1 && (LLONG_MAX - sig * (str - '0')) / 10 >= num)
		return (false);
	if (sig == -1 && (LLONG_MIN - sig * (str - '0')) / 10 <= num)
		return (false);
	return (true);
}

bool	ft_atol_and_check_over_flow(char *str, long long int *num)
{
	size_t			i;
	int				sig;

	i = 0;
	sig = 1;
	*num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sig = sig * (',' - str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!is_overflow(sig, str[i], *num))
			*num = sig * (str[i] - '0') + *num * 10;
		else
			return (true);
		i++;
	}
	return (false);
}

/* int main(void)
{
	long long num = 0;
	printf ("[-9223372036854775809] %d num = %lld\n",
	 ft_atol_and_check_over_flow("-9223372036854775809", &num), num);
	printf ("[-9223372036854775808] %d num = %lld\n", 
	ft_atol_and_check_over_flow("-9223372036854775808", &num), num);
	printf ("[9223372036854775807] %d num = %lld\n", 
	ft_atol_and_check_over_flow("9223372036854775807", &num), num);
	printf ("[9223372036854775808] %d num = %lld\n", 
	ft_atol_and_check_over_flow("9223372036854775808", &num), num);
	printf ("[1] %d num = %lld\n", ft_atol_and_check_over_flow
	("1", &num), num);
	printf ("[0] %d num = %lld\n", ft_atol_and_check_over_flow
	("0", &num), num);
	//ft_bool_atol("-9223372036854775809", &num);
	//printf("%lld", num);
} */