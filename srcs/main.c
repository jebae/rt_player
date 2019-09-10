/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:48:11 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:02:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static void		play(char *scene_src, char options)
{
	t_dispatcher			dispatcher;
	t_clkit					clkit;
	t_rt_settings			settings;
	t_utils					parse_res;

	ft_bzero(&parse_res, sizeof(parse_res));
	parse(&parse_res, scene_src);
	dispatcher.options = options;
	dispatcher.settings = &settings;
	dispatcher.clkit = &clkit;
	dispatcher.object_index = 0;
	set_mlx(&dispatcher, WIDTH, HEIGHT);
	if (set_rt_settings(&settings, &dispatcher, &parse_res) == RTP_FAIL)
	{
		clear_all(&dispatcher);
		exit(1);
	}
	if (init_clkit(&clkit, &settings) == RT_FAIL)
	{
		clear_all(&dispatcher);
		exit(1);
	}
	render_by_mlx(&dispatcher);
	mlx_loop(dispatcher.p_mlx);
}

static int		print_usage(void)
{
	ft_putendl("Usage: ./rtv1 [ parallel mode ] [ deep trace ] {target file}\n"\
		"parallel mode\n  -c, --cpu : use CPU\n  -g, --gpu : use GPU\n"\
		"deep trace\n  -d, --deep-trace :"\
		"ray trace including reflection and refraction");
	return (1);
}

int				main(int argc, char **args)
{
	int		i;
	char	options;
	char	*scene_src;

	options = init_options();
	if (argc >= 3)
	{
		if (handle_options(&options, &(args[1]), argc - 1) == RTP_FAIL)
			return (print_usage());
	}
	scene_src = NULL;
	i = 1;
	while (i < argc)
	{
		if (args[i][0] != '-')
			scene_src = args[i];
		i++;
	}
	if (scene_src == NULL)
		return (print_usage());
	play(scene_src, options);
	return (0);
}
