/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:20 by syukna            #+#    #+#             */
/*   Updated: 2025/10/07 16:18:43 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_color(char *str, t_color *color)
{
	char **args;

	if (!ft_accept_chars(str, "0123456789,"))
	{
		perror("The colors must not include other characters than numbers separated by ','.\n");
		return (EXIT_FAILURE);
	}
	args = ft_split(str, ',');
	if (!args[0] || (ft_strlen(args[0]) >= 10 && ft_strncmp(args[0], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (EXIT_FAILURE);
	}
	if (!args[1] || (ft_strlen(args[1]) >= 10 && ft_strncmp(args[1], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (EXIT_FAILURE);
	}
	if (!args[2] || (ft_strlen(args[2]) >= 10 && ft_strncmp(args[2], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (EXIT_FAILURE);
	}
	color->r = ft_atoi(args[0]);
	color->g = ft_atoi(args[1]);
	color->b = ft_atoi(args[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (EXIT_FAILURE);
	}
	ft_free_sptr(args);
	return (EXIT_SUCCESS);
}
