/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:57 by syukna            #+#    #+#             */
/*   Updated: 2025/10/06 15:58:33 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_coor(t_coor *coor)
{
	printf("        Coor: X=%f Y=%f Z=%f\n", coor->x, coor->y, coor->z);
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

void	print_scene(t_scene *scene)
{
	printf("\n\n**************************************************************************\n");
	printf("     SCENE\n\n");
	if (scene->amb)
		print_light(scene->amb, 1);
	if (scene->l)
		print_light(scene->l, 0);
	printf("**************************************************************************\n");
}