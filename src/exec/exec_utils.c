/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:02:23 by rshin             #+#    #+#             */
/*   Updated: 2025/12/15 14:02:30 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	pack_to_uint(t_vec4 color)
{
	unsigned int	packed;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;

	r = (unsigned int)(color.r * 255.0f + 0.5f);
	g = (unsigned int)(color.g * 255.0f + 0.5f);
	b = (unsigned int)(color.b * 255.0f + 0.5f);
	a = (unsigned int)(color.a * 255.0f + 0.5f);
	packed = (a << 24) | (r << 16) | (g << 8) | b;
	return (packed);
}

void	set_pixel(t_env *e, t_pix p)
{
	int	offset;

	offset = p.y * e->size_line + p.x * e->bytes_pp;
	if (p.x < 0 || p.y < 0 || p.x >= WIN_W || p.y >= WIN_H)
		return ;
	if (offset < e->max_bytes)
	{
		e->addr[offset] = p.col & 0xFF;
		e->addr[offset + 1] = (p.col >> 8) & 0xFF;
		e->addr[offset + 2] = (p.col >> 16) & 0xFF;
		e->addr[offset + 3] = (p.col >> 24) & 0xFF;
	}
}

t_mat4	get_inv_view_mat(const t_cam *c)
{
	t_vec4	fwd;
	t_vec4	world_up;
	t_vec4	rgt;
	t_vec4	up;
	t_mat4	v;

	fwd = vec4_norm(c->dir);
	world_up = vec4_vector(0, 1, 0);
	rgt = vec4_norm(vec4_cross_prod(world_up, fwd));
	if (vec4_len(rgt) == 0)
	{
		world_up = vec4_vector(1, 0, 0);
		rgt = vec4_norm(vec4_cross_prod(world_up, fwd));
	}
	up = vec4_cross_prod(fwd, rgt);
	v.m[0] = rgt;
	v.m[0].w = c->pos.x;
	v.m[1] = up;
	v.m[1].w = c->pos.y;
	v.m[2] = fwd;
	v.m[2].w = c->pos.z;
	v.m[3] = vec4_point(0, 0, 0);
	return (v);
}
