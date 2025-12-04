/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/04 17:28:38 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//a renommer
//tab = ligne qui commence par l id
//a ajouter : check si les elts en maj (A, L, C) n apparaissent q'une fois dans le fichier
//opti : ameliorer la remontee d erreur / eviter de trop passer error en param
static bool  check_id(char **tab)
{
    int     *error;

    *error = 0;
    if (ft_tablen(tab) == 3)
    {
        if (tab[0] == "A")
            fill_light_data(tab, true, error);
        else if (tab[0] == "L")
            fill_light_data(tab, false, error);
        else
            return (false);
    }
    else if (ft_tablen(tab) == 4)
    {
        if (tab[0] == "C")
            fill_camera_data(tab, error);
        else if (tab[0] == "sp")
            fill_sphere_data(tab, error);
        else if (tab[0] == "pl")
            fill_plane_data(tab, error);
        else
            return (false);
    }
    else if (ft_tablen(tab) == 6 && tab[0] == "cy")
        fill_cylinder_data(tab, error);
    else
        return (false);
    return (true);
}

//a ajouter : cas des lignes separees par plusieurs sauts de ligne
// + allocation de tab et data
bool    correct_ids(int fd)
{
    char    *line;
    char    **tab;
    char    ***data;
    int     i;

    i = 0;
    while ((line = ft_gnl(fd)) != NULL)
    {
        tab = ft_split_whitespaces(line);
        data[i] = tab;
        if (!check_id)
            return (false);
        free (line);
        i++;
    }
    return (true);
}
