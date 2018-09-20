/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:09:10 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/29 11:53:07 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (count);
		count++;
	}
	return (count);
}

static int	ft_count(char const *s, char c)
{
	int	count;
	int in_sub;

	in_sub = 0;
	count = 0;
	while (*s)
	{
		in_sub = (in_sub && *s == c) ? 0 : in_sub;
		if (!in_sub && *s != c)
		{
			count++;
			in_sub = 1;
		}
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		elements;
	char	**ptr;

	if (!s)
		return (NULL);
	elements = ft_count(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (elements + 1))))
		return (NULL);
	ptr = str;
	while (elements--)
	{
		while (*s == c && *s)
			s++;
		*str = ft_strsub(s, 0, ft_wordlen(s, c));
		str++;
		s = s + ft_wordlen(s, c);
	}
	*str = NULL;
	return (ptr);
}
