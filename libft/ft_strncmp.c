/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:38:34 by marcela           #+#    #+#             */
/*   Updated: 2023/09/21 17:00:10 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = n;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && str1[i] != '\0'
		&& str2[i] != '\0' && len - 1 > 0)
	{
		i++;
		len--;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
