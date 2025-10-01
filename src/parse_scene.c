/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:16:38 by syukna            #+#    #+#             */
/*   Updated: 2025/10/01 17:45:27 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_ambient(char **args, t_scene *scene)
{
	t_light *amb;
	t_coor	coor;
	t_color	color;

	amb = malloc(sizeof(t_light));
	if (!amb)
		return (EXIT_FAILURE);
	ft_memset(amb, '\0', sizeof(t_light));
	coor.x = 0;
	coor.y = 0;
	coor.z = 0;
	amb->coor = coor;
	amb->brightness = atof(args[1]);
	if (get_color(args[2], &color) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	amb->color = color;
	scene->amb = amb;
	return (EXIT_SUCCESS);
}

int	find_element(char **args, t_scene *scene)
{
	if (ft_strncmp(args[0], "A", 2) == 0)
		return (init_ambient(args, scene));
	else if (ft_strncmp(args[0], "C", 2) == 0)
		return (EXIT_SUCCESS);
	else if (ft_strncmp(args[0], "L", 2) == 0)
		return (EXIT_SUCCESS);
	else if (ft_strncmp(args[0], "pl", 3) == 0)
		return (EXIT_SUCCESS);
	else if (ft_strncmp(args[0], "sp", 3) == 0)
		return (EXIT_SUCCESS);
	else if (ft_strncmp(args[0], "cy", 3) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void replace_char(char **str, char old, char new)
{
	int i;
	
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == old)
		(*str)[i] = new;
	i++;
}
}

int parse_element(char *element, t_scene *scene)
{
	char	**args;
	
	args = NULL;
	// TODO better condition for jumping empty lines
	if (element[0] != '\n')
	{
		replace_char(&element, '\n', '\0');
		replace_char(&element, '\t', ' ');
		args = ft_split(element, ' ');
		if (find_element(args, scene) == EXIT_FAILURE)
		{
			// TODO solve perror
			perror("The element you entered does not exist, or is not known to this program. \nHere is a list of acceptable elements: A C L pl sp cy.\n");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int parse_scene(int fd)
{
	char *element;
	
	t_scene	scene;
	element = ft_gnl(fd);
	ft_memset(&scene, '\0', sizeof(t_scene));
	while (element)
	{
		if (parse_element(element, &scene) == EXIT_FAILURE)
		{
			// TODO add free all
			return (EXIT_FAILURE);
		}
		free(element);
		element = ft_gnl(fd);
	}
	print_scene(&scene);
	return (EXIT_SUCCESS);
}
