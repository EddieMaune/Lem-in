/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:02:59 by exam              #+#    #+#             */
/*   Updated: 2018/08/26 11:18:03 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int			is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int			count_words(char *s)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (!s[0])
		return (words);
	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		if (s[i])
			words++;
		while (s[i] && !is_space(s[i]))
			i++;
	}
	return (words);
}

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] && !is_space(s[i]))
		i++;
	return (i);
}

char		*ft_strdup(char *s)
{
	char	*str;
	int		i;
	
	i = 0;
	str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	str[ft_strlen(s)] = '\0';
	while (s[i] && !is_space(s[i]))
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char		**ft_split(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = (char**)malloc(sizeof(char*) * count_words(str) + 1);
	split[count_words(str)] = NULL;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (*str)
		{
			split[i] = ft_strdup(str);
			i++;
		}
		while (*str && !is_space(*str))
			str++;
	}
	return (split);
}
