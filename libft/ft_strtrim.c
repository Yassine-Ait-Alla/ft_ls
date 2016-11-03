/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:18:02 by yaitalla          #+#    #+#             */
/*   Updated: 2014/11/13 12:59:23 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_space(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static int		strfill(char **str, const char *s, int i, int j)
{
	int		k;

	k = 0;
	while (i < j)
	{
		(*str)[k] = s[i];
		i++;
		k++;
	}
	return (k);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_space(s[i]))
		i++;
	j = ft_strlen(s);
	while (j && ft_space(s[j - 1]))
		j--;
	if (i >= j)
		k = 0;
	else
		k = j - i;
	str = (char *)malloc(sizeof(char) * k + 1);
	if (!str)
		return (NULL);
	k = strfill(&str, s, i, j);
	str[k] = '\0';
	return (str);
}
