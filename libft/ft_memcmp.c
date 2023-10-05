/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:02:07 by marcela           #+#    #+#             */
/*   Updated: 2023/09/21 16:59:02 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*conv_s1;
	unsigned char	*conv_s2;

	i = 0;
	conv_s1 = (unsigned char *)str1;
	conv_s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while ((conv_s1[i] != '\0' && conv_s2[i] != '\0')
		&& (conv_s1[i] == conv_s2[i]) && i < (n - 1))
		i++;
	return (conv_s1[i] - conv_s2[i]);
}
