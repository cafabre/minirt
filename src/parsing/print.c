/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:57 by syukna            #+#    #+#             */
/*   Updated: 2025/10/09 12:40:40 by syukna           ###   ########.fr       */
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

void	print_planes(t_plane *plane)
{
	t_plane	*temp;
	
	temp = plane;
	printf("      **************************************************************\n");
	printf("      PLANES\n");
	while (temp)
	{
		printf("         Plane\n");
		print_coor(&temp->coor);
		print_vector(&temp->vector);
		print_color(&temp->color);
		temp = temp->next;
		printf("      ********************\n");
	}
	printf("      **************************************************************\n");
}

void	print_spheres(t_sphere *sphere)
{
	t_sphere	*temp;
	
	temp = sphere;
	printf("      **************************************************************\n");
	printf("      SPHERES\n");
	while (temp)
	{
		printf("         Sphere\n");
		print_coor(&temp->coor);
		printf("        Diameter: %f\n", temp->diameter);
		print_color(&temp->color);
		temp = temp->next;
		printf("      ********************\n");
	}
	printf("      **************************************************************\n");
}

void	print_cyl(t_cyl *cyl)
{
	t_cyl	*temp;
	
	temp = cyl;
	printf("      **************************************************************\n");
	printf("      CYLINDERS\n");
	while (temp)
	{
		printf("         Cylinder\n");
		print_coor(&temp->coor);
		print_vector(&temp->vector);
		printf("        Diameter: %f\n", temp->diameter);
		printf("        Height: %f\n", temp->height);
		print_color(&temp->color);
		temp = temp->next;
		printf("      ********************\n");
	}
	printf("      **************************************************************\n");
}

void	print_scene(t_scene *scene)
{
	printf("\n\n**************************************************************************\n");
	printf("     SCENE\n\n");
	if (scene->amb)
		print_light(scene->amb, 1);
	if (scene->l)
		print_light(scene->l, 0);
	if (scene->pl)
		print_planes(scene->pl);
	if (scene->sp)
		print_spheres(scene->sp);
	if (scene->cy)
		print_cyl(scene->cy);
	printf("**************************************************************************\n");
}