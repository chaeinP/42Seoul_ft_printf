/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:08:05 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/13 17:29:22 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dstc;
	const unsigned char	*srcc;

	i = -1;
	dstc = (unsigned char *)dst;
	srcc = (const unsigned char *)src;
	if (dstc == srcc || len == 0)
		return (dst);
	if (srcc < dstc)
	{
		while (len--)
			dstc[len] = srcc[len];
	}
	else
	{
		while (++i < len)
			dstc[i] = srcc[i];
	}
	return (dst);
}
