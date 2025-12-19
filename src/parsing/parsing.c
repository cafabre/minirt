/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/19 13:44:05 by cafabre          ###   ########.fr       */
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
        //fix : strtrim to accept whitespaces at the end of a line
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
- refactor of functions over 25 lines
- move libft_utils.c functions into the libft

ISSUES
- ambient lighting doesnt change the scene
- add the code to make create_cy(...) work -> render of cylinders not tested yet
- pixelated results in some cases (recurring issue in minirt, solutions easily found on internet)
    --> see room.rt

FIXED
- "invalid number of arguments on one line" when whitespaces at the end of the line
    --> fix : ft_strtrim(line, " \t\n") before split
- "invalid number of arguments on one line" when wrong id at the beginning of the line
    --> fix : changed the main dispatcher logic

BONUS
- add color to light -> NOT FINISHED (errors to handle)
*/