/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 07:53:07 by rukobaya          #+#    #+#             */
/*   Updated: 2022/08/14 13:13:24 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_idx(const char *s, int c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(s) + 1;
	while (i < n)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(const char *s, int size)
{
	char	*p;

	p = (char *)malloc(size + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, size + 1);
	return (p);
}
