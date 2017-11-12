/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/12 11:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef short	t_elm;

typedef struct	s_ctx
{
	t_elm		*elms;
	t_usz		nelms;
}				t_ctx;

extern t_u08	fillit_parse(t_ctx *ctx, t_dstr *str);
extern t_u08	fillit_parse_file(t_ctx *ctx, t_car const *filename);
extern t_u08	fillit_validate(t_elm elm);

#endif
