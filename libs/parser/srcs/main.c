/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:27:05 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/19 16:34:09 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "parse.h"

int main(int ac, char **av)
{
	t_utils u;

	ft_bzero(&u, sizeof(u));
	ft_putendl("FILE OPENED!");
	printf("%d = %s\n", ac, av[1]);
	if (ac == 2)
	{
		if (parse(&u, av[1]))
			ft_error("Parsing failed!");
	}
	else
		ft_error("Wrong number of arguments!\nUSAGE:\n./program_name file_to_parse!\n");
	return (0);
}
