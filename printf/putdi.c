/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:35:40 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:41 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_putd1flag_h(char *str, t_argue *s)
{
	if (s->nul && !s->pmod)
	{
		str = ft_strjoin(
			ft_a_z((s->width - ft_strlen(str) - 1), '0'), str);
		(s->nul == 1 && s->id == 'o') ? (str = ft_strjoin("0", str)) :
		(str = ft_strjoin(s->flag, str));
	}
	else
	{
		if (s->left)
		{
			((s->id != 'u') && (s->id != 'U')) ?
				(str = ft_strjoin(s->flag, str)) : 0;
			str = ft_strjoin(str,
				ft_a_z((s->width - ft_strlen(str)), ' '));
		}
		else
		{
			if (s->unsi != 1)
				str = ft_strjoin(s->flag, str);
			str = ft_strjoin(
				ft_a_z((s->width - ft_strlen(str)), ' '), str);
		}
	}
	return (str);
}

char			*ft_putd1flag(char *str, t_argue *s)
{
	if (s->width > ft_strlen(str) + 1)
		str = ft_putd1flag_h(str, s);
	else if ((s->flag) && (s->id != 'u') && (s->id != 'U')
			&& (s->id != 'o')
		&& (s->id != 'O') && (s->id != 'x') && (s->id != 'X'))
		str = ft_strjoin(s->flag, str);
	return (str);
}

char			*ft_putdnoflag_h(char *str, t_argue *s)
{
	if (s->hash == 1)
	{
		if (s->id == 'x' || s->id == 'X')
		{
			str = ft_strjoin(ft_a_z((s->width - ft_strlen(str) - 2), '0'), str);
			(s->id == 'x') ? (str = ft_strjoin("0x", str)) :
				(str = ft_strjoin("0X", str));
		}
		if (s->id == 'o' || s->id == 'O')
		{
			str = ft_strjoin(ft_a_z((s->width - ft_strlen(str) - 1), '0'), str);
			str = ft_strjoin("0", str);
		}
	}
	else
		str = ft_strjoin(ft_a_z((s->width - ft_strlen(str)), '0'), str);
	return (str);
}

char			*ft_putdnoflag(char *str, t_argue *s)
{
	if (s->nul)
		str = ft_putdnoflag_h(str, s);
	else
	{
		if (s->left)
			str = ft_strjoin(str, ft_a_z((s->width - ft_strlen(str)), ' '));
		else
			str = ft_strjoin(ft_a_z((s->width - ft_strlen(str)), ' '), str);
	}
	return (str);
}

int				ft_putdi(char *str, t_argue *s)
{
	if (ft_strcmp(str, "0") == 0)
		s->hash = 0;
	if ((ft_strcmp(str, "0") == 0) && s->pmod == 1 && s->pr == 0)
		str = "\0";
	str = ft_putd1step(str, s);
	if (s->flag != 0)
		str = ft_putd1flag(str, s);
	else if (s->width > ft_strlen(str))
		str = ft_putdnoflag(str, s);
	if (((s->id == 'x' || s->id == 'X') || ((s->id == 'o'
			|| s->id == 'O')
		&& (!s->hmod))) && (s->pr == 0) &&
			(s->pmod == 1) && (s->width == 0))
		return (0);
	if ((s->id == 'o' || s->id == 'O') && (ft_strcmp(str, "\0") == 0))
		str = "0";
	ft_putstr(str);
	s->ret += ft_strlen(str);
	return (0);
}
