/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:54:26 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/12 15:48:07 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

t_u08	fillit_put(t_ctx *ctx, t_tetr *tetr)
{
	(void)ctx;
	(void)tetr;
	return (0);
}

t_u08	fillit_solve(t_ctx *ctx)
{
	(void)ctx;
	return (0);
}
