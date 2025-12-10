/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/10 19:25:45 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
verifs a faire :
A : ft_isnumber(tab[1]) -> ft_atof(tab[1]) -> is_in_range(tab[1], 0.0, 1.0) ----> check_val(...)
    check 2 virgules -> check 3 val -> ft_split(tab[2], ',') -> boucle sur les 3 elts : ft_is_number(x) -> is_in_range(tab[2], 0, 255)
*/

///a renommer
static bool check_val(char *s, float r_min, float r_max)
{
    float   f;
    
    if (!ft_isnumber(s))
        return (false);
    f = ft_atof(s);
    if (!is_in_range(f, r_min, r_max))
        return (false);
    return (true);
}

static char **check_coords(char *s)
{
    char **coords;
    
    if (ft_strcnt(s, ',') != 2)
        return (NULL);
    **coords = malloc(3 * sizeof(char *));
    if (!coords)
        return (NULL);
    coords = ft_split(s, ',');
    if (ft_tablen(coords) != 3)
        return (NULL);
    return (coords);
}

static bool check_coords_range(char *s, float r_min, float r_max)
{
    int     i;
    char **coords;
    
    coords = check_coords(*s);
    if (!coords)
        return (false);
    i = 0;
    while (i <= 2)
    {
        if (!check_val(coords[i], r_min, r_max))
            return (false);
        i++;
    }
}

//a renommer
//a ajouter : check si les elts en maj (A, L, C) n apparaissent q'une fois dans le fichier
bool  dispatch_ids(char **tab)
{
    if (ft_tablen(tab) == 3)
    {
        if (ft_strcmp(tab[0], "A") == 0)
        {
            if (!check_val(tab[1], 0.0f, 1.0f) || !check_coords_range(tab[2], 0, 255))
                return (false);
            create_amb();
        }
        else if (ft_strcmp(tab[0], "L") == 0)
        {
            if (!check_coords(tab[1]) || !check_val(tab[2], 0.0f, 1.0f))
                return (false);
            create_light();
        }
        else
            return (false);
    }
    else if (ft_tablen(tab) == 4)
    {
        if (ft_strcmp(tab[0], "C") == 0)
        {
            if (!check_coords(tab[1]) || !check_coords_range(tab[2], -1, 1)
                || !check_val(tab[3], 0, 180))
                return (false);
            create_cam();
        }
        else if (ft_strcmp(tab[0], "sp") == 0)
        {
            if (!check_coords(tab[1]) || !ft_isnumber(tab[2]) || ft_atof(tab[2]) < 0
                || !check_coords_range(tab[3], 0, 255))
                return (false);
            create_sp();
        }
        else if (ft_strcmp(tab[0], "pl") == 0)
        {
            if (!check_coords(tab[1]) || !check_coords_range(tab[2], -1, 1)
                || !check_coords_range(tab[3], 0, 255))
                return (false);
            create_pl();
        }
        else
            return (false);
    }
    else if (ft_tablen(tab) == 6 && ft_strcmp(tab[0], "cy") == 0)
    {
        if (!check_coords(tab[1]) || !check_coords_range(tab[2], -1, 1) || !ft_isnumber(tab[3])
            || ft_atof(tab[3]) < 0 || !ft_isnumber(tab[4]) || ft_atof(tab[4] < 0) || !check_coords_range(tab[5], 0, 255))
            return (false);
        create_cy();
    }
    else
        return (false);
    return (true);
}
