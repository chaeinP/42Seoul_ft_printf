/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:02:34 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 04:32:23 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	char	*suc;
	size_t	suc_len;
	size_t	i;

	i = 0;
	suc = (char *)s;
	suc_len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	if (start < suc_len)
	{
		while (suc[start] && i < len)
			arr[i++] = suc[start++];
	}
	arr[i] = '\0';
	return ((char *)arr);
}
