/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:36:44 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/13 16:34:59 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstuc;
	const unsigned char	*srcuc;

	i = 0;
	dstuc = (unsigned char *)dst;
	srcuc = (const unsigned char *)src;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dstuc[i] = srcuc[i];
		i++;
	}
	return (dst);
}
