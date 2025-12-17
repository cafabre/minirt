/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misconfig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:18:04 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/17 14:11:24 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//fichier a renommer ?
// a normer -> trouver une solution pour diviser les fonctions plus proprement

static bool display_input_error(t_error e)
{
    if (e == ERR_INVALID_ARGS_COUNT)
        ft_printf("Invalid number of arguments, one expected (file name)");   
    else if (e == ERR_INVALID_FILE_TYPE)
        ft_printf("Invalid file type, need to be '.rt");
    else if (e == ERR_INVALID_FILE_NAME)
        ft_printf("Invalid file name, need to be '[name].rt");
    else if (e == ERR_OPEN)
    {
        perror("Open failed");
        return (false);
    }
    else if (e == ERR_EMPTY_FILE)
        ft_printf("Scene file is empty");
    return (true);
}

static void display_file_error(t_error e)
{
    if (e == ERR_INVALID_ARGS_LINE)
        ft_printf("Invalid number of arguments on one line");
    else if (e == ERR_INVALID_VALUE_RANGE)
        ft_printf("Values must be in the appropriate range");
    else if (e == ERR_INVALID_OBJECT_ID)
        ft_printf("Not a valid object identifier (sp, pl, cy)");
    else if (e == ERR_INVALID_SCENE_ID)
        ft_printf("Not a valid scene identifier (A, L, C)");
    else if (e == ERR_DUPLICATE_AMBIENT)
        ft_printf("There is already an existing ambient light");
    else if (e == ERR_DUPLICATE_LIGHT)
        ft_printf("There is already an existing light spot");
    else if (e == ERR_DUPLICATE_CAMERA)
        ft_printf("There is already an existing camera");
}

static void display_alloc_error(t_error e)
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
    else if (e == ERR_ADD_SPHERE)
        ft_printf("Couldn't add the sphere to the scene");
    else if (e == ERR_ADD_PLANE)
        ft_printf("Couldn't add the plane to the scene");
    else if (e == ERR_ADD_CYLINDER)
        ft_printf("Couldn't add the cylinder to the scene");
}

static void display_err_detail(t_err_detail d)
{
    ft_printf(": ");
    if (d == DETAIL_OUT_OF_RANGE)
        ft_printf("at least one value is outside of the allowed range");
    else if (d == DETAIL_NOT_A_NUMBER)
        ft_printf("at least one value is not a number");
    else if (d == DETAIL_BAD_FORMAT)
        ft_printf("coordinates need to be three floats separated by two comas");
}

void    display_error_message(t_data *data)
{
    if (!data || data->error == ERR_NONE)
        return ;
    else
        ft_printf("Error: ");
    if (!display_input_error(data->error))
        return ;
        
    display_file_error(data->error);
    display_alloc_error(data->error);

    if (data->error == ERR_INVALID_SPHERE_DATA)
        ft_printf("Invalid data for sphere");
    else if (data->error == ERR_INVALID_PLANE_DATA)
        ft_printf("Invalid data for plane");
    else if (data->error == ERR_INVALID_CYLINDER_DATA)
        ft_printf("Invalid data for cylinder");
    else if (data->error == ERR_INVALID_AMBIENT_DATA)
        ft_printf("Invalid data for ambient light");
    else if (data->error == ERR_INVALID_LIGHT_DATA)
        ft_printf("Invalid data for light spot");
    else if (data->error == ERR_INVALID_CAMERA_DATA)
        ft_printf("Invalid data for camera");
    else if (data->error == ERR_INVALID_VECTOR_COORDS)
        ft_printf("Not enough coordinates for a vector");
    if (data->detail != DETAIL_NONE)
        display_err_detail(data->detail);
    ft_printf("\n");
}
