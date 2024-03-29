/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parallel.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:42:37 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:42:39 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARALLEL_H
# define RT_PARALLEL_H

# include "clkit.h"
# include "rt_struct.h"

# define RT_NUM_CL_KERNELS				1
# define RT_NUM_CL_MEMS					3
# define RT_CL_MEM_IMAGE				0
# define RT_CL_MEM_OBJECTS				1
# define RT_CL_MEM_LIGHTS				2

int						create_buffers(
	t_clkit *clkit,
	t_rt_settings *args
);

int						update_buffers(
	t_clkit *clkit,
	t_rt_settings *settings
);

int						init_clkit(
	t_clkit *clkit,
	t_rt_settings *settings
);

int						set_kernel_args(
	t_clk_kernel *kernel,
	t_clk_mem *mems,
	t_rt_settings *settings
);

int						enqueue_ndrange_kernel(
	t_clk_cmd_queue *cmd_queue,
	t_clk_kernel *kernel,
	size_t work_size
);

int						enqueue_read_buffer(
	t_clk_cmd_queue *cmd_queue,
	t_clk_mem *mem,
	int *host_buf,
	t_rt_settings *settings
);

int						execute_cmd_queue(t_clk_cmd_queue *cmd_queue);

void					release_clkit(t_clkit *clkit);

char					*concat_kernel_src(void);

int						render_scene(
	t_clkit *clkit,
	t_rt_settings *settings
);

#endif
