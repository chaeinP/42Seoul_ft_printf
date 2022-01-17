/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:44:35 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/17 20:45:37 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//width < arglen 무시
//width > arglen 공백 생김
//.precision < arglen 문장 잘림
//.precision > arglen, arglen 그대로 나옴
//.* <= -1 .precision 무시됨
// width랑 precision 같이 썼을 때
// width > precision 이면 문장은 precision에 맞게 문장 총길이는 width 에 맞게
// printf("%5.2s","123"); "   12"

void	ft_convert_s(t_format *fmt, t_store *st)
{
	char	*s;
	int		len;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	if (st->precision > -1)
		len = st->precision;
	else
		len = ft_strlen(s);
	st->argument = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(st->argument, s, len + 1);
	if (!st->left_alignment)
		ft_add_left(&st->argument, ' ', st->width);
	else
		ft_add_right(&st->argument, ' ', st->width);
	st->len = ft_strlen(st->argument);
	free(s);
}
