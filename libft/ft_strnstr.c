/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 02:05:19 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/16 01:00:26 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*hay;

	i = 0;
	if (!haystack && !len)
		return (0);
	needle_len = ft_strlen(needle);
	hay = (char *)haystack;
	if (!needle_len)
		return (hay);
	while (hay[i] && len >= needle_len)
	{
		if (!ft_memcmp(&hay[i], needle, needle_len))
			return ((char *)hay + i);
		i++;
		len--;
	}
	return (0);
}
