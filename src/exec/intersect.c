/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2026/01/13 09:59:24 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

static float	intersect_sphere(t_ray *r, t_obj *sp)
{
	t_quad	q;
	t_vec4	oc;

	oc = vec4_sub(r->pos, sp->pos);
	q.a = vec4_dot_prod(r->dir, r->dir);
	q.b = 2 * vec4_dot_prod(oc, r->dir);
	q.c = vec4_dot_prod(oc, oc) - pow(sp->rad, 2);
	return (solve_quad(q));
}

static float	intersect_plane(t_ray *r, t_obj *pl)
{
	t_vec4	oc;
	float	denom;
	float	t;

	oc = vec4_sub(pl->pos, r->pos);
	denom = vec4_dot_prod(pl->dir, r->dir);
	if (fabs(denom) < 1e-6)
		return (INFINITY);
	t = vec4_dot_prod(oc, pl->dir) / denom;
	if (t > 0.0)
		return (t);
	return (INFINITY);
}

static float	intersect_cylinder(t_ray *r, t_obj *cy)
{
	float	tube_t;
	float	cap_t;
	float	h;
	t_vec4	p;

	tube_t = intersect_tube(r, cy);
	if (tube_t != INFINITY)
	{
		p = vec4_add(r->pos, vec4_scalar_mul(r->dir, tube_t));
		h = vec4_dot_prod(vec4_sub(p, cy->pos), cy->dir);
		if (h < -cy->height / 2.0f || h > cy->height / 2.0f)
			tube_t = INFINITY;
	}
	cap_t = min_positive(intersect_disc(r, cy, 1), intersect_disc(r, cy, -1));
	return (min_positive(tube_t, cap_t));
}

static float	intersect_obj(t_ray *ray, t_obj *obj)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, obj));
	else if (obj->type == PLANE)
		return (intersect_plane(ray, obj));
	else if (obj->type == CYLINDER)
		return (intersect_cylinder(ray, obj));
	return (INFINITY);
}

t_obj	*compute_nearest_obj(t_scene *s, t_ray *ray, t_obj *ignore)
{
	t_obj	*curr;
	t_obj	*nearest;
	float	t;

	ray->t = INFINITY;
	nearest = NULL;
	curr = s->objs;
	while (curr)
	{
		if (curr == ignore)
		{
			curr = curr->next;
			continue ;
		}
		t = intersect_obj(ray, curr);
		if (t > 0.00001f && t < ray->t)
		{
			ray->t = t;
			nearest = curr;
		}
		curr = curr->next;
	}
	return (nearest);
}
