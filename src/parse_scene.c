/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:16:38 by syukna            #+#    #+#             */
/*   Updated: 2025/09/30 16:49:21 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_ambient(char **args, t_scene *scene)
{
	(void)args;
	(void)scene;
	printf("FOUND AMBIENT\n");
	
	return (EXIT_SUCCESS);
}

int	find_element(char **args, t_scene *scene)
{
	if (ft_strncmp(args[0], "A", 2) == 0)
		return (init_ambient(args, scene));
	
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

int parse_element(char *element)
{
	char	**args;
	t_scene	scene;

	ft_memset(&scene, '\0', sizeof(t_scene));
	// replace_char(&element, '\n', ' ');
	replace_char(&element, '\t', ' ');
	args = ft_split(element, ' ');
	if (args[0][0] != '\n')
	{
		find_element(args, &scene);
		printf("args = |%s|%s|%s|%s|", args[0], args[1], args[2], args[3]);
	}
	return (EXIT_SUCCESS);
}

int parse_scene(int fd)
{
	char *element;

	element = ft_gnl(fd);
	while (element)
	{
		// printf("|%s|", element);
		parse_element(element);
		free(element);
		element = ft_gnl(fd);
	}
	return (EXIT_SUCCESS);
}