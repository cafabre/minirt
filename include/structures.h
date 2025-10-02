/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:01:33 by syukna            #+#    #+#             */
/*   Updated: 2025/10/02 17:23:52 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct  s_color t_color;
typedef struct  s_plane t_plane;
typedef struct  s_sphere t_sphere;
typedef struct  s_cyl t_cyl;
typedef struct  s_light t_light;
typedef struct  s_cam t_cam;
typedef struct  s_scene t_scene;

typedef struct  s_coor
{
	float	x;
	float	y;
	float	z;
}				t_coor;

typedef struct  s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

// OBJECTS
typedef struct  s_plane
{
	t_coor		coor;
	float		rot[3];
	t_color		*color;
    t_plane		*next;
}				t_plane;

typedef struct  s_sphere
{
	t_coor		coor;
	int			diameter;
	t_color		*color;
    t_sphere	*next;
}				t_sphere;

typedef struct  s_cyl
{
	t_coor		coor;
	float		rot[3];
	float		diameter;
	float		height;
	t_color		*color;
    t_cyl		*next;
}				t_cyl;

// TOOLS
typedef struct  s_light
{
	t_coor		coor;
	float		bri;
	t_color		color;
    t_light		*next;
}				t_light;

typedef struct  s_cam
{
	t_coor		coor;
	float		rot[3];
	int			fov;
}				t_cam;

// SCENE
typedef struct  s_scene
{
	t_light		*amb;
    t_plane		*pl;
    t_sphere	*sp;
	t_cyl		*cy;
	t_light		*l;
	t_cam		*cam;
}               t_scene;

#endif