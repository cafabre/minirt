/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:20:31 by rshin             #+#    #+#             */
/*   Updated: 2025/10/15 16:34:25 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec4	compute_ray(t_scene *s, t_pix p, t_mat4 view_mat)
{
	t_vec4	d_local;
	t_vec4	d_world;

	d_local.x = (p.x + 0.5f - CX) / s->param.cx_aspect;
	d_local.y = (CY - p.y + 0.5f) / s->param.cy_scale;
	d_local.z = -1.0f;
	d_local = vec4_norm(d_local);
	d_world = vec4_mat4_prod(d_local, view_mat);
	return (d_world);
}

unsigned int	cast_ray(t_scene *s, t_vec4 ray)
{
	t_obj	*target;
	t_vec4	color;
	t_vec4	light_dir;
	t_vec4	obj_norm;
	float	diffuse;

	target = compute_nearest_obj(s, &ray);
	if (target == NULL)
		return (s->amb.col.val);
	if (target->type == SPHERE)
		obj_norm = vec4_norm(vec4_sub(ray, target->pos));
	else
		obj_norm = vec4_norm(vec4_sub(ray, target->dir));
	light_dir = vec4_norm(vec4_sub(ray, s->light->pos));
	diffuse = fmax(vec4_dot_prod(obj_norm, light_dir), 0.0);
	color = vec4_point(target->col.r, target->col.g, target->col.b);
	color = vec4_scalar_prod(color, diffuse * s->light.bri);
	return (convert_vec_color(color));
}
