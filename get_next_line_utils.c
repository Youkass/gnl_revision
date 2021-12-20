/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:43:11 by yobougre          #+#    #+#             */
/*   Updated: 2021/12/20 21:39:15 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup_pimp(char *s)
{
	char	*output;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	output = malloc(sizeof(char) * (ft_strchr(s, '\n') + 1));
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = s[i];
		i++;
		if (output[i - 1] == '\n')
			break ;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strjoin_pimp(char *s1, char *s2)
{
	char	*output;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup_pimp("\0");
	if (!s2)
		return (NULL);
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		output[i + j] = s2[j];
		++j;
	}
	output[i + j] = '\0';
	return (free(s1), output);
}
