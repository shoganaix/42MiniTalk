/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:42:00 by marcela           #+#    #+#             */
/*   Updated: 2023/09/21 16:59:06 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;

	i = 0;
	if ((!src && !dest))
		return (NULL);
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	while (i < n)
	{
		*(dest2 + i) = *(src2 + i);
		i++;
	}
	return (dest);
}
