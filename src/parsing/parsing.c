/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/15 16:54:21 by cafabre          ###   ########.fr       */
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
    return (EXIT_SUCCESS);
}

/*
RESTE A FAIRE
- afficher le bon message d erreur en fonction de l'endroit ou on renvoie false
- refactor de certaines fonctions trop longues
- deplacer les utils dans la libft
*/