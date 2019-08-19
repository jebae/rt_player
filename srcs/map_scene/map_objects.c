#include "rt_player.h"

static size_t		get_object_size(t_objects *object)
{
	if (object->type == RT_OBJECT_TYPE_SPHERE)
		return (sizeof(t_sphere));
	else if (object->type == RT_OBJECT_TYPE_CONE)
		return (sizeof(t_cone));
	else if (object->type == RT_OBJECT_TYPE_PLANE)
		return (sizeof(t_plane));
	else if (object->type == RT_OBJECT_TYPE_CYLINDER)
		return (sizeof(t_cylinder));
	return (0);
}

static int			set_objects_buf(
	t_objects *objects,
	int num_objects,
	t_global_settings *settings
)
{
	int		i;

	settings->num_objects = num_objects;
	settings->objects_buf_size = 0;
	i = 0;
	while (i < num_objects)
	{
		settings->objects_buf_size += get_object_size(&(objects[i])) + sizeof(int);
		i++;
	}
	settings->objects_buf = (char *)ft_memalloc(settings->objects_buf_size);
	if (settings->objects_buf == NULL)
		return (RTP_FAIL);
	return (RTP_SUCCESS);
}

static void			write_object_by_type(t_objects *object, char *objects_buf)
{
	if (object->type == RT_OBJECT_TYPE_SPHERE)
		objects_buf += new_sphere(object, objects_buf);
	else if (object->type == RT_OBJECT_TYPE_CONE)
		objects_buf += new_cone(object, objects_buf);
	else if (object->type == RT_OBJECT_TYPE_PLANE)
		objects_buf += new_plane(object, objects_buf);
	else if (object->type == RT_OBJECT_TYPE_CYLINDER)
		objects_buf += new_cylinder(object, objects_buf);
}

int					map_objects(
	t_objects *objects,
	int num_objects,
	t_global_settings *settings
)
{
	int		i;

	if (set_objects_buf(objects, num_objects, settings) == RTP_FAIL)
		return (RTP_FAIL);
	i = 0;
	while (i < num_objects)
	{
		write_object_by_type(&(objects[i]), settings->objects_buf);
		i++;
	}
	return (RTP_SUCCESS);
}
