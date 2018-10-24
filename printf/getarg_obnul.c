/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg_obnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:34:57 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:00 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_stri(t_argue *s)
{
	char		*str;

	str = va_arg(s->g_ap, char *);
	if (!str)
	{
		ft_putstri(ft_strdup("(null)"), s);
		return (0);
	}
	ft_putstri(str, s);
	return (0);
}

int				ft_charik(t_argue *s)
{
	char		str[2];

	str[0] = va_arg(s->g_ap, int);
	str[1] = '\0';
	s->pr = 1;
	if (str[0] == '\0')
	{
		(s->width) ? s->width-- : 0;
		while (s->width--)
		{
			(s->nul == 1) ? ft_putchar('0') : ft_putchar(' ');
			s->ret += 1;
		}
		ft_putchar('\0');
		s->ret += 1;
		return (0);
	}
	ft_putstri(str, s);
	return (0);
}

int				ft_point(t_argue *s)
{
	unsigned long	poi;
	char			*str;

	poi = (unsigned long)va_arg(s->g_ap, void *);
	str = ft_itoabasepo(poi, 16, s);
	ft_putstri(str, s);
	return (0);
}

int				ft_get_arg(t_argue *s, char id)
{
	if ((id == 'd') || (id == 'i') || (id == 'D') || (id == 'o') || (id == 'O')
		|| (id == 'X') || (id == 'x') || (id == 'u') || (id == 'U'))
		ft_decemical(s);
	if (id == 'S' || (id == 's' && (ft_strcmp(s->type, "l") == 0)))
		ft_unis(s);
	if ((id == 's') && (ft_strcmp(s->type, "l") != 0))
		ft_stri(s);
	if (id == 'C' || (id == 'c' && (ft_strncmp(s->type, "l", 1) == 0)))
		ft_unic(s);
	if ((id == 'c') && (ft_strncmp(s->type, "l", 1) != 0))
		ft_charik(s);
	if (id == 'p')
		ft_point(s);
	if (id == '%')
		ft_putstri("%", s);
	return (0);
}

int				ft_obnul(t_argue *s, char id)
{
	s->unsi = 0;
	s->type = 0;
	if ((id == 'u') || (id == 'o') || (id == 'x') || (id == 'X')
		|| (id == 'O') || id == 'U')
		s->unsi = 1;
	if (s->id == 'D' || s->id == 'U' || s->id == 'O')
		s->type = "l";
	s->left = 0;
	s->pr = 0;
	s->width = 0;
	s->flag = 0;
	s->nul = 0;
	s->id = 0;
	s->hash = 0;
	s->dot = 0;
	s->pmod = 0;
	s->hmod = 0;
	return (0);
}
