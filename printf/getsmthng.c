/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsmthng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:35:06 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:07 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_get_spec_h(char *gets, t_argue *s, int i)
{
	if (gets[i] == '+')
		s->flag = "+";
	if (gets[i] == '-')
	{
		s->left = 1;
		s->nul = 0;
	}
	if (gets[i] == '#')
	{
		s->hash = 1;
		s->hmod = 1;
	}
	if ((gets[i] == '0') && (s->left != 1) && (!s->pr))
		s->nul = 1;
	if ((gets[i] == '0') && (s->left != 1) && (s->id == 's' ||
	s->id == '%'))
		s->nul = 1;
	if (((gets[i] == ' ') && (!s->flag)))
		s->flag = " ";
	return (0);
}

int				ft_get_spec(char *gets, t_argue *s)
{
	int			i;

	i = 0;
	while (gets[i] == '#' || gets[i] == ' ' || gets[i] == '0'
		|| gets[i] == '+' || gets[i] == '-')
	{
		ft_get_spec_h(gets, s, i);
		i++;
	}
	return (0);
}

int				ft_get_type(char *gets, t_argue *s)
{
	char		**arr;
	int			i;

	arr = NULL;
	arr = ft_strsplit(NUM_TYPES, ' ');
	s->type = "";
	i = -1;
	while (arr[++i])
		if (ft_strstr(gets, arr[i]) != 0)
		{
			s->type = ft_strjoin(s->type, arr[i]);
			break ;
		}
	i = -1;
	while (arr[++i])
		ft_strdel(&arr[i]);
	free(arr);
	return (0);
}

int				ft_get(char *gets, t_argue *s, char id)
{
	if (gets && *gets == '%')
		gets++;
	ft_obnul(s, id);
	s->id = id;
	ft_get_precision(gets, s);
	ft_get_spec(gets, s);
	ft_get_type(gets, s);
	ft_get_arg(s, id);
	ft_ftosubafter(gets, id, 0, s);
	return (0);
}
