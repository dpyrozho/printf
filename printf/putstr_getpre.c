/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_getpre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:35:47 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:48 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_prec_help(char *dot, int now, t_argue *s, char *newgets)
{
	dot += 1;
	(now != 1) ? s->width = ft_atoi(newgets) : 0;
	s->pr = ft_atoi(ft_strjoin(dot, "\0"));
	s->nul = 0;
	s->dot = 1;
	s->pmod = 1;
	return (0);
}

int				ft_get_precision(char *g, t_argue *s)
{
	char		*dot;
	int			now;
	char		*newgets;

	dot = "\0";
	now = 0;
	newgets = g;
	while (*newgets == ' ' || *newgets == 48)
		newgets++;
	(ft_m(g, s->id) > (ft_strchr(g, '.') - g)) ? dot = ft_strchr(g, '.') : 0;
	(*newgets == '0') ? newgets++ : 0;
	while (*newgets && (*newgets != s->id))
	{
		(newgets == dot) ? now = 1 : 0;
		if (ft_isdigit(*newgets))
			break ;
		newgets++;
	}
	if (*newgets == s->id && s->id == 's')
		return (0);
	(dot != '\0') ? ft_prec_help(dot, now, s, newgets) : 0;
	ft_prec_part2(dot, newgets, s, g);
	return (0);
}

char			*ft_putstrwid(char *str, t_argue *s)
{
	if (s->nul)
		str = ft_strjoin(ft_a_z((s->width - ft_strlen(str)), '0'), str);
	else
	{
		if (s->left)
			str = ft_strjoin(str, ft_a_z((s->width - ft_strlen(str)), ' '));
		else
			str = ft_strjoin(ft_a_z((s->width - ft_strlen(str)), ' '), str);
	}
	return (str);
}

int				ft_putstri(char *str, t_argue *s)
{
	if ((ft_strcmp(str, "") == 0) && (!s->width || s->width == 1))
		return (0);
	if ((s->pr < ft_strlen(str)) && (s->id != 'p')
		&& (s->id != '%') && (s->id != 'Q'))
		if ((s->dot != 0) && (s->pmod == 1) && s->id != '\0')
			str = ft_strsub(str, 0, s->pr);
	if (s->width > ft_strlen(str) + 1)
	{
		if (s->nul)
		{
			(s->id == 'p') ? (str =
	ft_strjoin(ft_a_z((s->width - ft_strlen(str) - 2), '0'), str)) :
	(str = ft_strjoin(ft_a_z((s->width - ft_strlen(str)), '0'), str));
			if (s->id == 'p' && s->nul)
			{
				str = ft_strjoin("0x", str);
				s->nul = 0;
			}
		}
		if (s->left)
			str = ft_strjoin(str, ft_a_z((s->width - ft_strlen(str)), ' '));
	}
	ft_ps_h(str, s);
	return (0);
}

int				ft_ftosubafter(char *gets, char id, int i, t_argue *s)
{
	char		*str;

	while (gets[i] != id && gets[i] != '\0')
		i++;
	str = ft_strsub(gets, i + 1, ft_strlen(gets) - i);
	ft_putstr(str);
	s->ret += ft_strlen(str);
	return (0);
}
