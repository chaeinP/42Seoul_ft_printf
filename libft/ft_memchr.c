/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:55:10 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 04:15:58 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			uc;
	const unsigned char		*suc;

	i = 0;
	uc = (unsigned char)c;
	suc = (const unsigned char *)s;
	while (i < n)
	{
		if (suc[i] == uc)
			return ((void *)suc + i);
		i++;
	}
	return (0);
}
