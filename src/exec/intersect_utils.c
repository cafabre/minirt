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

static float solve_quad(t_quad q)
{
	float	t_in;
	float	t_out;

	if (q.delta >= 0)
	{
		t_in = (-q.b - sqrt(q.delta)) / (2 * q.a);
		t_out = (-q.b + sqrt(q.delta)) / (2 * q.a);
		return (min_positive(t_in, t_out));
	}
	return (INFINITY);
}

static float	intersect_tube(t_ray *r, t_obj *cy)
{
	t_vec4	s;
	t_vec4	a_perp;
	t_vec4	d_perp;
	t_quad	q;

	s = vec4_sub(r->pos, cy->pos);
	a_perp = vec4_sub(s, vec4_scalar_prod(cy->dir, vec4_dot_prod(s, cy->dir)));
	d_perp = vec4_sub(r->dir, vec4_scalar_prod(cy->dir, vec4_dot_prod(r->dir, cy->dir)));
	q.a = vec4_dot_prod(d_perp, d_perp);
	q.b = 2 * vec4_dot_prod(a_perp, d_perp);
	q.c = vec4_dot_prod(a_perp, a_perp) - pow(cy->rad, 2);
	q.delta = pow(q.b, 2) - 4 * q.a * q.c;
	return (solve_quad(q));
}

float	height_filter(t_ray *r, t_obj *cy)
{
	float	t;
	float	h;

	t = intersect_tube(r, cy);
	if (t == INFINITY)
		return (t);
	h = vec4_dot_prod(vec4_sub(vec4_add(r->pos, vec4_scalar_prod(r->dir, t)), cy->pos), cy->dir);
	if (-cy->height / 2.0f <= h && h <= cy->height / 2.0f)
		return (t);
	return (INFINITY);
}

static float	intersect_disc(t_ray *r, t_obj *cy, int side)
{
	t_vec4	cap_center;
	t_vec4	p;
	t_vec4	d;
	float	denom;
	float	t;

	if (side == 1)
		cap_center = vec4_add(cy->pos, vec4_scalar_prod(cy->dir, cy->height / 2.0f));
	else
		cap_center = vec4_sub(cy->pos, vec4_scalar_prod(cy->dir, cy->height / 2.0f));
	denom = vec4_dot_prod(r->dir, cy->dir);
	if (fabs(denom) < 1e-6)
		return (INFINITY);
	t = vec4_dot_prod(vec4_sub(cap_center, r->pos), cy->dir) / denom;
	if (t < 0)
		return (INFINITY);
	p = vec4_add(r->pos, vec4_scalar_prod(r->dir, t));
	d = vec4_sub(p, cap_center);
	if (vec4_dot_prod(d, d) > pow(cy->rad, 2))
		return (INFINITY);
	return (t);
}

float	intersect_caps(t_ray *r, t_obj *cy)
{
	float	t1;
	float	t2;

	t1 = intersect_disc(r, cy, 1);
	t2 = intersect_disc(r, cy, -1);
	return (min_positive(t1, t2));
}
