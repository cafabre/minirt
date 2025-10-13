/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:20 by syukna            #+#    #+#             */
/*   Updated: 2025/10/12 14:42:23 by sandykds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color init_color(void)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (color);
}

int	get_color(char *str, t_obj *obj)
{
	char **args;
	t_color	*color;

	obj->color = init_color();
	color = &obj->color;
	if (!ft_accept_chars(str, "0123456789,"))
	{
		perror("The colors must not include other characters than numbers separated by ','.\n");
		return (0);
	}
	args = ft_split(str, ',');
	if (!args[0] || (ft_strlen(args[0]) >= 10 && ft_strncmp(args[0], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	if (!args[1] || (ft_strlen(args[1]) >= 10 && ft_strncmp(args[1], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	if (!args[2] || (ft_strlen(args[2]) >= 10 && ft_strncmp(args[2], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	};
	color->r = ft_atoi(args[0]);
	color->g = ft_atoi(args[1]);
	color->b = ft_atoi(args[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	ft_free_sptr(args);
	return (1);
}

int	get_color_light(char *str, t_light *light)
{
	char **args;
	t_color *color;

	light->color = init_color();
	color = &light->color;
	if (!ft_accept_chars(str, "0123456789,"))
	{
		perror("The colors must not include other characters than numbers separated by ','.\n");
		return (0);
	}
	args = ft_split(str, ',');
	if (!args[0] || (ft_strlen(args[0]) >= 10 && ft_strncmp(args[0], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	if (!args[1] || (ft_strlen(args[1]) >= 10 && ft_strncmp(args[1], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	if (!args[2] || (ft_strlen(args[2]) >= 10 && ft_strncmp(args[2], "2147483647", 10) > 0))
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	};
	color->r = ft_atoi(args[0]);
	color->g = ft_atoi(args[1]);
	color->b = ft_atoi(args[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	ft_free_sptr(args);
	return (1);
}
