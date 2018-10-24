/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:39:29 by dpyrozho          #+#    #+#             */
/*   Updated: 2017/11/14 16:39:30 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strword(char const *str, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		while (str[i] == c)
			i++;
	}
	return (words);
}

static int	ft_strwordlen(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dabmas;
	int		i;
	int		j;
	int		words;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	words = ft_strword(s, c);
	dabmas = (char**)malloc(sizeof(char*) * (words + 1));
	if (!dabmas)
		return (NULL);
	while (i < words && *s != '\0')
	{
		while (*s == c)
			s++;
		dabmas[i] = (char*)malloc(sizeof(char) * (ft_strwordlen(s, c) + 1));
		dabmas[i][ft_strwordlen(s, c)] = '\0';
		ft_strncpy(dabmas[i], s, ft_strwordlen(s, c));
		s += ft_strwordlen(s, c);
		i++;
	}
	dabmas[i] = 0;
	return (dabmas);
}
