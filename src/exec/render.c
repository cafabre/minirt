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
	e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->bytes_pp = e->bpp / 8; 
	e->max_bytes = WIN_H * e->size_line;
	return (true);
}

void	compute_cache(t_scene *s)
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

t_vec4 get_object_normal(const t_obj *target, const t_vec4 hit)
{
	t_vec4	normal;

	if (target->type == SPHERE)
		normal = vec4_norm(vec4_sub(hit, target->pos));
	else if (target->type == PLANE)
		normal = target->dir;
	else
		normal = vec4_norm(vec4_sub(hit, target->dir));
	return (normal);
}

static t_vec4 compute_lighting(t_scene *s, t_obj *obj, t_vec4 normal, t_ray *shadow)
{
	t_vec4	ambient;
	float	diffuse;
	t_vec4	diff_col;
	t_vec4	color;
	
	ambient = vec4_scalar_prod(vec4_mul(obj->col, s->amb->col), s->amb->lum);
	diffuse = fmax(vec4_dot_prod(normal, shadow->dir), 0.0);
	diff_col = vec4_scalar_prod(vec4_mul(obj->col, s->l->col), diffuse * s->l->lum);
	color = vec4_add(ambient, diff_col);
	return (color);
}

static unsigned int	trace_ray(t_scene *s, t_ray *ray)
{
	t_obj	*blocker;
	t_obj	*obj;
	t_vec4	hit;
	float	light_dist;
	t_ray	shadow;
	t_vec4	normal;
	t_vec4	color;

	obj = compute_nearest_obj(s, ray);
	if (!obj)
		return (pack_to_uint(s->cache.bg_col));
	hit = vec4_add(ray->pos, vec4_scalar_prod(ray->dir, ray->t));
	normal = get_object_normal(obj, hit);
	shadow.pos = vec4_add(hit, vec4_scalar_prod(normal, 0.001f));
	shadow.dir = vec4_norm(vec4_sub(s->l->pos, shadow.pos));
	shadow.t = vec4_len(vec4_sub(s->l->pos, shadow.pos));
	light_dist = shadow.t;
	blocker = compute_nearest_obj(s, &shadow);
	if (blocker && shadow.t < light_dist)
	{
		color = vec4_scalar_prod(vec4_mul(obj->col, s->amb->col), s->amb->lum);
		return (pack_to_uint(color));
	}
	color = compute_lighting(s, obj, normal, &shadow);
	return (pack_to_uint(color));
}

bool	render_scene(t_env *e)
{
	t_pix	pix;
	t_ray	ray;

	if (!init_mlx(e))
		return (false);
	compute_cache(e->scene);
	ft_memset(&pix, 0, sizeof(t_pix));
	ft_memset(&ray, 0, sizeof(t_ray));
//	pix.y = e->scene->cache.cy;
	while (pix.y < WIN_H)
	{
//		pix.x = e->scene->cache.cx;
		pix.x = 0;
		while (pix.x < WIN_W)
		{
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
