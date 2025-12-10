/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/10 13:47:27 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//a renommer
//a ajouter : check si les elts en maj (A, L, C) n apparaissent q'une fois dans le fichier
bool  check_id(char **tab)
{
    if (ft_tablen(tab) == 3)
    {
        if (tab[0] == "A")
            create_amb();
        else if (tab[0] == "L")
            create_light();
        else
            return (false);
    }
    else if (ft_tablen(tab) == 4)
    {
        if (tab[0] == "C")
            create_cam();
        else if (tab[0] == "sp")
            create_sp();
        else if (tab[0] == "pl")
            create_pl();
        else
            return (false);
    }
    else if (ft_tablen(tab) == 6 && tab[0] == "cy")
        create_cy();
    else
        return (false);
    return (true);
}
