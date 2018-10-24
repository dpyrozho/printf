/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoaandhelpfun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:35:24 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:27 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_a_z(int diff, char symv)
{
	char		*new;

	(diff < 0) ? (diff *= -1) : 0;
	new = malloc(sizeof(char) * (diff + 1));
	ft_nulls(new, diff, symv);
	new[diff] = '\0';
	return (new);
}

char			*ft_revstr(char *str)
{
	int			i;
	int			j;
	char		temp;

	i = ft_strlen(str) - 1;
	j = 0;
	while (j < i)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

char			*ft_itoabase(long long int ch, int base, int is_neg)
{
	int			i;
	char		*str;
	long long	temp;

	i = 0;
	if (ch < 0)
	{
		is_neg = 1;
		ch *= -1;
	}
	if (!(str = malloc(sizeof(char) * 50)))
		return (NULL);
	while (ch >= (long long)base)
	{
		temp = ch % base;
		str[i++] = temp >= 10 ? 'a' + temp - 10 : temp + '0';
		ch /= base;
	}
	temp = ch % base;
	str[i++] = temp >= 10 ? 'a' + temp - 10 : temp + '0';
	if (is_neg == 1 && base == 10)
		str[i] = '-';
	str[i + 1] = 0;
	return (ft_revstr(str));
}

char			*ft_itoabasepo(unsigned long ch, int base, t_argue *s)
{
	int			i;
	char		*str;
	long long	temp;

	i = 0;
	if (!(str = malloc(sizeof(char) * 50)))
		return (NULL);
	while (ch >= (unsigned long)base &&
		!(s->pr == 0 && s->pmod == 1))
	{
		temp = ch % base;
		str[i++] = temp >= 10 ? 'a' + temp - 10 : temp + '0';
		ch /= base;
	}
	temp = ch % base;
	if (!(s->pr == 0 && s->pmod == 1))
		str[i++] = temp >= 10 ? 'a' + temp - 10 : temp + '0';
	str[i + 1] = 0;
	if (s->pr > ft_strlen(str))
		str = ft_strjoin(str,
			ft_a_z((s->pr - ft_strlen(str)), '0'));
	if (!s->nul)
		str = ft_strjoin(str, "x0");
	return (ft_revstr(str));
}

char			*ft_itoabaseu(unsigned long long ch, t_argue *s, int i)
{
	char		*str;
	long long	temp;
	int			base;

	base = (s->id == 'x' || s->id == 'X') ? 16 : 8;
	base = (s->id == 'u' || s->id == 'U') ? 10 : base;
	if (!(str = malloc(sizeof(char) * 56)))
		return (NULL);
	while (ch >= (unsigned long long)base)
	{
		temp = ch % base;
		if (s->id == 'X' || s->id == 'O' || s->id == 'U')
			str[i++] = temp >= 10 ? 'A' + temp - 10 : temp + '0';
		if (s->id == 'x' || s->id == 'o' || s->id == 'u')
			str[i++] = temp >= 10 ? 'a' + temp - 10 : temp + '0';
		ch /= base;
	}
	temp = ch % base;
	if (s->id == 'X' || s->id == 'O' || s->id == 'U')
		str[i++] = temp >= 10 ? 'A' + temp - 10 : temp + '0';
	if (s->id == 'x' || s->id == 'o' || s->id == 'u')
		str[i++] = temp >= 10 ? 'a' + temp - 10 : temp + '0';
	str[i + 1] = 0;
	return (ft_revstr(str));
}
