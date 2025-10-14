/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:01:33 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 12:10:04 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "vec4.h"

// MODULES
typedef struct	s_color t_color;
typedef struct	s_obj t_obj;
typedef struct	s_light t_light;
typedef struct	s_cam t_cam;
typedef struct	s_scene t_scene;

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

typedef struct	s_obj
{
	t_objtype	type;
	t_vec4		coor;
	t_vec4		vector;
	float		diameter;
	float		height;
	t_color		color;
	t_obj		*next_objs;
	t_obj		*next;
}	t_obj;

// TOOLS
typedef struct  s_light
{
	t_vec4		coor;
	float		bri;
	t_color		color;
    t_light		*next;
}	t_light;

typedef struct  s_cam
{
	t_vec4		coor;
	t_vec4		vector;
	int			fov;
}	t_cam;

// SCENE
typedef struct  s_scene
{
	t_light	*amb;
	t_light	*l;
	t_cam	*cam;
	t_obj	*objs;
	t_obj	*pl;
	t_obj	*sp;
	t_obj	*cy;
}	t_scene;

#endif
