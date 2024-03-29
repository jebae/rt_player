__kernel void		render(
	__global int *out,
	__global char *objects_buf,
	__global char *lights_buf,
	t_rt_settings_args settings_args
)
{
	int						idx = get_global_id(0);
	t_ray					ray;
	t_rt_settings			settings;
	t_trace_record			rec;
	t_trace_record_queue	rec_queue;

	settings = get_rt_settings(objects_buf, lights_buf, settings_args);
	ray = ray_origin(
		&(settings_args.ray_grid_props),
		idx % settings_args.window_width, idx / settings_args.window_width);
	ray.ior_medium = 1.0f;
	if (trace(ray, NULL, &rec, &settings))
	{
		init_rec_queue(&rec_queue);
		rec.coeff = 1.0f;
		rec.depth = 0;
		push_rec_queue(&rec_queue, rec);
		out[idx] = ray_trace(&rec_queue, &settings);
		return ;
	}
	out[idx] = RT_BACKGROUND_COLOR;
}
