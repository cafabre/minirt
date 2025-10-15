/* ************************************************************************** */
/*                                                                            */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:15:42 by rshin             #+#    #+#             */
/*   Updated: 2025/10/15 15:53:21 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		return (false);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "minirt");
	if (e->win == NULL)
	{
		mlx_destroy_display(e->mlx);
		free(e->mlx);
		return (false);
	}
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	if (!e->img)
	{
		return (false);
	}
	return (true);
	e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->Bpp = e->bpp / 8; 
	e->max_bytes = WIN_H * e->size_line;
}

t_mat4	view_mat(t_cam *c)
{
	t_vec4	fwd;
	t_vec4	world_up;
	t_vec4	rgt;
	t_vec4	up;
	t_mat4	v;

	fwd = vec4_norm(c->dir);
	world_up = new_vec4(0, 0, 1);
	rgt = vec4_norm(vec4_cross_prod(world_up, fwd));
	if (vec4_len(right) == 0) {
		world_up = new_vec4(1, 0, 0);
		right = vec4_norm(vec4_cross_prod(world_up, fwd));
	}
	up = vec4_cross_prod(fwd, right);
	v.m[0][0] = rgt.x;
	v.m[1][0] = rgt.y;
	v.m[2][0] = rgt.z;
	v.m[3][0] = 0;
	v.m[0][1] = up.x;
	v.m[1][1] = up.y;
	v.m[2][1] = up.z;
	v.m[3][1] = 0;
	v.m[0][2] = -fwd.x;
	v.m[1][2] = -fwd.y;
	v.m[2][2] = -fwd.z;
	v.m[3][2] = 0;
	v.m[0][3] = -(rgt.x * c->pos.x + rgt.y * c->pos.y + rgt.z * c->pos.z);
	v.m[1][3] = -(up.x * c->pos.x + up.y * c->pos.y + up.z * c->pos.z);
	v.m[2][3] =  (fwd.x * c->pos.x + fwd.y * c->pos.y + fwd.z * c->pos.z);
	v.m[3][3] = 1;
	return (v);
}

static void	compute_cache(t_scene *s)
{
	s->cache.cx = (float)WIN_W * 0.5f;
	s->cache.cy = (float)WIN_H * 0.5f;
	s->cache.aspect_ratio = (float)WIN_W / (float)WIN_H;
	s->cache.fov_scale = tanf((s->cam.fov * 0.5f) * (M_PI / 180.0f));
	s->cache.cx_aspect = s->cache.cx * s->cache.aspect_ratio;
	s->cache.cy_scale = s->cache.cy * s->cache.fov_scale;
}

bool	render_scene(t_env *e)
{
	t_mat4	view_mat;
	t_pix	pix;
	t_vec4	ray;

	if (!init_mlx(e))
		return (false);
	compute_cache(e->scene);
	view_mat = view_mat(e->scene->cam);
	ft_memset(&pix, 0, sizeof(t_pix));
	while (pix.y < WIN_H)
	{
		pix.x = 0;
		while (pix.x < WIN_W)
		{
			ray = compute_ray(e->scene, pix);
			pix.col.val = cast_ray(e->scene, ray);
			set_pixel(e, pix);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (true);
}
