/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizutor <smizutor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:02:50 by smizutor          #+#    #+#             */
/*   Updated: 2022/02/06 23:07:18 by smizutor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_check(char c, char set)
{
	if (c == '\0' || c == set)
		return (1);
	return (0);
}

static void	ft_cpy(char *box, char *s, char c)
{
	size_t	i;

	i = 0;
	if (!box)
		return ;
	while (ft_check(s[i], c) == 0)
	{
		box[i] = s[i];
		i++;
	}
	box[i] = '\0';
}

static void	*ft_free(char **box)
{
	size_t	i;

	i = 0;
	while (box[i] != NULL)
	{
		free(box[i]);
		i++;
	}
	return (NULL);
}

static void	*ft_make_array(char **box, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if (ft_check(s[i], c) == 0)
		{
			while (ft_check(s[i + j], c) == 0)
				j++;
			box[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!box[k])
				return (ft_free(box));
			ft_cpy(box[k], &s[i], c);
			i = i + j;
			k++;
		}
		if (i != ft_strlen(s))
			i++;
	}
	return (box);
}

char	**ft_split(char const *s, char c)
{	
	char	**box;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (ft_check(s[i], c) == 0)
		{
			if (ft_check(s[i + 1], c) == 1)
				j++;
		}
		i++;
	}
	box = (char **)malloc(sizeof(char *) * (j + 1));
	if (box == NULL)
		return (NULL);
	box = ft_make_array(box, (char *)s, c);
	box[j] = NULL;
	return (box);
}

/*int main(void)
{
	char **box;
	int i;

	box = ft_split("aiiiiaiiiiaiiiiaiiiia",'a');
	i = 0;
	while (box[i] != NULL)
	{
		printf("%s\n", box[i]);
		i++;
	}
	i = 0;
	while (box[i++] != NULL)
		free(box[i]);
	
	box = ft_split("aaaaaaaaaaaaaa",'a');
	i = 0;
	while(box[i] != NULL)
	{
		printf("%s\n", box[i]);
		i++;
	}
	i = 0;
	while (box[i++] != NULL)
		free(box[i]);


	box = ft_split("",'a');
	i = 0;
	while(box[i] != NULL)
	{
		printf("%s\n", box[i]);
		i++;
	}
	i = 0;
	while (box[i++] != NULL)
		free(box[i]);
		
}

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}*/