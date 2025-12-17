/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/17 14:17:40 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool    parse_ids(int fd, t_scene *s, t_data *data)
{
    char    *line;
    char    **tab;
    bool    empty_fd;

    empty_fd = true;
    while ((line = ft_gnl(fd)) != NULL)
    {
        empty_fd = false;
        tab = ft_split_whitespaces(line);
        free (line);
        if (!tab || !tab[0] || ft_strcmp(tab[0], "\n") == 0)
        {
            free_tab(tab);
            continue ;
        }
        if (!dispatch_ids(tab, s, data))
        {
            free_tab(tab);
            return (false); 
        }
        free_tab(tab);
    }
    if (empty_fd)
    {
        data->error = ERR_EMPTY_FILE;
        return (false);
    }
    return (true);
}

int     parsing(int fd, t_scene *s, t_data *data)
{
    if (!parse_ids(fd, s, data))
    {
        //test : a supprimer
		display_scene(s);

        return (EXIT_FAILURE);
    }
    
    //test : a supprimer
	display_scene(s);
    
    return (EXIT_SUCCESS);
}

/*
RESTE A FAIRE
- refactor de certaines fonctions trop longues
- deplacer les utils dans la libft
*/