/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:37:16 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/04/05 17:37:17 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_ustrdup(const char *s1)
{
	int		i;
	wchar_t	*cpy;

	i = 0;
	cpy = (wchar_t *)malloc(sizeof(wchar_t) * (ft_strlen(s1) + 1));
	if (!cpy || !s1)
		return (0);
	while (s1[i] != 0)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

size_t		ft_ustrlen(wchar_t *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
