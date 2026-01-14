/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:50:21 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/14 13:28:07 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	dispatch_amb(char **tab, t_scene *s, char ***coords_r, t_data *data)
{
	t_light	*new_amb;

	*coords_r = check_coords_range(tab[2], 0, 255, data);
	if (!check_val(tab[1], 0.0f, 1.0f, data) || !*coords_r)
		return (ret_error(data, ERR_INVALID_AMBIENT_DATA));
	new_amb = create_amb(ft_atof(tab[1]), parse_vector(*coords_r, 3, data));
	if (!new_amb)
		return (ret_error(data, ERR_MALLOC_AMBIENT));
	s->amb = new_amb;
	return (true);
}

static bool	dispatch_light(char **tab, t_scene *s,
	t_coords *c, t_data *data)
{
	t_light	*new_l;

	c->coords = check_coords(tab[1], data);
	c->coords_r = check_coords_range(tab[3], 0, 255, data);
	if (!c->coords || !check_val(tab[2], 0.0f, 1.0f, data) || !c->coords_r)
		return (ret_error(data, ERR_INVALID_LIGHT_DATA));
	new_l = create_light(parse_vector(c->coords, 1, data), ft_atof(tab[2]),
			parse_vector(c->coords_r, 3, data));
	if (!new_l)
		return (ret_error(data, ERR_MALLOC_LIGHT));
	s->l = new_l;
	return (true);
}

static bool	dispatch_cam(char **tab, t_scene *s,
	t_coords *c, t_data *data)
{
	t_cam	*new_cam;

	c->coords = check_coords(tab[1], data);
	c->coords_r = check_coords_range(tab[2], -1, 1, data);
	if (!c->coords || !c->coords_r || !check_val(tab[3], 0, 180, data))
		return (ret_error(data, ERR_INVALID_CAMERA_DATA));
	new_cam = create_cam(parse_vector(c->coords, 1, data),
			parse_vector(c->coords_r, 2, data), ft_atof(tab[3]));
	if (!new_cam)
		return (ret_error(data, ERR_MALLOC_CAMERA));
	s->cam = new_cam;
	return (true);
}

bool	dispatch_scene(char **tab, t_scene *s, t_data *data)
{
	t_coords	c;
	bool		res;

	ft_memset(&c, 0, sizeof(t_coords));
	res = true;
	if (ft_strcmp(tab[0], "A") == 0)
	{
		if (s->amb)
			return (ret_error(data, ERR_DUPLICATE_AMBIENT));
		res = dispatch_amb(tab, s, &c.coords_r, data);
	}
	else if (ft_strcmp(tab[0], "L") == 0)
	{
		if (s->l)
			return (ret_error(data, ERR_DUPLICATE_LIGHT));
		res = dispatch_light(tab, s, &c, data);
	}
	else if (ft_strcmp(tab[0], "C") == 0)
	{
		if (s->cam)
			return (ret_error(data, ERR_DUPLICATE_CAMERA));
		res = dispatch_cam(tab, s, &c, data);
	}
	free_tabs(c.coords, c.coords_r, c.coords_r2);
	return (res);
}
