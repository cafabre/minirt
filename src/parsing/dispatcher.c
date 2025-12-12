/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/12 11:58:16 by cafabre          ###   ########.fr       */
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
    char    **coords_r;
    char    **coords;
    
    if (ft_strcmp(tab[0], "A") == 0)
    {
        coords_r = check_coords_range(tab[2], 0, 255);
        if (!check_val(tab[1], 0.0f, 1.0f) || !coords_r)
            return (false);
        create_amb(ft_atof(tab[1]), parse_vector(coords_r, 3));
    }
    else if (ft_strcmp(tab[0], "L") == 0)
    {
        coords = check_coords(tab[1]);
        if (!coords || !check_val(tab[2], 0.0f, 1.0f))
            return (false);
        create_light(parse_vector(coords, 1), ft_atof(tab[2]));
    }
    else if (ft_strcmp(tab[0], "C") == 0)
    {
        coords = check_coords(tab[1]);
        coords_r = check_coords_range(tab[2], -1, 1);
        if (!coords || !coords_r || !check_val(tab[3], 0, 180))
            return (false);
        create_cam(parse_vector(coords, 1), parse_vector(coords_r, 2), ft_atof(tab[3]));
    }
    else
        return (false);
    return (true);
}

static bool dispatch_obj(char **tab)
{
    char    **coords;
    char    **coords_r;
    char    **coords_r2;
    
    if (ft_strcmp(tab[0], "sp") == 0)
    {
        coords = check_coords(tab[1]);
        coords_r = check_coords_range(tab[3], 0, 255);
        if (!coords || !ft_isnumber(tab[2]) || ft_atof(tab[2]) < 0 || !coords_r)
            return (false);
        create_sp(parse_vector(coords, 1), ft_atof(tab[2]), parse_vector(coords_r, 3));
    }
    else if (ft_strcmp(tab[0], "pl") == 0)
    {
        coords = check_coords(tab[1]);
        coords_r = check_coords_range(tab[2], -1, 1);
        coords_r2 = check_coords_range(tab[3], 0, 255);
        if (!coords || !coords_r || !coords_r2)
            return (false);
        create_pl(parse_vector(coords, 1), parse_vector(coords_r, 2),
            parse_vector(coords_r2, 3));
    }
    else if (ft_strcmp(tab[0], "cy") == 0)
    {
        if (!check_coords(tab[1]) || !check_coords_range(tab[2], -1, 1) || !ft_isnumber(tab[3])
            || ft_atof(tab[3]) < 0 || !ft_isnumber(tab[4]) || ft_atof(tab[4]) < 0 || !check_coords_range(tab[5], 0, 255))
            return (false);
        create_cy(); //comment passer les 5 args a la fonction ???
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
