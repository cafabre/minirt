/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2026/01/12 16:42:34 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	intersect_sphere(t_ray *r, t_obj *sp)
{
	t_vec4	s;
	t_quad	q;
	double	t;

	s = vec4_sub(r->pos, sp->pos);
	q.b = vec4_dot_prod(s, r->dir);
	q.c = vec4_dot_prod(s, s) - sp->rad * sp->rad;
	q.delta = q.b * q.b - q.c;
	if (q.delta < 0.0)
		return (INFINITY);
	q.delta = sqrt(q.delta);
	t = -q.b - q.delta;
	if (t > 0.0)
		return (t);
	return (INFINITY);
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
	if (t > 0.0)
		return (t);
	return (INFINITY);
}

static float	intersect_cy(t_ray *r, t_obj *cy)
{
	float	tube_t;
	float	cap_t;

	tube_t = height_filter(r, cy);
	cap_t = intersect_caps(r, cy);
	return (min_positive(tube_t, cap_t));
}

t_obj	*compute_nearest_obj(t_scene *s, t_ray *ray, t_obj *ignore)
{
	t_obj	*curr;
	t_obj	*keep;
	double	t;

	ray->t = INFINITY;
	keep = NULL;
	curr = s->objs;
	while (curr)
	{
		if (curr == ignore)
		{
			curr = curr->next;
			continue ;
		}
		if (curr->type == SPHERE)
			t = intersect_sphere(ray, curr);
		else if (curr->type == PLANE)
			t = intersect_plane(ray, curr);
		else if (curr->type == CYLINDER)
			t = intersect_cy(ray, curr);
		if (t > 0.00001f && t < ray->t)
		{
			ray->t = t;
			keep = curr;
		}
		curr = curr->next;
	}
	return (keep);
}
