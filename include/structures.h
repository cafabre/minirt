/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:01:33 by syukna            #+#    #+#             */
/*   Updated: 2025/10/15 16:22:34 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "vec4.h"

// MODULES

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

// Enum for object types
typedef enum e_objtype
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_objtype;

// OBJECTS

typedef struct	s_pixel
{
	int		x;
	int		y;
	t_color	col;
}	t_pix;

typedef struct	s_object
{
	enum e_objtype	type;
	t_vec4			pos;
	t_vec4			dir;
	float			diam;
	float			height;
	struct s_color	col;
	struct s_object	*next_objs;
	struct s_object	*next;
}	t_obj;

// TOOLS
typedef struct  s_light
{
	t_vec4			pos;
	float			bri;
	struct s_color	col;
    struct s_light	*next;
}	t_light;

typedef struct  s_camera
{
	t_vec4		pos;
	t_vec4		dir;
	int			fov;
	float		fov_scale;
	float		aspect_ratio;
}	t_cam;

typedef struct	s_cache_param
{
	float	fov_scale;
	float	aspect_ratio;
	float	cx_scale;
	float	cy_scale;
}	t_cachep;

// SCENE
typedef struct  s_scene
{
	struct s_light	*amb;
	struct s_light	*l;
	struct s_camera	*cam;
	struct s_object	*objs;
	struct s_object	*pl;
	struct s_object	*sp;
	struct s_object	*cy;
	struct s_cache	*param;
}	t_scene;

typedef struct	s_environment
{
	struct s_scene	*scene;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				max_bytes;
	int				Bpp;
	int				bpp;
	int				size_line;
	int				endian;
}	t_env;

#endif
