/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:16:38 by syukna            #+#    #+#             */
/*   Updated: 2025/10/02 15:35:29 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	perror("The element you entered does not exist, or is not known to this program. \nHere is a list of acceptable elements: A C L pl sp cy.\n");
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
			free_splitted(args);
			return (EXIT_FAILURE);
		}
		free_splitted(args);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int parse_scene(int fd, t_scene	*scene)
{
	char *element;

	element = ft_gnl(fd);
	while (element)
	{
		if (parse_element(element, scene) == EXIT_FAILURE)
		{
			// TODO add free all
			free(element);
			free_all(scene);
			return (EXIT_FAILURE);
		}
		free(element);
		element = ft_gnl(fd);
	}
	print_scene(scene);
	return (EXIT_SUCCESS);
}
