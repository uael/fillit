/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/12 14:10:50 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef _Bool	t_bool;

typedef struct	s_tetr
{
	t_u16		form;
	t_u08		x;
	t_u08		y;
	t_car		letter;
}				t_tetr;

typedef struct	s_ctx
{
	t_tetr		*tetrs;
	t_usz		ntetrs;
	t_bool		*taken;
	t_usz		ntaken;
}				t_ctx;

extern t_u08	fillit_parse_file(t_ctx *ctx, t_car const *filename);

#endif
