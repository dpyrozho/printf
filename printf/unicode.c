/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:37:09 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/04/05 17:37:11 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_unic(t_argue *s)
{
	wchar_t			*str;
	wchar_t			chr;
	unsigned		chr_len;

	str = (wchar_t*)malloc(sizeof(wchar_t) * 2);
	str[0] = va_arg(s->g_ap, wchar_t);
	if (str[0] == 0)
		str[0] = '\302';
	chr = str[0];
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	str[1] = 0;
	ft_checkbitz(str[0], s, chr_len);
	return (0);
}

int					ft_unis_h_f(t_argue *s, wchar_t *str, int i)
{
	wchar_t			chr;
	unsigned		chr_len;
	unsigned int	wi;

	wi = 0;
	while (str[++i])
	{
		chr = str[i];
		if (chr <= 0x7F)
			chr_len = 1;
		else if (chr <= 0x7FF)
			chr_len = 2;
		else if (chr <= 0xFFFF)
			chr_len = 3;
		else if (chr <= 0x10FFFF)
			chr_len = 4;
		else
			chr_len = 0;
		wi += chr_len;
	}
	ft_unis_h_fp2(s, str, wi);
	return (0);
}

int					ft_unis_h_p2(t_argue *s, wchar_t *str, int i, unsigned wi)
{
	wchar_t			chr;
	unsigned		chr_len;

	while (str[++i] && (wi > 0))
	{
		chr = str[i];
		if (chr <= 0x7F)
			chr_len = 1;
		else if (chr <= 0x7FF)
			chr_len = 2;
		else if (chr <= 0xFFFF)
			chr_len = 3;
		else if (chr <= 0x10FFFF)
			chr_len = 4;
		else
			chr_len = 0;
		if (s->pr < chr_len)
			return (0);
		wi = wi - chr_len;
		ft_checkbitz(str[i], s, chr_len);
	}
	return (0);
}

int					ft_unis_h(t_argue *s, wchar_t *str, int i)
{
	wchar_t			chr;
	unsigned		chr_len;
	unsigned		wi;

	wi = 0;
	while (str[++i] && (wi <= s->pr))
	{
		chr = str[i];
		if (chr <= 0x7F)
			chr_len = 1;
		else if (chr <= 0x7FF)
			chr_len = 2;
		else if (chr <= 0xFFFF)
			chr_len = 3;
		else if (chr <= 0x10FFFF)
			chr_len = 4;
		else
			chr_len = 0;
		wi += chr_len;
		if (wi >= s->width)
			break ;
	}
	ft_unis_h_p2(s, str, i, wi);
	return (0);
}

int					ft_unis(t_argue *s)
{
	wchar_t			*str;
	int				i;

	i = -1;
	str = va_arg(s->g_ap, wchar_t *);
	if (!str)
		str = ft_ustrdup("(null)");
	if (ft_ustrlen(str) > s->width && ((s->pr > s->width) || !s->pmod))
		s->width = 0;
	if (s->pr == 0 && s->pmod == 1)
	{
		ft_putstri("\0", s);
		return (0);
	}
	if (s->pmod != 1)
		ft_unis_h_f(s, str, i);
	else
		ft_unis_h(s, str, i);
	return (0);
}
