/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:08:07 by mmago             #+#    #+#             */
/*   Updated: 2021/11/30 18:20:41 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_full(int fd, char *full);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *full, char *buff);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *full);
char	*ft_new_full(char *full);

#endif
