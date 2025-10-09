/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:01:50 by syukna            #+#    #+#             */
/*   Updated: 2025/10/09 12:52:15 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_sphere(t_sphere *sphere, t_scene *scene)
{
	t_sphere	*temp;

	if (scene->sp)
	{
		temp = scene->sp;
		while (temp->next)
			temp = temp->next;
		temp->next = sphere;
	}
	else
		scene->sp = sphere;
	return (EXIT_SUCCESS);
}

int	add_plane(t_plane *plane, t_scene *scene)
{
	t_plane	*temp;

	if (scene->pl)
	{
		temp = scene->pl;
		while (temp->next)
			temp = temp->next;
		temp->next = plane;
	}
	else
		scene->pl = plane;
	return (EXIT_SUCCESS);
}

int	init_sphere(char **args, t_scene *scene)
{
	t_sphere *sphere;
	t_color	color;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (EXIT_FAILURE);
	ft_memset(sphere, '\0', sizeof(t_sphere));
	sphere->coor = init_vec3();
	if (get_coor(args[1], &sphere->coor) == EXIT_FAILURE)
	{
		free(sphere);
		return (EXIT_FAILURE);
	}
	if (!ft_accept_chars(args[2], "0123456789."))
	{
		free(sphere);
		perror("The diameter must not include other characters than numbers separated by ','.\n");
		return (EXIT_FAILURE);
	}
	sphere->diameter = atof(args[2]);
	if (get_color(args[3], &color) == EXIT_FAILURE)
	{
		free(sphere);
		return (EXIT_FAILURE);
	}
	sphere->color = color;
	sphere->next = NULL;
	return (add_sphere(sphere, scene));
}

int	init_plane(char **args, t_scene *scene)
{
	t_plane *plane;
	t_color	color;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (EXIT_FAILURE);
	ft_memset(plane, '\0', sizeof(t_plane));
	plane->coor = init_vec3();
	plane->vector = init_vec3();
	if (get_coor(args[1], &plane->coor) == EXIT_FAILURE)
	{
		free(plane);
		return (EXIT_FAILURE);
	}
	if (get_norm(args[2], &plane->vector) == EXIT_FAILURE)
	{
		free(plane);
		return (EXIT_FAILURE);
	}
	if (get_color(args[3], &color) == EXIT_FAILURE)
	{
		free(plane);
		return (EXIT_FAILURE);
	}
	plane->color = color;
	return (add_plane(plane, scene));
}

int	init_cyl(char **args, t_scene *scene)
{
	t_cyl *cyl;
	t_color	color;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (EXIT_FAILURE);
	ft_memset(cyl, '\0', sizeof(t_cyl));
	cyl->coor = init_vec3();
	if (get_coor(args[1], &cyl->coor) == EXIT_FAILURE)
	{
		free(cyl);
		return (EXIT_FAILURE);
	}
	cyl->vector = init_vec3();
	if (get_norm(args[2], &cyl->vector) == EXIT_FAILURE)
	{
		free(cyl);
		return (EXIT_FAILURE);
	}
	cyl->diameter = atof(args[3]);
	cyl->height = atof(args[4]);
	if (get_color(args[5], &color) == EXIT_FAILURE)
	{
		free(cyl);
		return (EXIT_FAILURE);
	}
	cyl->color = color;
	scene->cy = cyl;
	return (EXIT_SUCCESS);
}
