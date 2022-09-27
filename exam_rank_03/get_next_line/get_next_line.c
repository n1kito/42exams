/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:17:06 by mjallada          #+#    #+#             */
/*   Updated: 2022/06/03 08:58:11 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp_line;
	int		readed;

	if (read(fd, buffer, 0) == -1)
		return (NULL);
	line = NULL;
	if (buffer[0])
		line = buffer_to_line(line, buffer);
	while (!found_newline(buffer))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == 0)
			break;
		buffer[readed] = '\0';
		tmp_line = line;
		line = buffer_to_line(line, buffer);
		free(tmp_line);
	}
	clean_buffer(buffer);
	return (line); 
}

char	*buffer_to_line(char *line, char *buffer)
{
	int	i;
	int	j;
	char	*new_line;

	i = 0;
	j = 0;
	if (found_newline(buffer))
		new_line = malloc(sizeof(char) * (ft_strlen(line) + found_newline(buffer) + 1));
	else
		new_line = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (!new_line)
		return (NULL);
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (buffer[j] && buffer[j] != '\n')
		new_line[i++] = buffer[j++]; 	
	if (buffer[j] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

void	clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = found_newline(buffer);
	if (j == 0)
		buffer[0] = '\0';
	else
	{
		while (buffer[j])
			buffer[i++] = buffer[j++];
		buffer[i] = '\0';
	}
}

int	found_newline(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
