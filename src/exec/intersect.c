/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2026/01/07 18:11:28 by cafabre          ###   ########.fr       */
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
	float	t_in;
	float	t_out;
	
	//calcul distance du rayon a l axe du cylindre

	//comment savoir si un point est entre les caps ?

	//filtre de hauteur

	return (min_positive(t_in, t_out));
}

//side = 1 pour cap "haut", side = -1 pour cap "bas"
static float	intersect_disc(t_ray *r, t_obj *cy, int side)
{
	//comment trouver le centre du cap a partir de pos, dir et height ?
}

static float	intersect_caps(t_ray *r, t_obj *cy)
{
	float	t1;
	float	t2;
	
	t1 = intersect_cap(r, cy, 1);
	t2 = intersect_cap(r, cy, -1);
	return (min_positive(t1, t2));
}

static float	intersect_cy(t_ray *r, t_obj *cy)
{
	//le cylindre a : un centre (t_vec4 pos), un axe (t_vec4 dir)
	//une hauteur (float height) et un rayon (float rad)
	float	tube_t;
	float	cap_t;
	
	//test tube
	tube_t = intersect_tube(r, cy);
	
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
