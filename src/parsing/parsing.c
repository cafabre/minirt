/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/15 14:57:49 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool    parse_ids(int fd, t_scene *s)
{
    char    *line;
    char    **tab;

    while ((line = ft_gnl(fd)) != NULL)
    {
        tab = ft_split_whitespaces(line);
        free (line);
        if (!tab || !tab[0] || ft_strcmp(tab[0], "\n") == 0)
        {
            free_tab(tab);
            continue ;
        }
        if (!dispatch_ids(tab, s))
        {
            free_tab(tab);
            return (false); 
        }
    }
    free_tab(tab);
    return (true);
}

int     parsing(int fd, t_scene *s)
{
    if (!parse_ids(fd, s))
        return (EXIT_FAILURE);
    //a completer
    return (EXIT_SUCCESS);
}

/*
RESTE A FAIRE
- gestion de la remontee d erreur a revoir EN COURS
- refactor de certaines fonctions trop longues EN COURS
- fonctions de free / clean (tab, all...) -> free_tab et free_tabs DONE, reste EN COURS
- deplacer les utils dans la libft
*/