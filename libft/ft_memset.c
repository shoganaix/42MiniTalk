/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:25:40 by marcela           #+#    #+#             */
/*   Updated: 2023/09/21 16:58:19 by msoriano         ###   ########.fr       */
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
