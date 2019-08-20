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

static size_t		write_object_by_type(t_objects *object, char *objects_buf)
{
	if (object->type == RT_OBJECT_TYPE_SPHERE)
		return (new_sphere(object, objects_buf));
	else if (object->type == RT_OBJECT_TYPE_CONE)
		return (new_cone(object, objects_buf));
	else if (object->type == RT_OBJECT_TYPE_PLANE)
		return (new_plane(object, objects_buf));
	else if (object->type == RT_OBJECT_TYPE_CYLINDER)
		return (new_cylinder(object, objects_buf));
	return (0);
}

int					map_objects(
	t_objects *objects,
	int num_objects,
	t_global_settings *settings
)
{
	int		i;
	char	*objects_buf;

	if (set_objects_buf(objects, num_objects + 1, settings) == RTP_FAIL)
		return (RTP_FAIL);
	i = 0;
	objects_buf = settings->objects_buf;
	while (i < num_objects + 1)
	{
		objects_buf += write_object_by_type(&(objects[i]), objects_buf);
		i++;
	}
	return (RTP_SUCCESS);
}
