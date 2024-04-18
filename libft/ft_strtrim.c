/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:07 by sho               #+#    #+#             */
/*   Updated: 2023/01/13 16:53:09 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_make_string(char *s2, char const *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	end = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j - 1]))
	{
		j--;
		end++;
	}
	if (i + end > ft_strlen(s1))
		end = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) - i - end + 1));
	if (s2 == NULL)
		return (NULL);
	s2 = ft_make_string(s2, &s1[i], ft_strlen(s1) - end - i);
	return (s2);
}
