/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:42 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/10 16:04:01 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>

char	*get_next_line(int fd);

#endif