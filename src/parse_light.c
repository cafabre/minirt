/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:49:17 by syukna            #+#    #+#             */
/*   Updated: 2025/10/02 16:07:42 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_brightness(char *str, t_light **light)
{
	
	(*light)->brightness = atof(str);
	if (!str || (ft_strlen(str) >= 10 && ft_strncmp(str, "2147483647", 10) > 0))
	{
		perror("The light must remain between 0.0 and 1.0\n");
		return (EXIT_FAILURE);
	}
	if (!ft_accept_chars(str, "0123456789-."))
	{
		// TODO solve perror
		perror("The light brightness must not include other characters than numbers, '-' and '.'\n");
		return (EXIT_FAILURE);
	}
	if ((*light)->brightness > 1 || (*light)->brightness < 0)
	{
		perror("The light must remain between 0.0 and 1.0\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_ambient(char **args, t_scene *scene)
{
	t_light *amb;
	t_coor	coor;
	t_color	color;

	amb = malloc(sizeof(t_light));
	if (!amb)
		return (EXIT_FAILURE);
	ft_memset(amb, '\0', sizeof(t_light));
	coor.x = 0;
	coor.y = 0;
	coor.z = 0;
	amb->coor = coor;
	if (get_brightness(args[1], &amb) == EXIT_FAILURE)
	{
		free(amb);
		return (EXIT_FAILURE);
	}
	if (get_color(args[2], &color) == EXIT_FAILURE)
	{
		free(amb);
		return (EXIT_FAILURE);
	}
	amb->color = color;
	scene->amb = amb;
	return (EXIT_SUCCESS);
}
