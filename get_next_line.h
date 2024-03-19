/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:42 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/19 23:15:18 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *dest, char *src, size_t size);

char	*ft_strdup(char *s, size_t len);

size_t	ft_strlcat(char *dest, char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);


#endif
