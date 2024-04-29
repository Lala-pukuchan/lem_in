/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:39:14 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/29 17:09:13 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*token;

	if (str)
		next_token = str;
	if (!next_token)
		return (NULL);
	while (*next_token && ft_strchr(delim, *next_token))
		next_token++;
	token = next_token;
	while (*next_token && !ft_strchr(delim, *next_token))
		next_token++;
	if (*next_token)
	{
		*next_token = '\0';
		next_token++;
	}
	else
		next_token = NULL;
	if (token == next_token)
		return (NULL);
	else
		return (token);
}
