/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 16:46:47 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fillit_print(t_car *m, t_usz n)
{
	t_usz i;

	i = 0;
	while (i < n)
	{
		write(1, m + (i++ * n), n);
		ft_putchar('\n');
	}
}

t_i32		main(t_i32 ac, t_car **av)
{
	t_tetrs	tetrs;
	t_car	*map;
	t_usz	n;

	if (ac != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (EXIT_FAILURE);
	}
	FT_INIT(&tetrs, t_tetrs);
	if (fillit_parse(&tetrs, av[1]))
	{
		ft_putendl("error");
		return (EXIT_FAILURE);
	}
	n = fillit_solve(&tetrs, &map);
	fillit_print(map, n);
	free(map);
	return (EXIT_SUCCESS);
}
