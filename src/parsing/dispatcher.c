/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/19 13:39:02 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//type = 1 for dispatch scene, type = 2 for dispatch obj
static bool dispatch_util(char **tab, t_scene *s, t_data *data, int nb_args, int type)
{
    if (ft_tablen(tab) == nb_args)
    {
        if (type == 1)
        {
            if (!dispatch_scene(tab, s, data))
                return (false);
        }
        else
        {
            if (!dispatch_obj(tab, s, data))
                return (false);
        }
    }
    else
    {
        data->error = ERR_INVALID_ARGS_LINE;
        return (false);
    }
    return (true);
}

bool  dispatch_ids(char **tab, t_scene *s, t_data *data)
{
    bool    valid_line;
    
    if (ft_strcmp(tab[0], "A") == 0)
        valid_line = dispatch_util(tab, s, data, 3, 1);
    else if (ft_strcmp(tab[0], "C") == 0 || ft_strcmp(tab[0], "L") == 0)
        valid_line = dispatch_util(tab, s, data, 4, 1);
    else if (ft_strcmp(tab[0], "sp") == 0 || ft_strcmp(tab[0], "pl") == 0)
        valid_line = dispatch_util(tab, s, data, 4, 2);
    else if (ft_strcmp(tab[0], "cy") == 0)
        valid_line = dispatch_util(tab, s, data, 6, 2);
    else
    {
        data->error = ERR_INVALID_ID;
        return (false);
    }
    return (valid_line);
}
