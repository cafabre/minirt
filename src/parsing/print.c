/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:57 by syukna            #+#    #+#             */
/*   Updated: 2025/10/12 15:32:12 by sandykds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_coor(t_vec3 *coor)
{
	printf("        Coor: X=%f Y=%f Z=%f\n", coor->x, coor->y, coor->z);
}
void	print_vector(t_vec3 *vector)
{
	printf("        vector: %f,%f,%f\n",vector->x, vector->y, vector->z);
}

void	print_color(t_color *color)
{
	printf("        Color: X=%d Y=%d Z=%d\n", color->r, color->g, color->b);
}

void	print_cam(t_cam *cam)
{
	printf("      **************************************************************\n");
	printf("      CAMERA\n");
	print_coor(&cam->coor);
	print_vector(&cam->vector);
	printf("        Field of view = %d\n", cam->fov);
	printf("      **************************************************************\n");
}

void	print_light(t_light *light, int amb)
{
	printf("      **************************************************************\n");
	if (amb)
		printf("      AMBIENT LIGHT\n");
	else
		printf("      LIGHT\n");
	print_coor(&light->coor);
	printf("        Brightness = %f\n", light->bri);
	print_color(&light->color);
	printf("      **************************************************************\n");
}

void	print_planes(t_obj *obj)
{
	t_obj	*temp;

	temp = obj;
	printf("      **************************************************************\n");
	printf("      PLANES\n");
	while (temp)
	{
		printf("        TYPE = %d\n", temp->type);
		if (&temp->coor)
      print_coor(&temp->coor);
    if (&temp->vector)
		  print_vector(&temp->vector);
    if (temp->diameter)
		  printf("        Diameter: %f\n", temp->diameter);
    if (temp->height)
		printf("        Height: %f\n", temp->height);
    if (&temp->color)
		  print_color(&temp->color);
		temp = temp->next;
		printf("      ********************\n");
	}
	printf("      **************************************************************\n");
}

void	print_obj(t_obj *obj)
{
	t_obj	*temp;

	temp = obj;
	printf("      **************************************************************\n");
	printf("      OBJECTS\n");
	while (temp)
	{
		printf("        TYPE = %d\n", temp->type);
		if (&temp->coor)
      print_coor(&temp->coor);
    if (&temp->vector)
		  print_vector(&temp->vector);
    if (temp->diameter)
		  printf("        Diameter: %f\n", temp->diameter);
    if (temp->height)
		printf("        Height: %f\n", temp->height);
    if (&temp->color)
		  print_color(&temp->color);
		temp = temp->next_objs;
		printf("      ********************\n");
	}
	printf("      **************************************************************\n");
}

void	print_scene(t_scene *scene)
{
	printf("\n\n**************************************************************************\n");
	printf("     SCENE\n\n");
	if (scene->cam)
		print_cam(scene->cam);
	if (scene->amb)
		print_light(scene->amb, 1);
	if (scene->l)
		print_light(scene->l, 0);
	if (scene->objs)
		print_obj(scene->objs);
	if (scene->pl)
		print_planes(scene->pl);
	printf("**************************************************************************\n");
}
