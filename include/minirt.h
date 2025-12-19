/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:45 by rshin             #+#    #+#             */
/*   Updated: 2025/12/19 16:22:00 by cafabre          ###   ########.fr       */
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
	CYLINDER,
}	t_objtype;

typedef enum e_error //erreurs de parsing uniquement
{
    ERR_NONE,
	ERR_INVALID_ARGS_COUNT,
	ERR_INVALID_FILE_TYPE,
	ERR_INVALID_FILE_NAME,
    ERR_OPEN,
    ERR_EMPTY_FILE,
    ERR_INVALID_ARGS_LINE,
    ERR_INVALID_VALUE_RANGE,
    ERR_INVALID_ID,
    ERR_DUPLICATE_AMBIENT,
    ERR_DUPLICATE_LIGHT,
    ERR_DUPLICATE_CAMERA,
    ERR_MALLOC_AMBIENT,
    ERR_MALLOC_LIGHT,
    ERR_MALLOC_CAMERA,
    ERR_MALLOC_SPHERE,
    ERR_MALLOC_PLANE,
    ERR_MALLOC_CYLINDER,
    ERR_ADD_SPHERE,
    ERR_ADD_PLANE,
    ERR_ADD_CYLINDER,
    ERR_INVALID_SPHERE_DATA,
    ERR_INVALID_PLANE_DATA,
    ERR_INVALID_CYLINDER_DATA,
    ERR_INVALID_AMBIENT_DATA,
    ERR_INVALID_LIGHT_DATA,
    ERR_INVALID_CAMERA_DATA,
    ERR_INVALID_VECTOR_COORDS,
	ERR_MISSING_ELEMENT,
}	t_error;

//pour preciser les messages d erreur si necessaire
typedef enum e_err_detail
{
	DETAIL_NONE,
	DETAIL_OUT_OF_RANGE,
	DETAIL_NOT_A_NUMBER,
	DETAIL_BAD_FORMAT,
} t_err_detail;

typedef struct s_data
{
	t_error error;
	t_err_detail detail;
}	t_data;

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
	float	t;
	size_t	rebound;
}	t_ray;

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

typedef struct s_coords
{
	char		**coords;
	char		**coords_r;
	char		**coords_r2;
} 	t_coords;

/*---FUNCTIONS---*/

unsigned int	pack_to_uint(t_vec4 color);
void	set_pixel(t_env *e, t_pix p);
t_mat4	get_inv_view_mat(const t_cam *c);

bool	render_scene(t_env *env);
t_obj	*compute_nearest_obj(t_scene *s, t_ray *ray, t_obj *ignore);
unsigned int	trace_ray(t_scene *s, t_ray *ray);

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
bool  dispatch_ids(char **tab, t_scene *s, t_data *data);

/*** dispatch_scene.c ***/
bool dispatch_scene(char **tab, t_scene *s, t_data *data);

/*** dispatch_obj.c ***/
bool dispatch_obj(char **tab, t_scene *s, t_data *data);

/*** parsing_utils.c ***/
t_vec4  parse_vector(char **coords, int type, t_data *data);

/*** parsing.c ***/
int     parsing(int fd, t_scene *s, t_data *data);

/*** values_check.c ***/
char **check_coords_range(char *s, float r_min, float r_max, t_data *data);
char **check_coords(char *s, t_data *data);
bool check_val(char *s, float r_min, float r_max, t_data *data);

/*** clean.c ***/
void    free_tab(char **tab);
void    free_tabs(char **t1, char **t2, char **t3);

/*** misconfig.c ***/
void    display_error_message(t_data *data);

/*** misconfig_utils.c ***/
bool display_input_error(t_error e);
void display_file_error(t_error e);
void display_alloc_error(t_error e);
void display_data_error(t_error e);

/*** create.c ***/ //-> pas dans le parsing
t_cam	*create_cam(t_vec4 point, t_vec4 vec, float f);
t_light	*create_light(t_vec4 point, float light, t_vec4 color);
t_light	*create_amb(float light, t_vec4 rgb);
t_obj	*create_sp(t_vec4 point, float d, t_vec4 color);
t_obj	*create_pl(t_vec4 point, t_vec4 vec, t_vec4 color);
t_obj	*create_cy(t_vec4 point, t_vec4 vec, float d, float h, t_vec4 color);
t_scene	*create_scene(void);

/********** LIBFT UTILS **********/
double	ft_atof(const char *nptr);
char	**ft_split_whitespaces(char *s);
size_t  ft_count_whitespace(char *s);
int     ft_tablen(char **tab);
bool		ft_isnumber(char *s);

//fonction de tests, a supprimer
void	display_scene(t_scene *s);

#endif
