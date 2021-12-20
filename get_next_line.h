/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:43:07 by yobougre          #+#    #+#             */
/*   Updated: 2021/12/20 21:39:16 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
char	*ft_strjoin_pimp(char *s1, char *s2);
char	*ft_strdup_pimp(char *s);
char	*ft_next_line(char *line);
size_t	ft_strlen(char *s);

#endif
