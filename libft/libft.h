/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:51:06 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/22 17:59:27 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_atoi
					(const char *str);
int					ft_isalnum
					(int a);
int					ft_isalpha
					(int a);
int					ft_isascii
					(int a);
int					ft_isdigit
					(int a);
int					ft_isprint
					(int a);
int					ft_memcmp
					(const void *s1, const void *s2, size_t n);
int					ft_strcmp
					(const char *str1, const char *str2);
int					ft_strncmp
					(const char *str1, const char *str2, size_t n);
int					ft_tolower
					(int a);
int					ft_toupper
					(int a);
int					ft_strequ
					(char const *s1, char const *s2);
int					ft_strnequ
					(char const *s1, char const *s2, size_t n);
char				*ft_itoa
					(int n);
char				**ft_strsplit
					(char const *s, char c);
char				*ft_strcat
					(char *s1, const char *s2);
char				*ft_strchr
					(const char *s, int c);
char				*ft_strcpy
					(char *dst, const char *src);
char				*ft_strdup
					(const char *s1);
char				*ft_strncat
					(char *s1, const char *s2, size_t n);
char				*ft_strncpy
					(char *dst, const char *src, size_t len);
char				*ft_strnstr
					(const char *big, const char *little, size_t len);
char				*ft_strrchr
					(const char *s, int c);
char				*ft_strstr
					(const char *big, const char *little);
char				*ft_strnew
					(size_t size);
char				*ft_strmap
					(char const *s, char (*f)(char));
char				*ft_strmapi
					(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin
					(char const *s1, char const *s2);
char				*ft_strtrim
					(char const *s);
char				*ft_strsub
					(char const *s, unsigned int start, size_t len);
void				ft_putendl
					(char const *s);
void				ft_putendl_fd
					(char const *s, int fd);
void				ft_bzero
					(void *s, size_t n);
void				*ft_memccpy
					(void *dst, const void *src, int c, size_t n);
void				*ft_memchr
					(const void *s, int c, size_t n);
void				*ft_memcpy
					(void *dst, const void *src, size_t n);
void				*ft_memmove
					(void *dst, const void *src, size_t len);
void				*ft_memset
					(void *b, int c, size_t len);
void				ft_putstr
					(char *str);
void				ft_putnbr
					(int c);
void				ft_putchar
					(char s);
void				*ft_memalloc
					(size_t size);
void				ft_memdel
					(void **ap);
void				ft_strdel
					(char **as);
void				ft_strclr
					(char *s);
void				ft_striter
					(char *s, void (*f)(char *));
void				ft_striteri
					(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd
					(char c, int fd);
void				ft_putstr_fd
					(char const *s, int fd);
void				ft_putnbr_fd
					(int n, int fd);
void				ft_revsort_char
					(char *str);
void				ft_sort_char
					(char *str);
void				ft_swap_char
					(char *a, char *b);
void				ft_swap_int
					(int *a, int *b);
void				ft_strjoin_free
					(char **s1, char *s2);
void				ft_strsub_free
					(char **s, unsigned int start, unsigned int len);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstiter
					(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone
					(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel
					(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd
					(t_list **alst, t_list *new);
size_t				ft_strlen
					(const char *str);
size_t				ft_strlcat
					(char *dst, const char *src, size_t size);
t_list				*ft_lstnew
					(void const *content, size_t content_size);
t_list				*ft_lstmap
					(t_list *lst, t_list *(*f)(t_list *elem));

#endif
