/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:48:11 by jebae             #+#    #+#             */
/*   Updated: 2019/09/02 18:48:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static void		play(char *scene_src, int parallel_mode)
{
	t_dispatcher			dispatcher;
	t_clkit					clkit;
	t_global_settings		settings;
	t_utils					parse_res;

	ft_bzero(&parse_res, sizeof(parse_res));
	parse(&parse_res, scene_src);
	dispatcher.parallel_mode = parallel_mode;
	dispatcher.settings = &settings;
	dispatcher.clkit = &clkit;
	dispatcher.object_index = 0;
	set_mlx(&dispatcher, WIDTH, HEIGHT);
	settings = init_rt_global_settings(&dispatcher, WIDTH, HEIGHT);
	if (map_scene(&parse_res, &settings) == RTP_FAIL)
		ft_error("Mapping scene failed!");
	set_rt_global_settings_ray_grid_props(&settings, &(settings.cam));
	init_clkit(&clkit, &settings);
	render_by_mlx(&dispatcher);
	mlx_loop(dispatcher.p_mlx);
}

static int		print_usage(void)
{
	ft_putstr("Usage: ./rtv1 [ parallel mode flag ] {target file}\n");
	ft_putstr("parallel mode flag\n  -c : use CPU\n  -g : use GPU\n");
	return (0);
}

int				main(int argc, char **argv)
{
	int		flag_index;

	if (argc <= 1 || argc > 3)
		return (print_usage());
	if (argc == 2)
		play(argv[1], CL_DEVICE_TYPE_GPU);
	flag_index = 1;
	while (flag_index < 3)
	{
		if (argv[flag_index][0] == '-')
		{
			if (ft_strcmp(argv[flag_index], "-c") == 0)
				play(argv[3 - flag_index], CL_DEVICE_TYPE_CPU);
			if (ft_strcmp(argv[flag_index], "-g") == 0)
				play(argv[3 - flag_index], CL_DEVICE_TYPE_GPU);
		}
		flag_index++;
	}
	return (0);
}
