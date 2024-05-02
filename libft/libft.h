/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sho <sho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:21:50 by smizutor          #+#    #+#             */
/*   Updated: 2023/02/17 15:49:24 by sho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1024
# define FD_MAX 1024

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_count
{
	int		byte;
	int		index;
	va_list	argument;
}	t_count;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *buf, int ch, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free_s1(char *s1, char const *s2);
bool	ft_atol_and_check_over_flow(char *str, long long int *num);

//strtok
char	*ft_strtok(char *str, const char *delim);

//Get_next_line
size_t	ft_strchr_idx(const char *s, int c);
char	*ft_append_buf_to_save(char *buf, char *save, int size);
char	*ft_read_file(int fd, char *save);
char	*ft_create_line(char *save);
char	*ft_save_remain(char *save);
char	*get_next_line(int fd);

//ft_printf
int		ft_printf(const char *format, ...);
int		print_char(const char **format, va_list list);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long nb);
void	conversion_checker(char *format, t_count *count);
void	print_before_sign(char *format, t_count *count);
int		to_hexadecimal(unsigned long long nb, char conversion);
int		print_pointer(void *nb, char format);
#endif // _LIBFT_H_