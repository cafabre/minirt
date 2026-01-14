/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:56:38 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/14 13:28:18 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

float	min_positive(float f1, float f2)
{
	if (f1 > 0.0)
	{
		if (f2 > 0.0)
			return (fmin(f1, f2));
		return (f1);
	}
	if (f2 > 0.0)
		return (f2);
	return (INFINITY);
}

size_t	ft_count_whitespace(char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_isblank(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_isblank(s[i]))
			i++;
	}
	return (count);
}

char	**ft_split_whitespaces(char *s)
{
	char	**tab;
	size_t	start;
	size_t	end;
	size_t	i;

	tab = ft_calloc((ft_count_whitespace(s) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	end = 0;
	while (s[end])
	{
		while (s[end] && ft_isblank(s[end]))
			end++;
		start = end;
		while (s[end] && !ft_isblank(s[end]))
			end++;
		if (end > start)
		{
			tab[i] = ft_substr(s, start, end - start);
			if (!tab[i++])
				return (ft_free_sptr(tab), NULL);
		}
	}
	return (tab);
}
