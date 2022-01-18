/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:24:22 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/18 13:54:32 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_left(char **arg, char pad, int width)
{
	char	*temp;
	int		arglen;
	int		padlen;

	arglen = ft_strlen(*arg);
	if (!width || width < arglen)
		width = arglen;
	temp = malloc(sizeof(char) * (width + 1));
	if (!temp)
		return ;
	padlen = width - arglen;
	ft_memset(temp, pad, padlen);
	temp[padlen] = '\0';
	ft_strlcat(temp, *arg, width + 1);
	free(*arg);
	*arg = temp;
}

void	ft_add_right(char **arg, char pad, int width)
{
	char	*temp;
	int		arglen;
	int		padlen;

	arglen = ft_strlen(*arg);
	if (!width || width < arglen)
		width = arglen;
	temp = malloc(sizeof(char) * (width + 1));
	if (!temp)
		return ;
	padlen = width - arglen;
	ft_strlcpy(temp, *arg, arglen + 1);
	ft_memset(&temp[arglen], pad, padlen);
	temp[width] = '\0';
	free(*arg);
	*arg = temp;
}

void	ft_add_prefix(t_store *st, int sign)
{
	int	len;

	len = ft_strlen(st->argument);
	if (st->type == 'd' || st->type == 'i')
	{
		if (ft_strchr(st->prefix, '+') && sign == 1)
			ft_add_left(&st->argument, '+', len + 1);
		else if (ft_strchr(st->prefix, ' ') && sign == 1)
			ft_add_left(&st->argument, ' ', len + 1);
		else if (sign == -1)
			ft_add_left(&st->argument, '-', len + 1);
	}
	else if (st->type == 'x' || st->type == 'X')
		ft_add_prefix_x(st);
}

void	ft_add_prefix_x(t_store *st)
{
	char	*temp;

	temp = st->argument;
	if (ft_strchr(st->prefix, '#'))
	{
		if (st->type == 'x')
		{
			st->argument = ft_strjoin("0x", temp);
			free(temp);
		}
		else if (st->type == 'X')
		{
			st->argument = ft_strjoin("0X", temp);
			free(temp);
		}
	}
}
