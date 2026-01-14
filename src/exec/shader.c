/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:46:44 by rshin             #+#    #+#             */
/*   Updated: 2026/01/12 14:54:24 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

#define SHADOW_BIAS 0.001f

static t_vec4	compute_ambient(t_scene *s, t_hit *hit)
{
	t_vec4	amb_col;

	amb_col = vec4_mul(hit->obj->col, s->amb->col);
	amb_col = vec4_scalar_mul(amb_col, s->amb->lum);
	return (amb_col);
}

static float	compute_shadow(t_scene *s, t_hit *hit, t_ray light)
{
	t_ray	shadow_ray;
	t_obj	*blocker;

	shadow_ray = light;
	blocker = compute_nearest_obj(s, &shadow_ray, hit->obj);
	if (blocker && shadow_ray.t < light.t - 1e-4)
		return (0.0f);
	return (1.0f);
}

static t_ray	compute_light(t_scene *s, t_hit *hit)
{
	t_ray	light;

	light.dir = vec4_norm(vec4_sub(s->l->pos, hit->pos));
	light.pos = vec4_add(hit->pos, vec4_scalar_mul(light.dir, SHADOW_BIAS));
	light.t = vec4_len(vec4_sub(s->l->pos, light.pos));
	return (light);
}

static t_vec4	compute_diffuse(t_scene *s, t_hit *hit)
{
	t_ray	light;
	float	shadow;
	float	diffuse;
	t_vec4	diff_col;
	float	ndotl;

	light = compute_light(s, hit);
	ndotl = fmax(vec4_dot_prod(hit->norm, light.dir), 0.0f);
	shadow = compute_shadow(s, hit, light) * ndotl;
	diffuse = ndotl * shadow;
	diff_col = vec4_mul(hit->obj->col, s->l->col);
	diff_col = vec4_scalar_mul(diff_col, s->l->lum * diffuse);
	return (diff_col);
}

t_vec4	shade(t_scene *s, t_hit *hit)
{
	t_vec4	amb_col;
	t_vec4	diff_col;
	t_vec4	final_col;

	amb_col = compute_ambient(s, hit);
	diff_col = compute_diffuse(s, hit);
	final_col = vec4_add(amb_col, diff_col);
	final_col.r = fmin(final_col.r, 1.0f);
	final_col.g = fmin(final_col.g, 1.0f);
	final_col.b = fmin(final_col.b, 1.0f);
	return (final_col);
}
