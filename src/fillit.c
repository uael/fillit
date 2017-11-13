/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 15:29:38 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_i32	main(t_i32 ac, t_car **av)
{
	t_ctx	ctx;

	if (ac != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (EXIT_FAILURE);
	}
	FT_INIT(&ctx, t_ctx);
	if (fillit_parse_file(&ctx, av[1]) || fillit_solve(&ctx))
	{
		ft_putendl("error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
