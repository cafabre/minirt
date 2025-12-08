/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/08 16:24:04 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     parsing(char *file_name, int argc)
{
    int fd;

    if (argc != 2)
    /// verif des args -> main ou parsing ?
    if (!has_rt_type(file_name))
    {
        perror("ERROR: file type need to be .rt");
        return (EXIT_FAILURE);
    }
    fd = open(file_name, O_RDONLY);
    if (file_parsing != 0)
    {
        clean_all(); //a coder
        close (fd);
        return (EXIT_FAILURE);
    }
    if (correct_ids(fd) == false)
    {
        clean_all();
        close (fd);
        return (EXIT_FAILURE);
    }
    close (fd);
    return (EXIT_SUCCESS);
}

/*
1. parsing.c -> parsing : verif des arguments (main ?), verif nom du fichier, open le fichier,
appelle file_parsing

2. file.c -> file_parsing : verifie si le fichier a pu etre ouvert puis s'il est vide. si tout ok ->
return EXIT_SUCCESS (EXIT_FAILURE sinon)

3. retour dans parsing : si erreur dans le parsing du fichier -> clean tout puis close le fichier et retour,
puis appelle correct_ids

4. dispatcher.c -> correct_ids : lit le fichier, rempli tab avec la ligne en cours
(ex : tab=[A][0.5][0,0,0]) puis l ajoute a data (data = tableau de tableaux)
puis appelle check_id sur tab actuel

5. dispatcher.c -> check_id : appelle la bonne fonction de fill en fonction du nb d infos
+ de l ID

6. objects.c -> fonctions de fill d objets (fill_sphere_data, fill_plane_data, fill_cylinder_data)
chacune : alloue un objet, remplit son type + les infos utiles (laisse le reste a NULL)
pour certaines infos (pos, dir, col) : appelle parse_vectors
OU
scene.c -> fonctions de fill de scene (fill_light_data, fill_camera_data)
chacune : idem que pour les obj, /!\ fill_light_data utilisee pour Light et Ambient light

7. parsing_utils.c -> parse_vectors : alloue un vecteur, cree un tableau de coordonnees
de type char ** (ex: coords = [-1,1,3] avec -1,1 et 3 des char *) en splitant la case numero 1 de tab (numero 0 = l ID)
puis appelle fill_vector

8. parsing_utils.c -> fill_vector : transforme les char * en float puis rempli vec avec

9. retour a parse_vectors -> retour aux fonctions de fill -> retour a check_id -> retour a correct_ids
tous les objets ont ete remplis avec les infos du fichier

10. retour dans parsing : parsing finit, les strcut sont remplies, close le fd et return EXIT_SUCCESS

RESTE A FAIRE
- verif de la syntaxe du fichier passe en param (doubles sauts de ligne (DONE),
plusieurs virgules, pas de chiffres (DONE))
- verif du nb d apparitions de A, L et C
- gestion de la remontee d erreur a revoir
- utiliser va_args pour les fonctions de fill ??
- refactor de certaines fonctions trop longues
- deplacer les utils dans la libft
- gerer le probleme de caertains param de obj, light et camera passes en pointeurs pour le parsing /
utilises tels quels dans l exec
- fonctions de free / clean (tab, all...)
*/