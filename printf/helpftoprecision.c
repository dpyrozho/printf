/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpftoprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:07:22 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/04/20 19:07:23 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_prec_part2(char *dot, char *newgets, t_argue *s, char *g)
{
	if (dot == '\0')
		(ft_isdigit(newgets[0]) != 1) ? (s->width = ft_atoi(g)) :
		(s->width = ft_atoi(newgets));
	if ((!dot) && (!s->width) && (s->id != 's'))
		s->width = 1;
	return (0);
}

int					ft_ps_h(char *str, t_argue *s)
{
	if (s->id == 'p' && s->nul)
		str = ft_strjoin("0x", str);
	if (s->width > ft_strlen(str))
		str = ft_putstrwid(str, s);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	return (0);
}

int					ft_unis_h_fp2(t_argue *s, wchar_t *str, unsigned int wi)
{
	wchar_t			chr;
	int				i;
	unsigned		chr_len;

	i = -1;
	(wi > s->width) ? (s->width = 0) : (s->width -= wi);
	(!s->left) ? ft_putstri("\0", s) : 0;
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
		ft_checkbitz(str[i], s, chr_len);
	}
	(s->left) ? ft_putstri("\0", s) : 0;
	return (0);
}
