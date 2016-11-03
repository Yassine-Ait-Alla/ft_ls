/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 04:10:07 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/28 08:20:16 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcword(const char *s)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((!ft_isblank(s[i]) && i == 0) ||
			(!ft_isblank(s[i]) && ft_isblank(s[i - 1])))
			word++;
		i++;
	}
	return (word);
}

static char	**malloctab(char const *s)
{
	int	numword;

	if (s)
	{
		numword = calcword(s);
		return ((char **)ft_memalloc(sizeof(char *) * (numword + 1)));
	}
	return (NULL);
}

static int	calcmalloc(char const *s, int i)
{
	int	n;

	n = i;
	while (s[n] && !ft_isblank(s[n]))
		n++;
	return (n);
}

char		**ft_space_split(char const *s)
{
	char	**tab;
	int		i;
	int		n;
	int		j;

	if (s == NULL || (tab = malloctab(s)) == NULL)
		return (NULL);
	i = -1;
	n = 0;
	while (s[++i])
	{
		if (!ft_isblank(s[i]))
		{
			if (tab[n] == NULL)
			{
				j = 0;
				if ((tab[n] = ft_strnew(calcmalloc(s, i) + 2)) == NULL)
					return (NULL);
			}
			tab[n][j++] = s[i];
		}
		else if (tab[n] != NULL)
			n++;
	}
	return (tab);
}
