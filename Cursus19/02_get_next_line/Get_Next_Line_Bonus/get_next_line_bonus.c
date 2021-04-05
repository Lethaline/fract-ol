/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:07:09 by llemmens          #+#    #+#             */
/*   Updated: 2021/04/05 04:48:13 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check(int fd, char **line);

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr && *ptr != c)
		ptr++;
	if (*ptr == c)
		return (ptr);
	else
		return (NULL);
}

static int	ft_ajoutline(char **s, char **line)
{
	int				len;
	char			*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	ft_output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !ft_strchr(s[fd], '\n'))
	{
		*line = ft_strdup(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	else
		return (ft_ajoutline(&s[fd], line));
}

int	get_next_line(int fd, char **line)
{
	int				ret;
	static char		*s[FOPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;

	ft_check(fd, line);
	while (!ft_strchr(s[fd], '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (!(ret > 0))
			return (ft_output(s, line, ret, fd));
		if (buff[0] == '\0')
			return (0);
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
	}
	return (ft_output(s, line, ret, fd));
}

int	ft_check(int fd, char **line)
{
	if (BUFFER_SIZE < 1)
		return (-1);
	if (fd < 0 || line == NULL)
		return (-1);
	return (1);
}
