/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/16 23:29:43 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool  dispatch_ids(char **tab, t_scene *s, t_data *data)
{
    if (ft_tablen(tab) == 3 || (ft_tablen(tab) == 4 && ft_strcmp(tab[0], "C") == 0))
    {
        if (!dispatch_scene(tab, s, data))
        {
            //test - a supprimer
            ft_printf("dispatch scene failed\n");
            return (false);
        }
        //test - a supprimer
        ft_printf("dispatch scene success\n");
    }
    else if (ft_tablen(tab) == 4 || ft_tablen(tab) == 6)
    {
        if (!dispatch_obj(tab, s, data))
        {
            //test - a supprimer
            ft_printf("dispatch objects failed\n");
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
