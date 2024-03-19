/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:33:01 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/19 23:16:46 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest0;

	dest0 = dest;
	if (src)
	{
		while (*src)
			*dest++ = *src++;
	}
	*dest = '\0';
	return (dest0);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
			size--;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(char *s, size_t len)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, len);
	return (dest);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (ft_strlen(src) + size);
	i = dest_len;
	j = 0;
	while (i < (size - 1) && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest_len + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	join_len;


	join_len = ft_strlen(s1) + ft_strlen(s2) + 1;

	joined = (char *)malloc(join_len * sizeof(char));

	if (joined == NULL)
		return (NULL);
	ft_strcpy(joined, s1);
	if (s1)
		free(s1);
	ft_strlcat(joined, s2, join_len);
	return (joined);
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

void	*ft_memset(void *s, int c, size_t n)
{
	void	*s_tmp;

	s_tmp = s;
	while (n--)
	{
		*(unsigned char *)s_tmp = (unsigned char) c;
		s_tmp++;
	}
	return (s);
}
