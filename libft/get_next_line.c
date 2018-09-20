/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 20:20:54 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/26 11:05:54 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(int const fd, char **str)
{
	char	*buff;
	char	*tmp;
	int		readchars;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	readchars = read(fd, buff, BUFF_SIZE);
	if (readchars > 0)
	{
		buff[readchars] = '\0';
		tmp = ft_strjoin(*str, buff);
		free(*str);
		*str = tmp;
	}
	free(buff);
	return (readchars);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*next_line;
	int			readchars;

	if ((!str && !(str = (char *)malloc(sizeof(*str)))) ||
			!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	next_line = ft_strchr(str, '\n');
	while (next_line == '\0')
	{
		readchars = ft_read(fd, &str);
		if (readchars < 0)
			return (-1);
		if (!readchars && !ft_strlen(str))
			return (0);
		if (!readchars)
			str = ft_strjoin(str, "\n");
		next_line = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(next_line));
	next_line = ft_strdup(next_line + 1);
	free(str);
	str = next_line;
	return (1);
}
