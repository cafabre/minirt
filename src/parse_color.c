/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:20 by syukna            #+#    #+#             */
/*   Updated: 2025/10/01 17:45:37 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_color(char *str, t_color *color)
{
	char **args;

	if (!ft_accept_chars(str, "0123456789,"))
		return (EXIT_FAILURE);
	args = ft_split(str, ',');
	color->r = ft_atoi(args[0]);
	color->g = ft_atoi(args[1]);
	color->b = ft_atoi(args[2]);
	return (EXIT_SUCCESS);
}