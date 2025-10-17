/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:37 by rshin             #+#    #+#             */
/*   Updated: 2025/10/17 12:55:10 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double  intersect_sphere(t_cam *cam, t_vec4 *r, t_obj *sp)
{
	t_vec4	s;
	double	b;
	double	c;
	double	delta;
	double	t;

	s = vec4_sub(cam->pos, sp->pos);
	b = vec4_dot_prod(s, *r);
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

t_obj   *compute_nearest_obj(t_scene *s, t_vec4 *ray)
{
	t_obj	*curr;
	t_obj	*keep;
	double	mag;
	double	t;

	mag = INFINITY;
	keep = NULL;
	curr = s->objs;
	while (curr)
	{
		if (curr->type == SPHERE)
			t = intersect_sphere(s->cam, ray, curr);
		if (t < mag)
		{
			keep = curr;
			mag = t;
		}
		curr = curr->next;
	}
	if (mag == INFINITY)
		return (NULL);
	*ray = vec4_add(s->cam->pos, vec4_scalar_prod(*ray, mag));
	return (keep);
}
