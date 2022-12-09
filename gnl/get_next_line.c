/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:24:42 by esalim            #+#    #+#             */
/*   Updated: 2022/12/08 12:11:16 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sm_getline(char *str)
{
	char	*newline;

	newline = sm_strchr(str, '\n');
	if (!str[0])
		return (NULL);
	if (!newline)
		return (sm_strdup(str));
	return (sm_substr(str, 0, newline - str + 1));
}

char	*sm_getbuffer(char *line)
{
	char	*buff;
	char	*newline;

	newline = sm_strchr(line, '\n');
	if (!newline)
		return (free(line), NULL);
	if (*(++newline))
	{
		buff = sm_strdup(newline);
		free(line);
		return (buff);
	}
	return (free(line), sm_strdup(""));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			n;

	n = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			n = 0;
		buff[n] = '\0';
		str = sm_strjoin(str, buff);
		if (sm_strchr(buff, '\n'))
			break ;
	}
	line = sm_getline(str);
	str = sm_getbuffer(str);
	return (line);
}
