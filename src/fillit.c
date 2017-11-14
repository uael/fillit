/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 14:48:41 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_tetrs	tetrs;
	char	*map;
	size_t	n;
	size_t	i;

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
	i = 0;
	while (i < n && write(1, map + (i++ * n), n))
		ft_putchar('\n');
	free(map);
	free(tetrs.buf);
	return (EXIT_SUCCESS);
}
