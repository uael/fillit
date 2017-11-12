/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/12 11:48:04 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_i32	ft_exit(t_i32 code, t_car *msg)
{
	if (msg)
		ft_putendl(msg);
	else
		ft_putchar('\n');
	return (code);
}

t_i32	main(t_i32 ac, t_car **av)
{
	t_ctx	ctx;
	t_usz	i;

	if (ac != 2)
		return (ft_exit(EXIT_FAILURE, "usage: fillit source_file"));
	FT_INIT(&ctx, t_ctx);
	if (fillit_parse_file(&ctx, av[1]))
		return (ft_exit(EXIT_FAILURE, "error"));
	i = 0;
	while (i < ctx.nelms)
		ft_putnbr(fillit_validate(ctx.elms[i++]));
	return (EXIT_SUCCESS);
}
