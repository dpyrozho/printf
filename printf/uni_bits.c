/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:37:24 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/04/05 17:37:25 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_manybits(wchar_t symv, t_argue *s)
{
	ft_putchar((symv >> 18) + 0xF0);
	ft_putchar(((symv >> 12) & 0x3F) + 0x80);
	ft_putchar(((symv >> 6) & 0x3F) + 0x80);
	ft_putchar((symv & 0x3F) + 0x80);
	s->ret += 4;
	return (0);
}

int					ft_3bits(wchar_t symv, t_argue *s)
{
	ft_putchar((symv >> 12) + 0xE0);
	ft_putchar(((symv >> 6) & 0x3F) + 0x80);
	ft_putchar((symv & 0x3F) + 0x80);
	s->ret += 3;
	return (0);
}

int					ft_twobits(wchar_t symv, t_argue *s)
{
	if (s->width == 1)
		s->width--;
	if (s->width != 0)
		s->width = s->width - 2;
	ft_putchar((symv >> 6) + 0xC0);
	ft_putchar((symv & 0x3F) + 0x80);
	s->ret += 2;
	return (0);
}

int					ft_onebit(wchar_t symv, t_argue *s)
{
	unsigned char	oct;

	oct = symv;
	write(1, &oct, 1);
	s->ret += 1;
	return (0);
}

int					ft_checkbitz(wchar_t str, t_argue *s, unsigned chr_len)
{
	unsigned int	ch;

	ch = str;
	if (ch == 4294967234)
	{
		ch = 0;
		str = 0;
	}
	if (chr_len == 1)
		ft_onebit(str, s);
	else if (chr_len == 2)
		ft_twobits(str, s);
	else if (chr_len == 3)
		ft_3bits(str, s);
	else
		ft_manybits(str, s);
	return (0);
}
