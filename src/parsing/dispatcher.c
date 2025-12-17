/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/17 12:41:38 by cafabre          ###   ########.fr       */
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
        //2 lignes de test : a supprimer
        ft_printf("display scene : \n");
        display_scene(s);
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
