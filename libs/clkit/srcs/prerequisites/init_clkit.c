/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clkit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:41:29 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:41:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

void		clk_init_clkit(
	t_clkit *clkit,
	cl_uint num_mems,
	cl_uint num_kernels
)
{
	clkit->num_mems = num_mems;
	clkit->num_kernels = num_kernels;
	clkit->devices = NULL;
	clkit->cmd_queues = NULL;
	clkit->mems = NULL;
	clkit->kernels = NULL;
	clkit->context.created = CLKIT_FALSE;
	clkit->program.created = CLKIT_FALSE;
}
