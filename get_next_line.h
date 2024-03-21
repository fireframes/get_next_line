/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:42 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/21 19:08:01 by mmaksimo         ###   ########.fr       */
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

char	*ft_strendup(char *s_start, char *s_end);

void	ft_strcat(char *dest, char *src);

void	*ft_memset(void *s, int c, size_t n);

char	*ft_strchr(char *s, int c);

#endif
