/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:56:38 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/08 16:13:07 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//ajouter a la libft ?
//check si la chaine passee en param est un int / float ou non
bool		ft_isnumber(char *s)
{
        int i;
        bool	is_float;
        bool	has_digit;

        i = 0;
        is_float = false;
        has_digit = false;
        while (ft_isspace(s[i]))
            i++;
        if (s[i] == '-' || s[i] == '+')
            i++;
        while (s[i] != '\0')
        {
            if (ft_isdigit(s[i]))
                has_digit = true;
            else if (s[i] == '.')
            {
                if (is_float)
                    return (false);
                is_float = true;
            }
            else if (ft_isspace(s[i]))
            {
                while (ft_isspace(s[i]))
                    i++;
                break ;
            }
            else
                return (false);
            i++;
        }
        if (s[i] != '\0' || !has_digit)
            return (false);
        return (true);
}

//ajouter a libft ?? (utilisee aussi dans objects.c)
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

//ajouter a la libft ??
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

char	**ft_split_whitespace(char const *s)
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

//version d'atof valide jusqu a 3 chiffres apres la virgule, ignore le reste
//fonction a refactor !!!
float	ft_atof(const char *nptr)
{
	size_t	i;
	int		sign;
	float	res;

	i = 0;
	sign = 1;
	res = 0.0f;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
    if (nptr[i] == '.')
    {
        i++;
        if (ft_isdigit(nptr[i]))
        {
            res += (nptr[i] - '0') / 10.0f;
            i++;
        }
        if (ft_isdigit(nptr[i]))
        {
            res += (nptr[i] - '0') / 100.0f;
            i++;
        }
        if (ft_isdigit(nptr[i]))
        {
            res += (nptr[i] - '0') / 1000.0f;
            i++;
        }
    }
	return (res * sign);
}
