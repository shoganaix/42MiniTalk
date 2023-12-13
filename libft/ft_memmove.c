/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:18 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:07:20 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!src && !dest)
		return (NULL);
	if (src < dest)
	{
		while (n != 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else if (src > dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
