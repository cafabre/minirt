/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:20 by syukna            #+#    #+#             */
/*   Updated: 2025/10/17 14:27:27 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_color(char *str, t_obj *obj)
{
	char	**args;
	t_vec4	*color;

	color = &obj->col;
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
	color->r = (float)ft_atoi(args[0]);
	color->g = (float)ft_atoi(args[1]);
	color->b = (float)ft_atoi(args[2]);
	color->a = 255.0;
	if (color->r < 0.0 || color->r > 255.0 || color->g < 0.0 || color->g > 255.0 || color->b < 0 || color->b > 255.0)
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	*color = vec4_scalar_div(*color, 255.0f);
	ft_free_sptr(args);
	return (1);
}

int	get_color_light(char *str, t_light *light)
{
	char **args;
	t_vec4 *color;

	color = &light->col;
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
	color->r = (float)ft_atoi(args[0]);
	color->g = (float)ft_atoi(args[1]);
	color->b = (float)ft_atoi(args[2]);
	color->a = 255.0;
	if (color->r < 0.0 || color->r > 255.0 || color->g < 0.0 || color->g > 255.0 || color->b < 0.0 || color->b > 255.0)
	{
		perror("The RGB values must remain between 0 and 255.\n");
		ft_free_sptr(args);
		return (0);
	}
	*color = vec4_scalar_div(*color, 255.0f);
	ft_free_sptr(args);
	return (1);
}
