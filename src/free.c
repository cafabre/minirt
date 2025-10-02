/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:32:15 by syukna            #+#    #+#             */
/*   Updated: 2025/10/02 17:24:41 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_splitted(char **args)
{
	int i;
	
	i = 0;
	while(args[i])
		i++;
	while (i > 0)
	{
		i--;
		free(args[i]);
	}
	free(args);
}

void	free_all(t_scene *scene)
{
	if (scene->amb)
		free(scene->amb);
}