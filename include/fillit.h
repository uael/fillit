/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 14:19:52 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef _Bool	t_bool;

typedef struct	s_tetr
{
	t_u16		form;
	t_u08		n;
}				t_tetr;

typedef struct	s_ctx
{
	t_tetr		*tetrs;
	t_usz		n;
}				t_ctx;

typedef struct	s_solve_ctx
{
	t_car		*map;
	t_usz		i;
	t_usz		n;
	t_u08		ok[26];
}				t_solve_ctx;

extern t_u08	fillit_parse_file(t_ctx *ctx, t_car const *filename);
extern t_u08	fillit_solve(t_ctx *c);

#endif
