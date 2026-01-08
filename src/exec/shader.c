/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:46:44 by rshin             #+#    #+#             */
/*   Updated: 2026/01/08 13:59:14 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SHADOW_BIAS 0.001f

static t_vec4	compute_ambient(t_scene *s, t_hit *hit)
{
	t_vec4	amb_col;

    amb_col = vec4_scalar_prod(vec4_mul(hit->obj->col, s->amb->col), s->amb->lum);
	return (amb_col);
}

static float compute_shadow(t_scene *s, t_hit *hit, t_ray light)
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
	t_ray   light;

	light.dir = vec4_norm(vec4_sub(s->l->pos, hit->pos));
	light.pos = vec4_add(hit->pos, vec4_scalar_prod(light.dir, SHADOW_BIAS));
	light.t = vec4_len(vec4_sub(s->l->pos, light.pos));
	return (light);
}

static t_vec4	compute_diffuse(t_scene *s, t_hit *hit)
{
	t_ray   light;
	float	shadow;
	float   diffuse;
	t_vec4  diff_col;
	float	ndotl;

	light = compute_light(s, hit);
//	ndotl = vec4_dot_prod(hit->norm, light.dir);
	ndotl = fmax(vec4_dot_prod(hit->norm, light.dir), 0.0f);
//	if (ndotl <= 0.0f)
//		return (vec4_color(0, 0, 0));
	shadow = compute_shadow(s, hit, light) *ndotl;
	diffuse = ndotl * shadow;
	diff_col = vec4_scalar_prod(vec4_mul(hit->obj->col, s->l->col), diffuse * s->l->lum);
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
	static int triggered = 0;
	if (!triggered && (final_col.r > 1.0f || final_col.g > 1.0f || final_col.b > 1.0f))
	{
		printf("overflowed\n");
		printf("r = %f g = %f b = %f\n", final_col.r, final_col.g, final_col.b);
		triggered = 1;
	}
	final_col.r = fmin(final_col.r, 1.0f);
	final_col.g = fmin(final_col.g, 1.0f);
	final_col.b = fmin(final_col.b, 1.0f);
	return (final_col);
}
