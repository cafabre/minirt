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

static void	set_pixel(t_env *e, t_pix p)
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
	}
}

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
	e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->bytes_pp = e->bpp / 8; 
	e->max_bytes = WIN_H * e->size_line;
	return (true);
}

t_mat4	view_mat(t_cam *c)
{
	t_vec4	fwd;
	t_vec4	world_up;
	t_vec4	rgt;
	t_vec4	up;
	t_mat4	v;

	fwd = vec4_norm(c->dir);
	//world_up = vec4_vector(0, 0, 1);
	world_up = vec4_vector(0, 1, 0);
	rgt = vec4_norm(vec4_cross_prod(world_up, fwd));
	if (vec4_len(rgt) == 0)
	{
		world_up = vec4_vector(1, 0, 0);
		rgt = vec4_norm(vec4_cross_prod(world_up, fwd));
	}
	up = vec4_cross_prod(fwd, rgt);
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
	s->cache.fov_scale = tanf((s->cam->fov * 0.5f) * (M_PI / 180.0f));
	s->cache.cx_aspect = s->cache.cx * s->cache.aspect_ratio;
	s->cache.cy_scale = s->cache.cy * s->cache.fov_scale;
}

void	compute_ray(t_ray *ray, t_scene *s, t_pix p, t_mat4 view_mat)
{
	t_vec4	d_local;
	t_vec4	d_world;

	d_local.x = (p.x + 0.5f - s->cache.cx) / s->cache.cx;
	d_local.x /= s->cache.aspect_ratio;
	d_local.y = (s->cache.cy - p.y + 0.5f) / s->cache.cy;
//	d_local.x *= s->cache.fov_scale;
	d_local.y *= s->cache.fov_scale;
//	d_local.y = -d_local.y;
	d_local.z = -1.0f;
	d_local = vec4_norm(d_local);
	d_world = vec4_mat4_prod(d_local, view_mat);
//	d_world = vec4_norm(d_world);
	ray->pos = s->cam->pos;
	ray->dir = d_world;
}

unsigned int	trace_ray(t_scene *s, t_ray *ray)
{
	t_vec4	color;
	t_obj	*target;
	t_ray	shadow;
	t_ray	light;
	float	diffuse;

	target = compute_nearest_obj(s, ray);
	if (target == NULL)
		return (pack_to_uint(s->amb->col));
	ray->recur_depth++;
	if (target->type == SPHERE)
		ray->norm = vec4_norm(vec4_sub(ray->hit, target->pos));
	else
		ray->norm = vec4_norm(vec4_sub(ray->hit, target->dir));
	shadow.pos = vec4_add(ray->hit, vec4_scalar_prod(ray->norm, 0.001f));
	light.dir = vec4_norm(vec4_sub(s->l->pos, ray->hit));
	light.t = vec4_len(vec4_sub(s->l->pos, shadow.pos));
	shadow.dir = light.dir;
	diffuse = fmax(vec4_dot_prod(ray->norm, light.dir), 0.0);
	color = vec4_scalar_prod(target->col, diffuse * s->l->col.a);
	target = compute_nearest_obj(s, &shadow);
	if (target)
		return (pack_to_uint(s->amb->col));
	return (pack_to_uint(color));
}

bool	render_scene(t_env *e)
{
	t_mat4	view;
	t_pix	pix;
	t_ray	ray;

	if (!init_mlx(e))
		return (false);
	compute_cache(e->scene);
	view = view_mat(e->scene->cam);
	ft_memset(&pix, 0, sizeof(t_pix));
	ft_memset(&ray, 0, sizeof(t_ray));
	pix.y = e->scene->cache.cy;
	while (pix.y < WIN_H)
	{
		pix.x = e->scene->cache.cx;
//		pix.x = 0;
		while (pix.x < WIN_W)
		{
			compute_ray(&ray, e->scene, pix, view);
			pix.col = trace_ray(e->scene, &ray);
			set_pixel(e, pix);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (true);
}
