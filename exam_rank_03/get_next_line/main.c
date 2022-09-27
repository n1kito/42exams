/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:16:34 by mjallada          #+#    #+#             */
/*   Updated: 2022/06/02 09:22:02 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *line;

	fd = open("test", O_RDONLY);
	while (1)
	{	
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
	}
	return (0);
}
