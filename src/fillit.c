/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 10:32:39 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BIT_AT(SET, Y, X, N) (((SET) >> (((Y) * (N)) + (X))) & 1)

t_i32		ft_exit(t_i32 code, t_car *msg)
{
	if (msg)
		ft_putendl(msg);
	else
		ft_putchar('\n');
	return (code);
}

static void	fillit_print(t_tetr *tetr)
{
	t_i32 x;
	t_i32 y;

	x = -1;
	while (++x < 4 && (y = -1) < 0)
	{
		while (++y < 4)
			if (BIT_AT(tetr->form, x, y, 4))
				ft_putchar(tetr->letter);
			else
				ft_putchar('.');
		ft_putchar('\n');
	}
}

t_i32		main(t_i32 ac, t_car **av)
{
	t_ctx	ctx;
	t_usz	i;

	if (ac != 2)
		return (ft_exit(EXIT_FAILURE, "usage: fillit source_file"));
	FT_INIT(&ctx, t_ctx);
	if (fillit_parse_file(&ctx, av[1]))
		return (ft_exit(EXIT_FAILURE, "error"));
	i = 0;
	while (i < ctx.ntetrs)
	{
		fillit_print(ctx.tetrs + i++);
		ft_putchar('\n');
	}
	return (EXIT_SUCCESS);
}
