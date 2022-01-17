/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:48:32 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 19:48:48 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*arr;

	len = ft_strlen(s1) + 1;
	arr = (char *)malloc(sizeof(char) * len);
	if (!arr)
		return (0);
	return (ft_memcpy(arr, s1, len));
}
