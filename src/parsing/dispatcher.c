/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/17 14:03:44 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool  dispatch_ids(char **tab, t_scene *s, t_data *data)
{
    //test - a supprimer
    ft_printf("tab[0] = %s\n", tab[0]);
    
    if (ft_tablen(tab) == 3 || (ft_tablen(tab) == 4 && ft_strcmp(tab[0], "C") == 0))
    {
        if (!dispatch_scene(tab, s, data))
            return (false);
    }
    else if ((ft_tablen(tab) == 4 && (ft_strcmp(tab[0], "sp") == 0
        || ft_strcmp(tab[0], "pl") == 0)) || ft_tablen(tab) == 6)
    {
        if (!dispatch_obj(tab, s, data))
            return (false);
    }
    else
    {
        //test - a supprimer
        ft_printf("err invalid args line, tab[0] = %s\n", tab[0]);
        
        data->error = ERR_INVALID_ARGS_LINE;
        return (false);
    }
    return (true);
}
