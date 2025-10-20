/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2025/10/20 16:55:09 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	intersect_sphere(t_ray *r, t_obj *sp)
{
	t_vec4	s;
	double	b;
	double	c;
	double	delta;
	double	t;

	s = vec4_sub(r->pos, sp->pos);
	b = vec4_dot_prod(s, r->dir);
	c = vec4_dot_prod(s, s) - sp->rad * sp->rad;
	delta = b * b - c;
	if (delta < 0.0)
		return (INFINITY);
	delta = sqrt(delta);
	t = -b - delta;
	if (t < 0.0)
		return (INFINITY);
	return (t);
}

static float	intersect_plane(t_ray *r, t_obj *pl)
{	
	t_vec4	diff;
	float	div;
	float	t;

	diff = vec4_sub(pl->pos, r->pos);
	div = vec4_dot_prod(pl->dir, r->dir);
	if (fabs(div) < 1e-6)
		return (INFINITY);
	t = vec4_dot_prod(diff, pl->dir) / div;
	if (t < 0.0)
		return (INFINITY);
	return (t);
}

t_obj   *compute_nearest_obj(t_scene *s, t_ray *ray)
{
	t_obj	*curr;
	t_obj	*keep;
	double	t;

	ray->t = INFINITY;
	keep = NULL;
	curr = s->objs;
	while (curr)
	{
		if (curr->type == SPHERE)
			t = intersect_sphere(ray, curr);
		else if (curr->type == PLANE)
			t = intersect_plane(ray, curr);
		if (t < ray->t)
		{
			keep = curr;
			ray->t = t;
		}
		curr = curr->next;
	}
	if (ray->t == INFINITY)
		return (NULL);
	ray->hit = vec4_add(ray->pos, vec4_scalar_prod(ray->dir, ray->t));
	return (keep);
}
