/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:09:35 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/17 11:24:36 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*find_start_s1(char const *s1, char const *set)
{
	size_t	i;
	char	*start;

	i = 0;
	start = (char *)s1;
	while (start[i] && check_in_set(start[i], set))
		i++;
	return (start + i);
}

static char	*find_end_s1(char *start, char const *s1, char const *set)
{
	size_t	i;
	char	*end;

	i = ft_strlen(s1);
	end = (char *)(s1 + i);
	while (start < end && check_in_set(*(end - 1), set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*start;
	char	*end;
	char	*str;

	i = 0;
	start = find_start_s1(s1, set);
	end = find_end_s1(start, s1, set);
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	while (start < end)
		str[i++] = *start++;
	str[i] = '\0';
	return (str);
}
