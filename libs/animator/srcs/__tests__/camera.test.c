#include "animator_test.h"

static float		WIDTH = 1000;
static float		HEIGHT = 800;
static t_vec4		i_a = (t_vec4){{0.05f, 0.05f, 0.05f, 1.0f}};

static t_ray_grid_properties	get_ray_grid_props_for_test(t_camera *cam)
{
	t_ray_grid_properties	props;
	t_vec4					focus;

	focus = (t_vec4){{0.0f, 5.0f, 0.0f, 1.0f}};
	cam->pos = (t_vec4){{0.0f, 0.0f, 0.0f, 1}};
	cam->roll = 0.0f;
	cam->zoom = 1.0f;
	set_camera_axis(cam, &focus);
	props = get_ray_grid_properties(cam, WIDTH, HEIGHT, M_PI / 2.0f);
	return (props);
}

static size_t		get_cone(char *objects_buf)
{
	t_new_cone_args				args_cone;
	t_object_commons			commons;

	commons.specular_alpha = 50;
	commons.reflectivity = 0.1f;
	commons.transparency = 0.0f;
	commons.ior = 1.5f;
	commons.color = (t_vec4){{0.2f, 0.6f, 0.8f, 1}};
	args_cone.h = 2.0f;
	args_cone.theta = M_PI / 6.0f;
	args_cone.c = (t_vec4){{1.0f, 5.0f, 0.0f, 1.0f}};
	args_cone.v = (t_vec4){{-1.0f, 0.0f, -1.0f, 1.0f}};
	return (new_cone(commons, &args_cone, objects_buf));
}

static size_t		get_sphere(char *objects_buf)
{
	t_new_sphere_args			args_sphere;
	t_object_commons			commons;

	commons.specular_alpha = 50;
	commons.reflectivity = 0.1f;
	commons.transparency = 0.0f;
	commons.ior = 1.5f;
	commons.color = (t_vec4){{0.9f, 0.6f, 0.1f, 1}};
	args_sphere.r = 1.0f;
	args_sphere.c = (t_vec4){{-2.0f, 5.0f, 0.5f, 1.0f}};
	return (new_sphere(commons, &args_sphere, objects_buf));
}

static size_t		get_cylinder(char *objects_buf)
{
	t_new_cylinder_args			args_cylinder;
	t_object_commons			commons;

	commons.specular_alpha = 50;
	commons.reflectivity = 0.1f;
	commons.transparency = 0.4f;
	commons.ior = 1.5f;
	commons.color = (t_vec4){{0.6f, 0.9f, 0.1f, 1}};
	args_cylinder.r = 1.0f;
	args_cylinder.h = 2.0f;
	args_cylinder.c = (t_vec4){{0.0f, 5.0f, 0.5f, 1.0f}};
	args_cylinder.v = (t_vec4){{2.0f,-5.0f, -0.5f, 1.0f}};
	return (new_cylinder(commons, &args_cylinder, objects_buf));
}

static size_t		get_distant_light(char *lights_buf)
{
	t_new_distant_light_args	args_light;
	t_light_commons				commons;

	commons.intensity = (t_vec4){{1.0f, 1.0f, 1.0f}};
	args_light.d = (t_vec4){{1.0f, 1.0f, -1.0f, 1}};
	return (new_distant_light(commons, &args_light, lights_buf));
}

static void			write_objects(char *objects_buf)
{
	objects_buf += get_cone(objects_buf);
	objects_buf += get_sphere(objects_buf);
	objects_buf += get_cylinder(objects_buf);
}

static void			write_lights(char *lights_buf)
{
	lights_buf += get_distant_light(lights_buf);
}

void				test_camera(int parallel_mode)
{
	t_test_dispatcher		dispatcher;
	size_t					buf_size;
	t_clkit					clkit;
	t_global_settings		settings;

	dispatcher.settings = &settings;
	dispatcher.clkit = &clkit;
	settings.parallel_mode = parallel_mode;
	settings.window_width = WIDTH;
	settings.window_height = HEIGHT;
	init_mlx(&dispatcher, WIDTH, HEIGHT);
	init_marker(&(dispatcher.marker), dispatcher.p_mlx, dispatcher.p_win, &settings);

	settings.ray_grid_props = get_ray_grid_props_for_test(&(dispatcher.cam));
	settings.i_a = i_a;

	settings.img_buf = (int *)get_img_buffer(
		dispatcher.marker.p_img, settings.window_width);

	settings.num_objects = 3;
	buf_size = sizeof(t_cone) +
		sizeof(t_sphere) +
		sizeof(t_cylinder) +
		sizeof(int) * settings.num_objects;
	settings.objects_buf_size = buf_size;
	settings.objects_buf = (char *)ft_memalloc(buf_size);
	write_objects(settings.objects_buf);

	settings.num_lights = 1;
	buf_size = sizeof(t_distant_light) +
		sizeof(int) * settings.num_lights;
	settings.lights_buf_size = buf_size;
	settings.lights_buf = (char *)ft_memalloc(buf_size);
	write_lights(settings.lights_buf);

	init_clkit(&clkit, &settings);
	render_scene(&clkit, &settings);
	mlx_put_image_to_window(
		dispatcher.marker.p_mlx,
		dispatcher.marker.p_win,
		dispatcher.marker.p_img, 0, 0);
	mlx_loop(dispatcher.p_mlx);
}
