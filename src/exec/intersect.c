/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2026/01/08 22:46:11 by cafabre          ###   ########.fr       */
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

static float	intersect_tube(t_ray *r, t_obj *cy)
{
	t_vec4	a;
	t_vec4	a_perp;
	t_vec4	d_perp;
	float	A;
	float	B;
	float	C;
	float	delta;
	float	t_in;
	float	t_out;
	
	a = vec4_sub(r->pos, cy->pos);
	a_perp = vec4_sub(a, vec4_scalar_prod(cy->dir, vec4_dot_prod(a, cy->dir)));
	d_perp = vec4_sub(r->dir, vec4_scalar_prod(cy->dir, vec4_dot_prod(r->dir, cy->dir)));
	A = vec4_dot_prod(d_perp, d_perp);
	B = 2 * vec4_dot_prod(a_perp, d_perp);
	C = vec4_dot_prod(a_perp, a_perp) - pow(cy->rad, 2);
	delta = pow(B, 2) - 4 * A * C;
	if (delta >= 0)
	{
		t_in = (-B - sqrt(delta)) / (2 * A);
		t_out = (-B + sqrt(delta)) / (2 * A);
		return (min_positive(t_in, t_out));
	}
	return (INFINITY);
}

static float	height_filter(t_ray *r, t_obj *cy)
{
	float	t;
	float	h;
	
	t = intersect_tube(r, cy);
	if (t == INFINITY)
		return (t);
	h = vec4_dot_prod(vec4_sub(vec4_add(r->pos,vec4_scalar_prod(r->dir, t)), cy->pos), cy->dir);
	if (0.0f <= h && h <= cy->height)
		return (t);
	return (INFINITY);
}

//side = 1 pour cap "haut", side = -1 pour cap "bas"
static float	intersect_disc(t_ray *r, t_obj *cy, int side)
{
	t_vec4	cap_center;
	t_vec4	p;
	t_vec4	d;
	float	denom;
	float	t;

	if (side == 1)
		cap_center = vec4_add(cy->pos, vec4_scalar_prod(cy->dir, cy->height));
	else
		cap_center = cy->pos;
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

static float	intersect_caps(t_ray *r, t_obj *cy)
{
	float	t1;
	float	t2;
	
	t1 = intersect_disc(r, cy, 1);
	t2 = intersect_disc(r, cy, -1);
	return (min_positive(t1, t2));
}

static float	intersect_cy(t_ray *r, t_obj *cy)
{
	//le cylindre a : un centre (t_vec4 pos), un axe (t_vec4 dir)
	//une hauteur (float height) et un rayon (float rad)
	float	tube_t;
	float	cap_t;
	
	//test tube
	tube_t = height_filter(r, cy);
	
	//test cercles extremites
	cap_t = intersect_caps(r, cy);
	
	//choix de la bonne collision : renvoie le t le + petit
	//existe t il un t tel que P(t) soit sur l objet ?
	return (min_positive(tube_t, cap_t));
}

t_obj   *compute_nearest_obj(t_scene *s, t_ray *ray, t_obj *ignore)
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
			continue;
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
