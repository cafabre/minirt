/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:57 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 20:02:16 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_pos(t_vec4 *pos)
{
	printf("        Coor: X=%f Y=%f Z=%f\n", pos->x, pos->y, pos->z);
}
void	print_dir(t_vec4 *dir)
{
	printf("        vector: %f,%f,%f\n", dir->x, dir->y, dir->z);
}

void	print_color(t_color *color)
{
	printf("        Color: X=%d Y=%d Z=%d\n", color->r, color->g, color->b);
}

void	print_cam(t_cam *cam)
{
	printf("      **************************************************************\n");
	printf("      CAMERA\n");
	print_pos(&cam->pos);
	print_dir(&cam->dir);
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
	print_pos(&light->pos);
	printf("        Brightness = %f\n", light->bri);
	print_color(&light->col);
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
	//	if (&temp->pos)
	//		print_pos(&temp->pos);
	//	if (&temp->dir)
	//		print_dir(&temp->dir);
		if (temp->diam)
			printf("        Diameter: %f\n", temp->diam);
		if (temp->height)
			printf("        Height: %f\n", temp->height);
	//	if (&temp->col)
	//		print_color(&temp->col);
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
	//	if (&temp->pos)
	//		print_pos(&temp->pos);
	//	if (&temp->dir)
			print_dir(&temp->dir);
		if (temp->diam)
			printf("        Diameter: %f\n", temp->diam);
		if (temp->height)
			printf("        Height: %f\n", temp->height);
	//	if (&temp->col)
	//		print_color(&temp->col);
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
