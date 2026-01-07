/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:46:44 by rshin             #+#    #+#             */
/*   Updated: 2026/01/07 17:34:04 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static t_vec4	compute_ambient(t_scene *s, t_hit hit)
{
	t_vec4	ambient;
	t_vec4	amb_strength;
	t_vec4	amb_


    ambient = vec4_scalar_prod(vec4_mul(hit.obj->col, s->amb->col), s->amb->lum);
	return (ambient);
}

static t_vec4 compute_lighting(t_scene *s, t_ray hit)
{
	t_ray   light;
	t_vec4  ambient;
	float   light_dist;


	light.pos = vec4_add(hit.pos, vec4_scalar_prod(hit.dir, 0.001f));
	light.dir = vec4_norm(vec4_sub(s->l->pos, light.pos));
	light_dist = vec4_len(vec4_sub(s->l->pos, light.pos));
	float shadow_factor = 1.0f;
	if (compute_nearest_obj(s, &light, obj) && light.t < light_dist)
		shadow_factor = 0.0f;


	return (vec4_add(ambient, diff_col));
}

static t_vec4	compute_diffuse(t_scene *s, t_hit hit)
{
	float   diff;
	t_vec4  diff_col;

	diffuse = fmax(vec4_dot_prod(hit.norm, light.dir), 0.0f) * shadow_factor;




	diff_col = vec4_scalar_prod(vec4_mul(obj->col, s->l->col), diffuse * s->l->lum);
	return (diff_col);
}

static t_vec4	compute_
{
	
}

t_vec4	shade(t_scene *s, t_hit *hit)
{
	t_vec4	color;
	t_vec4	ambient;
	t_vec4	diffuse;

	ambient = compute_ambient(s, hit);
	diffuse = compute_diffuse(s, hit);
	color = vec4_add(ambient, diffuse);
	return (color);
}
