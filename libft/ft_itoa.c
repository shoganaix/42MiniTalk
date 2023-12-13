/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:05:07 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:05:09 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	num_digits(int n)
{
	size_t	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	counter;
	int		s;

	counter = num_digits(n);
	str = malloc(sizeof(char) * (counter + 1));
	if (str == NULL)
		return (NULL);
	s = 1;
	str[counter] = '\0';
	counter--;
	if (n < 0)
	{
		str[0] = '-';
		s = -1;
	}
	else if (n == 0)
		str[counter] = '0';
	while (n != 0)
	{
		str[counter] = ((n % 10) * s) + 48;
		n = n / 10;
		counter--;
	}
	return (str);
}
