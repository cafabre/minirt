/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misconfig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:18:04 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/16 12:23:55 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//fichier a renommer ?

/* TYPES D ERREUR
1 couldn't open file
2 wrong file type
3 empty file
4 wrong data : A and L take 2 args, C, sp and pl take 4, cy take 6
5 coords need to be 3 floats
6 values need to be in the appropriate range
7 can't have more than one A, L or C

*/

#include "minirt.h"

void    display_error_message(t_error error)
{
    write(2, "Error\n", 6);
    if (error == ERR_MALLOC)
        write(2, "Malloc failed\n", 14);
    else if (error == ERR_OPEN)
        perror("Open failed");
    else if (error == ERR_EMPTY_FILE)
        write(2, "Scene file is empty\n", 20);
    else if (error == ERR_INVALID_ARGS_COUNT)
        write(2, "Invalid number of arguments on one line\n", 40);
    else if (error == ERR_INVALID_COORDS)
        write(2, "Coordinates must be 3 floats separated by commas\n", 50);
    else if (error == ERR_INVALID_VALUE_RANGE)
        write(2, "Values must be in the appropriate range\n", 40);
    else if (error == ERR_INVALID_OBJECT_ID)
        write(2, "Not a valid object identifier (sp, pl, cy)\n", 43);
    else if (error == ERR_INVALID_SCENE_ID)
        write(2, "Not a valid scene identifier (A, L, C)\n", 39);
    else if (error == ERR_DUPLICATE_AMBIENT)
        write(2, "There is already an existing ambient light\n", 43);
    else if (error == ERR_DUPLICATE_LIGHT)
        write(2, "There is already an existing light spot\n", 40);
    else if (error == ERR_DUPLICATE_CAMERA)
        write(2, "There is already an existing camera\n", 36);
    else if (error == ERR_MALLOC_AMBIENT)
        write(2, "Malloc failed: couldn't allocate ambient light\n", 47);
    else if (error == ERR_MALLOC_LIGHT)
        write(2, "Malloc failed: couldn't allocate light spot\n", 44);
    else if (error == ERR_MALLOC_CAMERA)
        write(2, "Malloc failed: couldn't allocate camera\n", 40);
    else if (error == ERR_MALLOC_SPHERE)
        write(2, "Malloc failed: couldn't allocate sphere\n", 40);
    else if (error == ERR_MALLOC_PLANE)
        write(2, "Malloc failed: couldn't allocate plane\n", 39);
    else if (error == ERR_MALLOC_CYLINDER)
        write(2, "Malloc failed: couldn't allocate cylinder\n", 42);
    else if (error == ERR_ADD_AMBIENT)
        write(2, "Couldn't add the ambient light to the scene\n", 44);
    else if (error == ERR_ADD_LIGHT)
        write(2, "Couldn't add the light spot to the scene\n", 41);
    else if (error == ERR_ADD_CAMERA)
        write(2, "Couldn't add the camera to the scene\n", 37);
    else if (error == ERR_ADD_SPHERE)
        write(2, "Couldn't add the sphere to the scene\n", 37);
    else if (error == ERR_ADD_PLANE)
        write(2, "Couldn't add the plane to the scene\n", 36);
    else if (error == ERR_ADD_CYLINDER)
        write(2, "Couldn't add the cylinder to the scene\n", 39);
    else if (error == ERR_INVALID_SPHERE_DATA)
        write(2, "Invalid data for sphere\n", 24);
    else if (error == ERR_INVALID_PLANE_DATA)
        write(2, "Invalid data for plane\n", 23);
    else if (error == ERR_INVALID_CYLINDER_DATA)
        write(2, "Invalid data for cylinder\n", 26);
    else if (error == ERR_INVALID_AMBIENT_DATA)
        write(2, "Invalid data for ambient light\n", 31);
    else if (error == ERR_INVALID_LIGHT_DATA)
        write(2, "Invalid data for light spot\n", 28);
    else if (error == ERR_INVALID_CAMERA_DATA)
        write(2, "Invalid data for camera\n", 24);
    else if (error == ERR_INVALID_VECTOR_COORDS)
        write(2, "Not enough coordinates for a vector\n", 36);
}
