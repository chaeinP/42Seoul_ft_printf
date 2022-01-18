/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:48:32 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/18 00:51:17 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*arr;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + 1;
	arr = (char *)malloc(sizeof(char) * len);
	if (!arr)
		return (0);
	return (ft_memcpy(arr, s1, len));
}
