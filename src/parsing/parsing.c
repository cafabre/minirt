/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/19 18:30:05 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool    parse_lines(int fd, t_scene *s, t_data *data, bool *empty_fd)
{
    char    *line;
    char    **tab;

    *empty_fd = true;
    while ((line = ft_gnl(fd)) != NULL)
    {
        *empty_fd = false;
        line = ft_strtrim(line, " \t\n");
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
    return (empty_fd);
}

static bool    parse_scene(t_scene *s, t_data *data, bool *empty_fd)
{
    if (*empty_fd)
    {
        data->error = ERR_EMPTY_FILE;
        return (false);
    }
    if (!s->cam || !s->amb || !s->l)
    {
        data->error = ERR_MISSING_ELEMENT;
        return (false);
    }
    return (true);
}

int     parsing(int fd, t_scene *s, t_data *data)
{
    bool    empty_fd;
    
    if (!parse_lines(fd, s, data, &empty_fd))
    {
        //test : a supprimer
		display_scene(s);

        return (EXIT_FAILURE);
    }
    if (!parse_scene(s, data, &empty_fd))
    {
        //test : a supprimer
		display_scene(s);

        return (EXIT_FAILURE);
    }
    
    //test : a supprimer
	display_scene(s);
    
    return (EXIT_SUCCESS);
}
