/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:47:17 by mmago             #+#    #+#             */
/*   Updated: 2021/11/30 17:48:52 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *full)
{
	char	*str;
	int		i;

	i = 0;
	if (!full[i])
		return (NULL);
	while (full[i] && full[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (full[i] && full[i] != '\n')
	{
		str[i] = full[i];
		i++;
	}
	if (full[i] == '\n')
	{
		str[i] = full[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_full(char *full)
{
	int		i;
	int		o;
	char	*str;

	i = 0;
	while (full[i] && full[i] != '\n')
		i++;
	if (!full[i])
	{
		free(full);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(full) - i + 1));
	if (!str)
		return (NULL);
	i++;
	o = 0;
	while (full[i])
		str[o++] = full[i++];
	str[o] = '\0';
	free(full);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *full, char *buff)
{
	char	*str;
	size_t	i;
	size_t	o;

	if (!full)
	{
		full = malloc(sizeof(char) * 1);
		full[0] = '\0';
	}
	if (!full || !buff)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_strlen(full) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	o = 0;
	if (full)
		while (full[++i] != '\0')
			str[i] = full[i];
	while (buff[o] != '\0')
		str[i++] = buff[o++];
	str[ft_strlen(full) + ft_strlen(buff)] = '\0';
	free(full);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
