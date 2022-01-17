/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:33:01 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 04:26:35 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*suc1;
	const unsigned char	*suc2;

	i = 0;
	suc1 = (const unsigned char *)s1;
	suc2 = (const unsigned char *)s2;
	while ((suc1[i] || suc2[i]) && i < n)
	{
		if (suc1[i] != suc2[i])
			return ((suc1[i] - suc2[i]));
		i++;
	}
	return (0);
}
