/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmens <llemmens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:55:39 by llemmens          #+#    #+#             */
/*   Updated: 2021/04/05 02:18:20 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sect;
	char			*str;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	sect = (char *)malloc(sizeof(char) * (len + 1));
	if (sect == 0)
		return (NULL);
	while (i < (len + 1))
	{
		sect[i] = '\0';
		i++;
	}
	i = 0;
	while (str != NULL && str[i + start] && len--)
	{
		sect[i] = str[i + start];
		i++;
	}
	sect[i] = '\0';
	return (sect);
}

char	*ft_strdup(const char *s1)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == 0)
		return (NULL);
	while (i < (ft_strlen(s1) + 1))
	{
		dest[i] = '\0';
		i++;
	}
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	char			*str1;
	char			*str2;
	size_t			len;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = ft_strlen(str1) + ft_strlen(str2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (NULL);
	while (*str1)
		*(dst++) = *(str1++);
	while (*str2)
		*(dst++) = *(str2++);
	*dst = '\0';
	return (dst - len);
}

size_t	ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s && s[len] != '\0')
		len++;
	return (len);
}
