/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:06:56 by syukna            #+#    #+#             */
/*   Updated: 2025/10/12 14:46:54 by sandykds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_cam(char **args, t_scene *scene)
{
	t_cam *cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (EXIT_FAILURE);
	ft_memset(cam, '\0', sizeof(t_cam));
	cam->coor = init_vec3();
	if (!get_coor(args[1], &cam->coor))
		return (free(cam), EXIT_FAILURE);
	cam->vector = init_vec3();
	if (!get_norm(args[2], &cam->vector))
		return (free(cam), EXIT_FAILURE);
	cam->fov = ft_atoi(args[3]);
	scene->cam = cam;
	return (EXIT_SUCCESS);
}
