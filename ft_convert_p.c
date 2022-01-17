/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:49:56 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/17 23:01:11 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_p(t_format *fmt, t_store *st)
{
	void	*ptr;
	char	*s;
	char	*temp;
	int		len;

	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		s = "0";
	else
		s = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	temp = s;
	s = ft_strjoin("0x", s);
	len = ft_strlen(s);
	st->argument = malloc(sizeof(char) * len + 3);
	ft_strlcpy(st->argument, s, len + 1);
	st->len = ft_strlen(st->argument);
	free(temp);
}
