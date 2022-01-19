/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:46:40 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/19 19:25:53 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	i_size(long long n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long long	nbr;

	nbr = n;
	str = (char *)malloc(sizeof(char) * (i_size(nbr) + 1));
	if (!str)
		return (0);
	i = i_size(n);
	str[i] = '\0';
	if (n < 0)
		nbr = -nbr;
	if (n == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--i] = nbr % 10 + 48;
		nbr /= 10;
	}
	return ((char *)str);
}
