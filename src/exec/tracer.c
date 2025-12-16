/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:08:46 by rshin             #+#    #+#             */
/*   Updated: 2025/12/16 09:08:53 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec4 get_object_normal(const t_obj *obj, t_vec4 hit_pos)
{
	t_vec4	normal;

	if (obj->type == SPHERE)
		normal = vec4_norm(vec4_sub(hit_pos, obj->pos));
	else if (obj->type == PLANE)
		normal = obj->dir;
	else
		normal = vec4_norm(vec4_sub(hit_pos, obj->dir));
	return (normal);
}

static t_vec4 compute_lighting(t_scene *s, t_obj *obj, t_ray hit)
{
	t_ray	light;
	t_vec4	ambient;
	float	diffuse;
	t_vec4	diff_col;
	float	light_dist;

	light.pos = vec4_add(hit.pos, vec4_scalar_prod(hit.dir, 0.001f));
	light.dir = vec4_norm(vec4_sub(s->l->pos, light.pos));
	light_dist = vec4_len(vec4_sub(s->l->pos, light.pos));
	float shadow_factor = 1.0f;
	if (compute_nearest_obj(s, &light, obj) && light.t < light_dist)
		shadow_factor = 0.0f;
	diffuse = fmax(vec4_dot_prod(hit.dir, light.dir), 0.0f) * shadow_factor;
	float hemi = 0.5f + 0.5f * hit.dir.y;
	ambient = vec4_scalar_prod(s->amb->col, s->amb->lum * hemi);
	diff_col = vec4_scalar_prod(vec4_mul(obj->col, s->l->col), diffuse * s->l->lum);
	t_vec4 amb_part = vec4_scalar_prod(ambient, 1.0f - diffuse);
	return (vec4_add(amb_part, diff_col));
}

unsigned int	trace_ray(t_scene *s, t_ray *ray)
{
	t_obj	*target;
	t_ray	hit;
	t_vec4	color;

	target = compute_nearest_obj(s, ray, NULL);
	if (!target)
		return (pack_to_uint(s->cache.bg_col));
	hit.pos = vec4_add(ray->pos, vec4_scalar_prod(ray->dir, ray->t));
	hit.dir = get_object_normal(target, hit.pos);
	color = compute_lighting(s, target, hit);
	return (pack_to_uint(color));
}

