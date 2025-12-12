/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/12 17:43:33 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// /!\ check_coords et check_coords_range allouent un tableau avec ft_split
// -> trouver un moyen de free toute la memoire allouee
//      - si issue
//      - une fois utilisee

//a renommer
bool  dispatch_ids(char **tab, t_scene *s)
{
    if (ft_tablen(tab) == 3 || (ft_tablen(tab) == 4 && ft_strcmp(tab[0], "C") == 0))
    {
        if (!dispatch_scene(tab, s))
            return (false);
    }
    else if (ft_tablen(tab) == 4 || ft_tablen(tab) == 6)
    {
        if (!dispatch_obj(tab, s))
            return (false);
    }
    else
        return (false);
    return (true);
}
