/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:28:14 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 18:28:21 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_error(char *error)
{
	ft_putstr(error);
	ft_putstr(" | Freeing...");
	// TODO(almoraru): add freeing functions
	ft_putendl("Done");
	exit(1);
}
