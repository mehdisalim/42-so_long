/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:33:25 by esalim            #+#    #+#             */
/*   Updated: 2022/12/18 14:50:20 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*sm_strjoin(char *str, char *buff);
char	*sm_strchr(const char *s, int c);
char	*sm_substr(char *s, unsigned int start, size_t len);
char	*sm_strdup(char *s1);

#endif
