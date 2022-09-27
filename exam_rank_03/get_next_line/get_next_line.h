/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:18:53 by mjallada          #+#    #+#             */
/*   Updated: 2022/06/02 09:46:02 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*buffer_to_line(char *line, char *buffer);
void	clean_buffer(char *buffer);
int	found_newline(char *buffer);
int	ft_strlen(char *str);

#endif
