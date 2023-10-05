/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:12:31 by marcela           #+#    #+#             */
/*   Updated: 2023/09/21 17:00:18 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*new_str;

	if (*s1 == '\0' || *set == '\0')
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg++;
	end = ft_strlen(s1 + beg);
	while (s1[beg + end - 1] != '\0' && ft_strchr(set, s1[beg + end - 1])
		!= NULL)
		end--;
	new_str = malloc(sizeof(char) * (end + 1));
	if (!new_str)
		return (NULL);
	ft_strncpy(new_str, (s1 + beg), end);
	return (new_str);
}
