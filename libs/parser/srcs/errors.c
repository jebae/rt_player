/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:28:14 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/07 16:32:15 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_error_parse(t_utils *u, char *str, char *error)
{
	ft_putendl(error);
	ft_putendl("Freeing...");
	free_strings(u, str);
	ft_putendl("Done!");
	exit(1);
}

void	ft_error(char *error)
{
	ft_putendl(error);
	ft_putendl("No allocations were made before this point!");
	ft_putendl("Done!");
	exit(1);
}
