/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 07:26:11 by rukobaya          #+#    #+#             */
/*   Updated: 2022/08/14 13:13:46 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define FD_MAX 1024

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int	fd);
size_t	ft_strlen(const char	*s);
char	*ft_strndup(const char	*s, int size);
char	*ft_strjoin(const char	*s1, const char	*s2);
size_t	ft_strchr_idx(const char	*s, int	c);

#endif
