/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:38:02 by rshin             #+#    #+#             */
/*   Updated: 2026/01/12 15:15:19 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "mlx_int.h"
#include "mlx.h"

static bool	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		return (false);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "minirt");
	if (e->win == NULL)
		return (false);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	if (!e->img)
		return (false);
	e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->bytes_pp = e->bpp / 8;
	e->max_bytes = WIN_H * e->size_line;
	return (true);
}

static void	compute_cache(t_scene *s)
{
	s->cache.cx = (float)WIN_W * 0.5f;
	s->cache.cy = (float)WIN_H * 0.5f;
	s->cache.aspect_ratio = (float)WIN_W / (float)WIN_H;
	s->cache.fov_scale = tanf((s->cam->fov * 0.5f) * (M_PI / 180.0f));
	s->cache.cx_aspect = s->cache.cx * s->cache.aspect_ratio;
	s->cache.cy_scale = s->cache.cy * s->cache.fov_scale;
	s->cache.view_mat = get_inv_view_mat(s->cam);
	s->cache.bg_col = vec4_color(32, 32, 32);
}

static void	compute_ray(t_ray *ray, t_scene *s, t_pix p)
{
	t_vec4	d_local;
	t_vec4	d_world;
	float	ndc_x;
	float	ndc_y;

	ndc_x = (p.x + 0.5f) / WIN_W;
	ndc_y = (p.y + 0.5f) / WIN_H;
	ndc_x = (2.0f * ndc_x - 1.0f) * s->cache.aspect_ratio * s->cache.fov_scale;
	ndc_y = (1.0f - 2.0f * ndc_y) * s->cache.fov_scale;
	d_local = vec4_vector(ndc_x, ndc_y, 1.0f);
	d_local = vec4_norm(d_local);
	d_world = vec4_mat4_prod(d_local, &s->cache.view_mat);
	d_world = vec4_norm(d_world);
	ray->pos = s->cam->pos;
	ray->dir = d_world;
}

bool	render_scene(t_env *e)
{
	t_pix	pix;
	t_ray	ray;

	if (!init_mlx(e))
		return (false);
	compute_cache(e->scene);
	ft_memset(&pix, 0, sizeof(t_pix));
	while (pix.y < WIN_H)
	{
		pix.x = 0;
		while (pix.x < WIN_W)
		{
			ft_memset(&ray, 0, sizeof(t_ray));
			compute_ray(&ray, e->scene, pix);
			pix.col = trace_ray(e->scene, &ray);
			set_pixel(e, pix);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (true);
}
