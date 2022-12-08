/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:25:05 by secker            #+#    #+#             */
/*   Updated: 2022/11/23 11:42:23 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*ft_strjoin2(char const *s1, char const *s2);
size_t			ft_strlen2(const char *s);
char			*ft_strchr2(const char *s, char c);
char			*ft_calloc2(size_t nmemb, size_t size);
void			ft_bzero2(void *s, size_t n);

#endif