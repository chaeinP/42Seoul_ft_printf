/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:27:51 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 04:27:51 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	uc;

	len = ft_strlen(s);
	uc = (char)c;
	while (len)
	{
		if (s[len] == uc)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == uc)
		return ((char *)&s[len]);
	return (0);
}
