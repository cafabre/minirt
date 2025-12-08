/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:53 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/08 13:04:14 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//1. .rt ?
static bool    has_rt_type(char *file)
{
    int len;

    len = ft_strlen(file);
    if (len >= 4)
    {
        if (file[len - 3] == '.' && file[len - 2] == 'r' && file[len - 1] == 't')
            return (true);
    }
    return (false);
}

//2. fichier vide ?
static bool    is_empty(int fd)
{
    if (ft_gnl(fd) == NULL)
        return (true);
    return (false);
}

int    file_parsing(int fd)
{
    if (fd < 0)
    {
        perror("ERROR: couldn't open file");
        return (EXIT_FAILURE);
    }
    if (is_empty(fd))
    {
        perror("ERROR: file is empty");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
