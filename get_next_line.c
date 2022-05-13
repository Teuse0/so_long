/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:16:30 by broy              #+#    #+#             */
/*   Updated: 2022/04/22 15:01:19 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *save, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(save, buffer);
	free(save);
	return (temp);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		s[i + 1] = 0;
	}
	else
		s[i] = 0;
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save)
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(save) - i + 1);
	if (!str)
		return (NULL);
	i++;
	n = 0;
	while (save[i])
		str[n++] = save[i++];
	str[n] = 0;
	free(save);
	return (str);
}

char	*ft_read_file(int fd, char *save)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc(1 + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!(ft_strchr(save, '\n')) && i > 0)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		save = ft_free(save, buffer);
		if (!save)
			return (NULL);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0)
		return (NULL);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
