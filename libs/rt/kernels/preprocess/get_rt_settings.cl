t_rt_settings	get_rt_settings(
	__global char *objects_buf,
	__global char *lights_buf,
	t_rt_settings_args args
)
{
	t_rt_settings		settings;

	settings.objects_buf = objects_buf;
	settings.lights_buf = lights_buf;
	settings.num_objects = args.num_objects;
	settings.num_lights = args.num_lights;
	settings.i_a = args.i_a;
	settings.deep_trace = args.deep_trace;
	return (settings);
}
