/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2026/01/13 10:02:45 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	solve_quad(t_quad q)
{
	float	t_in;
	float	t_out;

	q.delta = pow(q.b, 2) - 4 * q.a * q.c;
	if (q.delta >= 0)
	{
		t_in = (-q.b - sqrt(q.delta)) / (2 * q.a);
		t_out = (-q.b + sqrt(q.delta)) / (2 * q.a);
		return (min_positive(t_in, t_out));
	}
	return (INFINITY);
}

float	intersect_tube(t_ray *r, t_obj *cy)
{
	t_vec4	oc;
	t_vec4	oc_perp;
	t_vec4	d_perp;
	t_quad	q;

	oc = vec4_sub(r->pos, cy->pos);
	oc_perp = vec4_scalar_prod(cy->dir, vec4_dot_prod(oc, cy->dir));
	oc_perp = vec4_sub(oc, oc_perp);
	d_perp = vec4_scalar_prod(cy->dir, vec4_dot_prod(r->dir, cy->dir));
	d_perp = vec4_sub(r->dir, d_perp);
	q.a = vec4_dot_prod(d_perp, d_perp);
	q.b = 2 * vec4_dot_prod(oc_perp, d_perp);
	q.c = vec4_dot_prod(oc_perp, oc_perp) - pow(cy->rad, 2);
	return (solve_quad(q));
}

float	intersect_disc(t_ray *r, t_obj *cy, int side)
{
	t_vec4	cap_center;
	t_vec4	p;
	t_vec4	d;
	float	denom;
	float	t;

	cap_center = vec4_scalar_prod(cy->dir, cy->height / 2.0f);
	if (side == 1)
		cap_center = vec4_add(cy->pos, cap_center);
	else
		cap_center = vec4_sub(cy->pos, cap_center);
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
