/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/11 15:03:08 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void list_to_array(t_list *list, char ****data_ptr)
{
    int     size;
    char    ***data;
    t_list  *tmp;
    int     i;

    size = ft_lstsize(list);
    i = 0;
    data = malloc(sizeof(char **) * (size + 1));
    if (!data)
        return ;
    tmp = list;
    while (tmp)
    {
        data[i++] = (char **)tmp->content; // recuperer le tab stocke
        tmp = tmp->next;
    }
    data[i] = NULL;
    *data_ptr = data;
}

static bool    parse_ids(int fd, char ****data)
{
    char    *line;
    char    **tab;
    t_list  *list; //liste chainee -> chaque node = un tableau des infos d une ligne
    t_list  *node;

    list = NULL;
    while ((line = ft_gnl(fd)) != NULL)
    {
        tab = ft_split_whitespaces(line);
        free (line);
        if (!tab || !tab[0] || ft_strcmp(tab[0], "\n") == 0)
        {
            free_tab(tab);
            continue ;
        }
        node = ft_lstnew(tab);
        if (!node)
        {
            free_tab(tab);
            //free list
            return (false);
        }
        ft_lstadd_back(&list, node);     
        if (!dispatch_ids(tab))
        {
            free_tab(tab);
            //free list
            return (false); 
        }
    }
    list_to_array(list, data);
    return (true);
}

int     parsing(int fd)
{
    char ***data;

    data = NULL;
    if (!parse_ids(fd, &data))
        return (EXIT_FAILURE);
    //a completer
    return (EXIT_SUCCESS);
}

/*
RESTE A FAIRE
- verif du nb d apparitions de A, L et C
- gestion de la remontee d erreur a revoir
- refactor de certaines fonctions trop longues
- deplacer les utils dans la libft
- fonctions de free / clean (tab, all...)
*/