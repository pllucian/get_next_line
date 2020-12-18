/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:58:14 by pllucian          #+#    #+#             */
/*   Updated: 2020/12/18 23:19:55 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	*memory[MAX_FD];
	char		*buffer;
	int			read_size;
	char		*tmp;

	read_size = 1;
	if ((read(fd, 0, 0) == -1) || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(ft_strchr(memory[fd], '\n')) && read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		tmp = memory[fd];
		memory[fd] = ft_strjoin(memory[fd], buffer);
		free(tmp);
	}
	free(buffer);
	*line = get_head(memory[fd]);
	memory[fd] = get_tail(memory[fd]);
	return (read_size ? 1 : 0);
}

char	*get_head(char *memory)
{
	char	*line;
	char	*ptr_n;

	if (!memory)
		return (NULL);
	ptr_n = NULL;
	if ((ptr_n = ft_strchr(memory, '\n')))
	{
		*ptr_n = '\0';
		line = ft_strdup(memory);
		*ptr_n = '\n';
	}
	else
		line = ft_strdup(memory);
	return (line);
}

char	*get_tail(char *memory)
{
	char	*ptr_n;
	char	*tmp;

	if (!memory)
		return (NULL);
	ptr_n = NULL;
	if ((ptr_n = ft_strchr(memory, '\n')))
	{
		tmp = memory;
		memory = ft_strdup(++ptr_n);
		free(tmp);
	}
	else
	{
		free(memory);
		return (NULL);
	}
	return (memory);
}
