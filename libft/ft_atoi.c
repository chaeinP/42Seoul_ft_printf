/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:01:57 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/15 01:37:39 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\v' || c == '\n'
		|| c == ' ' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			n;
	long long	result;
	long long	tmp;

	i = 0;
	n = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		tmp = result * 10 + str[i++] - 48;
		if (tmp < result && n == 1)
			return (-1);
		if (tmp < result && n == -1)
			return (0);
		result = tmp;
	}
	return (result * n);
}
