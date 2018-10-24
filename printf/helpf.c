/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:35:17 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/03/28 20:35:19 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_checker(char *str)
{
	int i;

	i = 0;
	if (ft_m(str, '%') != -1)
		i = ft_m(str, '%') + 1;
	else
		return (0);
	i = (str[i] != '\0' && str[i - 1] != '%') ? 0 : i;
	while (isnt_valid(str[i]))
		i++;
	if (str[i] == 's' || str[i] == 'S' || str[i] == 'c' || str[i] == 'C'
		|| str[i] == 'x' || str[i] == 'X' || str[i] == 'o' || str[i] == 'O'
		|| str[i] == 'u' || str[i] == 'U' || str[i] == 'p' || str[i] == 'd'
		|| str[i] == 'D' || str[i] == '%' || str[i] == 'i')
		return (i);
	if (str[i - 1] == 's' || str[i - 1] == 'S' || str[i - 1] == 'c'
		|| str[i - 1] == 'C' || str[i - 1] == 'x' || str[i - 1] == 'X'
		|| str[i - 1] == 'o' || str[i - 1] == 'O'
		|| str[i - 1] == 'u' || str[i - 1] == 'U' || str[i - 1] == 'p'
		|| str[i - 1] == 'd' || str[i - 1] == 'D' || str[i] == 'i')
		return (i);
	else
		return (0);
}

int				isnt_valid(char str)
{
	if (ft_strchr(FLAGS, str) != 0 || str == '.' ||
		ft_isdigit(str) != 0 || ft_strchr(NUM_TYPES, str) != 0)
		return (1);
	return (0);
}

int				ft_m(char const *s, char c)
{
	int			i;

	i = 0;
	while (s && s[i] != c && s[i])
		i++;
	return (((size_t)i == ft_strlen(s)) ? -1 : i);
}

void			ft_nulls(void *b, size_t len, char symv)
{
	while (len--)
		((unsigned char *)b)[len] = symv;
}
