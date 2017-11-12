/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/11 18:03:45 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_i32	main(void)
{
	t_ctx	ctx;
	t_usz	i;

	FT_INIT(&ctx, t_ctx);
	if (fillit_parse_file(&ctx, "map01"))
	{
		ft_putstr("error");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < ctx.nelms)
		ft_putnbr(fillit_validate(ctx.elms[i++]));
	return (EXIT_SUCCESS);
}
