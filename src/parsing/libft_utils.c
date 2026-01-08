/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:56:38 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/07 18:02:24 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	parse_number_body(char *s, int *i, bool *has_digit)
{
	bool	is_float;

	is_float = false;
	*has_digit = false;
	while (s[*i])
	{
		if (ft_isdigit(s[*i]))
			*has_digit = true;
		else if (s[*i] == '.')
		{
			if (is_float)
				return (false);
			is_float = true;
		}
		else if (ft_isspace(s[*i]))
		{
			while (ft_isspace(s[*i]))
				(*i)++;
			return (true);
		}
		else
			return (false);
		(*i)++;
	}
	return (true);
}

//check si la chaine passee en param est un int / float ou non
bool	ft_isnumber(char *s)
{
	int		i;
	bool	has_digit;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!parse_number_body(s, &i, &has_digit))
		return (false);
	if (s[i] != '\0' || !has_digit)
		return (false);
	return (true);
}

// /!| valide uniquement pour NULL terminated tabs
// (le cas ici car tab cree avec split)
int     ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

//utile dans exec cylindre
//entre 2 collisions possibles, laquelle est valide ET la + proche
float	min_positive(float f1, float f2)
{
	if (f1 > 0.0)
	{
		if (f2 > 0.0)
			return (min(f1, f2));
		return (f1);
	}
	if (f2 > 0.0)
		return (f2);
	return (INFINITY);
}

size_t  ft_count_whitespace(char *s)
{
    size_t i;
    size_t count;

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

static double	parse_unsigned_float(const char *s, size_t *i)
{
	double	res;
	double	div;

	res = 0.0;
	while (s[*i] && ft_isdigit(s[*i]))
		res = res * 10.0 + (s[(*i)++] - '0');

	if (s[*i] == '.')
	{
		(*i)++;
		div = 10.0;
		while (s[*i] && ft_isdigit(s[*i]))
		{
			res += (s[*i] - '0') / div;
			div *= 10.0;
			(*i)++;
		}
	}
	return (res);
}

double	ft_atof(const char *nptr)
{
	size_t	i;
	int		sign;
	double	res;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;

	res = parse_unsigned_float(nptr, &i);
	return (res * (double)sign);
}
