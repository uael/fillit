/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 11:57:52 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_i32	ft_strnequ(t_car const *s1, t_car const *s2, t_usz n)
{
	if (!s1)
		return (!s2 && !n);
	if (!s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}
