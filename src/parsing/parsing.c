/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/19 18:00:10 by cafabre          ###   ########.fr       */
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

/*
RESTE A FAIRE
- refactor of functions over 25 lines -> ONGOING
    -> parse_ids DONE
    -> dispatch_ids DONE
    -> dispatch_scene TO DO
    -> check_coords DONE
    -> display_error_message DONE
    -> ft_atof DONE
    -> ft_isnumber DONE
- move libft_utils.c functions into the libft

ISSUES
- ambient lighting isnt right (ex : amb max + no light -> shadows houldnt appear) -> exec
- add the code to make create_cy(...) work -> render of cylinders not tested yet -> exec
- pixelated results in some cases (recurring issue in minirt, solutions easily found on internet) -> exec
    --> see room.rt

FIXED
- "invalid number of arguments on one line" when whitespaces at the end of the line -> parsing
    --> fix : ft_strtrim(line, " \t\n") before split
- "invalid number of arguments on one line" when wrong id at the beginning of the line -> parsing
    --> fix : changed the main dispatcher logic
- need to check that there is at least one C, one L and one A -> parsing
    --> fix : added a check in parse_ids at the end of the loop

IMPROVEMENTS
- ft_strcmp to get the id -> called twice (dispatch_id and dispatch_scene / dispatch_obj) -> parsing
    --> find a way to keep only one check

BONUS
- add color to light -> NOT FINISHED (errors to handle)
*/