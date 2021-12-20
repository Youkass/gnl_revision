/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:42:44 by yobougre          #+#    #+#             */
/*   Updated: 2021/12/20 21:39:14 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *line)
{
	char	*output;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = ft_strchr(line, '\n');
	if (!line[i] || !line[i + 1])
		return (free(line), NULL);
	i++;
	output = malloc(sizeof(char) * (ft_strlen(line + i) + 1));
	if (!output)
		return (free(line), NULL);
	j = 0;
	while (line[i + j])
	{
		output[j] = line[i + j];
		++j;
	}
	output[j] = '\0';
	return (free(line), output);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*buff;
	char		*output;
	int			read_file;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (NULL);
	read_file = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (read_file && (!(ft_strchr(line, '\n'))))
	{
		read_file = read(fd, buff, BUFFER_SIZE);
		buff[read_file] = 0;
		if (read_file <= 0)
			break ;
		line = ft_strjoin_pimp(line, buff);
	}
	output = ft_strdup_pimp(line);
	line = ft_next_line(line);
	return (free(buff), output);
}

int main(void)
{
	char	*tmp;
	int		read_f;
	
	read_f = open("text.txt", O_RDONLY);
	if (!read_f)
		exit(1);
	tmp = get_next_line(read_f);
	printf("%s", tmp);
	/*while (tmp)
	{
		printf("%s", tmp);
		free(tmp);
		tmp = get_next_line(read_f);
	}*/
	free(tmp);
	close(read_f);
}
