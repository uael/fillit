/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 15:14:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef _Bool	t_bool;

typedef struct	s_ctx
{
	t_u16		*tetrs;
	t_usz		n;
}				t_ctx;

typedef struct	s_solve_ctx
{
	t_car		*map;
	t_usz		n;
	t_u08		ok[26];
}				t_solve_ctx;

extern t_u08	fillit_parse_file(t_ctx *ctx, t_car const *filename);
extern t_u08	fillit_solve(t_ctx *c);

#endif
