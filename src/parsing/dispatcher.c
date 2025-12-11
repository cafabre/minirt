/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/11 14:53:31 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
verifs a faire :
A : ft_isnumber(tab[1]) -> ft_atof(tab[1]) -> is_in_range(tab[1], 0.0, 1.0) ----> check_val(...)
    check 2 virgules -> check 3 val -> ft_split(tab[2], ',') -> boucle sur les 3 elts : ft_isnumber(x) -> is_in_range(tab[2], 0, 255)
*/

static bool dispatch_scene(char **tab)
{
    if (ft_strcmp(tab[0], "A") == 0)
    {
        if (!check_val(tab[1], 0.0f, 1.0f) || check_coords_range(tab[2], 0, 255))
            return (false);
    }
    else if (ft_strcmp(tab[0], "L") == 0)
    {
        if (!check_coords(tab[1]) || !check_val(tab[2], 0.0f, 1.0f))
            return (false);
    }
    else if (ft_strcmp(tab[0], "C") == 0)
    {
        if (!check_coords(tab[1]) || !check_coords_range(tab[2], -1, 1)
            || !check_val(tab[3], 0, 180))
            return (false);
    }
    else
        return (false);
    return (true);
}

static bool dispatch_obj(char **tab)
{
    if (ft_strcmp(tab[0], "sp") == 0)
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
    else if (ft_strcmp(tab[0], "cy") == 0)
    {
        if (!check_coords(tab[1]) || !check_coords_range(tab[2], -1, 1) || !ft_isnumber(tab[3])
            || ft_atof(tab[3]) < 0 || !ft_isnumber(tab[4]) || ft_atof(tab[4]) < 0 || !check_coords_range(tab[5], 0, 255))
            return (false);
        create_cy();
    }
    else
        return (false);
    return (true);
}

//a renommer
//a ajouter : check si les elts en maj (A, L, C) n apparaissent q'une fois dans le fichier
bool  dispatch_ids(char **tab)
{
    if (ft_tablen(tab) == 3 || (ft_tablen(tab) == 4 && ft_strcmp(tab[0], "C") == 0))
    {
        if (!dispatch_scene(tab))
            return (false);
    }
    else if (ft_tablen(tab) == 4 || ft_tablen(tab) == 6)
    {
        if (!dispatch_obj(tab))
            return (false);
    }
    else
        return (false);
    return (true);
}
