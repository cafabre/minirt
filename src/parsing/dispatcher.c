/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/16 12:57:10 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool  dispatch_ids(char **tab, t_scene *s, t_data *data)
{
    if (ft_tablen(tab) == 3 || (ft_tablen(tab) == 4 && ft_strcmp(tab[0], "C") == 0))
    {
        if (!dispatch_scene(tab, s, data))
            return (false);
    }
    else if (ft_tablen(tab) == 4 || ft_tablen(tab) == 6)
    {
        if (!dispatch_obj(tab, s, data))
            return (false);
    }
    else
    {
        //data->error = ERR_ invalid number of arguments on one line
        return (false);
    }
    return (true);
}
