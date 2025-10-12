/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:49:17 by syukna            #+#    #+#             */
/*   Updated: 2025/10/12 16:17:49 by sandykds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_bri(char *str, t_light **light)
{
	(*light)->bri = atof(str);
	if (!str || (ft_strlen(str) >= 10 && ft_strncmp(str, "2147483647", 10) > 0))
	{
		perror("The light must remain between 0.0 and 1.0\n");
		return (0);
	}
	if (!ft_accept_chars(str, "0123456789-."))
	{
		perror("The light brightness must not include other characters than numbers, '-' and '.'\n");
		return (0);
	}
	if ((*light)->bri > 1 || (*light)->bri < 0)
	{
		perror("The light must remain between 0.0 and 1.0\n");
		return (0);
	}
	return (1);
}

int	init_ambient(char **args, t_scene *scene)
{
	t_light *amb;

	amb = malloc(sizeof(t_light));
	if (!amb)
		return (EXIT_FAILURE);
	ft_memset(amb, '\0', sizeof(t_light));
	amb->coor = init_vec3();
	if (!get_bri(args[1], &amb))
		return (free(amb),EXIT_FAILURE);
	if (!get_color_light(args[2], amb))
		return (free(amb),EXIT_FAILURE);
	scene->amb = amb;
	return (EXIT_SUCCESS);
}

int	init_light(char **args, t_scene *scene)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (EXIT_FAILURE);
	ft_memset(light, '\0', sizeof(t_light));
	light->coor = init_vec3();
	if (!get_coor(args[1], &light->coor))
		return (free(light),EXIT_FAILURE);
	if (!get_bri(args[2], &light))
    	return (free(light),EXIT_FAILURE);
	if (!get_color_light(args[3], light))
		return (free(light),EXIT_FAILURE);
	scene->l = light;
	return (EXIT_SUCCESS);
}
