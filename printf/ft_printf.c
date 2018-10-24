/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:10:19 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/01/29 13:10:20 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_bool_get_h(t_argue *s, char *str, int i, char *gets)
{
	ft_obnul(s, 'Q');
	gets = ft_strsub(str, ft_m(str, '%') + 1, i - 1);
	ft_get_precision(gets, s);
	ft_get_spec(gets, s);
	ft_putstri(ft_strsub(str, i, 1), s);
	return (0);
}

int				ft_boolinval1d(t_argue *s, char *str, int i)
{
	if (ft_strchr(str, '%'))
	{
		i = ft_m(str, '%');
		if (!str[i + 1])
			return (0);
		else
			i += 1;
	}
	else
	{
		ft_putstr(str);
		s->ret += ft_strlen(str);
		return (ft_strlen(str));
	}
	while (isnt_valid(str[i]))
		i++;
	if (ft_strchr(str, '%'))
	{
		ft_putstr(ft_strsub((char *)str, 0, ft_m(str, '%')));
		s->ret += ft_m(str, '%');
	}
	ft_bool_get_h(s, str, i, "0");
	if (ft_strchr(str, '%'))
		return (i + 1);
	return (i);
}

char			*ft_printf_h(t_argue *s, char *str, int boole)
{
	char		*newstr;

	s->ret += ft_strlen(ft_strsub((char *)str, 0, ft_m((char *)str, '%')));
	ft_putstr(ft_strsub((char *)str, 0, ft_m((char *)str, '%')));
	newstr = ft_strsub(str, ft_m((char *)str, '%'),
boole - ft_m((char *)str, '%') + 1);
	ft_get(newstr, s, str[boole]);
	free(newstr);
	str = ft_strsub(str, boole + 1, ft_strlen(str) - boole - 1);
	return (str);
}

int				ft_printf(const char *format, ...)
{
	char		*str;
	t_argue		s;
	int			boole;

	if (ft_strcmp(format, "%") == 0)
		return (0);
	s.ret = 0;
	str = ft_strdup((char*)format);
	va_start(s.g_ap, format);
	while (str && *str != '\0')
	{
		ft_obnul(&s, '\0');
		boole = ft_checker(str);
		if (boole != 0)
			str = ft_printf_h(&s, str, boole);
		else
		{
			boole = ft_boolinval1d(&s, str, 0);
			if ((size_t)boole == ft_strlen(str))
				break ;
			str = ft_strsub(str, boole, ft_strlen(str) - boole);
		}
	}
	va_end(s.g_ap);
	return (s.ret);
}
