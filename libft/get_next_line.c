/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:10:09 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:20:38 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *str)
{
	char	*array;
	int		bytes;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!array)
		return (NULL);
	bytes = -1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, array, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(array);
			return (NULL);
		}
		array[bytes] = '\0';
		str = ft_free_join(str, array);
	}
	free(array);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*s[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = ft_get_line(s[fd]);
	s[fd] = ft_new_line(s[fd]);
	return (line);
}
