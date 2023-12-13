/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:06:17 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:21:56 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*conv_str;

	i = 0;
	conv_str = (unsigned char *)str;
	while (conv_str[i] != '\0' && i < n)
	{
		if (conv_str[i] == (unsigned char)c)
			return (conv_str + i);
		i++;
	}
	return (NULL);
}
