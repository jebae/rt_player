/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:30:31 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:31:19 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		rt_print_err(const char *msg)
{
	put_color_str(KRED, msg);
	return (RT_FAIL);
}

int		rt_print_memalloc_err(const char *target)
{
	rt_print_err("RT : memalloc : Failed to allocate ");
	rt_print_err(target);
	ft_putchar('\n');
	return (RT_FAIL);
}
