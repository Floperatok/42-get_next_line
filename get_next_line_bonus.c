/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:48:58 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/22 12:04:37 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	found_newline(char *buf)
{
	int	i;

	i = -1;
	if (!buf)
		return (i);
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*clean_stash(char *stash)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
		res[j++] = stash[i++];
	res[j] = '\0';
	free(stash);
	return (res);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		line_size;
	int		i;

	line_size = 0;
	while (stash[line_size] != '\n' && stash[line_size] != '\0')
		line_size++;
	if (stash[line_size] == '\0')
	{
		if (line_size == 0)
			return (NULL);
		return (ft_strdup(stash));
	}
	i = 0;
	line_size++;
	line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (NULL);
	while (i < line_size)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		readed;
	int		nl_index;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	nl_index = -1;
	while (readed > 0 && nl_index == -1)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[readed] = '\0';
		stash = ft_strjoin(stash, buf);
		nl_index = found_newline(buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
