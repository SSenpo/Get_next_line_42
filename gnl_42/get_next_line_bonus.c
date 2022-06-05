/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:53:55 by mmago             #+#    #+#             */
/*   Updated: 2021/11/30 19:32:45 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_to_full(int fd, char *full)
{
	char		*buff;
	int			rd_b;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_b = 1;
	while (!ft_strchr(full, '\n') && rd_b != 0)
	{
		rd_b = read(fd, buff, BUFFER_SIZE);
		if (rd_b == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_b] = '\0';
		full = ft_strjoin(full, buff);
	}
	free(buff);
	return (full);
}

char	*get_next_line(int fd)
{
	static char	*full[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	full[fd] = read_to_full(fd, full[fd]);
	if (!full[fd])
		return (NULL);
	line = ft_strdup(full[fd]);
	full[fd] = ft_new_full(full[fd]);
	return (line);
}
