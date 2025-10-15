/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:16:38 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 19:57:43 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	find_element(char **args, t_scene *scene)
{
	if (!args[0])
		return (EXIT_FAILURE);
	if (ft_strncmp(args[0], "#", 1) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(args[0], "A", 2) == 0)
		return (init_ambient(args, scene));
	else if (ft_strncmp(args[0], "C", 2) == 0)
		return (init_cam(args, scene));
	else if (ft_strncmp(args[0], "L", 2) == 0)
		return (init_light(args, scene));
	else if (ft_strncmp(args[0], "pl", 3) == 0)
		return (init_obj(args, scene, PLANE));
	else if (ft_strncmp(args[0], "sp", 3) == 0)
		return (init_obj(args, scene, SPHERE));
	else if (ft_strncmp(args[0], "cy", 3) == 0)
		return (init_obj(args, scene, CYLINDER));
	perror("The element you entered does not exist, \
		or is not known to this program. \nHere is a\
		 list of acceptable elements: A C L pl sp cy.\n");
	return (EXIT_FAILURE);
}

int parse_element(char *element, t_scene *scene)
{
	char	**args;
	int		i;

	i = 0;
	args = NULL;
	while (ft_accept_char(" \t", element[i]))
		i++;
	if (element[i] != '\n')
	{
		replace_char(&element, '\n', '\0');
		replace_char(&element, '\t', ' ');
		args = ft_split(element, ' ');
		if (find_element(args, scene) == EXIT_FAILURE)
			return (ft_free_sptr(args), EXIT_FAILURE);
		ft_free_sptr(args);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int parse_scene(int fd, t_env *env) //changed from scene to env
{
	t_scene	*scene; //added
	char	*element;

	scene = malloc(1 * sizeof(t_scene)); //added
	if (!scene) //added
		return (EXIT_FAILURE); //added
	env->scene = scene; //added
	element = ft_gnl(fd);
	while (element)
	{
		if (parse_element(element, scene) == EXIT_FAILURE)
		{
			free(element);
			free_scene(scene);
			return (EXIT_FAILURE);
		}
		free(element);
		element = ft_gnl(fd);
	}
	print_scene(scene);
	return (EXIT_SUCCESS);
}
