/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:32:15 by syukna            #+#    #+#             */
/*   Updated: 2025/10/09 13:13:58 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_spheres(t_sphere *lst)
{
	t_sphere *tmp;
	t_sphere *next;

	tmp = lst;
	next = tmp->next;
	while (next)
	{
		free(tmp);
		tmp = next;
		next = tmp->next;
	}
	free(tmp);
}

void	free_cyls(t_cyl *lst)
{
	t_cyl *tmp;
	t_cyl *next;

	tmp = lst;
	next = tmp->next;
	while (next)
	{
		free(tmp);
		tmp = next;
		next = tmp->next;
	}
	free(tmp);
}

void	free_planes(t_plane *lst)
{
	t_plane *tmp;
	t_plane *next;

	tmp = lst;
	next = tmp->next;
	while (next)
	{
		free(tmp);
		tmp = next;
		next = tmp->next;
	}
	free(tmp);
}

void	free_all(t_scene *scene)
{
	if (scene->cam)
		free(scene->cam);
	if (scene->amb)
		free(scene->amb);
	if (scene->l)
		free(scene->l);
	if (scene->sp)
		free_spheres(scene->sp);
	if (scene->cy)
		free_cyls(scene->cy);
	if (scene->pl)
		free_planes(scene->pl);
}
