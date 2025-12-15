/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:45 by rshin             #+#    #+#             */
/*   Updated: 2025/12/15 14:29:41 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "vec4.h"

# define WIN_W 1600
# define WIN_H 900
# define ESC_KEY 65307

/*---STRUCTURES---*/

typedef enum e_objtype
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_objtype;

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	col;
}	t_pix;

typedef struct s_ray
{
	t_vec4	pos;
	t_vec4	dir;
	t_vec4	norm;
	t_vec4	hit;
	float	t;
	float	t_min;
	float	t_max;
	t_vec4	color;
	int		recur_depth;
}	t_ray;

typedef struct parse {
	struct t_object;
	struct t_light;
	struct t_camera;
} t_parse;

typedef struct s_object
{
	enum e_objtype	type;
	t_vec4			pos;
	t_vec4			dir;
	float			diam;
	float			height;
	float			rad;
	t_vec4			col;
	struct s_object	*next;
}	t_obj;

typedef struct s_light
{
	t_vec4			pos;
	t_vec4			col;
	float			lum;
	struct s_light	*next;
}	t_light;

typedef struct s_camera
{
	t_vec4		pos;
	t_vec4		dir;
	int			fov;
}	t_cam;

typedef struct s_cache
{
	float	cx;
	float	cy;
	float	fov_scale;
	float	aspect_ratio;
	float	cx_aspect;
	float	cy_scale;
	t_vec4	bg_col;
	t_mat4	view_mat;
}	t_cache;

typedef struct s_scene
{
	struct s_light			*amb;
	struct s_light			*l;
	struct s_camera			*cam;
	struct s_object			*objs;
	struct s_object			*pl;
	struct s_object			*sp;
	struct s_object			*cy;
	struct s_cache			cache;
}	t_scene;

typedef struct s_environment
{
	struct s_scene	*scene;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				max_bytes;
	int				bytes_pp;
	int				bpp;
	int				size_line;
	int				endian;
	int				fd;
}	t_env;

/*---FUNCTIONS---*/

bool	render_scene(t_env *env);
t_obj	*compute_nearest_obj(t_scene *s, t_ray *ray);

t_scene	*create_scene(void); //fonction temporaire en attendant full parsing

int		close_win(void *param);
void	hook_controls(t_env *env);

int	init_cam(char **args, t_scene *scene);
int	init_ambient(char **args, t_scene *scene);
int	init_light(char **args, t_scene *scene);
int	init_obj(char **args, t_scene *scene, t_objtype objt);

int		ft_accept_chars(char *str, char *ref);
int		ft_accept_char(char *ref, char letter);
void	replace_char(char **str, char old, char new);

void	print_scene(t_scene *scene);

void	free_env(t_env *env);
void	free_scene(t_scene *scene);
void	free_splitted(char **args);

/********** PARSING **********/
/*** dispatcher.c ***/
bool  dispatch_ids(char **tab, t_scene *s);

/*** dispatch_scene.c ***/
bool dispatch_scene(char **tab, t_scene *s);

/*** dispatch_obj.c ***/
bool dispatch_obj(char **tab, t_scene *s);

/*** objects.c ***/
void    fill_cylinder_data(char **tab);
void    fill_plane_data(char **tab);
void    fill_sphere_data(char **tab);

/*** parsing_utils.c ***/
t_vec4  parse_vector(char **coords, int type);

/*** parsing.c ***/
int     parsing(int fd, t_scene *s);

/*** scene.c ***/
void    fill_camera_data(char **tab);
void    fill_light_data(char **tab, bool amb);

/*** values_check.c ***/
char **check_coords_range(char *s, float r_min, float r_max);
char **check_coords(char *s);
bool check_val(char *s, float r_min, float r_max);

/*** clean.c ***/
void    free_tab(char **tab);
void    free_tabs(char **t1, char **t2, char **t3);

/********** LIBFT UTILS **********/
double	ft_atof(const char *nptr);
char	**ft_split_whitespaces(char const *s);
size_t  ft_count_whitespace(char *s);
int     ft_tablen(char **tab);
bool		ft_isnumber(char *s);

#endif
