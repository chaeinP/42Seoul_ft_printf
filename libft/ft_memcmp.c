/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 02:00:03 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 01:49:00 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*suc1;
	const unsigned char	*suc2;
	size_t				i;

	suc1 = s1;
	suc2 = s2;
	i = 0;
	while (i < n)
	{
		if (suc1[i] != suc2[i])
			return (suc1[i] - suc2[i]);
		i++;
	}
	return (0);
}
