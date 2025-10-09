/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:49:17 by syukna            #+#    #+#             */
/*   Updated: 2025/10/09 12:50:37 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_bri(char *str, t_light **light)
{
	(*light)->bri = atof(str);
	if (!str || (ft_strlen(str) >= 10 && ft_strncmp(str, "2147483647", 10) > 0))
	{
		perror("The light must remain between 0.0 and 1.0\n");
		return (EXIT_FAILURE);
	}
	if (!ft_accept_chars(str, "0123456789-."))
	{
		perror("The light brightness must not include other characters than numbers, '-' and '.'\n");
		return (EXIT_FAILURE);
	}
	if ((*light)->bri > 1 || (*light)->bri < 0)
	{
		perror("The light must remain between 0.0 and 1.0\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_ambient(char **args, t_scene *scene)
{
	t_light *amb;
	t_color	color;

	amb = malloc(sizeof(t_light));
	if (!amb)
		return (EXIT_FAILURE);
	ft_memset(amb, '\0', sizeof(t_light));
	amb->coor = init_vec3();
	if (get_bri(args[1], &amb) == EXIT_FAILURE)
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

int	init_light(char **args, t_scene *scene)
{
	t_light *light;
	t_color	color;

	light = malloc(sizeof(t_light));
	if (!light)
		return (EXIT_FAILURE);
	ft_memset(light, '\0', sizeof(t_light));
	light->coor = init_vec3();
	if (get_coor(args[1], &light->coor) == EXIT_FAILURE)
	{
		free(light);
		return (EXIT_FAILURE);
	}
	if (get_bri(args[2], &light) == EXIT_FAILURE)
	{
		free(light);
		return (EXIT_FAILURE);
	}
	if (get_color(args[3], &color) == EXIT_FAILURE)
	{
		free(light);
		return (EXIT_FAILURE);
	}
	light->color = color;
	scene->l = light;
	return (EXIT_SUCCESS);
}
