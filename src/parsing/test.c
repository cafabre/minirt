#include "minirt.h"

#include <stdio.h>

static void	display_vec4(const char *name, t_vec4 v)
{
	printf("    %s : (%.2f, %.2f, %.2f, %.2f)\n",
		name, v.x, v.y, v.z, v.w);
}

static void	display_lights(t_light *l)
{
	int	i = 0;

	while (l)
	{
		printf("Light\n");
		display_vec4("pos", l->pos);
		printf("    lum : %.2f\n", l->lum);
		display_vec4("col", l->col);
		l = l->next;
		i++;
	}
	if (i == 0)
		printf("  (no lights)\n");
}

static const char	*obj_type_to_str(enum e_objtype type)
{
	if (type == SPHERE)
		return ("SPHERE");
	if (type == PLANE)
		return ("PLANE");
	if (type == CYLINDER)
		return ("CYLINDER");
	return ("UNKNOWN");
}

static void	display_object(t_obj *o, int i)
{
	printf("  Object [%d] (%s)\n", i, obj_type_to_str(o->type));
	display_vec4("pos", o->pos);
	display_vec4("dir", o->dir);
	display_vec4("col", o->col);
	printf("    diam   : %.2f\n", o->diam);
	printf("    height : %.2f\n", o->height);
	printf("    rad    : %.2f\n", o->rad);
}

static void	display_objects(t_obj *objs)
{
	int	i = 0;

	while (objs)
	{
		display_object(objs, i);
		objs = objs->next;
		i++;
	}
	if (i == 0)
		printf("  (no objects)\n");
}

static void	display_camera(t_cam *cam)
{
	if (!cam)
	{
		printf("Camera : (null)\n");
		return;
	}
	printf("Camera\n");
	display_vec4("pos", cam->pos);
	display_vec4("dir", cam->dir);
	printf("    fov : %d\n", cam->fov);
}

void	display_scene(t_scene *s)
{
	if (!s)
	{
		printf("Scene : (null)\n");
		return;
	}

	printf("========== SCENE ==========\n");

	/* Ambient light */
	printf("Ambient light\n");
	if (s->amb)
	{
		display_vec4("col", s->amb->col);
		printf("    lum : %.2f\n", s->amb->lum);
	}
	else
		printf("  (none)\n");

	/* Lights */
	printf("\n");
	display_lights(s->l);

	/* Camera */
	printf("\n");
	display_camera(s->cam);

	/* Objects */
	printf("\nObjects\n");
	display_objects(s->objs);

	printf("======== END SCENE ========\n");
}
