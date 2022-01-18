/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:09:26 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/18 00:20:38 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c는 width와 -에만 영향을 받는다.
void	ft_convert_c(t_format *fmt, t_store *st)
{
	char	c;
	int		width;

	c = va_arg(fmt->ap, int);
	if (!st->width)
		width = 1;
	else
		width = st->width;
	st->argument = malloc(sizeof(char) * (width));
	if (!st->argument)
		return ;
	ft_memset(st->argument, ' ', width);
	if (st->left_alignment)
		st->argument[0] = c;
	else
		st->argument[width - 1] = c;
	st->len = width;
}
