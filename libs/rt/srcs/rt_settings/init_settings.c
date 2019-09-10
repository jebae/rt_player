/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:45:09 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:45:37 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_rt_settings(
	t_rt_settings *settings,
	t_init_rt_settings_args *args
)
{
	settings->parallel_mode = args->parallel_mode;
	settings->deep_trace = args->deep_trace;
	settings->window_width = args->width;
	settings->window_height = args->height;
	settings->i_a = args->i_a;
	settings->img_buf = args->img_buf;
}
