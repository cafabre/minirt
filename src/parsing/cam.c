/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:06:56 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 19:47:56 by rshin            ###   ########lyon.fr   */
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
	cam->pos = init_vec4();
	if (!get_pos(args[1], &cam->pos))
		return (free(cam), EXIT_FAILURE);
	cam->dir = init_vec4();
	if (!get_dir(args[2], &cam->dir))
		return (free(cam), EXIT_FAILURE);
	cam->fov = ft_atoi(args[3]);
	scene->cam = cam;
	return (EXIT_SUCCESS);
}
