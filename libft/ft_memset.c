/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:24 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:07:26 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t			i;
	unsigned char	*conv_ptr;

	i = 0;
	conv_ptr = (unsigned char *)ptr;
	while (i < n)
	{
		conv_ptr[i] = c;
		i++;
	}
	return (ptr);
}
