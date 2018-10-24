/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:35:34 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:35 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_putd1step(char *str, t_argue *s)
{
	if (((s->id == 'x' || s->id == 'X') ||
((s->id == 'o' || s->id == 'O') && (!s->hmod))) && (s->pr == 0) &&
(ft_strcmp(str, "0") == 0) && (s->pmod == 1))
		str = " ";
	if ((s->id == 'd' || s->id == 'D' || s->id == 'i') && (s->pr == 0)
		&& (s->pmod == 1) && (ft_strcmp(str, "0") == 0))
		str = "\0";
	if (s->pr > ft_strlen(str))
	{
		if (s->hash && (s->id == 'o' || s->id == 'O'))
			str = ft_strjoin(
ft_a_z((s->pr - ft_strlen(str) - 1), '0'), str);
		else
			str = ft_strjoin(
					ft_a_z((s->pr - ft_strlen(str)), '0'), str);
	}
	if ((s->hash == 1) && (!s->nul))
	{
		if ((s->id == 'x' || s->id == 'X') && (ft_strcmp(str, "0") != 0))
			(s->id == 'x') ? (str = ft_strjoin("0x", str)) :
				(str = ft_strjoin("0X", str));
		if ((s->id == 'o' || s->id == 'O') && (ft_strcmp(str, "0")))
			str = ft_strjoin("0", str);
	}
	return (str);
}

unsigned long int		ft_decem_unsi(t_argue *s)
{
	unsigned long long	arg;

	arg = 0;
	if ((s->id == 'D' || s->id == 'U' || s->id == 'O')
		&& ft_strncmp(s->type, "ll", 2) != 0)
		s->type = "l";
	if (ft_strncmp(s->type, "ll", 2) == 0)
		arg = va_arg(s->g_ap, unsigned long long);
	else if (ft_strncmp(s->type, "l", 1) == 0)
		arg = va_arg(s->g_ap, unsigned long int);
	else if (ft_strncmp(s->type, "hh", 2) == 0)
		arg = (unsigned char)va_arg(s->g_ap, int);
	else if (ft_strncmp(s->type, "h", 1) == 0)
		arg = (unsigned short int)va_arg(s->g_ap, unsigned int);
	else if (ft_strncmp(s->type, "j", 1) == 0)
		arg = va_arg(s->g_ap, uintmax_t);
	else if (ft_strncmp(s->type, "z", 1) == 0)
		arg = va_arg(s->g_ap, size_t);
	else if (!arg)
		arg = (unsigned)va_arg(s->g_ap, long long int);
	return (arg);
}

long long int			ft_decem_sign(t_argue *s, long long int arg)
{
	if (ft_strncmp(s->type, "ll", 2) == 0)
		arg = va_arg(s->g_ap, long long);
	else if (ft_strncmp(s->type, "l", 1) == 0)
		arg = va_arg(s->g_ap, long int);
	else if (ft_strncmp(s->type, "hh", 2) == 0)
		arg = (signed char)va_arg(s->g_ap, int);
	else if (ft_strncmp(s->type, "h", 1) == 0)
		arg = (short int)va_arg(s->g_ap, int);
	else if (ft_strncmp(s->type, "j", 1) == 0)
		arg = va_arg(s->g_ap, intmax_t);
	else if (ft_strncmp(s->type, "z", 1) == 0)
		arg = va_arg(s->g_ap, size_t);
	else if (s->id == 'O')
		arg = va_arg(s->g_ap, unsigned long long int);
	else if (!arg)
		arg = va_arg(s->g_ap, int);
	if ((arg < 0) && (s->id != 'u') && (s->id != 'U')
		&& (s->id != 'x') && (s->id != 'X'))
	{
		arg *= -1;
		s->flag = "-";
	}
	return (arg);
}

int						ft_decemical(t_argue *s)
{
	char				*str;
	long long int		arg;
	unsigned long long	arg1;

	arg = 0;
	arg1 = 0;
	if ((s->id == 'D' || s->id == 'U' || s->id == 'O')
		&& ft_strncmp(s->type, "ll", 2) != 0)
		s->type = "l";
	if (s->unsi == 1)
		arg1 = ft_decem_unsi(s);
	else
		arg = ft_decem_sign(s, arg);
	if (arg < -9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		s->ret += 20;
		return (0);
	}
	str = (s->unsi == 0) ? ft_itoabase(arg, 10, 0) :
		ft_itoabaseu(arg1, s, 0);
	ft_putdi(str, s);
	return (0);
}
