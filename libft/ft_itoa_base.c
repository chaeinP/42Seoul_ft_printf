/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:46:40 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/19 19:24:07 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	i_size(unsigned long n, int base)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (1);
	while (n > (unsigned long)base - 1)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long n, char *s)
{
	char			*str;
	size_t			i;
	int				base;

	base = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (i_size(n, base) + 1));
	if (!str)
		return (0);
	i = i_size(n, base);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--i] = s[n % base];
		n /= base;
	}
	return ((char *)str);
}
