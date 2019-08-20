/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:05:26 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 17:07:45 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//TODO: if someone puts float for int I'll return error
void	handle_int_number(t_utils *u, int i, char *str)
{
	ft_getnumbers(u->number, str);
	printf("what is str %s\n", str);
	printf("nb copied = %s\n", u->number);
	while (*u->number != '\0')
	{
		ft_cpynb(u->sub_nb, u->number);
		printf("sub_nb copied = %s\n", u->sub_nb);
		if (check_sub(u->sub_nb))
			puts("THIS IS AN ERROR WILL RETURN ERROR LATER");
		i = ft_atoi(u->sub_nb);
		printf("INT DETECTED\n");
		while (*u->number != ',' && *u->number != '\0')
			u->number++;
		u->number++;
	}
	printf("THE INT IS = %d\n", i);
}

void	handle_theta_number(t_utils *u, float f, char *str)
{
	ft_getnumbers(u->number, str);
	printf("what is str %s\n", str);
	printf("nb copied = %s\n", u->number);
	while (*u->number != '\0')
	{
		ft_cpynb(u->sub_nb, u->number);
		printf("\nsub_nb copied = %s\n", u->sub_nb);
		if (check_sub(u->sub_nb))
		{
			f = M_PI / ft_atof(u->sub_nb);
			printf("FLOAT DETECTED\n");
		}
		else
		{
			f = M_PI / ft_atoi(u->sub_nb);
			printf("INT DETECTED\n");
		}
		while (*u->number != ',' && *u->number != '\0')
			u->number++;
		u->number++;
	}
	printf("THE FLOAT IS = %f\n", f);
}

void	handle_float_number(t_utils *u, float f, char *str)
{
	ft_getnumbers(u->number, str);
	printf("what is str %s\n", str);
	printf("nb copied = %s\n", u->number);
	while (*u->number != '\0')
	{
		ft_cpynb(u->sub_nb, u->number);
		printf("\nsub_nb copied = %s\n", u->sub_nb);
		if (check_sub(u->sub_nb))
		{
			f = ft_atof(u->sub_nb);
			printf("FLOAT DETECTED\n");
		}
		else
		{
			f = ft_atoi(u->sub_nb);
			printf("INT DETECTED\n");
		}
		while (*u->number != ',' && *u->number != '\0')
			u->number++;
		u->number++;
	}
	printf("THE FLOAT IS = %f\n", f);
}

void	handle_4vec_number(t_utils *u, t_vec4 *vec, char *str)
{
	int i;

	i = 0;
	ft_getnumbers(u->number, str);
	printf("what is str %s\n", str);
	printf("nb copied = %s\n", u->number);
	while (*u->number != '\0')
	{
		ft_cpynb(u->sub_nb, u->number);
		printf("sub_nb copied = %s\n", u->sub_nb);
		if (check_sub(u->sub_nb))
		{
			vec->arr[i]= ft_atof(u->sub_nb);
			printf("FLOAT DETECTED\n");
			i++;
		}
		else
		{
			vec->arr[i] = ft_atoi(u->sub_nb);
			printf("INT DETECTED\n");
			i++;
		}
		while (*u->number != ',' && *u->number != '\0')
			u->number++;
		u->number++;
	}
	// This is to print
	i = -1;
	while (++i < 4)
		printf("NUMBER = %f|\n", vec->arr[i]);

}
