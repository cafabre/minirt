/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:31:14 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 20:00:10 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// PARSING
int		parse_scene(int fd, t_scene *scene);
int		get_pos(char *str, t_vec4 *pos);
int		get_color(char *str, t_obj *obj);
int		get_color_light(char *str, t_light *light);
int		get_dir(char *str, t_vec4 *dir);
t_vec4	init_vec4(void);
t_color	init_color(void);

// PARSING OBJECTS
int	init_cam(char **args, t_scene *scene);
int	init_ambient(char **args, t_scene *scene);
int	init_light(char **args, t_scene *scene);
int	init_obj(char **args, t_scene *scene, t_objtype objt);

// PARSING UTILS
int		ft_accept_chars(char *str, char *ref);
int		ft_accept_char(char *ref, char letter);
void	replace_char(char **str, char old, char new);

// PRINT ALL
void	print_scene(t_scene *scene);

// FREE ALL
void	free_all(t_scene *scene);
void	free_splitted(char **args);

#endif
