/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misconfig_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:28:08 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/14 13:25:39 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	display_input_error(t_error e)
{
	if (e == ERR_INVALID_ARGS_COUNT)
		ft_printf("Invalid number of arguments, one expected (file name)");
	else if (e == ERR_INVALID_FILE_TYPE)
		ft_printf("Invalid file type, need to be .rt");
	else if (e == ERR_INVALID_FILE_NAME)
		ft_printf("Invalid file name, need to be [name].rt");
	else if (e == ERR_OPEN)
	{
		perror("Open failed");
		return (false);
	}
	else if (e == ERR_EMPTY_FILE)
		ft_printf("Scene file is empty");
	return (true);
}

void	display_file_error(t_error e)
{
	if (e == ERR_INVALID_ARGS_LINE)
		ft_printf("Invalid number of arguments on one line");
	else if (e == ERR_INVALID_VALUE_RANGE)
		ft_printf("Values must be in the appropriate range");
	else if (e == ERR_INVALID_ID)
		ft_printf("Not a valid identifier (accepted : A, C, L, sp, pl, cy)");
	else if (e == ERR_DUPLICATE_AMBIENT)
		ft_printf("There is already an existing ambient light");
	else if (e == ERR_DUPLICATE_LIGHT)
		ft_printf("There is already an existing light spot");
	else if (e == ERR_DUPLICATE_CAMERA)
		ft_printf("There is already an existing camera");
	else if (e == ERR_INVALID_VECTOR_COORDS)
		ft_printf("Not enough coordinates for a vector");
	else if (e == ERR_MISSING_ELEMENT)
		ft_printf("Missing at least one element (expected : C, A and L)");
}

void	display_alloc_error(t_error e)
{
	if (e == ERR_MALLOC_AMBIENT)
		ft_printf("Malloc failed: couldn't allocate ambient light");
	else if (e == ERR_MALLOC_LIGHT)
		ft_printf("Malloc failed: couldn't allocate light spot");
	else if (e == ERR_MALLOC_CAMERA)
		ft_printf("Malloc failed: couldn't allocate camera");
	else if (e == ERR_MALLOC_SPHERE)
		ft_printf("Malloc failed: couldn't allocate sphere");
	else if (e == ERR_MALLOC_PLANE)
		ft_printf("Malloc failed: couldn't allocate plane");
	else if (e == ERR_MALLOC_CYLINDER)
		ft_printf("Malloc failed: couldn't allocate cylinder");
}

void	display_data_error(t_error e)
{
	if (e == ERR_INVALID_SPHERE_DATA)
		ft_printf("Invalid data for sphere");
	else if (e == ERR_INVALID_PLANE_DATA)
		ft_printf("Invalid data for plane");
	else if (e == ERR_INVALID_CYLINDER_DATA)
		ft_printf("Invalid data for cylinder");
	else if (e == ERR_INVALID_AMBIENT_DATA)
		ft_printf("Invalid data for ambient light");
	else if (e == ERR_INVALID_LIGHT_DATA)
		ft_printf("Invalid data for light spot");
	else if (e == ERR_INVALID_CAMERA_DATA)
		ft_printf("Invalid data for camera");
}
