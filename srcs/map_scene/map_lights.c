#include "rt_player.h"

static size_t		get_light_size(t_lights *light)
{
	if (light->type == RT_LIGHT_TYPE_DISTANT)
		return (sizeof(t_distant_light));
	else if (light->type == RT_LIGHT_TYPE_SPHERICAL)
		return (sizeof(t_spherical_light));
	return (0);
}

static int			set_lights_buf(
	t_lights *lights,
	int num_lights,
	t_global_settings *settings
)
{
	int		i;

	settings->num_lights = num_lights;
	settings->lights_buf_size = 0;
	i = 0;
	while (i < num_lights)
	{
		settings->lights_buf_size += get_light_size(&(lights[i])) + sizeof(int);
		i++;
	}
	settings->lights_buf = (char *)ft_memalloc(settings->lights_buf_size);
	if (settings->lights_buf == NULL)
		return (RTP_FAIL);
	return (RTP_SUCCESS);
}

static void			write_light_by_type(t_lights *light, char *lights_buf)
{
	if (light->type == RT_LIGHT_TYPE_DISTANT)
		lights_buf += new_distant_light(light, lights_buf);
	else if (light->type == RT_LIGHT_TYPE_SPHERICAL)
		lights_buf += new_spherical_light(light, lights_buf);
}

int					map_lights(
	t_lights *lights,
	int num_lights,
	t_global_settings *settings
)
{
	int		i;

	if (set_lights_buf(lights, num_lights, settings) == RTP_FAIL)
		return (RTP_FAIL);
	i = 0;
	while (i < num_lights)
	{
		write_light_by_type(&(lights[i]), settings->lights_buf);
		i++;
	}
	return (RTP_SUCCESS);
}
