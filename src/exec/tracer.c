/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:08:46 by rshin             #+#    #+#             */
/*   Updated: 2026/01/12 14:42:33 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec4	get_object_normal(const t_obj *obj, t_vec4 hit_pos)
{
	t_vec4	normal;
	t_vec4	proj;
	float	t;

	if (obj->type == SPHERE)
		normal = vec4_norm(vec4_sub(hit_pos, obj->pos));
	else if (obj->type == PLANE)
		normal = obj->dir;
	else if (obj->type == CYLINDER)
	{
		t = vec4_dot_prod(vec4_sub(hit_pos, obj->pos), obj->dir);
		if (t >= (obj->height / 2.0f) - 1e-4)
			normal = obj->dir;
		else if (t <= -(obj->height / 2.0f) + 1e-4)
			normal = vec4_scalar_mul(obj->dir, -1.0f);
		else
		{
			proj = vec4_add(obj->pos, vec4_scalar_mul(obj->dir, t));
			normal = vec4_norm(vec4_sub(hit_pos, proj));
		}
	}
	else
		normal = vec4_color(0, 0, 0);
	return (normal);
}

unsigned int	trace_ray(t_scene *s, t_ray *ray)
{
	t_hit	hit;
	t_vec4	color;

	hit.obj = compute_nearest_obj(s, ray, NULL);
	if (!hit.obj)
		return (pack_to_uint(s->cache.bg_col));
	hit.pos = vec4_add(ray->pos, vec4_scalar_mul(ray->dir, ray->t));
	hit.norm = get_object_normal(hit.obj, hit.pos);
	color = shade(s, &hit);
	return (pack_to_uint(color));
}
