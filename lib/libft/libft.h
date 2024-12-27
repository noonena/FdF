/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:39:20 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 00:18:13 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*context;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

char	*ft_strncpy(char *s1, char *s2, size_t size);
t_list	*create_newnode(char *str, size_t size);
void	addback_list(t_list **head, char *str, size_t size);
int		list_length(t_list **list);
char	*combine_tostring(t_list **list);
char	*handle_line(t_list **list, char *str, size_t pos);
int		loop_find_newline(int str_len, char *char_buffer);
char	*process_remaining_context(t_list **list);
char	*read_and_process_buffer(int fd, t_list **list, char *char_buffer);
char	*get_next_line(int fd);

char	**ft_split_space(char const *s);
int		ft_count_words_space(char const *s);

#endif