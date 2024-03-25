/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:33:01 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/25 23:17:39 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

void	ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	total_len;

	dest_len = ft_strlen(dest);
	total_len = dest_len + ft_strlen(src);
	i = dest_len;
	j = 0;
	while (i < total_len && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	join_len;
	char	*join_tmp;

	join_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *) malloc(join_len * sizeof(char));
	if (join == NULL)
		return (NULL);
	join_tmp = join;
	if (s1)
		while (*s1)
			*join_tmp++ = *s1++;
	*join_tmp = '\0';
	ft_strcat(join, s2);
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&s[i]);
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	if (!dest && !src)
		return (NULL);
	dest_tmp = dest;
	src_tmp = src;
	if (dest_tmp < src_tmp)
	{
		while (n--)
			*dest_tmp++ = *src_tmp++;
	}
	else
	{
		dest_tmp += n;
		src_tmp += n;
		while (n--)
			*--dest_tmp = *--src_tmp;
	}
	return (dest);
}
