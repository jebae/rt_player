/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:49 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:41:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_create_context(t_clkit *clkit)
{
	cl_int		ret;

	clkit->context.obj = clCreateContext(
		NULL,
		clkit->num_devices,
		clkit->devices,
		NULL,
		NULL,
		&ret);
	if (clk_check_create_context(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	clkit->context.created = CLKIT_TRUE;
	return (CLKIT_SUCCESS);
}
